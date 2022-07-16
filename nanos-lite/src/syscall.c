#include <common.h>
#include "syscall.h"

enum {
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
};

static int sys_yield(Context *c){
  yield();
  c->GPRx = 0;
  printf("***********STRACE**************\nmcause=1,syscall_name=SYS_YIELD,ret_value=0\n");
  return 0;
}

static int sys_exit(Context *c,uint64_t a){
  halt(a);
  c->GPRx = 0;
  printf("***********STRACE**************\nmcause=0,syscall_name=SYS_EXIT,ret_value=0\n");
  return 0;
} 

////////////////  strace is immplemented here////////////////
void do_syscall(Context *c) {
  uintptr_t a[4];
  a[0] = c->GPR1;//a7,mcause
  a[1] = c->GPR2;//a0,void _exit(int status)->status


  switch (a[0]) {
    case SYS_exit :sys_exit(c,a[1]);   break;
    case SYS_yield:sys_yield(c);      break;

    default: panic("Unhandled syscall ID = %d", a[0]);
  }
}


