`include "ysyx_22040365_defines.v"
module ysyx_22040365_id(
  input	[31:0]	inst,
  output[1:0]	inst_type,
  output[4:0]	rs1,
 // output[4:0]	rs2,
  output[4:0]	rd,
  output[63:0]	imm_I,
//  output	wen_rd,
  output	ren_rs1
);



wire[6:0]	opcode;
wire[2:0]	func;
//assign	mod_type = 
assign	rd       = inst[11:7];
assign	rs1      = inst[19:15];
assign	imm_I 	 = {{52{inst[31]}},inst[31:20]};
wire	addi     = ~opcode[2] & ~opcode[3] & opcode[4] & ~opcode[5] & ~opcode[6]
 		   & ~func3[0] & ~func3[1] & ~func3[2];

assign	inst_type[0] = (!rst) ? 0 : addi ;
assign  inst_type[1] = (!rst) ? 0 :  0   ;               
//assign  inst_type[0] =  
//assign  inst_type[0] =  
//assign  inst_type[0] =  
//assign  inst_type[0] =  
//assign  inst_type[0] =  
always@(*)begin
  case (inst_type)
  	`INST_ADDI: 	 begin  ren_rs1=1'b1;  end
	default: begin  ren_rs1=1'b0;  end   
  endcase
end



endmodule
