module Barrel_shifter(

input[7:0]	shift_in,
input[2:0]	shift_num,
input[1:0]	shift_ctl,
output [7:0]	shift_out
);

 reg [7:0]	temp0;
 reg [7:0]      temp1;
 reg [7:0]      temp2;

 assign	shift_out = temp2;
 always@(shift_in or shift_num or shift_ctl)begin
		case(shift_ctl)
		2'b00:begin 
		temp0 = shift_num[0] ? {shift_in[6:0],1'b0} : shift_in;
		temp1 = shift_num[1] ? {temp0[5:0],{2{1'b0}}} : temp0;
		temp2 = shift_num[2] ? {temp1[3:0],{4{1'b0}}} : temp1;
		end // a/l shift left
		2'b01:begin 
		temp0 = shift_num[0] ? {1'b0,shift_in[7:1]} : shift_in;
		temp1 = shift_num[1] ? {{2{1'b0}},temp0[7:2]} : temp0;
 		temp2 = shift_num[2] ? {{4{1'b0}},temp1[7:4]} : temp1;
		end // l shift right
		2'b10:begin 
		temp0 = shift_num[0] ? {shift_in[7],shift_in[7:1]} : shift_in;      
		temp1 = shift_num[1] ? {temp0[7],1'b0,temp0[7:2]} : temp0;
		temp2 = shift_num[2] ? {temp1[7],{3{1'b0}},temp1[7:4]} : temp1; 
		end // a shift right
		2'b11:begin 
		temp0 = shift_num[0] ? {shift_in[0],shift_in[7:1]} : shift_in;   
		temp1 = shift_num[1] ? {temp0[1:0],temp0[7:2]} : temp0;
		temp2 = shift_num[2] ? {temp1[3:0],temp1[7:4]} : temp1;
		end // rotate  right
		default:begin	temp2 = shift_in;  				end
		endcase	
 end

endmodule
