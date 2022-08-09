`include "ysyx_22040365_defines.v"
module ysyx_22040365_stall(
  input                                   rst,
  input                                   clk,
  //from id/ex_reg
  input        [4  : 0]                   rs1_addr_34,
  input        [4  : 0]                   rs2_addr_34,  
  //from exe_stage
  input        [4  : 0]                   rd_addr_56,
  input        [7  : 0]                   inst_opcode_56,

  output reg                              stall_mem_ex,
  output reg                              stall_mem_ex1,
  output reg                              stall_mem_ex2
);

wire   load_type;
assign load_type  = ( (inst_opcode_56 == `ysyx_22040365_INST_LD)||(inst_opcode_56 == `ysyx_22040365_INST_LB)
                       ||(inst_opcode_56 == `ysyx_22040365_INST_LBU)||(inst_opcode_56 == `ysyx_22040365_INST_LH)
                       ||(inst_opcode_56 == `ysyx_22040365_INST_LHU)||(inst_opcode_56 == `ysyx_22040365_INST_LW)
                       ||(inst_opcode_56 == `ysyx_22040365_INST_LWU));


reg     flag;
wire    stall_mem_ex_temp;
//wire    stall_mem_ex;
assign  stall_mem_ex_temp = ( (flag==1'b0)&&(rd_addr_56!=5'd0)&&(load_type==1'b1)&&((rs1_addr_34==rd_addr_56)||(rs2_addr_34==rd_addr_56)) )
                           ? 1'b1 : 1'b0;
//one cycle
assign  stall_mem_ex = ( (flag==1'b0) && (stall_mem_ex_temp==1'b1) );

always@(posedge clk)begin
  if(rst)begin
    stall_mem_ex1   <=  1'b0;
    stall_mem_ex2   <=  1'b0;
  end
  else begin
    stall_mem_ex1   <=  stall_mem_ex;
    stall_mem_ex2   <=  stall_mem_ex1;
  end
end

//generate one cycle stall_mem_ex
always@(posedge clk)begin
  if(rst)begin
    flag <= 1'b0;
  end
  else if(stall_mem_ex_temp) begin
    flag <= 1'b1;
  end
  else begin
    flag <= 1'b0;
  end
end



endmodule