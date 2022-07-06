  // #include <nvboard.h>  
   #include <stdio.h>
   #include <stdlib.h>
   #include <assert.h>
   #include <Vtop.h>
   #include <verilated.h>
   #include <memory>
   #include <verilated_vcd_c.h>
   //////////////////////////////
   #include <stdint.h>        
   #include <stdbool.h>
   #include <string.h>
   
  #define PC_BASE 0x80000000

   static struct itcm {
  	int pc;
  	int inst;
	} ITCM[] ={
	{PC_BASE     , 0xffc10113},//sp=sp-4
	{PC_BASE+0x4 , 0xff010113},//sp=sp-16
  {PC_BASE+0x8 , 0Xfb010113},//sp=sp-80
	};

   vluint64_t   main_time = 0; //仿真时间
   //int  reset(n) { if(n!=0) {n--;} else {return 0;}}
   double sc_time_stamp() { return  main_time  ; }     
   void mem_read(int addr);    //memory-element

  int main(int argc, char** argv, char** env) {
     ///////////////////////////固定内容   verilator init/////////////////////////////
     Verilated::commandArgs(argc, argv);          // Remember args
     Verilated::traceEverOn(true);                // 导出波形必备  命令行里还需--trace
     VerilatedVcdC*  tfp = new  VerilatedVcdC;    //导出波形需用，且可根据tfp设置trace追踪的层次
     Vtop *ysyx_22040365_top = new Vtop("ysyx_22040365_top"); 		  //指向Vtop类的 top地址的指针，new分配内存空间并且调用Vtop的构造函数，新建了一个对象（类）top
     top->trace(tfp, 99);  			  // Trace 99 levels of hierarchy (or see below)
   //  tfp->dumpvars(1, "t");  			  // trace 1 level under "t"
     tfp->open("npc_onecycle.vcd"); 
     ///////////////////////////固定内容 verilator init////////////////////////////////
     int   addr=0;
     int   clk=0;
     //int   rst=0;
     while (sc_time_stamp() <= 20 && !Verilated::gotFinish()){  
         ////////////////////////步进执行并产生波形；更新电路状态////////////////////////
         clk = ~clk;
        // if(main_time<3) {rst=0;} else{rst=1;}
         top->clk  = clk;
        // top->rst  = rst;
         top->inst = mem_read(addr); // 取指令，从pmem_read函数中读出 
         top->eval();    //执行一次erilog代码 更新值
	       tfp->dump(main_time);
         main_time++;
         if(main_time==6||main_time==12||main_time==18)
         {
          addr ++;      //clk
         }
         printf("pc=0x016%x,inst=0x016%x\n",ITCM[clki].pc,ITCM[clki].inst);
      } 
         //退出nvboard 和 verilator 若不用 第一个while=1,则不会走到这
      top->final();
      tfp->close();
      delete top;
      return 0;
  }   
  
void  mem_read(int addr) {
  switch(ITCM[addr].pc){
    case PC_BASE    :  return ITCM[addr].inst; 
    case PC_BASE+0X4:  return ITCM[addr].inst;
    case PC_BASE+0X8:  return ITCM[addr].inst;
    default         :  printf("wu pi pei pc\n");  assert(0);
  }
}

