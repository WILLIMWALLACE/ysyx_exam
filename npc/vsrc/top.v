module top(
input 		rst,
input 		clk,
input	[15:0]	sw,
output  [15:0]	ledr,
  );
  
wire[2:0]	func;
wire		overflow;
wire[3:0]	sum;
wire		cout;
wire[3:0]	logic;
wire		zero;
wire[3:0]	a;
wire[3:0]       b;

assign  zero = ~(|sum);
assign	func = sw[10:8];
assign	ledr = {{6{1'b0}},logci[3:0],overflow,cout,sum[3:0]};
always@(func) begin
	case(func)
	3'b000:begin a=sw[3:0]; b=sw[7:4]; end //+
	3'b001:begin a=sw[3:0]; b=sw[7:4]; end //-
	3'b010:begin a=4'd0; b=4'd0; logic= ~sw[3:0];          end //~
  	3'b011:begin a=4'd0; b=4'd0; logic= sw[3:0] & sw[7:4]; end //&
  	3'b100:begin a=4'd0; b=4'd0; logic= sw[3:0] | sw[7:4]; end //|
	3'b101:begin a=4'd0; b=4'd0; logic= sw[3:0] ^ sw[7:4]; end // xor
  	3'b110:begin a=sw[3:0]; b=sw[7:4]; logic= sum[3] ^ overflow; end //a<b则为1 ；>则为0
  	3'b111:begin a=sw[3:0]; b=sw[7:4]; logic[0]=zero;  end //相等则为1；
	default:begin a=4'd0; b=4'd0; logic=4'd0;	end
	endcase
end

  fadd fadd_inst(
	.sum		(sum),
	.cout		(cout),
	.overflow	(overflow),
	.a		(a),
	.b		(b),
	.cin		(1'b0),
	.clk		(clk),
	.rst		(rst));

endmodule
