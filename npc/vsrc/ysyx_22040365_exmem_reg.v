`include "ysyx_22040365_defines.v"
module ysyx_22040365_exmem_reg(
input                               rst,
input                               clk,
//gerenrate 
input  [7 : 0]                      inst_opcode_56,
input  [`ysyx_22040365_REG_BUS]     ex_data_56,
input  [`ysyx_22040365_REG_BUS]     store_data_56,

output reg                          store_67,
output reg                          load_67,
output reg [`ysyx_22040365_REG_BUS] wmask_67,
output reg [`ysyx_22040365_REG_BUS] store_data_67,
output reg [`ysyx_22040365_REG_BUS] ex_data_67,
//just pipeline signal
input                               rd_en_56,
input  [4 : 0]                      rd_addr_56,
input  [31: 0]                      inst_56,
input  [`ysyx_22040365_REG_BUS]     pc_56,

output reg [7 : 0]                  inst_opcode_67,
output reg                          rd_en_67,
output reg [4 : 0]                  rd_addr_67,
output reg [31: 0]                  inst_67, 
output reg [`ysyx_22040365_REG_BUS] pc_67                                            
);

wire store_temp_67  ; 
wire load_temp_67   ;

assign store_temp_67 = ( (inst_opcode_56 == `ysyx_22040365_INST_SD)||(inst_opcode_56 == `ysyx_22040365_INST_SW)
                       ||(inst_opcode_56 == `ysyx_22040365_INST_SH)||(inst_opcode_56 == `ysyx_22040365_INST_SB)
);
assign load_temp_67  = ( (inst_opcode_56 == `ysyx_22040365_INST_LD)||(inst_opcode_56 == `ysyx_22040365_INST_LB)
                       ||(inst_opcode_56 == `ysyx_22040365_INST_LBU)||(inst_opcode_56 == `ysyx_22040365_INST_LH)
                       ||(inst_opcode_56 == `ysyx_22040365_INST_LHU)||(inst_opcode_56 == `ysyx_22040365_INST_LW)
                       ||(inst_opcode_56 == `ysyx_22040365_INST_LWU));
//prepare the store wmask
reg  [`ysyx_22040365_REG_BUS]      wmask_temp;
wire [`ysyx_22040365_REG_BUS]      sw_mask;
reg  [`ysyx_22040365_REG_BUS]      sh_mask;
reg  [`ysyx_22040365_REG_BUS]      sb_mask;
//assign store_data_temp_sw = (ex_data_56[2]==1'b1) ? (store_data_56<<32) : store_data_56;
assign sw_mask = (ex_data_56[2]==1'b1) ? (64'hffffffff00000000) : (64'h00000000ffffffff); 

always@(*)begin
  if(rst)begin
    sh_mask =  `ysyx_22040365_ZERO_WORD;
  end
  else begin
    case(ex_data_56[2:1])
    2'b00:begin     sh_mask =  64'h000000000000ffff;end
    2'b01:begin     sh_mask =  64'h00000000ffff0000;end
    2'b10:begin     sh_mask =  64'h0000ffff00000000;end
    default:begin   sh_mask =  64'hffff000000000000;end
    endcase
  end
end

always@(*)begin
  if(rst)begin
    sb_mask =  `ysyx_22040365_ZERO_WORD;
  end
  else begin
    case (ex_data_56[2:0])
    3'b000:begin  sb_mask = 64'h00000000000000ff;end
    3'b001:begin  sb_mask = 64'h000000000000ff00;end
    3'b010:begin  sb_mask = 64'h0000000000ff0000;end
    3'b011:begin  sb_mask = 64'h00000000ff000000;end
    3'b100:begin  sb_mask = 64'h000000ff00000000;end
    3'b101:begin  sb_mask = 64'h0000ff0000000000;end
    3'b110:begin  sb_mask = 64'h00ff000000000000;end
    default:begin sb_mask = 64'hff00000000000000;end
    endcase
  end
end

always@(*)begin
  if(rst)begin
    wmask_temp = `ysyx_22040365_ZERO_WORD;
  end
  else begin
    case(inst_opcode_56)
    `ysyx_22040365_INST_SD:begin wmask_temp = 64'hffffffffffffffff;end
    `ysyx_22040365_INST_SW:begin wmask_temp = sw_mask; end
    `ysyx_22040365_INST_SH:begin wmask_temp = sh_mask; end
    `ysyx_22040365_INST_SB:begin wmask_temp = sb_mask; end
    default:begin  wmask_temp = 64'hffffffffffffffff;end
    endcase
  end
end
//prepare the store data
reg  [`ysyx_22040365_REG_BUS]      store_data_temp;
wire [`ysyx_22040365_REG_BUS]      store_data_temp_sw;
reg  [`ysyx_22040365_REG_BUS]      store_data_temp_sh;
reg  [`ysyx_22040365_REG_BUS]      store_data_temp_sb;

assign store_data_temp_sw = (ex_data_56[2]==1'b1) ? ((store_data_56<<32)&sw_mask) : (store_data_56&sw_mask);

always@(*)begin
  if(rst)begin
    store_data_temp_sh =  `ysyx_22040365_ZERO_WORD;
  end
  else begin
    case(ex_data_56[2:1])
    2'b00:begin     store_data_temp_sh =  store_data_56 & sh_mask;      end
    2'b01:begin     store_data_temp_sh =  (store_data_56<<16) & sh_mask;end
    2'b10:begin     store_data_temp_sh =  (store_data_56<<32) & sh_mask;end
    default:begin   store_data_temp_sh =  (store_data_56<<48) & sh_mask;end
    endcase
  end
end

always@(*)begin
  if(rst)begin
    store_data_temp_sb =  `ysyx_22040365_ZERO_WORD;
  end
  else begin
    case (ex_data_56[2:0])
    3'b000:begin  store_data_temp_sb = store_data_56 & sb_mask;      end
    3'b001:begin  store_data_temp_sb = (store_data_56<<8) & sb_mask; end
    3'b010:begin  store_data_temp_sb = (store_data_56<<16)& sb_mask; end
    3'b011:begin  store_data_temp_sb = (store_data_56<<24)& sb_mask; end
    3'b100:begin  store_data_temp_sb = (store_data_56<<32)& sb_mask; end
    3'b101:begin  store_data_temp_sb = (store_data_56<<40)& sb_mask; end
    3'b110:begin  store_data_temp_sb = (store_data_56<<48)& sb_mask; end
    default:begin store_data_temp_sb = (store_data_56<<56)& sb_mask; end
    endcase
  end
end

always@(*)begin
  if(rst)begin
    store_data_temp = `ysyx_22040365_ZERO_WORD;
  end
  else begin
    case(inst_opcode_56)
    `ysyx_22040365_INST_SD:begin store_data_temp = store_data_56; end
    `ysyx_22040365_INST_SW:begin store_data_temp = store_data_temp_sw; end
    `ysyx_22040365_INST_SH:begin store_data_temp = store_data_temp_sh; end
    `ysyx_22040365_INST_SB:begin store_data_temp = store_data_temp_sb; end
    default:begin  store_data_temp = store_data_56;end
    endcase
  end
end


//generate store type operation num
//always@(posedge clk)begin
always@(*)begin
  if(rst)begin
    store_67        = 1'b0;
    load_67         = 1'b0;
    ex_data_67      = `ysyx_22040365_ZERO_WORD;
    store_data_67   = `ysyx_22040365_ZERO_WORD;
    wmask_67        = `ysyx_22040365_ZERO_WORD;
  end
  else if(load_temp_67)begin
    store_67        = 1'b0;
    load_67         = 1'b1;
    ex_data_67      = ex_data_56;
    store_data_67   = `ysyx_22040365_ZERO_WORD;
    wmask_67        = `ysyx_22040365_ZERO_WORD; 
  end
  else if(store_temp_67)begin
    store_67        = 1'b1;
    load_67         = 1'b0;
    ex_data_67      = ex_data_56;
    store_data_67   = store_data_temp;
    wmask_67        = wmask_temp;
  end
  else begin
    store_67        = 1'b0;
    load_67         = 1'b0;
    ex_data_67      = ex_data_56;
    store_data_67   = `ysyx_22040365_ZERO_WORD;
    wmask_67        = `ysyx_22040365_ZERO_WORD;
  end
end

//just for pipeline
//always@(posedge clk)begin
always@(*)begin
  if(rst)begin
   rd_en_67         = 1'b0;
   rd_addr_67       = 5'd0;
   inst_67          = 32'd0;
   pc_67            = `ysyx_22040365_ZERO_WORD;
   inst_opcode_67   = 8'd0;
  end
  else begin
    rd_en_67        = rd_en_56;
    rd_addr_67      = rd_addr_56;
    inst_67         = inst_56;
    pc_67           = pc_56;
    inst_opcode_67  = inst_opcode_56;
  end
end


endmodule