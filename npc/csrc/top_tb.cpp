   #include <nvboard.h>  
   #include <stdio.h>
   #include <stdlib.h>
   #include <assert.h>
   #include <Vtop.h>
   #include <verilated.h>
   #include <memory>
   #include <verilated_vcd_c.h>
   
   vluint64_t   main_time = 0; //仿真时间
   double sc_time_stamp() { return  main_time  ; }     

   static TOP_NAME dut;
   void nvboard_bind_all_pins(Vtop* top);
  // Vtop *top = new Vtop("top");  
   
  static void single_cycle() {
  	dut.clk = 0; dut.eval();
  	dut.clk = 1; dut.eval();
   }

  static void reset(int n) {
  	dut.rst = 1;
  	while (n -- > 0) single_cycle();
  	dut.rst = 0;
   }

  int main(int argc, char** argv, char** env) {
     //接入nvboard
     nvboard_bind_all_pins(&dut); 
     nvboard_init();
     reset(10);

     ///////////////////////////固定内容   verilator init/////////////////////////////
     Verilated::commandArgs(argc, argv);          // Remember args
     Verilated::traceEverOn(true);                // 导出波形必备  命令行里还需--trace
     VerilatedVcdC*  tfp = new  VerilatedVcdC;    //导出波形需用，且可根据tfp设置trace追踪的层次
     Vtop *top = new Vtop("top"); 		  //指向Vtop类的 top地址的指针，new分配内存空间并且调用Vtop的构造函数，新建了一个对象（类）top
     top->trace(tfp, 99);  			  // Trace 99 levels of hierarchy (or see below)
    // tfp->dumpvars(1, "t");  			  // trace 1 level under "t"
     tfp->open("test.vcd"); 
     ///////////////////////////固定内容 verilator init////////////////////////////////
  
    // while (sc_time_stamp() < 20 && !Verilated::gotFinish())                                                                                                                                        
    while (1) {
  	  nvboard_update();
	  single_cycle();

         /////////////////////////仿真赋值用///////////////////////////////////
         // int a = rand() & 1;
         // int b = rand() & 1;
         //  top->a = a;
         //  top->b = b;      //top指针操作，赋值a，b
        
        ////////////////////////步进执行并产生波形；更新电路状态/////////////////////////////
        top->eval();    //执行一次erilog代码 更新值
	// tfp->dump(main_time);
        // main_time++;                                            //更新仿真时间
        ////////////////////////步进执行并产生波形；更新电路状态////////////////////////////

	////////////////////检测查看用//////////////////////////////////////
	int ps2_data = dut.ps2_data;
	int seg0     = dut.seg0;
	int seg1     = dut.seg1;
	 printf("ps2_data = %d, seg0=%d,seg1=%d\n", dut.ps2_data,dut.seg0,dut.seg1);       //看看而已
        //  assert(top->f == a ^ b);                                //断言检测 
       }

       //退出nvboard 和 verilator 若不用 第一个while限制次数，则不会走到这
     	  nvboard_quit();
          top->final();
          tfp->close();
          delete top;
          return 0;
  }   
  

