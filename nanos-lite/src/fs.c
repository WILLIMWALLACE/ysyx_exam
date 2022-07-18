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
  //lseek offset
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
  for(int i=0;i<23;i++){
    if(strcmp(path,file_table[i].name)==0){
      return i;
    }     
  }
  printf("There is no matched file_name");
      assert(0);
 /* switch(*path){
    case "stdin"  :  return 0;  break;
    case "stdout" :  return 1;  break;
    case "stderr" :  return 2;  break;
    case "/share/pictures/projectn.bmp":  return 3;   break;
    case "/share/files/num" :             return 4;   break;
    case "/share/music/little-star.ogg":  return 5;   break;
    case "/share/music/rhythm/Re.ogg"  :  return 6;   break;
    case "/share/music/rhythm/Si.ogg"  :  return 7;   break;
    case "/share/music/rhythm/Mi.ogg"  :  return 8;   break;
    case "/share/music/rhythm/empty.ogg": return 9;   break;
    case "/share/music/rhythm/La.ogg":    return 10;  break;
    case "/share/music/rhythm/Do.ogg":    return 11;  break;
    case "/share/music/rhythm/Fa.ogg":    return 12;  break;
    case "/share/music/rhythm/So.ogg":    return 13;  break;
    case "/share/fonts/Courier-11.bdf":   return 14;  break;
    case "/share/fonts/Courier-9.bdf" :   return 15;  break;
    case "/share/fonts/Courier-10.bdf":   return 16;  break;
    case "/share/fonts/Courier-12.bdf":   return 17;  break;
    case "/share/fonts/Courier-8.bdf" :   return 18;  break;
    case "/share/fonts/Courier-13.bdf":   return 19;  break;
    case "/share/fonts/Courier-7.bdf":    return 20;  break;
    case "/bin/dummy"                :    return 21;  break;
    case "/bin/hello"                :    return 22;  break;
    default: printf("There is no matched file_name");assert(0);break;
  }*/
   return -1;
}
///////////////  fs_write  ////////////////
 int sys_write(int fd,  char *buf, size_t count,Context *c){
  if((fd!=1) && (fd!=2)){ 
    printf("fd is not valid!\n");
    c->GPRx = -1;
    assert(0);
  }
  else if(count == 0){
    c->GPRx = 0;
  }
  else{
    int ret_cnt=0;
    while(count!=0){
      //if(*buf != '\0'){
        putch(*buf);
      //}
      buf++; count--; ret_cnt++;
    }
  c->GPRx = ret_cnt;
  //retrun c->GPRx;
  }
  printf("***********STRACE**************\nmcause=4,syscall_name=SYS_WRITE,ret_value=%d\n",
  c->GPRx);    
  return c->GPRx;
}
/////////////// fs_read  /////////////////////
 int sys_read(int fd,void *buf,size_t count,Context *c){

      //printf("disk_offset=%d\n",file_table[fd].disk_offset);
      //printf("disk_size=%d\n",file_table[fd].size);
      ramdisk_read(buf,file_table[fd].disk_offset,count);//sizeof(ehdr)
      //printf("read finish\n");
      //printf("buf=%s\n",buf);
      //c->GPRx = strlen(buf);
      //printf("ret_read = %d\n",c->GPRx);
      return 0;
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
