module Barrel_shifter(

input[7:0]	shift_in,
input[2:0]	shift_num,
input[1:0]	shift_ctl,
output reg [7:0]	shift_out
);

 integer i;
 always@(shift_in or shift_num or shift_ctl)begin
	shift_out = shift_in;
	for(i=0;i<shift_num;i=i+1)begin
		case(shift_ctl)
		2'b00:begin shift_out = {shift_in[6:0],1'b0};			end // a/l shift left
		2'b01:begin shift_out = {1'b0,shift_in[7:1]};			end // l shift right
		2'b10:begin shift_out = {shift_in[7],shift_in[7:1]};           	end // a shift right
		2'b11:begin shift_out = {shift_in[0],shift_in[7:1]};            end // rotate  right
		default:begin	shift_out = shift_in;  				end
		endcase	
	end
 end

endmodule
