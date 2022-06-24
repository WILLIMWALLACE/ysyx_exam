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
output [7:0] 		VGA_B
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
 reg  [3:0]	x,y;
 //vga控制所需信号
  wire [9:0] h_addr;
  wire [9:0] v_addr;
  reg [23:0] vga_data;
  assign VGA_CLK = clk;
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
	pix <= 0;
	end
	else begin
	case(mc)
	8'b0001_0101:begin pix <= {9'h0,9'h0,9'h0,9'h0,9'h0,9'h0,9'h0fc,9'h0,9'h0,9'h0fc,9'h0,9'h0,9'h0,9'h0,9'h0,9'h0};  end//q ,15h
	8'b0010_0011:begin pix <= {9'h060,9'h060,9'h060,9'h060,9'h078,9'h0,9'h0,9'h0,9'h0,9'h010,9'h038,9'h06c,9'h0c6,9'h0,9'h0,9'h0}; end//d, 23h
	default:begin      pix <= pix;  end
	endcase
	end
  end
  //产生vgadata数据显示,循环显示pix的16行9bit数值！当其为1时显示f黑，为0时显示0白
  always@(posedge clk) begin
	if(rst)begin
	x <= 0;
	pix_line <= 0;
	end
	else begin
		pix_line <= pix[x];
		if(x==4'd15)begin//x<=16 hang
		x <= 0;
		end
		else begin
		x <= x+1;
		end
	end
  end
  always@(posedge clk) begin
	if(rst)begin
      	y <= 0;
      	end
	else if(y==8)begin
	y <= 0;
	end
	else begin
	y <= y+1;
	end
  end
always@(posedge clk) begin
      	if(rst)begin
	vga_data <= 24'h0;
	end
      	else if(pix_line[y]) begin
	vga_data <= 24'hffffff;
	end
	vga_data <= 24'h0;
end

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
 //led指示灯
 assign ledr[15:0]  = {led_flag[6:0],v_addr[9], sampling, count[3:0], overflow, ready, nextdata_n};
 always@(posedge clk)begin
	if(rst)begin
	led_flag <= 7'd0;
	end
	else begin
	led_flag <= 7'd0;
	end
 end
endmodule
