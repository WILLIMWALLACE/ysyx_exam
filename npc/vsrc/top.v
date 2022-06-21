module top(
//  input  [7:0] x,
// input  [1:0] y,
//  output [1:0] f
input	[7:0]	sw,
output  [15:0]	ledr
  );

wire  [7:0]	x;//四个两位输入信号
wire  [1:0]	y;//使能key信号
wire  [1:0]     f;//输出信号

  MuxKeyWithDefault #(4, 2, 2) 
  inst  (f, 
  	y, 
  	2'b11, 
  	{ 2'b00, x[1:0],
    	  2'b01, x[3:2],
    	  2'b10, x[5:4],
    	  2'b11, x[7:6]
  	});
  assign  ledr[15:0] = {{14{1'b1}},f[1:0]};
  assign  y[1:0]     = sw[1:0];
  assign  x[7:0]     = {1'b0,1'b1,sw[7:2]};

endmodule
