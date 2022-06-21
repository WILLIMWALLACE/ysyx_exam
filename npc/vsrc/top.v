module top(
input 		rst,
input 		clk,
input	[7:0]	sw,
output  [15:0]	ledr,
output  [7:0] 	seg0,
/*output  [7:0] 	seg1,
output  [7:0] 	seg2,
output  [7:0] 	seg3,
output  [7:0] 	seg4,
output  [7:0] 	seg5,
output  [7:0] 	seg6,*/
output  [7:0] 	seg7

  );

reg	[2:0]	decimal;
wire		flag;
//assign	decimal = 3'd6; //test

  always@(sw) begin
	casez(sw) 
	8'b1???????: decimal = 3'd7;
	8'b01??????: decimal = 3'd6;
	8'b001?????: decimal = 3'd5;
	8'b0001????: decimal = 3'd4;
	8'b00001???: decimal = 3'd3;
	8'b000001??: decimal = 3'd2;
	8'b0000001?: decimal = 3'd1;
	8'b00000001: decimal = 3'd0;
	default:     decimal = 3'd0;
	endcase
  end
  assign flag = (sw == 8'd0) ? 1'b0 : 1'b1;
  assign ledr[15:0] = {{12{1'b0}},flag,decimal[2:0]};

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
