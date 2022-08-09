`include "ysyx_22040365_defines.v"
module ysyx_22040365_mem(
input                               rst,
input                               clk,

input                               store_67,
input                               load_67,
input [`ysyx_22040365_REG_BUS]      wmask_67,
input [`ysyx_22040365_REG_BUS]      store_data_67,
input [`ysyx_22040365_REG_BUS]      ex_data_67,
//just pipeline signal
input [7 : 0]                       inst_opcode_67,
input                               rd_en_67,
input [4 : 0]                       rd_addr_67,
input [31: 0]                       inst_67, 
input [`ysyx_22040365_REG_BUS]      pc_67,      
//output reg [`ysyx_22040365_REG_BUS] dtcm_data_78,
output reg [`ysyx_22040365_REG_BUS] result_78,
output reg                          rd_en_78,
output reg [4 : 0]                  rd_addr_78,
output reg [31: 0]                  inst_78,
output reg [`ysyx_22040365_REG_BUS] pc_78
);
//pipeline signal
wire [`ysyx_22040365_REG_BUS]  result_temp;
assign result_temp = (load_67==1'b1) ? load_data : ex_data_67;
always@(posedge clk)begin
  if(rst)begin
    result_78       <= `ysyx_22040365_ZERO_WORD;
    rd_en_78        <= 1'b0;
    rd_addr_78      <= 5'd0;
    inst_78         <= 32'd0;
    pc_78           <= `ysyx_22040365_ZERO_WORD;
  end
  else begin
    result_78       <= result_temp;
    rd_en_78        <= rd_en_67;
    rd_addr_78      <= rd_addr_67;
    inst_78         <= inst_67;
    pc_78           <= pc_67;
  end
end

RAMHelper memory(
  .clk              (clk),
  .en               (store_67|load_67),
  .rIdx             ((ex_data_67 - `ysyx_22040365_PC_START) >> 3),
  .rdata            (dtcm_data),
  .wIdx             ((ex_data_67 - `ysyx_22040365_PC_START) >> 3),
  .wdata            (store_data_67),
  .wmask            (wmask_67),
  .wen              (store_67)
);

//generate load output
reg  [`ysyx_22040365_REG_BUS]  load_data;
wire [`ysyx_22040365_REG_BUS]  dtcm_data;
reg  [`ysyx_22040365_REG_BUS]  lb_temp;
reg  [`ysyx_22040365_REG_BUS]  lbu_temp;
reg  [`ysyx_22040365_REG_BUS]  lh_temp;
reg  [`ysyx_22040365_REG_BUS]  lhu_temp;
reg  [`ysyx_22040365_REG_BUS]  lw_temp;
reg  [`ysyx_22040365_REG_BUS]  lwu_temp;
always@(*)begin
  if(rst)begin
    load_data  = `ysyx_22040365_ZERO_WORD;
  end
  else begin
    case(inst_opcode_67)
    `ysyx_22040365_INST_LB :begin load_data = lb_temp;  end
    `ysyx_22040365_INST_LBU:begin load_data = lbu_temp; end
    `ysyx_22040365_INST_LH :begin load_data = lh_temp;  end
    `ysyx_22040365_INST_LHU:begin load_data = lhu_temp; end
    `ysyx_22040365_INST_LW :begin load_data = lw_temp;  end
    `ysyx_22040365_INST_LWU:begin load_data = lwu_temp; end
    `ysyx_22040365_INST_LD :begin load_data = dtcm_data;end
    default: begin load_data = `ysyx_22040365_ZERO_WORD;end  
    endcase
  end
end
//generate lb_temp
always@(*)begin
  if(rst)begin
    lb_temp     = `ysyx_22040365_ZERO_WORD;
  end
  else begin
    case(ex_data_67[2:0])
    3'b000:begin lb_temp  = {{56{dtcm_data[7]}}  ,dtcm_data[7:0]  };end
    3'b001:begin lb_temp  = {{56{dtcm_data[15]}} ,dtcm_data[15:8] };end
	  3'b010:begin lb_temp  = {{56{dtcm_data[23]}} ,dtcm_data[23:16]};end
	  3'b011:begin lb_temp  = {{56{dtcm_data[31]}} ,dtcm_data[31:24]};end
	  3'b100:begin lb_temp  = {{56{dtcm_data[39]}} ,dtcm_data[39:32]};end
	  3'b101:begin lb_temp  = {{56{dtcm_data[47]}} ,dtcm_data[47:40]};end
    3'b110:begin lb_temp  = {{56{dtcm_data[55]}} ,dtcm_data[55:48]};end
	  3'b111:begin lb_temp  = {{56{dtcm_data[63]}} ,dtcm_data[63:56]};end
	  default:begin lb_temp = {{56{dtcm_data[7]}}  ,dtcm_data[7:0]  };end
    endcase
  end
end
//generate lbu_temp
always@(*)begin
  if(rst)begin
    lbu_temp     = `ysyx_22040365_ZERO_WORD;
  end
  else begin
    case(ex_data_67[2:0])
    3'b000:begin lbu_temp  = {{56{1'b0}} ,dtcm_data[7:0] }; end
    3'b001:begin lbu_temp  = {{56{1'b0}} ,dtcm_data[15:8] };end
	  3'b010:begin lbu_temp  = {{56{1'b0}} ,dtcm_data[23:16]};end
	  3'b011:begin lbu_temp  = {{56{1'b0}} ,dtcm_data[31:24]};end
	  3'b100:begin lbu_temp  = {{56{1'b0}} ,dtcm_data[39:32]};end
	  3'b101:begin lbu_temp  = {{56{1'b0}} ,dtcm_data[47:40]};end
    3'b110:begin lbu_temp  = {{56{1'b0}} ,dtcm_data[55:48]};end
	  3'b111:begin lbu_temp  = {{56{1'b0}} ,dtcm_data[63:56]};end
	  default:begin lbu_temp = {{56{1'b0}} ,dtcm_data[7:0]  };end
    endcase
  end
end
//generate lh_temp
always@(*)begin
  if(rst)begin
    lh_temp     = `ysyx_22040365_ZERO_WORD;
  end
  else begin
    case(ex_data_67[2:1])
    2'b00:begin lh_temp   = {{48{dtcm_data[15]}} ,dtcm_data[15:0] };end
    2'b01:begin lh_temp   = {{48{dtcm_data[31]}} ,dtcm_data[31:16]};end
    2'b10:begin lh_temp   = {{48{dtcm_data[47]}} ,dtcm_data[47:32]};end
    2'b11:begin lh_temp   = {{48{dtcm_data[63]}} ,dtcm_data[63:48]};end
    default:begin lh_temp = {{48{dtcm_data[15]}} ,dtcm_data[15:0] };end
    endcase
  end
end
//generate lhu_temp
always@(*)begin
  if(rst)begin
    lhu_temp     = `ysyx_22040365_ZERO_WORD;
  end
  else begin
    case(ex_data_67[2:1])
    2'b00:begin lhu_temp   = {{48{1'b0}} ,dtcm_data[15:0] };end
    2'b01:begin lhu_temp   = {{48{1'b0}} ,dtcm_data[31:16]};end
    2'b10:begin lhu_temp   = {{48{1'b0}} ,dtcm_data[47:32]};end
    2'b11:begin lhu_temp   = {{48{1'b0}} ,dtcm_data[63:48]};end
    default:begin lhu_temp = {{48{1'b0}} ,dtcm_data[15:0] };end
    endcase
  end
end
//generate lw_temp
always@(*)begin
  if(rst)begin
    lw_temp     = `ysyx_22040365_ZERO_WORD;
  end
  else begin
    case(ex_data_67[2])
    1'b0: begin lw_temp = {{32{dtcm_data[31]}} ,dtcm_data[31:0]  };end
    1'b1: begin lw_temp = {{32{dtcm_data[63]}} ,dtcm_data[63:32] };end
    default:begin lw_temp = {{32{dtcm_data[31]}} ,dtcm_data[31:0]};end
    endcase
  end
end
//generate lwu_temp
always@(*)begin
  if(rst)begin
    lwu_temp     = `ysyx_22040365_ZERO_WORD;
  end
  else begin
    case(ex_data_67[2])
    1'b0: begin lwu_temp = {{32{1'b0}} ,dtcm_data[31:0]  };end
    1'b1: begin lwu_temp = {{32{1'b0}} ,dtcm_data[63:32] };end
    default:begin lwu_temp = {{32{1'b0}} ,dtcm_data[31:0]};end
    endcase
  end
end
endmodule