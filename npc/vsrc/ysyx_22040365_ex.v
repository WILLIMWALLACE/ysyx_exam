`include "ysyx_22040365_defines.v"
module ysyx_22040365_ex(
  input                               rst,
  input                               clk,
  input                               stall_mem_ex,
  input                               stall_mem_ex1,

  input  [3 : 0]                      op_type_45,
  input  [`ysyx_22040365_REG_BUS]     op1_45,
  input  [`ysyx_22040365_REG_BUS]     op2_45,
  input  [`ysyx_22040365_REG_BUS]     op3_45,
  input                               bit_w,
  input  [6 : 0]                      inst_type_45,
  //input pipelin signal
  input  [7 : 0]                      inst_opcode_45,
  input                               rd_en_45,
  input  [4 : 0]                      rd_addr_45,       
  input  [31: 0]                      inst_45,
  input  [`ysyx_22040365_REG_BUS]     pc_45,
  //output  pipeline signal
  output reg [7 : 0]                  inst_opcode_56,
  output reg                          rd_en_56,
  output reg [4 : 0]                  rd_addr_56,       
  output reg [31: 0]                  inst_56,
  output reg [`ysyx_22040365_REG_BUS] pc_56,
  //generate result & memory operation num/type
  output reg [`ysyx_22040365_REG_BUS] ex_data_56,
  output reg [`ysyx_22040365_REG_BUS] store_data_56,                      
  //output reg [ : ]                    op_type_56,
  //for jump or branch instruction to change next pc
  output reg                          B_flush,
  output reg [`ysyx_22040365_REG_BUS] pc_change  
);

//for (op2)shamt operation num
wire   [5 : 0]                  shamt;
wire   [`ysyx_22040365_REG_BUS] op1_shamt;
assign shamt = (bit_w==1'b0) ? op2_45[5:0] : {1'b0,op2_45[4:0]};
assign op1_shamt  =  (bit_w==1'b0) ? op1_45[63:0] : op1_45[31:0];
//for logic // arithmetic shamt 
wire   logic_shamt  = ( (inst_opcode_45==`ysyx_22040365_INST_SRLI)||(inst_opcode_45==`ysyx_22040365_INST_SRLIW)
                    ||(inst_opcode_45==`ysyx_22040365_INST_SRLW)||(inst_opcode_45==`ysyx_22040365_INST_SRL));
wire   arithmetic_w = ( (inst_opcode_45==`ysyx_22040365_INST_SRAIW)||(inst_opcode_45==`ysyx_22040365_INST_SRAW));

//pre judge the set type instruction
wire   set_valid;
wire   slti_valid,sltiu_valid;
assign slti_valid = ((inst_opcode_45 == `ysyx_22040365_INST_SLTI)||(inst_opcode_45 == `ysyx_22040365_INST_SLT))  ? ( ($signed(op1_45) ) < ($signed(op2_45))  ) : 1'b0;
assign sltiu_valid= ((inst_opcode_45 == `ysyx_22040365_INST_SLTIU)||(inst_opcode_45 == `ysyx_22040365_INST_SLTU)) ? ( (op1_45 < op2_45 )  ) : 1'b0;
assign set_valid  = slti_valid || sltiu_valid;

//128bit mul instruciton
wire [127 : 0]                  extend_data;
wire [`ysyx_22040365_REG_BUS]   mul_temp; 
wire [`ysyx_22040365_REG_BUS]   div_temp;
wire [`ysyx_22040365_REG_BUS]   rem_temp;//temporary operation 
wire [`ysyx_22040365_REG_BUS]   MDR_op1_su;
wire [`ysyx_22040365_REG_BUS]   MDR_op2_su;
wire [`ysyx_22040365_REG_BUS]   MDR_op1;
wire [`ysyx_22040365_REG_BUS]   MDR_op2;
wire extend_valid;
wire div_valid;

assign div_valid   =( (inst_opcode_45==`ysyx_22040365_INST_DIV)||(inst_opcode_45==`ysyx_22040365_INST_DIVU)
||(inst_opcode_45==`ysyx_22040365_INST_DIVW)||(inst_opcode_45==`ysyx_22040365_INST_DIVUW)
);

assign MDR_op1_su  = ((inst_opcode_45 == `ysyx_22040365_INST_MUL)||(inst_opcode_45 == `ysyx_22040365_INST_MULH)
||(inst_opcode_45 == `ysyx_22040365_INST_MULHSU)||(inst_opcode_45==`ysyx_22040365_INST_DIV)||(inst_opcode_45 == `ysyx_22040365_INST_REM)
||(inst_opcode_45 ==`ysyx_22040365_INST_DIVW)||(inst_opcode_45 ==`ysyx_22040365_INST_REMW)) 
? ($signed(op1_45)) : op1_45;

