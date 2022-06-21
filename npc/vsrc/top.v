module top(
input 		rst,
input 		clk,
//input	[7:0]	sw,
//output  [15:0]	ledr,
output  [7:0] 	seg0,
/*output  [7:0] 	seg1,
output  [7:0] 	seg2,
output  [7:0] 	seg3,
output  [7:0] 	seg4,
output  [7:0] 	seg5,
output  [7:0] 	seg6,*/
output  [7:0] 	seg7

  );

wire	[2:0]	decimal;
assign	decimal = 3'd6;

  seg seg_inst(
	.clk		(clk),
	.rst		(rst),
	.decimal	(decimal),
	.o_seg0		(seg0),
/*	.o_seg1		(seg1),
	.o_seg2		(seg2),
	.o_seg3		(seg3),
	.o_seg4		(seg4),
	.o_seg5		(seg5),
	.o_seg6		(seg6),*/
	.o_seg7		(seg7) );


endmodule
