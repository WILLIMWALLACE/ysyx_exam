module seg(
  input clk,
  input rst,
  input  [2:0] decimal,
  output reg [7:0] o_seg0,
/*  output reg [7:0] o_seg1,
  output reg [7:0] o_seg2,
  output reg [7:0] o_seg3,
  output reg [7:0] o_seg4,
  output reg [7:0] o_seg5,
  output reg [7:0] o_seg6,*/
  output reg [7:0] o_seg7
);

  wire [7:0] segs [7:0];
  assign segs[0] = 8'b11111101;
  assign segs[1] = 8'b01100000;
  assign segs[2] = 8'b11011010;
  assign segs[3] = 8'b11110010;
  assign segs[4] = 8'b01100110;
  assign segs[5] = 8'b10110110;
  assign segs[6] = 8'b10111110;
  assign segs[7] = 8'b11100000;        

always@(decimal) begin
	case(decimal)
	3'd0:	o_seg0 = segs[0];
	3'd1:   o_seg0 = segs[1];
	3'd2:	o_seg0 = segs[2];
	3'd3:	o_seg0 = segs[3];
	3'd4:	o_seg0 = segs[4];
	3'd5:	o_seg0 = segs[5];
	3'd6:	o_seg0 = segs[6];
	3'd7:	o_seg0 = segs[7];
	default: o_seg0 = segs[0];
	endcase
end



//do not care,just for clk & rst
  always@(posedge clk) begin
	if(rst) begin
		o_seg7 <= segs[7];
		end
	else
		o_seg7 <= segs[7];
  end
  endmodule   
