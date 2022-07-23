#include <fs.h>
#include <string.h>
typedef size_t (*ReadFn) (void *buf, size_t offset, size_t len);
typedef size_t (*WriteFn) (const void *buf, size_t offset, size_t len);

size_t ramdisk_read(void *buf, size_t offset, size_t len) ;
size_t ramdisk_write(const void *buf, size_t offset, size_t len);

size_t serial_write(const void *buf, size_t offset, size_t len);
size_t events_read(void *buf, size_t offset, size_t len);
size_t dispinfo_read(void *buf, size_t offset, size_t len);
size_t fb_write(const void *buf, size_t offset, size_t len);

typedef struct {
  char *name;
  size_t size;
  size_t disk_offset;
  ReadFn read;
  WriteFn write;
  size_t  lseek_off;
} Finfo;

enum {FD_STDIN, FD_STDOUT, FD_STDERR, FD_KEY, FD_DISPINFO, FD_FB};

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
  [FD_STDOUT] = {"stdout", 0, 0, invalid_read, serial_write},
  [FD_STDERR] = {"stderr", 0, 0, invalid_read, serial_write},
  [FD_KEY]    = {"/dev/events", 0, 0, events_read, invalid_write},
  [FD_DISPINFO] = {"/proc/dispinfo", 0, 0, dispinfo_read, invalid_write},
  [FD_FB]     = {"/dev/fb", 0, 0, invalid_read, fb_write},
#include "files.h"
};

////////////  fs_open    ////////////////////
 int sys_open(const char *path){
  for(int i=0;i<39;i++){
    if(strcmp(path,file_table[i].name)==0){
      //printf("***********STRACE**************\nmcause=2,syscall_name=SYS_open,ret_value=%d\n",i);
      return i;
    }     
  }
  printf("There is no matched file_name");
      assert(0);
   return -1;
}
///////////////  fs_write  ////////////////
 int sys_write(int fd,  char *buf, size_t count,Context *c){
 if((fd==1) || (fd==2)){
  c->GPRx = file_table[fd].write(buf,0,count);
  return c->GPRx;
  }
 else if(fd == 5){
   if(file_table[fd].lseek_off>file_table[fd].size)
     { assert(0);}
   if(file_table[fd].lseek_off+count>file_table[fd].size)
     { count = file_table[fd].size - file_table[fd].lseek_off;}  
  // printf("********************\n");
   c->GPRx = file_table[fd].write(buf,file_table[fd].lseek_off,count);
   
      file_table[fd].lseek_off += count;
  return c->GPRx;
 }
 else{
  if(file_table[fd].lseek_off>file_table[fd].size){
    assert(0);
  }
  if(file_table[fd].lseek_off+count>file_table[fd].size){
    count = file_table[fd].size - file_table[fd].lseek_off;
  }  
  ramdisk_write(buf,file_table[fd].lseek_off+file_table[fd].disk_offset, count);
  file_table[fd].lseek_off += count;
  c->GPRx = strlen(buf);
 }    
  printf("***********STRACE**************\nmcause=4,syscall_name=SYS_write,ret_value=%d\n",c->GPRx);
  return c->GPRx;
}

/*size_t fs_read(int fd, void *buf, size_t len){ 
 if(file_table[fd].read != NULL){ 
 return (file_table[fd].read)(buf,0,len); 
 } 
 else{ 
 size_t f_size = file_table[fd].size; 
 if(open_offset >= f_size){ 
 return -1; 
 } 
 if(open_offset + len > f_size){ 
 len = f_size - open_offset; 
 } 
 ramdisk_read(buf, file_table[fd].disk_offset + open_offset, len); 
 open_offset = open_offset + len; 
 return len; 
 } 
 }*/

/////////////// fs_read  /////////////////////
 int sys_read(int fd,void *buf,size_t count,Context *c){
   /* if(fd==3){ //for events read
     c->GPRx = file_table[fd].read(buf, 0, 0);   
     return 0;
    }
    else if(fd == 4){//// *buf=*w  count = size
      c->GPRx = file_table[fd].read(buf,0,0);
      return 0;
    }
    else if(c == 0){
      ramdisk_read(buf,file_table[fd].disk_offset,count);//sizeof(ehdr)
      //printf("打开文件=%s\n",file_table[fd].name);
      //printf("***********STRACE**************\nmcause=3,syscall_name=SYS_read_disk,ret_value=0\n");
      return 0;
    }*/
    if(file_table[fd].read != NULL){
      c->GPRx = file_table[fd].read(buf,0,0);
      return 0;
    }
    else{
       if(file_table[fd].lseek_off>file_table[fd].size){
        assert(0);
       }
       if(file_table[fd].lseek_off+count>file_table[fd].size){
        count = file_table[fd].size - file_table[fd].lseek_off;
       }  
      ramdisk_read(buf,file_table[fd].lseek_off+file_table[fd].disk_offset, count);//sizeof(ehdr)
      c->GPRx = count;
      file_table[fd].lseek_off += count; 
      //printf("***********STRACE**************\nmcause=3,syscall_name=SYS_read_file,ret_value=%d\n",c->GPRx);
       return c->GPRx;
      //assert(0);
    }
}
///////////////  fs_lseek  ///////////////////
 long sys_lseek(int fd, long offset, int whence){
    switch(whence){
      case SEEK_SET: file_table[fd].lseek_off = offset;
      //printf("seek_set\n"); 
      break;
      case SEEK_CUR: file_table[fd].lseek_off += offset;
      //printf("seek_cur\n");
      break;
      case SEEK_END: file_table[fd].lseek_off = file_table[fd].size+offset;
      //printf("seek_end\n");
      break;
      default : printf("invalid whence!\n");  assert(0);
    }
    if(file_table[fd].lseek_off<1||file_table[fd].lseek_off>file_table[fd].size){
      return -1;
    }
    else{
      //printf("lseek_off = %d\n",file_table[fd].lseek_off);
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
  int w = io_read(AM_GPU_CONFIG).width ;
  int h = io_read(AM_GPU_CONFIG).height ;
  for(int i=0;i<39;i++){
    if(strcmp("/dev/fb",file_table[i].name)==0){
      file_table[i].size = w*h*4; //byte num
    }     
  }

}
