  // #include <nvboard.h>  
   #include <stdio.h>
   #include <stdlib.h>
   #include <assert.h>
   #include <Vysyx_22040365_top.h>
   #include <verilated.h>
   #include <memory>
   #include <verilated_vcd_c.h>
   ////////////dpi///////////
   #include "svdpi.h"
   #include "Vysyx_22040365_top__Dpi.h"
  ///////////from nemu/////////
   #include <stdint.h>        
   #include <stdbool.h>
   #include <string.h>
   
  #define PC_BASE 0x80000000

   static struct itcm {
  	u_int32_t   pc;
  	u_int32_t inst;
	} ITCM[] ={
	{PC_BASE     , 0xffc10113},//sp=sp-4
	{PC_BASE+0x4 , 0xff010113},//sp=sp-16
  {PC_BASE+0x8 , 0xfb010113},//sp=sp-80
  {PC_BASE+0xc , 0x00100073},//ebreak
	};
  ///////////////////DPI-C//////////
   int64_t flag;
   int64_t quit(int64_t a){ return flag = a; }
  //////////////////DPI-C//////////
   vluint64_t   main_time = 0; //仿真时间
   //int  reset(n) { if(n!=0) {n--;} else {return 0;}}
   double sc_time_stamp() { return  main_time  ; }     
   int mem_read(int addr);    //memory-element

  int main(int argc, char** argv, char** env) {
     ///////////////////////////固定内容   verilator init/////////////////////////////
     Verilated::commandArgs(argc, argv);          // Remember args
     Verilated::traceEverOn(true);                // 导出波形必备  命令行里还需--trace
     VerilatedVcdC*  tfp = new  VerilatedVcdC;    //导出波形需用，且可根据tfp设置trace追踪的层次
     Vysyx_22040365_top *ysyx_22040365_top = new Vysyx_22040365_top("ysyx_22040365_top"); 		  //指向Vtop类的 top地址的指针，new分配内存空间并且调用Vtop的构造函数，新建了一个对象（类）top
     ysyx_22040365_top->trace(tfp, 99);  			  // Trace 99 levels of hierarchy (or see below)
   //  tfp->dumpvars(1, "t");  			  // trace 1 level under "t"
     tfp->open("npc_onecycle.vcd"); 
     ///////////////////////////固定内容 verilator init////////////////////////////////
     int   addr=0;
     int   clk=0;
     //int   quit=0;       //DPI-C
     //int   rst=0;
     while (sc_time_stamp() <= 20 && !Verilated::gotFinish() && !quit()){  
         ////////////////////////步进执行并产生波形；更新电路状态////////////////////////
         clk = ~clk;
        // if(main_time<3) {rst=0;} else{rst=1;}
         ysyx_22040365_top->clk  = clk;
        // top->rst  = rst;
         ysyx_22040365_top->inst = mem_read(addr); // 取指令，从pmem_read函数中读出 
         ysyx_22040365_top->eval();    //执行一次erilog代码 更新值
	       tfp->dump(main_time);
         main_time++;
         //quit = quit(int a);        //DPI-C
         if(main_time==6||main_time==12||main_time==18)
         {
          addr ++;      
          printf("out=%lx\n",ysyx_22040365_top->out);
         }
        printf("pc=0x%x,inst=0x%x\n",ITCM[addr].pc,ITCM[addr].inst);
      } 
         //退出nvboard 和 verilator 若不用 第一个while=1,则不会走到这
         printf("\n");
      ysyx_22040365_top->final();
      tfp->close();
      delete ysyx_22040365_top;
      return 0;
  }   
  
int  mem_read(int addr) {
  switch(ITCM[addr].pc){
    case PC_BASE     :  return ITCM[addr].inst; 
    case PC_BASE+0X4 :  return ITCM[addr].inst;
    case PC_BASE+0X8 :  return ITCM[addr].inst;
    case PC_BASE+0Xc :  return ITCM[addr].inst;
    default         :  printf("wu pi pei pc\n");  assert(0);
  }
}

