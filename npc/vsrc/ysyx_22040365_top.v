`include "ysyx_22040365_defines.v"

module ysyx_22040365_top(
  input		clk,
//  input		rst,
  input		inst,
  output[63:0]	out
);

//common
wire[1:0]	inst_type;

//id to regfile
wire[4:0]	rs1_addr;
wire[4:0]	rd_addr;
wire[63:0]	imm_I;	
wire		ren_rs1;	
//regfile to ex
wire[63:0]	rs1_data;
//ex to regfile
wire[63:0]	rd_data;
wire		wen_rd;

ysyx_22040365_id u_ysyx_22040365_id(
  .inst		(inst),
  .inst_type	(inst_type),
  .rs1		(rs1_addr),
  .rd		(rd_addr_id),
  .immI		(imm_I),
  .ren_rs1	(ren_rs1));

ysyx_22040365_regfile#(2,64)
 u_ysyx_22040365_regfile(
  .clk		(clk),
  .wdata	(rd_data),
  .waddr	(rd_addr_ex),
  .wen		(wen_rd),
  .ren_rs1	(ren_rs1),
  .raddr	(rs1_addr),
  .rdata	(rs1_data));

ysyx_22040365_ex u_ysyx_22040365_ex(
//  .clk		(),
  .op1		(rs1_data),
  .op2		(imm_I),
  .op_type	(inst_type),
  .ex_result	(rd_data));

endmodule
