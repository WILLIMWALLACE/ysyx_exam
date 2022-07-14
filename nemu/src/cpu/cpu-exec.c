#include <cpu/cpu.h>
#include <cpu/decode.h>
#include <cpu/difftest.h>
#include <locale.h>
//#include "sdb.h"
/* The assembly code of instructions executed is only output to the screen
 * when the number of instructions executed is less than this value.
 * This is useful when you use the `si' command.
 * You can modify this value as you want.
 */
#define MAX_INST_TO_PRINT 10
/////////////////////////////////////////
/***********mo fang menuconfig***********/
//#define CONFIG_WATCHPOINT 1
int scan_wp();
void sdb_mainloop();
////////////shou dong kai guan//////////////
///////////   etrace    ////////////////////////////
//enum {
 //   EVENT_NULL = 0,
 //   EVENT_YIELD, EVENT_SYSCALL, EVENT_PAGEFAULT, EVENT_ERROR,
 //   EVENT_IRQ_TIMER, EVENT_IRQ_IODEV,
//};
#define etrace
////////////////////////////////////////////
////////////////////////////////////////////




CPU_state cpu = {};
uint64_t g_nr_guest_inst = 0;
static uint64_t g_timer = 0; // unit: us
static bool g_print_step = false;

void device_update();

static void trace_and_difftest(Decode *_this, vaddr_t dnpc) {
#ifdef CONFIG_ITRACE_COND
  if (ITRACE_COND) { log_write("%s\n", _this->logbuf); }
#endif
  if (g_print_step) { IFDEF(CONFIG_ITRACE, puts(_this->logbuf)); }
  IFDEF(CONFIG_DIFFTEST, difftest_step(_this->pc, dnpc));
#ifdef CONFIG_WATCHPOINT  
  //for(int i =0;i<32;i++){
   //printf("jin ru cpu_exe\n");
   //printf("head[i].value=%d",head[i].value);
  //}
  int flag = scan_wp();
  if(flag==1){
    printf("chu fa jian shi dian\n");
    nemu_state.state=NEMU_STOP;
    sdb_mainloop();
  }
#endif
}

/**************for i trace*******************/
/*typedef struct{
    char *buffer;
    int   length;
    int   w_ptr;
    int   current_ptr;
//int   r_ptr;
}c_fifo*/
u_int64_t fifo_pc[40]; // 10*4,mei.ge.wei.zhi.cun.chu.8bit,mei.ge.shu.ju.32bit
u_int64_t fifo_inst[40];
int  itrace_index; //0-9,cun.shi.ge

void fifo_itrace_tran(){
    for(int i=0;i<10;i++){
      if(i == (itrace_index-1))
      {
      printf("  -->pc= 0x%08lx                   ",fifo_pc[i*4]);
      printf("      inst= 0x%08lx\n",fifo_inst[i*4]);
      }
      else{
      printf("     pc= 0x%08lx                   ",fifo_pc[i*4]);
      printf("      inst= 0x%08lx\n",fifo_inst[i*4]);
      }
    }
}
static void fifo_wr(Decode *s){
    if(itrace_index >= 10)
      {itrace_index = 0; } 
    fifo_pc[itrace_index*4]   = cpu.pc;
    fifo_inst[itrace_index*4] = s->isa.inst.val;
    itrace_index++;
    //printf("dang qian pc = 0x%08lx\n",s->pc);
}
/**************for i trace*******************/
static void exec_once(Decode *s, vaddr_t pc) {
  s->pc = pc;
  s->snpc = pc;
  isa_exec_once(s);
  
  fifo_wr(s);  //cun.chu.pc & inst.

  cpu.pc = s->dnpc;

  #ifdef etrace

  switch(cpu.mcause){
   case 0xffffffffffffffff: 
    printf("EVENT_YIELD\n");
    printf("mepc=%lx,mcaus=%lx,mtvec=%lx\n",cpu.mepc,cpu.mcause,cpu.mtvec); 
    break;

   default: printf("EVENT_NULL\n");
  }
  #endif


#ifdef CONFIG_ITRACE
  char *p = s->logbuf;
  p += snprintf(p, sizeof(s->logbuf), FMT_WORD ":", s->pc);
  int ilen = s->snpc - s->pc;
  int i;
  uint8_t *inst = (uint8_t *)&s->isa.inst.val;
  for (i = 0; i < ilen; i ++) {
    p += snprintf(p, 4, " %02x", inst[i]);
  }
  int ilen_max = MUXDEF(CONFIG_ISA_x86, 8, 4);
  int space_len = ilen_max - ilen;
  if (space_len < 0) space_len = 0;
  space_len = space_len * 3 + 1;
  memset(p, ' ', space_len);
  p += space_len;

  void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte);
  disassemble(p, s->logbuf + sizeof(s->logbuf) - p,
      MUXDEF(CONFIG_ISA_x86, s->snpc, s->pc), (uint8_t *)&s->isa.inst.val, ilen);
#endif
}

static void execute(uint64_t n) {
  Decode s;
  for (;n > 0; n --) {
    exec_once(&s, cpu.pc);
    g_nr_guest_inst ++;
    trace_and_difftest(&s, cpu.pc);
    if (nemu_state.state != NEMU_RUNNING) break;
    IFDEF(CONFIG_DEVICE, device_update());
  }
}

static void statistic() {
  IFNDEF(CONFIG_TARGET_AM, setlocale(LC_NUMERIC, ""));
#define NUMBERIC_FMT MUXDEF(CONFIG_TARGET_AM, "%ld", "%'ld")
  Log("host time spent = " NUMBERIC_FMT " us", g_timer);
  Log("total guest instructions = " NUMBERIC_FMT, g_nr_guest_inst);
  if (g_timer > 0) Log("simulation frequency = " NUMBERIC_FMT " inst/s", g_nr_guest_inst * 1000000 / g_timer);
  else Log("Finish running in less than 1 us and can not calculate the simulation frequency");
}

void assert_fail_msg() {
  isa_reg_display();
  statistic();
}

/* Simulate how the CPU works. */
void cpu_exec(uint64_t n) {
  g_print_step = (n < MAX_INST_TO_PRINT);
  switch (nemu_state.state) {
    case NEMU_END: case NEMU_ABORT:
      printf("Program execution has ended. To restart the program, exit NEMU and run again.\n");
      return;
    default: nemu_state.state = NEMU_RUNNING;
  }

  uint64_t timer_start = get_time();

  execute(n);

  uint64_t timer_end = get_time();
  g_timer += timer_end - timer_start;

  switch (nemu_state.state) {
    case NEMU_RUNNING: nemu_state.state = NEMU_STOP; break;

    case NEMU_END: case NEMU_ABORT:
      Log("nemu: %s at pc = " FMT_WORD,
          (nemu_state.state == NEMU_ABORT ? ASNI_FMT("ABORT", ASNI_FG_RED) :
           (nemu_state.halt_ret == 0 ? ASNI_FMT("HIT GOOD TRAP", ASNI_FG_GREEN) :
            ASNI_FMT("HIT BAD TRAP", ASNI_FG_RED))),
          nemu_state.halt_pc);
      // fall through
    case NEMU_QUIT: statistic();
  }
}
