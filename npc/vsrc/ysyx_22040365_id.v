`include "ysyx_22040365_defines.v"
module ysyx_22040365_id(
  input	[31:0]	inst,
//  output[7:0]	inst_type,
  output[4:0]	rs1,
 // output[4:0]	rs2,
  output[4:0]	rd,
  output[63:0]	imm_I,
//  output	wen_rd,
  output reg	ren_rs1
);



wire[6:0]	opcode;
wire[2:0]	func3;
//common 
assign func3  = inst[14 : 12];
assign	rd       = inst[11:7];
assign	rs1      = inst[19:15];
assign	imm_I 	 = {{52{inst[31]}},inst[31:20]};
assign opcode = inst[6  :  0];
//inst type
wire	addi     = ~opcode[2] & ~opcode[3] & opcode[4] & ~opcode[5] & ~opcode[6]
 		   & ~func3[0] & ~func3[1] & ~func3[2];

//assign	inst_type[0] =  addi ;
//assign  inst_type[1] =  0   ;               
//assign  inst_type[2] =  0;
//assign  inst_type[3] =  0;
//assign  inst_type[4] =  0;
//assign  inst_type[5] =  0;
//assign  inst_type[6] =  0;
//always@(*)begin
//  case (inst_type)
  	//`INST_ADDI: 	 begin  ren_rs1=1'b1;  end
	//default: begin  ren_rs1=1'b0;  end   
//  endcase
//end
assign ren_rs1 = 1'b1;


endmodule

