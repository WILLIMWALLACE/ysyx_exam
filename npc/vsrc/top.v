module top(
input 			rst,
input 			clk,
input 			ps2_clk,
input 			ps2_data,
output [15:0]		ledr,
output reg[7:0] 		seg0,
output reg[7:0] 		seg1,
output reg[7:0]                 seg4,
output reg[7:0]                 seg5

  );
  
 reg  [7:0]	led_flag;
 wire [7:0] 	segs [8:0];
 reg		nextdata_n;
 wire [7:0]	data;
 reg  [7:0]	mc;
 wire		ready, overflow;
 reg  [2:0]	cnt;
 //test
 wire [3:0]	count;	
 wire 		sampling;

 assign ledr[15:0]  = {led_flag[7:0],sampling,count[3:0],overflow,ready,nextdata_n};

 //键盘控制器 
 always@(posedge clk)	begin
	if(rst)begin
	nextdata_n  <= 1'b0;
	mc	    <= 8'd0;
	cnt	    <= 3'd0;
	end
	else if(ready) begin
	mc          <= data;
	nextdata_n  <= 1'b0;
	cnt	    <= cnt+1'b1;
	end
	else begin
	mc          <= 8'd0;
	nextdata_n  <= 1'b1;
	cnt	    <= cnt;
	end
 end

ps2_keyboard my_keyboard(
    .clk		(clk),
    .resetn		(~rst),
    .ps2_clk		(ps2_clk),
    .ps2_data		(ps2_data),
    .nextdata_n		(nextdata_n),
    .data		(data),
    .ready		(ready),
    .overflow		(overflow),
    .sampling		(sampling),
    .count		(count)

    );

 //数码管
 assign segs[0] = 8'b11111101;
 assign segs[1] = 8'b01100000;
 assign segs[2] = 8'b11011010;
 assign segs[3] = 8'b11110010;
 assign segs[4] = 8'b01100110;
 assign segs[5] = 8'b10110110;
 assign segs[6] = 8'b10111110;
 assign segs[7] = 8'b11100000;
 assign segs[8] = 8'b11111111;
 always@(mc or cnt) begin
	case(mc)
	8'b0001_0101:begin  seg0 = ~segs[5];  seg1 = ~segs[1]; end//q ,15h
	8'b0010_0011:begin  seg0 = ~segs[3];  seg1 = ~segs[2]; end//d, 23h
/*	8'b0100_0000:begin  seg0 = ~segs[0];  seg1 = ~segs[4]; end
	8'b0010_0000:begin  seg0 = ~segs[0];  seg1 = ~segs[2]; end
	8'b0001_0000:begin  seg0 = ~segs[0];  seg1 = ~segs[1]; end
	8'b1000_1000:begin  seg0 = ~segs[8];  seg1 = ~segs[8]; end*/
	default:begin  seg0 = ~segs[8]; seg1 = ~segs[8];end
	endcase
	case(cnt)
	3'd0:begin   seg5 = ~segs[0];  seg4 = ~segs[0]; end
	3'd1:begin   seg5 = ~segs[0];  seg4 = ~segs[1]; end
	3'd2:begin   seg5 = ~segs[0];  seg4 = ~segs[2]; end
	3'd3:begin   seg5 = ~segs[0];  seg4 = ~segs[3]; end
	default:begin seg5 = ~segs[8];  seg4 = ~segs[8]; end
	endcase
 end

 always@(posedge clk)begin
	if(rst)begin
	led_flag <= 8'd0;
	end
	else begin
	led_flag <= 8'd0;
	end
 end

endmodule
