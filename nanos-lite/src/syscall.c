#include <common.h>
#include "syscall.h"
/*enum {
  SYS_exit,
  SYS_yield,
  SYS_open,
  SYS_read,
  SYS_write,
  SYS_kill,
  SYS_getpid,
  SYS_close,
  SYS_lseek,
  SYS_brk,
  SYS_fstat,
  SYS_time,
  SYS_signal,
  SYS_execve,
  SYS_fork,
  SYS_link,
  SYS_unlink,
  SYS_wait,
  SYS_times,
  SYS_gettimeofday
};*/


int sys_open(const char *path);
int sys_write(int fd,  char *buf, size_t count,Context *c);
int sys_read(int fd,void *buf,size_t count,Context *c);
int sys_close();

////////////////  strace is immplemented here////////////////
static int sys_yield(Context *c){
  yield();
  c->GPRx = 0;
  printf("***********STRACE**************\nmcause=1,syscall_name=SYS_YIELD,ret_value=0\n");
  return 0;
}

static int sys_exit(Context *c,uint64_t a){
  printf("***********STRACE**************\nmcause=0,syscall_name=SYS_EXIT,ret_value=0\n");
  halt(a);
  c->GPRx = 0;
  return 0;
} 

void do_syscall(Context *c) {
  uintptr_t a[4];
  a[0] = c->GPR1;//a7,mcause
  a[1] = c->GPR2;//a0,void _exit(int status)->status****a0=fd***a0=path
  a[2] = c->GPR3;//****a1=buf_addr****
  a[3] = c->GPR4;//****a2=count****
  //char *temp = NULL;
  //temp = (char*)a[2];
  switch (a[0]) {
    case SYS_exit :sys_exit(c,a[1]);   break;
    case SYS_yield:sys_yield(c);       break;
    case SYS_write:sys_write(a[1],(char*)a[2],a[3],c); break;
    case SYS_brk  :c->GPRx = 0;        break;
    case SYS_open :c->GPRx = sys_open((char*) a[1]);   break;
    case SYS_read :sys_read(a[1],(void *)a[2],a[3],c); break;
    case SYS_close:sys_close();        break;

    default: panic("Unhandled syscall ID = %d", a[0]);
  }
}

