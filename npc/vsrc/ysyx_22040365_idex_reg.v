`include "ysyx_22040365_defines.v"
module ysyx_22040365_idex_reg (
  input  rst,
  input  clk,
  input  B_flush, // change from pc_reset
  input  stall_mem_ex,
  input  stall_mem_ex1, // need to add
  //to create operate num/type
  input        [`ysyx_22040365_REG_BUS]   rs1_data_34,
  input        [`ysyx_22040365_REG_BUS]   rs2_data_34,
  input        [`ysyx_22040365_REG_BUS]   imm_34,
  input        [`ysyx_22040365_REG_BUS]   pc_34,
  input        [7 : 0]                    inst_opcode_34,
  input        [6 : 0]                    inst_type_34,

  output  reg  [3 : 0]                    op_type_45,
  output  reg  [`ysyx_22040365_REG_BUS]   op1_45,
  output  reg  [`ysyx_22040365_REG_BUS]   op2_45,
  output  reg  [`ysyx_22040365_REG_BUS]   op3_45,
  output  reg                             bit_w,
  output  reg  [6 : 0]                    inst_type_45,
  //just pipeline
  input	                            rd_en_34,
  input        [4 : 0]                    rd_addr_34,       
  input        [31: 0]                    inst_34,

  output reg   [7 : 0]                    inst_opcode_45,
  output reg                              rd_en_45,
  output reg   [4 : 0]                    rd_addr_45,       
  output reg   [31: 0]                    inst_45,
  output reg   [`ysyx_22040365_REG_BUS]   pc_45,         
  //for bypass input from reg_files
  input        [4  : 0]                   rs1_addr_34,
  input        [4  : 0]                   rs2_addr_34,
  //for bypass input from ex_stage  
  input                                   rd_en_56,
  input        [4  : 0]                   rd_addr_56,
  input        [`ysyx_22040365_REG_BUS]   ex_data_56,  
  //for bypass input from mem/wb_reg
  input        [`ysyx_22040365_REG_BUS]   result_78,
  input                                   rd_en_78,
  input        [4 : 0]                    rd_addr_78
);

//control signal // collect all the flush operation 
wire    pc_reset;
reg     B_flush1;
always@(posedge clk)begin
  B_flush1    <=    B_flush; 
end
assign  pc_reset = (B_flush||B_flush1)&&(stall_mem_ex1!=1'b1);

//******************generate operation num(start)****************//
reg  [`ysyx_22040365_REG_BUS]  rs1_data;
reg  [`ysyx_22040365_REG_BUS]  rs2_data;
// bypass enable signal
wire	                        op1_bypass_ex;
wire	                        op2_bypass_ex;
wire	                        op1_bypass_mem;
wire	                        op2_bypass_mem;

wire                           op1_successive_mem;
wire                           op2_successive_mem;
//latch the successive op2\op1 mem bypass
reg                            op1_bypass_mem_latency;
reg  [`ysyx_22040365_REG_BUS]  op1_data_mem_latency; 
reg  [4 : 0]                   rs1_addr34_latency;
reg                            op2_bypass_mem_latency;
reg  [`ysyx_22040365_REG_BUS]  op2_data_mem_latency;
reg  [4 : 0]                   rs2_addr34_latency;

always@(posedge clk)begin
  if(rst)begin
    op1_bypass_mem_latency <= 1'b0;
    op1_data_mem_latency   <=  `ysyx_22040365_ZERO_WORD;
    rs1_addr34_latency     <= 5'd0;
  end
  else begin
    op1_bypass_mem_latency <= op1_bypass_mem;
    op1_data_mem_latency   <= result_78 ;
    rs1_addr34_latency     <= rs1_addr_34;
  end
end

always@(posedge clk)begin
  if(rst)begin
    op2_bypass_mem_latency <= 1'b0;
    op2_data_mem_latency   <=  `ysyx_22040365_ZERO_WORD;
    rs2_addr34_latency     <= 5'd0;
  end
  else begin
    op2_bypass_mem_latency <= op2_bypass_mem;
    op2_data_mem_latency   <= result_78 ;
    rs2_addr34_latency     <= rs2_addr_34;
  end
end

assign  op1_successive_mem  = op1_bypass_mem_latency && op2_bypass_mem&&(rs1_addr34_latency==rs1_addr_34);
assign  op2_successive_mem  = op2_bypass_mem_latency && op1_bypass_mem&&(rs2_addr34_latency==rs2_addr_34); 
////////////////////// need to change/////////////////
assign  op1_bypass_mem = ((rd_en_78 == 1'b1) && (rd_addr_78 == rs1_addr_34) && (rd_addr_78 != 5'b00000) ) ? 1'b1 : 1'b0;
assign  op2_bypass_mem = ((rd_en_78 == 1'b1) && (rd_addr_78 == rs2_addr_34) && (rd_addr_78 != 5'b00000) ) ? 1'b1 : 1'b0;
assign  op1_bypass_ex  = ((rd_en_56 == 1'b1) && (rd_addr_56 == rs1_addr_34) && (rd_addr_56 != 5'b00000) ) ? 1'b1 : 1'b0;
assign  op2_bypass_ex  = ((rd_en_56 == 1'b1) && (rd_addr_56 == rs2_addr_34) && (rd_addr_56 != 5'b00000) ) ? 1'b1 : 1'b0;
//bypass choose rs1_data/rs2_data
always@ (*) begin
	if( (rst == 1'b1) || (pc_reset == 1'b1) )begin
                rs1_data = `ysyx_22040365_ZERO_WORD;
        end
        else if(op1_bypass_ex == 1'b1  && stall_mem_ex1 !=1'b1)begin
	         rs1_data = ex_data_56;//from ex	
	 end
	 else if(op1_bypass_mem == 1'b1 ) begin
		  rs1_data = result_78; // from mem
        end
        else if(op1_successive_mem)begin
                rs1_data = op1_data_mem_latency;     
        end
	 else begin  rs1_data = rs1_data_34;   end
end

always@ (*) begin
        if( (rst == 1'b1) || (pc_reset == 1'b1) )begin
                rs2_data = `ysyx_22040365_ZERO_WORD;
        end
        else if(op2_bypass_ex == 1'b1 && stall_mem_ex1 !=1'b1 )begin
                rs2_data = ex_data_56;// from ex
        end
        else if(op2_bypass_mem == 1'b1 )begin
                rs2_data = result_78;// from mem
        end
        else if(op2_successive_mem)begin
                rs2_data = op2_data_mem_latency;     
        end
        else begin  rs2_data = rs2_data_34;  end
end

//change sub to sum!!rs1_data-"*rs2_data* = sub_temp\sub_complement"
wire	[`ysyx_22040365_REG_BUS]   sub_temp;
wire	[`ysyx_22040365_REG_BUS]   sub_complement;
wire    sub_flag       =  (inst_opcode_34==`ysyx_22040365_INST_SUB)||(inst_opcode_34==`ysyx_22040365_INST_SUBW); 
//assign  sub_temp       = (rs2_data != `ysyx_22040365_ZERO_WORD) ? { ~rs2_data[63], rs2_data[62:0]} : rs2_data;
//assign  sub_complement =  {sub_temp[63],(~sub_temp[62 : 0]+1'b1)} ;
assign    sub_complement = (rs2_data != `ysyx_22040365_ZERO_WORD) ? {~rs2_data[63:0] + 1'b1} : rs2_data[63:0];
//generate operation num
//always@(posedge clk)begin
always@(*)begin  
  if( (rst == 1'b1) || (pc_reset == 1'b1) )begin
	op1_45      = `ysyx_22040365_ZERO_WORD;
	op2_45      = `ysyx_22040365_ZERO_WORD;
       op3_45      = `ysyx_22040365_ZERO_WORD;
        //op_type_45  <= 3'd0;
  end
  //else if(stall_mem_ex != 1'b1 || stall_mem_ex1!=1'b1) 
  else begin
     //{1'b0, S_type, U_type, J_type, B_type, R_type, I_type};   
	case( inst_type_34 )
        7'b0000001: begin //I_tupe
        op1_45      =  rs1_data;
        op2_45      =  imm_34;
        op3_45      =  `ysyx_22040365_ZERO_WORD;
        end
        7'b0000010: begin //R_tupe
        op1_45      =  rs1_data;
        op3_45      =  `ysyx_22040365_ZERO_WORD;
            if(sub_flag)begin
            op2_45      =  sub_complement;//chang sub to sum
            end
            else begin
            op2_45      =  rs2_data;
            end
        end
        7'b0000100: begin //B_tupe
        op1_45      =  rs1_data;
        op2_45      =  rs2_data;
        op3_45      =  imm_34;
        end
        7'b0001000: begin //J_tupe
        op1_45      =  pc_34;
        op2_45      =  imm_34;
        op3_45      =  `ysyx_22040365_ZERO_WORD;
        end
        7'b0010000: begin //U_tupe
        op3_45      =  `ysyx_22040365_ZERO_WORD;
        if(inst_opcode_34==`ysyx_22040365_INST_AUIPC)begin
          op1_45      =  pc_34;
          op2_45      =  imm_34;
        end
        else begin
          op1_45      =  imm_34;
          op2_45      =  `ysyx_22040365_ZERO_WORD;
        end        
        end
        7'b0100000: begin //S_tupe
        op1_45      =  rs1_data;
        op2_45      =  rs2_data;
        op3_45      =  imm_34;
        end
        default: begin  
        op1_45      =  `ysyx_22040365_ZERO_WORD;
        op2_45      =  `ysyx_22040365_ZERO_WORD;
        op3_45      =  `ysyx_22040365_ZERO_WORD;
        end
        endcase		
  end
  /*else begin
  op1_45      =  `ysyx_22040365_ZERO_WORD;
  op2_45      =  `ysyx_22040365_ZERO_WORD;
  op3_45      =  `ysyx_22040365_ZERO_WORD;
  end*/
end
//******************generate operation num(end)****************// 

//******************generate operation type(start)*************// 
wire    sum_type;
wire    div_type;
wire    mul_type;
wire    sl_type;
wire    sr_type;
wire    xor_type;
wire    or_type;
wire    and_type;
wire    set_type;

assign  sum_type =( (inst_opcode_34==`ysyx_22040365_INST_AUIPC)||(inst_opcode_34==`ysyx_22040365_INST_ADDI)
||(inst_opcode_34==`ysyx_22040365_INST_ADD)||(inst_opcode_34==`ysyx_22040365_INST_ADDW)
||(inst_opcode_34==`ysyx_22040365_INST_ADDIW)||(inst_opcode_34==`ysyx_22040365_INST_SUB)
||(inst_opcode_34==`ysyx_22040365_INST_SUBW)||(inst_opcode_34==`ysyx_22040365_INST_BEQ)
||(inst_opcode_34==`ysyx_22040365_INST_BNE)||(inst_opcode_34==`ysyx_22040365_INST_BGE)
||(inst_opcode_34==`ysyx_22040365_INST_BGEU)||(inst_opcode_34==`ysyx_22040365_INST_BLT)
||(inst_opcode_34==`ysyx_22040365_INST_BLTU)||(inst_opcode_34==`ysyx_22040365_INST_JAL)
||(inst_opcode_34==`ysyx_22040365_INST_JALR)||(inst_opcode_34==`ysyx_22040365_INST_LHU)
||(inst_opcode_34==`ysyx_22040365_INST_LH)||(inst_opcode_34==`ysyx_22040365_INST_LBU)
||(inst_opcode_34==`ysyx_22040365_INST_LB)||(inst_opcode_34==`ysyx_22040365_INST_LW)
||(inst_opcode_34==`ysyx_22040365_INST_LWU)||(inst_opcode_34==`ysyx_22040365_INST_LD)
||(inst_opcode_34==`ysyx_22040365_INST_SD)||(inst_opcode_34==`ysyx_22040365_INST_SW)
||(inst_opcode_34==`ysyx_22040365_INST_SB)||(inst_opcode_34==`ysyx_22040365_INST_SH)
||(inst_opcode_34==`ysyx_22040365_INST_LUI)
);
assign  div_type = ( (inst_opcode_34==`ysyx_22040365_INST_DIV)||(inst_opcode_34==`ysyx_22040365_INST_DIVU)
||(inst_opcode_34==`ysyx_22040365_INST_REM)||(inst_opcode_34==`ysyx_22040365_INST_REMU)
||(inst_opcode_34==`ysyx_22040365_INST_DIVW)||(inst_opcode_34==`ysyx_22040365_INST_DIVUW)
||(inst_opcode_34==`ysyx_22040365_INST_REMW)||(inst_opcode_34==`ysyx_22040365_INST_REMUW)
);
assign  mul_type = ( (inst_opcode_34 == `ysyx_22040365_INST_MUL)||(inst_opcode_34 == `ysyx_22040365_INST_MULH)
||(inst_opcode_34 == `ysyx_22040365_INST_MULHSU)||(inst_opcode_34 == `ysyx_22040365_INST_MULHU) 
||(inst_opcode_34==`ysyx_22040365_INST_MULW));

assign  sl_type  = ( (inst_opcode_34==`ysyx_22040365_INST_SLL)||(inst_opcode_34==`ysyx_22040365_INST_SLLI)
||(inst_opcode_34==`ysyx_22040365_INST_SLLW)||(inst_opcode_34==`ysyx_22040365_INST_SLLIW)
);
assign  sr_type  = ( (inst_opcode_34==`ysyx_22040365_INST_SRLI)||(inst_opcode_34==`ysyx_22040365_INST_SRLIW)
||(inst_opcode_34==`ysyx_22040365_INST_SRAI)||(inst_opcode_34==`ysyx_22040365_INST_SRAIW)
||(inst_opcode_34==`ysyx_22040365_INST_SRAW)||(inst_opcode_34==`ysyx_22040365_INST_SRLW)
||(inst_opcode_34==`ysyx_22040365_INST_SRA)||(inst_opcode_34==`ysyx_22040365_INST_SRL)
);
assign  xor_type = ( (inst_opcode_34==`ysyx_22040365_INST_XOR)||(inst_opcode_34==`ysyx_22040365_INST_XORI)
);
assign  or_type  = ( (inst_opcode_34==`ysyx_22040365_INST_OR)||(inst_opcode_34==`ysyx_22040365_INST_ORI)
);
assign  and_type = ( (inst_opcode_34==`ysyx_22040365_INST_AND)||(inst_opcode_34==`ysyx_22040365_INST_ANDI)
);
assign  set_type = ( (inst_opcode_34==`ysyx_22040365_INST_SLTI)||(inst_opcode_34==`ysyx_22040365_INST_SLTIU)
||(inst_opcode_34==`ysyx_22040365_INST_SLT)||(inst_opcode_34==`ysyx_22040365_INST_SLTU)
);
//always@(posedge clk)begin
always@(*)begin  
  if( (rst == 1'b1) || (pc_reset == 1'b1) )begin
        op_type_45  = 4'b1111;
  end
  else if(sum_type)begin
        op_type_45  = `ysyx_22040365_INST_ADD_SUB;
  end
  else if(mul_type)begin
         op_type_45 = `ysyx_22040365_INST_MUL_TYPE;
  end
  else if(div_type)begin
         op_type_45 = `ysyx_22040365_INST_DIV_REM;
  end
  else if(sl_type)begin
         op_type_45 = `ysyx_22040365_INST_SHAMT_LEFT;
  end
  else if(sr_type)begin
         op_type_45 = `ysyx_22040365_INST_SHAMT_RIGHT;
  end
  else if(xor_type)begin
         op_type_45 = `ysyx_22040365_INST_LOGIC_XOR;
  end
  else if(or_type)begin
         op_type_45 = `ysyx_22040365_INST_LOGIC_OR;
  end
  else if(and_type)begin
         op_type_45 = `ysyx_22040365_INST_LOGIC_AND;
  end
  else if(set_type)begin
         op_type_45 = `ysyx_22040365_INST_SET;
  end
  else begin
         op_type_45 = 4'b1111;  
  end
end
//******************generate operation type(end)****************//

//******************generate operation bit(start)****************//
wire bit_w_temp = ( (inst_opcode_34==`ysyx_22040365_INST_ADDIW)||(inst_opcode_34==`ysyx_22040365_INST_ADDW)
||(inst_opcode_34==`ysyx_22040365_INST_SUBW)||(inst_opcode_34==`ysyx_22040365_INST_SRLIW)
||(inst_opcode_34==`ysyx_22040365_INST_SRAW)||(inst_opcode_34==`ysyx_22040365_INST_SRAIW)
||(inst_opcode_34==`ysyx_22040365_INST_SRLW)||(inst_opcode_34==`ysyx_22040365_INST_SLLW)
||(inst_opcode_34==`ysyx_22040365_INST_SLLIW)||(inst_opcode_34==`ysyx_22040365_INST_MULW)
||(inst_opcode_34==`ysyx_22040365_INST_DIVW)||(inst_opcode_34==`ysyx_22040365_INST_DIVUW)
||(inst_opcode_34==`ysyx_22040365_INST_REMW)||(inst_opcode_34==`ysyx_22040365_INST_REMUW)
);
//always@(posedge clk)begin
always@(*)begin  
    bit_w = bit_w_temp;
end
//******************generate operation bit(end)****************//
//just pipeline
//always@(posedge clk)begin
always@(*)begin 
  if( (rst == 1'b1) || (pc_reset == 1'b1) )begin
        inst_opcode_45  =      8'd0;
        rd_en_45        =      1'b0;     
        rd_addr_45      =      5'd0;     
        inst_45         =      32'd0;
        pc_45           =      `ysyx_22040365_ZERO_WORD;   
        inst_type_45    =      7'd0;
  end
  else begin
        inst_opcode_45  =      inst_opcode_34;
        rd_en_45        =      rd_en_34;     
        rd_addr_45      =      rd_addr_34;     
        inst_45         =      inst_34;
        pc_45           =      pc_34;
        inst_type_45    =      inst_type_34;
  end
end

endmodule
