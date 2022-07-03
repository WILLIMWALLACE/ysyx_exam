#include <utils.h>

NEMUState nemu_state = { .state = NEMU_END };

int is_exit_status_bad() {
  //int flag;
  int good = (nemu_state.state == NEMU_END && nemu_state.halt_ret == 0) ||
    (nemu_state.state == NEMU_QUIT);
 // if(!good){flag = !good;}
 // if(good) {flag = good;}
 // printf("flag = %d\n",flag);
  return good;
}
