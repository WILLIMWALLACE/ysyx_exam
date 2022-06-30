#include <isa.h>
#include "local-include/reg.h"
//#include <string.h>

const char *regs[] = {
  "$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
  "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5",
  "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7",
  "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"
};

void isa_reg_display() {
  //16wei shu chu,bu zu bu 0;long leixing 16 jinzhi
    for(int i=0;i<4;i++)
    printf("   %s   = 0x%016lx",regs[i],cpu.gpr[i]);
    printf("\n");
    for(int i=4;i<8;i++)
    printf("   %s   = 0x%016lx",regs[i],cpu.gpr[i]);
    printf("\n");
    for(int i=8;i<12;i++)
    printf("   %s   = 0x%016lx",regs[i],cpu.gpr[i]);
    printf("\n");
    for(int i=12;i<16;i++)
    printf("   %s   = 0x%016lx",regs[i],cpu.gpr[i]);
    printf("\n");
    for(int i=16;i<20;i++)
    printf("   %s   = 0x%016lx",regs[i],cpu.gpr[i]);
    printf("\n");
    for(int i=20;i<24;i++)
    printf("   %s   = 0x%016lx",regs[i],cpu.gpr[i]);
    printf("\n");
    for(int i=24;i<28;i++)
    printf("   %s   = 0x%016lx",regs[i],cpu.gpr[i]);
    printf("\n");
    for(int i=28;i<32;i++)
    printf("   %s   = 0x%016lx",regs[i],cpu.gpr[i]);
    printf("\n");
    printf("   pc   = %lx",cpu.pc);
}

word_t isa_reg_str2val(const char *s, bool *success) {
    int i=0;
    ++s;
    printf("%s",s);
    for(i=0;i<32;i++){
        printf("reg[%d]=%s",i,regs[i]);
      if(strcmp(s,regs[i])==0){
        printf("reg[%d]=%s",i,regs[i]);
      *success = true;
      return cpu.gpr[i];
      }
     else{
      printf("jie xi shi bai\n");
      return 0;
      }
    }  
    return 0;
}