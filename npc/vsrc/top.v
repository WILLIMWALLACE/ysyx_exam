module top(
input 			rst,
input 			clk,
input  [9:0]		sw,//en,clk,seed_datas
output [15:0]		ledr,//flag,zero_flag,indentify
output [7:0] 		seg0,//l 4bit
output [7:0] 		seg1 //h 4bit
  );
  
 reg		led_flag;
 wire [4:0]	led_zero;
 reg  [7:0]	lfsr;
 reg            h_xor;
 wire [7:0] 	segs [8:0];
 
 assign segs[0] = 8'b11111101;
 assign segs[1] = 8'b01100000;
 assign segs[2] = 8'b11011010;
 assign segs[3] = 8'b11110010;
 assign segs[4] = 8'b01100110;
 assign segs[5] = 8'b10110110;
 assign segs[6] = 8'b10111110;
 assign segs[7] = 8'b11100000;
 assign segs[8] = 8'b11111111;
 assign	ledr[15:0] = {led_flag,led_zero[4:0],sw[9:0]};
 
 always@(posedge sw[8])	begin
	if(sw[9])begin
	lfsr  <= sw[7:0];
	h_xor <= sw[0] ^ sw[2] ^ sw[3] ^ sw[4]; 
	end
	else begin
	lfsr  <= {h_xor,lfsr[7:1]};
	h_xor <= lfsr[0] ^ lfsr[2] ^ lfsr[3] ^ lfsr[4];
	end
 end

 always@(lfsr) begin
	case(lfsr)
	8'b0000_0001:begin  seg0 = ~segs[1];  seg1 = ~segs[0]; end
	8'b1000_0000:begin  seg0 = ~segs[0];  seg1 = ~segs[8]; end
	8'b0100_0000:begin  seg0 = ~segs[0];  seg1 = ~segs[4]; end
	8'b0010_0000:begin  seg0 = ~segs[0];  seg1 = ~segs[2]; end
	8'b0001_0000:begin  seg0 = ~segs[0];  seg1 = ~segs[1]; end
	8'b1000_1000:begin  seg0 = ~segs[8];  seg1 = ~segs[8]; end
	default:begin  seg0 = ~segs[0]; seg1 = ~segs[0];end
	endcase
 end

 always@(posedge clk)begin
	if(rst)begin
	led_flag <= 1'b0;
	end
	else begin
	led_flag <= 1'b0;
	end
 end

endmodule
