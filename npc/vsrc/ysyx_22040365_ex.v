`include "ysyx_22040365_defines.v"

module ysyx_22040365_ex(
 // input			clk,
  input[63:0]		op1,
  input[63:0]		op2,
//  input[7:0]		op_type,
  input			op_type,
  output 		wen_rd,
  output[63:0]		ex_result		
);

assign ex_result = (op_type==1'b1) ? op1+op2 : 0 ;  
assign wen_rd = 1'b1;
//always@(*) begin
//  case (op_type)
//  `INST_ADDI	 : begin ex_result = op1+op2;  wen_rd = 1'b1; end
//  default: begin  ex_result = 0;  wen_rd = 1'b0;   end 
//  endcase
//end

endmodule

