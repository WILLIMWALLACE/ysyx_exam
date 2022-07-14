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
  printf("mepc=%lx,mcaus=%lx,mtvec=%lx\n",
  cpu.mepc,cpu.mcause,cpu.mtvec);
  return cpu.mtvec;
}


void csr_write(word_t csr_addr, word_t data){
  switch(csr_addr){
    //case 0x341: cpu.mepc  = data; break;
    case 0x305: cpu.mtvec = data; break;
    default:    printf("invalid csr address\n");  assert(0);
  }
}

word_t csr_read(word_t csr_addr){
  //word_t  data;
  switch(csr_addr){
    //case 0x341: return cpu.mepc; break;
    case 0x305: return cpu.mtvec; break;
    default:  printf("invalid csr address\n");  assert(0);
  }
}

word_t isa_query_intr() {
  return INTR_EMPTY;
}
