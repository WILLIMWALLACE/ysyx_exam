#include <fs.h>
#include <string.h>
typedef size_t (*ReadFn) (void *buf, size_t offset, size_t len);
typedef size_t (*WriteFn) (const void *buf, size_t offset, size_t len);

size_t ramdisk_read(void *buf, size_t offset, size_t len) ;
size_t ramdisk_write(const void *buf, size_t offset, size_t len);

typedef struct {
  char *name;
  size_t size;
  size_t disk_offset;
  ReadFn read;
  WriteFn write;
  size_t  lseek_off;
} Finfo;

enum {FD_STDIN, FD_STDOUT, FD_STDERR, FD_FB};

size_t invalid_read(void *buf, size_t offset, size_t len) {
  panic("should not reach here");
  return 0;
}

size_t invalid_write(const void *buf, size_t offset, size_t len) {
  panic("should not reach here");
  return 0;
}

/* This is the information about all files in disk. */
static Finfo file_table[] __attribute__((used)) = {
  [FD_STDIN]  = {"stdin", 0, 0, invalid_read, invalid_write},
  [FD_STDOUT] = {"stdout", 0, 0, invalid_read, invalid_write},
  [FD_STDERR] = {"stderr", 0, 0, invalid_read, invalid_write},
#include "files.h"
};

////////////  fs_open    ////////////////////
 int sys_open(const char *path){
  for(int i=0;i<24;i++){
    if(strcmp(path,file_table[i].name)==0){
      printf("***********STRACE**************\nmcause=2,syscall_name=SYS_open,ret_value=%d\n",i);
      return i;
    }     
  }
  printf("There is no matched file_name");
      assert(0);
   return -1;
}
///////////////  fs_write  ////////////////
 int sys_write(int fd,  char *buf, size_t count,Context *c){
/*  if((fd!=1) && (fd!=2)){ 
    printf("fd is not valid!\n");
    c->GPRx = -1;
    assert(0);
  }
  else if(count == 0){
    c->GPRx = 0;
  }*/
 if((fd==1) || (fd==2)){
    int ret_cnt=0;
    while(count!=0){
        putch(*buf);
      buf++; count--; ret_cnt++;
    }
  c->GPRx = ret_cnt;
  printf("*********fd=%d*************\n",fd);
  printf("cuo wu xie ru,ret_cnt=%d\n",ret_cnt);
  //retrun c->GPRx;
  }
 else{
  if(file_table[fd].lseek_off>file_table[fd].size){
    assert(0);
  }
  if(file_table[fd].lseek_off+count>file_table[fd].size){
    count = file_table[fd].size - file_table[fd].lseek_off;
  }  
  ramdisk_write(buf,file_table[fd].lseek_off, count);
  printf("test fd = %d\n",fd);
  c->GPRx = strlen(buf);
 }
  //printf("***********STRACE**************\nmcause=4,syscall_name=SYS_WRITE,ret_value=%d\n",
  //c->GPRx);    
  printf("***********STRACE**************\nmcause=4,syscall_name=SYS_write,ret_value=%d\n",c->GPRx);
  return c->GPRx;
}
/////////////// fs_read  /////////////////////
 int sys_read(int fd,void *buf,size_t count,Context *c){
    if(c==0){
      //printf("disk_offset=%d\n",file_table[fd].disk_offset);
      //printf("disk_size=%d\n",file_table[fd].size);
      ramdisk_read(buf,file_table[fd].disk_offset,count);//sizeof(ehdr)
      //printf("read finish\n");
      //printf("buf=%s\n",buf);
      //c->GPRx = strlen(buf);
      //printf("ret_read = %d\n",c->GPRx);
      printf("***********STRACE**************\nmcause=3,syscall_name=SYS_read_disk,ret_value=0\n");
      return 0;
    }
    else{
       if(file_table[fd].lseek_off>file_table[fd].size){
        assert(0);
       }
       if(file_table[fd].lseek_off+count>file_table[fd].size){
        count = file_table[fd].size - file_table[fd].lseek_off;
       }  
       printf("\ncount=%d\n",count);
      ramdisk_read(buf,file_table[fd].lseek_off, count);//sizeof(ehdr)
      c->GPRx = strlen(buf);
      printf("***********STRACE**************\nmcause=3,syscall_name=SYS_read_file,ret_value=%d\n",c->GPRx);
       return c->GPRx;
      //assert(0);
    }
}
///////////////  fs_lseek  ///////////////////
 long sys_lseek(int fd, long offset, int whence){
    switch(whence){
      case SEEK_SET: file_table[fd].lseek_off = offset;
      printf("seek_set\n"); break;
      case SEEK_CUR: file_table[fd].lseek_off += offset;
      printf("seek_cur\n");break;
      case SEEK_END: file_table[fd].lseek_off = file_table[fd].size+offset;
      printf("seek_end\n");break;
      default : printf("invalid whence!\n");  assert(0);
    }
    if(file_table[fd].lseek_off<1||file_table[fd].lseek_off>file_table[fd].size){
      return -1;
    }
    else{
      printf("lseek_off = %d\n",file_table[fd].lseek_off);
      return file_table[fd].lseek_off;
    }
}


////////////////  fs_close  ////////////////////////
 int sys_close(){
  return 0;
}

 int file_size(int fd){
  return file_table[fd].size;
 }

 int ret_offset(int fd){
  return file_table[fd].disk_offset;
 }

void init_fs() {
  // TODO: initialize the size of /dev/fb
}
