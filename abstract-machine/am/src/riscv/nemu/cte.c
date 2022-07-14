#include <am.h>
#include <riscv/riscv.h>
#include <klib.h>

static Context* (*user_handler)(Event, Context*) = NULL;

Context* __am_irq_handle(Context *c) {
  //long a=0xffffffffffffffff;
  //printf("a=%d\n",a);
 printf("mcause=%x,mstatus=%x,mepc=%x\n",c->mcause,c->mstatus,c->mepc);
  if (user_handler) {
    Event ev = {0};
    switch (c->mcause) {
      default: ev.event = EVENT_ERROR; break;
    }
    c = user_handler(ev, c);
    assert(c != NULL);
  }

  return c;
}

extern void __am_asm_trap(void);
//外层指针函数，内层函数指针， 即函数指针handler 返回值是 由 Context定义的指针
//发生事件，将 事件（原因等信息）、上下文信息 传回 操作系统 ，以供处理
bool cte_init(Context*(*handler)(Event, Context*)) {
  // initialize exception entry
  asm volatile("csrw mtvec, %0" : : "r"(__am_asm_trap));

  // register event handler
  user_handler = handler;//调用*handler函数，user_handler也是函数指针。 函数的首地址 赋值

  return true;
}

Context *kcontext(Area kstack, void (*entry)(void *), void *arg) {
  return NULL;
}

void yield() {
  //printf("jin ru yield\n");
  asm volatile("li a7, -1; ecall");
}

bool ienabled() {
  return false;
}

void iset(bool enable) {
}
