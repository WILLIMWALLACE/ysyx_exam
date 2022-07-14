#include <isa.h>

word_t isa_raise_intr(word_t NO, vaddr_t epc) {
  /* TODO: Trigger an interrupt/exception with ``NO''.
   * Then return the address of the interrupt/exception vector.
   */
  //mepc = irq_pc;
  //mcause = NO;
  //return epc;  // &mtvec 
  cpu.mepc   = epc;
  cpu.mcause = NO;

  return cpu.mtvec;
}

void csr_write(word_t csr_addr, word_t data, int op){
  if(op==0){//write
    switch(csr_addr){
      case 0x300: cpu.mstatus = data;   break;
      case 0x305: cpu.mtvec   = data;   break;
      case 0x341: cpu.mepc    = data;   break;
      case 0x342: cpu.mcause  = data;  break;
      default:    printf("invalid csr address\n");  assert(0);
    }
  }
  else if(op==1){//set
    switch(csr_addr){
      case 0x300: cpu.mstatus = cpu.mstatus|data;   break;
      case 0x305: cpu.mtvec   = cpu.mtvec  |data;   break;
      case 0x341: cpu.mepc    = cpu.mepc   |data;   break;
      case 0x342: cpu.mcause  = cpu.mcause |data;  break;
      default:    printf("invalid csr address\n");  assert(0);
    }
  }
  else if(op==2){//clear
    switch(csr_addr){
      case 0x300: cpu.mstatus = cpu.mstatus&(~data);   break;
      case 0x305: cpu.mtvec   = cpu.mtvec  &(~data);   break;
      case 0x341: cpu.mepc    = cpu.mepc   &(~data);   break;
      case 0x342: cpu.mcause  = cpu.mcause &(~data);  break;
      default:    printf("invalid csr address\n");  assert(0);
    }
  }
  else{
    printf("invalid op\n");
    assert(0);
  }
}

word_t csr_read(word_t csr_addr){
  //word_t  data;
  switch(csr_addr){
    case 0x300: return cpu.mstatus; break;
    case 0x305: return cpu.mtvec;   break;
    case 0x341: return cpu.mepc;    break;
    case 0x342: return cpu.mcause;  break;
    default:  printf("invalid csr address\n");  assert(0);
  }
}

word_t isa_query_intr() {
  return INTR_EMPTY;
}
