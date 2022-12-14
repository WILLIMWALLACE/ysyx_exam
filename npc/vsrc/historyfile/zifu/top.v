module top(
input 			rst,
input 			clk,
input 			ps2_clk,
input 			ps2_data,
output [15:0]		ledr,
output 			VGA_CLK,
output 			VGA_HSYNC,
output 			VGA_VSYNC,
output 			VGA_BLANK_N,
output [7:0] 		VGA_R,
output [7:0] 		VGA_G,
output [7:0] 		VGA_B,

output reg[7:0]                 seg0,
output reg[7:0]                 seg1,
output reg[7:0]                 seg4,
output reg[7:0]                 seg5

  );
 // ps2键盘输入控制所需信号  
 reg  [6:0]	led_flag;
 reg		nextdata_n;
 wire [7:0]	data;
 reg  [7:0]	mc;
 wire		ready, overflow;
 reg  [2:0]	cnt;
 //test
 wire [3:0]	count;	
 wire 		sampling;
 reg  [2:0]	c_state;
 reg  [2:0]     n_state;
 reg		flag;//切换 一个按键按下来并松开的三种情况
 reg  [8:0]	pix[15:0];
 reg  [8:0]	pix_line;
// reg  [15:0]	cnt_clk;
 reg  [3:0]	y;
//vga控制所需信号
  wire [9:0] h_addr;
  wire [9:0] v_addr;
  reg [23:0] vga_data;
  assign VGA_CLK = clk;
 //clock
 /* always@(posedge clk)begin
	if(rst)begin
	cnt_clk <= 0;
	VGA_CLK <= 0;
	end
	else if(cnt_clk==16'd3000)begin
	cnt_clk<=0;
	VGA_CLK <= ~VGA_CLK;
	end
	else begin
	cnt_clk <= cnt_clk+1;
	end
  end
*/
  vga vga_ctrl(
    .pclk(clk),
    .reset(rst),
    .vga_data(vga_data),
    .h_addr(h_addr),
    .v_addr(v_addr),
    .hsync(VGA_HSYNC),
    .vsync(VGA_VSYNC),
    .valid(VGA_BLANK_N),
    .vga_r(VGA_R),
    .vga_g(VGA_G),
    .vga_b(VGA_B)
  );
  //q和d的点阵表示，省去了asc码转换的过程，直接用扫描玛映射像素点阵，16个9bit数
  always@(posedge clk)begin
	if(rst)begin
	pix[0] <= 9'h0;pix[1] <= 9'h0; pix[2] <= 9'h0; pix[3] <= 9'h0; pix[4] <= 9'h0; pix[5] <= 9'h0;   
	pix[6] <= 9'h0;pix[7] <= 9'h0; pix[8] <= 9'h0; pix[9] <= 9'h0; pix[10] <= 9'h0; pix[11] <= 9'h0;
	pix[15] <= 9'h0; pix[14] <= 9'h0; pix[13] <= 9'h0; pix[12] <= 9'h0;
	end
	else begin
	case(mc)
	8'b0001_0101:begin pix[0] <= 9'h0;pix[1] <= 9'h0; pix[2] <= 9'h07c; 
	pix[3] <= 9'h0c6; pix[4] <= 9'hc6; pix[5] <= 9'h0c6;pix[6] <= 9'h0c6; pix[7] <= 9'h0c6; pix[8] <= 9'h0c6; 
	pix[9] <= 9'h0d6; pix[10] <= 9'h0f6; pix[11] <= 9'h07c; pix[12] <= 9'h060; pix[13] <= 9'h0e0; 
	pix[14] <= 9'h000; pix[15] <= 9'h000;  end//q 23h
//	8'b0010_0011:begin pix <= {9'h060,9'h060,9'h060,9'h060,9'h078,9'h0,9'h0,9'h0,9'h0,9'h010,9'h038,9'h06c,9'h0c6,9'h0,9'h0,9'h0}; end//d, 23h
	default:begin      pix <= pix;  end
	endcase
	end
  end
  //产生vgadata数据显示,循环显示pix的16行9bit数值！当其为0时显示f黑，为1时显示0白
  always@(posedge clk) begin
	if(rst)begin
	vga_data <= 24'h000000;
	pix_line <= 0;
	end
	else if(v_addr<16)begin
		pix_line <= pix[v_addr[3:0]];
		if(h_addr>0 && h_addr<576) begin
        		if(pix_line[y])begin
        		vga_data <= 24'hffffff;
        		end
        		else begin
        		vga_data <= 24'h000000;
        		end
		end
		else begin
		vga_data <= 24'h000000;
		end
	end
	else begin
	pix_line <= pix_line;
	vga_data <= 24'h000000;
	end
  end
  //根据消隐后的有效信号，定位到某一行，扫描本行9bit像素,根据
  always@(posedge clk) begin
	if(rst)begin
      	y <= 0;
      	end
	else if(VGA_BLANK_N)begin
		if(y==8)begin
		y <= 0;
		end
		else begin
		y <= y +1;
		end
	end
	else begin
	y <= 0;
	end
  end
/*
always@(posedge clk) begin
      	if(rst)begin
	vga_data <= 24'h000000;
	end
      	else if(h_addr>0 && h_addr<576) begin
		if(pix_line[y])begin
		vga_data <= 24'hffffff;
		end
		else begin
		vga_data <= 24'h000000;
		end
	end
	vga_data <= 24'h000000;
end
*/

 //键盘控制器 ,二段式状态机控制+键盘输入缓冲模块
  always@(posedge clk)   begin
        if(rst)begin
       	c_state <= 3'd0;
        end
        else begin
	c_state <= n_state;
        end
  end
  always@(data or flag or rst) begin
	if(rst)begin
 	n_state = 3'd0;
	end
	else if((data!=8'hf0)&&flag && ready) begin
	n_state = 3'b001;
	end
	else if(data == 8'hf0 && ready) begin
	n_state = 3'b010;
	end
	else if(!flag && ready) begin
	n_state = 3'b100;
	end
	else begin
	n_state = 3'd0;
	end
  end
  always@(c_state or rst)begin
	if(rst)begin
	flag = 1'b1;
	cnt  = 3'd0;
	mc   =8'd0;
	nextdata_n = 1'b0;
	end
	else begin
	case(c_state)
	3'b001:begin  flag = 1'b1; mc = data; cnt = cnt;       nextdata_n = 1'b0; end
	3'b010:begin  flag = 1'b0; mc = data; cnt = cnt+1'b1;  nextdata_n = 1'b0; end
	3'b100:begin  flag = 1'b1; mc = data; cnt = cnt;       nextdata_n = 1'b0; end
	default:begin flag = flag; mc = mc;   cnt = cnt;       nextdata_n = 1'b1; end
	endcase
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
    .count		(count));
  //数码管
  wire [7:0]     segs [8:0];
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
 /*      8'b0100_0000:begin  seg0 = ~segs[0];  seg1 = ~segs[4]; end
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

//led指示灯
 assign ledr[15:0]  = {led_flag[6:0],1'b0,sampling, count[3:0], overflow, ready, pix_line[y]};
 always@(posedge clk)begin
	if(rst)begin
	led_flag <= 7'd0;
	end
	else begin
	led_flag <= pix_line[6:0];
	end
 end
endmodule
