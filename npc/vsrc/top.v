module top(
input 		rst,
input 		clk,
input	[12:0]	sw,
output  [13:0]	ledr
  );
  
 wire [7:0]	led;
 always@(posedge clk)begin
	if(rst)begin
	ledr <= 14'd0;
	end
	else begin
	ledr <= {1'b0,sw[12:8],led[7:0]};
	end
 end

  Barrel_shifter u_Barrel_shifter(
	.shift_in	(sw[7:0]),
	.shift_num	(sw[10:8]),
	.shift_ctl	(sw[12:11]),
	.shift_out	(led[7:0]));
endmodule


