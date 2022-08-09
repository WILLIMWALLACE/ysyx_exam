`include "ysyx_22040365_defines.v"
module ysyx_22040365_memwb_reg(
input                                    rst,
input                                    clk,
     
input [`ysyx_22040365_REG_BUS]           result_78,
input                                    rd_en_78,
input [4 : 0]                            rd_addr_78,
input [31: 0]                            inst_78,
input [`ysyx_22040365_REG_BUS]           pc_78,

output reg [`ysyx_22040365_REG_BUS]      result_83,
output reg                               rd_en_83,
output reg [4 : 0]                       rd_addr_83,
output reg [31: 0]                       inst_83,
output reg [`ysyx_22040365_REG_BUS]      pc_83
);

//always@(posedge clk)begin
always@(*)begin
  if(rst)begin
    result_83       =  `ysyx_22040365_ZERO_WORD;
    rd_en_83        =  1'b0;
    rd_addr_83      =  5'd0;
    inst_83         =  32'd0;
    pc_83           =  `ysyx_22040365_ZERO_WORD;
  end
  else begin
    result_83       =  result_78;
    rd_en_83        =  rd_en_78;
    rd_addr_83      =  rd_addr_78;
    inst_83         =  inst_78;
    pc_83           =  pc_78;
  end
end

endmodule