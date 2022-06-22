module Barrel_shifter(

input[7:0]	shift_in,
input[2:0]	shift_num,
input[1:0]	shift_ctl,
output reg [7:0]	shift_out
);

 reg [7:0]	temp;
// reg [7:0]      temp1;
// reg [7:0]      temp2;

 always@(shift_in or shift_num or shift_ctl)begin
	shift_out = temp;
		case(shift_ctl)
		2'b00:begin 
		temp = shift_num[0] ? {shift_in[6:0],1'b0} : shift_in;
		temp = shift_num[1] ? {temp[5:0],{2{1'b0}}} : temp;
		temp = shift_num[2] ? {temp[3:0],{4{1'b0}}} : temp;
		end // a/l shift left
		2'b01:begin 
		temp = shift_num[0] ? {1'b0,shift_in[7:1]} : shift_in;
		temp = shift_num[1] ? {{2{1'b0}},temp[7:2]} : temp;
 		temp = shift_num[2] ? {{4{1'b0}},temp[7:4]} : temp;
		end // l shift right
		2'b10:begin 
		temp = shift_num[0] ? {shift_in[7],shift_in[7:1]} : shift_in;      
		temp = shift_num[1] ? {temp[7],1'b0,temp[7:2]} : temp;
		temp = shift_num[2] ? {temp[7],{3{1'b0}},temp[7:4]} : temp; 
		end // a shift right
		2'b11:begin 
		temp = shift_num[0] ? {shift_in[0],shift_in[7:1]} : shift_in;   
		temp = shift_num[1] ? {temp[1:0],temp[7:2]} : temp;
		temp = shift_num[2] ? {temp[3:0],temp[7:4]} : temp;
		end // rotate  right
		default:begin	shift_out = shift_in;  				end
		endcase	
 end

endmodule
