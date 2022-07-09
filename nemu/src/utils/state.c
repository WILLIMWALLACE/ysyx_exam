#include <utils.h>
#include <cpu/cpu.h>
NEMUState nemu_state = { .state = NEMU_STOP };
void fifo_itrace_tran();
int is_exit_status_bad() {
  //int flag;
  int good = (nemu_state.state == NEMU_END && nemu_state.halt_ret == 0) ||
    (nemu_state.state == NEMU_QUIT);
  
  if(!good)
  { fifo_itrace_tran(); }
    //flag = good;}
  //if(good) {flag = !good;}
 
  return !good;
}
