#ifndef __CPU_CPU_H__
#define __CPU_CPU_H__

#include <common.h>

void cpu_exec(uint64_t n);

void set_nemu_state(int state, vaddr_t pc, int halt_ret);
void invalid_inst(vaddr_t thispc);

/*typedef struct{
    char *buffer;
    int   length;
    int   w_ptr;
    int   current_ptr;
//int   r_ptr;
}c_fifo*/

char fifo_pc[40]; // 10*4,mei.ge.wei.zhi.cun.chu.8bit,mei.ge.shu.ju.32bit
char fifo_inst[40];
int  itrace_index; //0-9,cun.shi.ge


#define NEMUTRAP(thispc, code) set_nemu_state(NEMU_END, thispc, code)
#define INV(thispc) invalid_inst(thispc)

#endif