assign MDR_op2_su  = ((inst_opcode_45 == `ysyx_22040365_INST_MUL)||(inst_opcode_45 == `ysyx_22040365_INST_MULH)
||(inst_opcode_45==`ysyx_22040365_INST_DIV)||(inst_opcode_45 == `ysyx_22040365_INST_REM)
||(inst_opcode_45 ==`ysyx_22040365_INST_DIVW)||(inst_opcode_45 ==`ysyx_22040365_INST_REMW))
? ($signed(op2_45)) : op2_45;

assign MDR_op1 = (bit_w==1'b1) ? (MDR_op1_su[31:0]) : MDR_op1_su;
assign MDR_op2 = (bit_w==1'b1) ? (MDR_op2_su[31:0]) : MDR_op2_su;

assign extend_valid= ( (inst_opcode_45 == `ysyx_22040365_INST_MULH)||(inst_opcode_45 == `ysyx_22040365_INST_MULHU)||(inst_opcode_45 == `ysyx_22040365_INST_MULHSU));
assign extend_data = (extend_valid==1'b1) ? (MDR_op1*MDR_op2) : (128'd0);

assign mul_temp    = (extend_valid==1'b1) ? (extend_data[127:64]) : (extend_data[63:0]) ;
assign div_temp    = MDR_op1 / MDR_op2;
assign rem_temp    = MDR_op1 % MDR_op2;
//generate alu_result
//alu operation
reg    [`ysyx_22040365_REG_BUS]  ex_data_temp;//alu_result
wire   [`ysyx_22040365_REG_BUS]  alu_result;
assign  alu_result  = (bit_w==1'b1) ? {{32{ex_data_temp[31]}},ex_data_temp[31:0]} : ex_data_temp;
always@(*)begin
  if(rst)begin
    ex_data_temp  = `ysyx_22040365_ZERO_WORD;
  end
  else begin
    case(op_type_45)
    `ysyx_22040365_INST_ADD_SUB:begin
      if(inst_type_45==7'b0000100)begin//B_type,pc+imm
        ex_data_temp = pc_45  + op3_45;
      end
      else if(inst_opcode_45 == `ysyx_22040365_INST_JALR)begin//jalr
        ex_data_temp = ((op1_45+op2_45) & 64'hfffffffe);
      end
      else if(inst_type_45 == 7'b0100000)begin//S_type,op1+op3(imm)
        ex_data_temp = op1_45 + op3_45;
      end
      else begin
        ex_data_temp = op1_45 + op2_45;
      end
    end    
    `ysyx_22040365_INST_MUL_TYPE:begin
      ex_data_temp = mul_temp;
    end       
    `ysyx_22040365_INST_DIV_REM:begin
      if(div_valid)begin
      ex_data_temp = div_temp;
      end
      else begin
      ex_data_temp = rem_temp;
      end
    end           
    `ysyx_22040365_INST_SHAMT_LEFT:begin
      ex_data_temp = op1_45 << shamt;
    end        
    `ysyx_22040365_INST_SHAMT_RIGHT:begin
      if(logic_shamt)begin
        ex_data_temp = op1_shamt >> shamt;
      end
      else if(arithmetic_w)begin
         ex_data_temp = ($signed(op1_45[31:0])) >>> shamt;
      end
      else begin
         ex_data_temp = ($signed(op1_shamt)) >>> shamt;
      end
    end 
    `ysyx_22040365_INST_SET:begin
        if(set_valid)begin ex_data_temp = 64'd1;end
        else begin         ex_data_temp = 64'd0;end
    end      
    `ysyx_22040365_INST_LOGIC_XOR:begin
         ex_data_temp = op1_45 ^ op2_45;
    end         
    `ysyx_22040365_INST_LOGIC_OR:begin
         ex_data_temp = op1_45 | op2_45;
    end          
    `ysyx_22040365_INST_LOGIC_AND:begin
         ex_data_temp = op1_45 & op2_45;
    end         
    default:begin
         ex_data_temp  = `ysyx_22040365_ZERO_WORD;
    end 
    endcase      
  end
end

//B_type judge to support the branch
wire   bne_valid;
wire   beq_valid;
wire   bge_valid;
wire   bgeu_valid;
wire   blt_valid;
wire   bltu_valid;
wire   branch_valid;
assign bne_valid    = (inst_opcode_45 == `ysyx_22040365_INST_BNE)  ? ( op1_45 != op2_45 ) : 1'b0;
assign beq_valid    = (inst_opcode_45 == `ysyx_22040365_INST_BEQ)  ? ( op1_45 == op2_45 ) : 1'b0;
assign bge_valid    = (inst_opcode_45 == `ysyx_22040365_INST_BGE)  ? ( ($signed(op1_45) ) >= ($signed(op2_45))) : 1'b0;
assign bgeu_valid   = (inst_opcode_45 == `ysyx_22040365_INST_BGEU) ? ( op1_45 >= op2_45 ) : 1'b0;
assign blt_valid    = (inst_opcode_45 == `ysyx_22040365_INST_BLT)  ? ( ($signed(op1_45) ) < ($signed(op2_45))  ) : 1'b0;
assign bltu_valid   = (inst_opcode_45 == `ysyx_22040365_INST_BLTU) ? ( op1_45 < op2_45  ) : 1'b0;
assign branch_valid = (stall_mem_ex!=1'b1) ? 
                      ((bne_valid==1'b1)||(beq_valid==1'b1)
                      ||(bge_valid==1'b1)||(bgeu_valid==1'b1)
                      ||(blt_valid==1'b1)||(bltu_valid==1'b1))
                      : 1'b0;
//change the pc
wire    bj_valid;
wire    jump;
assign  jump        = ( (inst_opcode_45==`ysyx_22040365_INST_JAL)||(inst_opcode_45==`ysyx_22040365_INST_JALR) ); 
assign  bj_valid    = ( (branch_valid==1'b1)||(jump==1'b1));
//assign  B_flush     =  
//generate real result, including pc_change and memory
always@(posedge clk)begin
//always@(*)begin  
  if(rst) begin
      ex_data_56      <= `ysyx_22040365_ZERO_WORD;
      store_data_56   <= `ysyx_22040365_ZERO_WORD;
      //op_type_56     <=  'd0;
      B_flush         <= 1'b0;
      pc_change       <= `ysyx_22040365_ZERO_WORD;
  end
  else if(stall_mem_ex1&&B_flush)begin//to keep the ex_data_56!!!wait for bypass
      B_flush         <= 1'b0;
      pc_change       <= alu_result;
      ex_data_56      <= ex_data_56; //load_type + bj_type!!!
      store_data_56   <= store_data_56;
  end
  /*else if(stall_mem_ex1)begin
      B_flush         <= 1'b0;
      pc_change       <= alu_result;
      ex_data_56      <= alu_result; //normal load inst 
      store_data_56   <= store_data_56;
  end*/
  else begin
    if(bj_valid == 1'b1)begin
      B_flush         <= 1'b1;
      pc_change       <= alu_result;
      ex_data_56      <= pc_45 + 4; //for jal/r to write back
      store_data_56   <= `ysyx_22040365_ZERO_WORD;
      //op_type_56      <=  'd0;
    end
    else begin
      B_flush         <= 1'b0;
      pc_change       <= `ysyx_22040365_ZERO_WORD;
      ex_data_56      <= alu_result;
      store_data_56   <= op2_45;
    end
  end
end

//just pipeline signal
always@(posedge clk)begin
//always@(*)begin
  if(rst) begin
    inst_opcode_56  <= 8'd0;
    rd_en_56        <= 1'b0;
    rd_addr_56      <= 5'd0;
    inst_56         <= 32'd0;
    pc_56           <= `ysyx_22040365_ZERO_WORD;
  end
  else if(stall_mem_ex1)begin //normal load inst 
    inst_opcode_56  <= inst_opcode_56 ;
    rd_en_56        <= rd_en_56       ;
    rd_addr_56      <= rd_addr_56     ;
    inst_56         <= inst_56        ;
    pc_56           <= pc_56          ;
  end
  else begin
    inst_opcode_56  <= inst_opcode_45;
    rd_en_56        <= rd_en_45;
    rd_addr_56      <= rd_addr_45;
    inst_56         <= inst_45;
    pc_56           <= pc_45; 
  end
end  

endmodule

