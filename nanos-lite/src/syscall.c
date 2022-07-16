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

static int sys_yield(){
  yield();
  return 0;
}

//static int sys_exit(){
 // halt();

//} 


void do_syscall(Context *c) {
  uintptr_t a[4];
  a[0] = c->GPR1;//a7,mcause

  switch (a[0]) {
    //case SYS_exit :sys_exit();
    case SYS_yield:sys_yield();

    default: panic("Unhandled syscall ID = %d", a[0]);
  }
}


