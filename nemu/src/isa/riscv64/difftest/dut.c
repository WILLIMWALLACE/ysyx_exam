#include <isa.h>
#include <cpu/difftest.h>
#include "../local-include/reg.h"
//ref_r tong yong ji cun qi //pc du chu ji cun qi
bool isa_difftest_checkregs(CPU_state *ref_r, vaddr_t pc) {
  int i;
  bool flag = true;
  //printf("ref_r->pc=%lx,cpu.pc=%lx\n",ref_r->pc,cpu.pc);
  if(ref_r->pc==cpu.pc){
   // printf("pc is true\n");
    for(i=0;i<32;i++){
      if(ref_r->gpr[i] != cpu.gpr[i]){
        flag = false;  
        printf("*************ref_r.gpr[%d]=0x%016lx,cpu.gpr[%d]=0x%016lx****************\n",
        i,ref_r->gpr[i],i,cpu.gpr[i]);
        printf("*************ref_r.pc=0x%016lx,cpu.pc=0x%016lx****************\n",
        ref_r->pc,cpu.pc);
        break;
      }
    }
  }
  else { 
    flag  =  false;
    printf("*************ref_r.pc=0x%016lx,cpu.pc=0x%016lx****************\n",
        ref_r->pc,cpu.pc);
  }
  //printf("flag=%d\n",flag);
  return flag;
}

void isa_difftest_attach() {
}
