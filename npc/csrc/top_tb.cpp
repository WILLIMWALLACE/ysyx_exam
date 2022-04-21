   #include <nvboard.h>  
   #include <stdio.h>
   #include <stdlib.h>
   #include <assert.h>
   #include <Vtop.h>
   #include <verilated.h>
   #include <memory>
   #include <verilated_vcd_c.h>
   
   vluint64_t   main_time = 0; //仿真时间
   static TOP_NAME dut;

   double sc_time_stamp() { return  main_time  ; }
   void nvboard_bind_all_pins(Vtop* top);
  // Vtop *top = new Vtop("top");  
   
  /* void single_cycle() {
  	top->clk = 0; top->eval();
  	top->clk = 1; top->eval();
   }

   void reset(int n) {
  	top->rst = 1;
  	while (n -- > 0) single_cycle();
  	top->rst = 0;
   }
*/
  int main(int argc, char** argv, char** env) {
     //接入nvboard
     nvboard_bind_all_pins(&dut); 
     nvboard_init();
    // reset(10);
     //固定内容//////////////////////////
   //  Verilated::commandArgs(argc, argv);          // Remember args
   //  Verilated::traceEverOn(true);                // 导出波形必备  命令行里还需--trace
   //  VerilatedVcdC*  tfp = new  VerilatedVcdC;    //导出波形需用，且可根据tfp设置trace追踪的层次
//     Vtop *top = new Vtop("top"); 		  //指向Vtop类的 top地址的指针，new分配内存空间并且调用Vtop的构造函数，新建了一个对象（类）top
     
    // top->trace(tfp, 99);  // Trace 99 levels of hierarchy (or see below)
     // tfp->dumpvars(1, "t");  // trace 1 level under "t"
   //  tfp->open("test.vcd");
  /////////////////////////////产生波形固定内容

    // while (sc_time_stamp() < 20 && !Verilated::gotFinish()) {                                                                                                                                            
  while (1) {
  	  nvboard_update();
	 // single_cycle();
        //  int a = rand() & 1;
         // int b = rand() & 1;
         // top->a = a;
         // top->b = b;                                             //top指针操作，赋值a，b
         // top->eval();    //执行一次erilog代码 更新值
         int a = dut->a;
	 int b = dut->b;
	 int f = dut->f;
//	  tfp->dump(main_time);
    //      main_time++;                                            //更新仿真时间
          
          printf("sw0 = %d, sw1 = %d, ld0 = %d\n", a, b, f);       //看看而已
        //  assert(top->f == a ^ b);                                //断言检测 
          
  
      }
   //  	  nvboard_quit();
  //        top->final();
    //      tfp->close();
      //    delete top;
          
//          return 0;
  }   
  

