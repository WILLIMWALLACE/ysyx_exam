#include <utils.h>
#include <cpu/cpu.h>
NEMUState nemu_state = { .state = NEMU_STOP };

int is_exit_status_bad() {
  int flag;
  int good = (nemu_state.state == NEMU_END && nemu_state.halt_ret == 0) ||
    (nemu_state.state == NEMU_QUIT);
  if(!good){
    printf("pc= 0x%08x                   ",fifo_pc[itrace_index]);
    printf("      inst= 0x%08x\n",fifo_inst[itrace_index]);
    flag = good;}
  if(good) {flag = !good;}
 
  return flag;
}
