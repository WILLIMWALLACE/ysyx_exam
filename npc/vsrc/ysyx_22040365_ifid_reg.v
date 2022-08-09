`include "ysyx_22040365_defines.v"

module ysyx_22040365_ifid_reg( 
  input                               rst,
  input                               clk,
  input                               B_flush,//change from pc_reset
  input                               if_flush,
  input                               stall_mem_ex,
  input  [`ysyx_22040365_REG_BUS]     pc_12,
  input  [31 : 0] 	                  inst_12,
  //source 1  low bit    to reg
  output reg	                        rs1_en_23,
  output reg [4 : 0]                  rs1_addr_23,
  //source 2  high bit   to reg
  output reg	                        rs2_en_23,
  output reg [4 : 0]                  rs2_addr_23,
  //reg destination for pipeline
  output reg	                        rd_en_23,
  output reg [4 : 0]                  rd_addr_23,
  //immediate num
  output reg [`ysyx_22040365_REG_BUS] imm_23,
  //just pipeline
  output reg [`ysyx_22040365_REG_BUS]	pc_23,
  output reg [31 : 0]	                inst_23,
  //decode instruction                
  output reg [7 : 0]                  inst_opcode_23,
  output reg [6 : 0]                  inst_type_23
);

//control signal // collect all the flush operation 
wire    pc_reset;
assign  pc_reset = B_flush||if_flush;
//decode the instruction
//general decode
wire [7  : 0]inst_opcode; // for output temp
wire [6  : 0]opcode;
wire [4  : 0]rd;
wire [2  : 0]func3;
wire [4  : 0]rs1;
wire [4  : 0]rs2;
wire [6  : 0]func7;  
wire [6  : 0]inst_type;
 
assign opcode    = inst_12[6  :  0];
assign rd        = inst_12[11 :  7];
assign func3     = inst_12[14 : 12];
assign rs1       = inst_12[19 : 15];
assign rs2       = inst_12[24 : 20];
assign func7     = inst_12[31 : 25];
assign inst_type = {1'b0, S_type, U_type, J_type, B_type, R_type, I_type}; 
//immediate num for all type decode
wire [`ysyx_22040365_REG_BUS]  immI; 
wire [`ysyx_22040365_REG_BUS]  immB;
wire [`ysyx_22040365_REG_BUS]  immU;
wire [`ysyx_22040365_REG_BUS]  immS;
wire [`ysyx_22040365_REG_BUS]  immJ;

assign immI =( (rst == 1'b1) || (pc_reset == 1'b1) ) ? 0 :(  { {52{inst_12[31]}}, inst_12[31:20]} );
assign immB =( (rst == 1'b1) || (pc_reset == 1'b1) ) ? 0 :(  { {52{inst_12[31]}}, inst_12[7], inst_12[30:25], inst_12[11:8], 1'b0});
assign immU =( (rst == 1'b1) || (pc_reset == 1'b1) ) ? 0 :(  { {33{inst_12[31]}}, inst_12[30:20], inst_12[19:12], {12{1'b0}} });
assign immS =( (rst == 1'b1) || (pc_reset == 1'b1) ) ? 0 :(  { {53{inst_12[31]}}, inst_12[30:25], inst_12[11:7] });
assign immJ =( (rst == 1'b1) || (pc_reset == 1'b1) ) ? 0 :(  { {44{inst_12[31]}}, inst_12[19:12], inst_12[20], inst_12[30:25], inst_12[24:21], 1'b0});

//just pipe line ///all types are valid 
always@(posedge clk) begin
  if(rst || pc_reset)begin
    rs1_addr_23     <= 5'd0;
    rs2_addr_23     <= 5'd0;
    rd_addr_23      <= 5'd0;
    pc_23           <= 64'd0;
    inst_23         <= 32'd0;
    inst_opcode_23  <= 8'd0;
    inst_type_23    <= 7'd0;
  end
  else if(stall_mem_ex)begin
    rs1_addr_23     <= rs1_addr_23   ;
    rs2_addr_23     <= rs2_addr_23   ;
    rd_addr_23      <= rd_addr_23    ;
    pc_23           <= pc_23         ;
    inst_23         <= inst_23       ;
    inst_opcode_23  <= inst_opcode_23;
    inst_type_23    <= inst_type_23  ;
  end
  else begin
    rs1_addr_23     <= rs1;
    rs2_addr_23     <= rs2;
    rd_addr_23      <= rd;
    pc_23           <= pc_12;
    inst_23         <= inst_12;
    inst_opcode_23  <= inst_opcode;
    inst_type_23    <= inst_type;
  end
end

//choose enable signal according to inst_type
always@(posedge clk) begin
  if(rst || pc_reset) begin
    rs1_en_23       <= 1'b0;
    rs2_en_23       <= 1'b0;
    rd_en_23        <= 1'b0;
    imm_23          <= 64'd0;
  end
  else if(stall_mem_ex)begin
    rs1_en_23       <= rs1_en_23 ;
    rs2_en_23       <= rs2_en_23 ;
    rd_en_23        <= rd_en_23  ;
    imm_23          <= imm_23    ;
  end
  else begin
  case (inst_type)
//{1'b0, S_type, U_type, J_type, B_type, R_type, I_type};     
  7'b0000001: begin //I_tupe
    rs1_en_23       <= 1'b1;
    rs2_en_23       <= 1'b0;
    rd_en_23        <= 1'b1;
    imm_23          <= immI;
  end
   7'b0000010: begin //R_tupe
    rs1_en_23       <= 1'b1;
    rs2_en_23       <= 1'b1;
    rd_en_23        <= 1'b1;
    imm_23          <= 64'd0;
  end
   7'b0000100: begin //B_tupe
    rs1_en_23       <= 1'b1;
    rs2_en_23       <= 1'b1;
    rd_en_23        <= 1'b0;
    imm_23          <= immB;
  end
  7'b0001000: begin //J_tupe
    rs1_en_23       <= 1'b0;
    rs2_en_23       <= 1'b0;
    rd_en_23        <= 1'b1;
    imm_23          <= immJ;
  end
  7'b0010000: begin //U_tupe
    rs1_en_23       <= 1'b0;
    rs2_en_23       <= 1'b0;
    rd_en_23        <= 1'b1;
    imm_23          <= immU;
  end
  7'b0100000: begin //S_tupe
    rs1_en_23       <= 1'b1;
    rs2_en_23       <= 1'b1;
    rd_en_23        <= 1'b0;
    imm_23          <= immS;
  end
  default: begin  
    rs1_en_23       <= 1'b0;
    rs2_en_23       <= 1'b0;
    rd_en_23        <= 1'b0;
    imm_23          <= 64'd0;
  end
  endcase
  end
end
   
//generate inst_opcode-->true single instruction-->define by defines.v
assign inst_opcode[0] = (inst_addi||inst_addiw||inst_bne ||inst_auipc||inst_addw||inst_and  ||inst_bge ||inst_blt||inst_jalr||inst_or   ||inst_slliw
||inst_sll||inst_slti||inst_sltu||inst_sraiw||inst_sraw||inst_srliw||inst_srlw||inst_xor||inst_ld||inst_lbu||inst_lhu||inst_lwu||inst_sw||inst_sb
||inst_mulh||inst_mulhsu||inst_div||inst_rem||inst_divw||inst_remw) ;

assign inst_opcode[1] = (inst_lui ||inst_addiw||inst_jal ||inst_auipc||inst_andi||inst_and  ||inst_bgeu||inst_blt||inst_sub ||inst_or   ||inst_sllw
||inst_sll||inst_sltiu||inst_sltu||inst_sra||inst_sraw||inst_srl||inst_srlw||inst_xori||inst_ld||inst_lh ||inst_lhu  ||inst_sd||inst_sw ||inst_mul
||inst_mulh||inst_mulw||inst_div ||inst_remu||inst_divw||inst_remuw) ;

assign inst_opcode[2] = (inst_slli||inst_bne  ||inst_jal ||inst_auipc||inst_beq ||inst_bge  ||inst_bgeu||inst_blt||inst_ori ||inst_slliw||inst_sllw
||inst_sll||inst_srai||inst_sraiw||inst_sra||inst_sraw||inst_subw||inst_xor||inst_xori||inst_ld||inst_lw||inst_lwu ||inst_sd||inst_sw
||inst_mulhu||inst_mulhsu||inst_mulw||inst_div||inst_divuw||inst_remw||inst_remuw) ;

assign inst_opcode[3] = (inst_add ||inst_addw ||inst_andi||inst_and  ||inst_beq ||inst_bge  ||inst_bgeu||inst_blt||inst_slt ||inst_slti ||inst_sltiu
||inst_sltu||inst_srai||inst_sraiw||inst_sra||inst_sraw||inst_lb||inst_lbu||inst_lh||inst_lhu ||inst_lw||inst_lwu||inst_sd||inst_sw ||inst_divu
||inst_rem ||inst_remu||inst_divw||inst_divuw||inst_remw||inst_remuw) ;

assign inst_opcode[4] = (inst_bltu||inst_jalr ||inst_sub ||inst_or   ||inst_ori ||inst_slliw||inst_sllw||inst_sll||inst_slt ||inst_slti ||inst_sltiu
||inst_sltu||inst_srai||inst_sraiw||inst_sra||inst_sraw||inst_sh||inst_sb||inst_mul||inst_mulh||inst_mulhu||inst_mulhsu||inst_mulw||inst_div||inst_divu
||inst_rem ||inst_remu||inst_divw||inst_divuw||inst_remw||inst_remuw);

assign inst_opcode[5] = (inst_srli||inst_srliw||inst_srl ||inst_srlw ||inst_subw||inst_xor  ||inst_xori||inst_ld ||inst_lb  ||inst_lbu||inst_lh
||inst_lhu||inst_lw||inst_lwu||inst_sd||inst_sw||inst_sh||inst_sb ||inst_mul||inst_mulh||inst_mulhu||inst_mulhsu ||inst_mulw||inst_div||inst_divu
||inst_rem||inst_remu||inst_divw||inst_divuw||inst_remw||inst_remuw);

assign inst_opcode[6] =  0;
assign inst_opcode[7] =  0;
//decode type 
wire U_type   =  (inst_auipc | inst_lui);
wire I_type   =  (inst_addi  | inst_addiw | inst_srli | inst_srliw | inst_srai | inst_sraiw | inst_slli | inst_slliw | inst_xori | inst_ori | inst_andi
                 | inst_slti | inst_sltiu | inst_jalr | inst_lhu | inst_lh | inst_lbu | inst_lb | inst_lw | inst_lwu | inst_ld);
wire B_type   =  (inst_beq | inst_bne | inst_bge | inst_bgeu | inst_blt | inst_bltu);
wire J_type   =  (inst_jal);
//mul div rem not immplement///////////////
wire R_type   =  (inst_add | inst_addw | inst_sub | inst_subw | inst_sraw | inst_srlw | inst_sll | inst_sllw | inst_xor | inst_or | inst_and | inst_sltu
                | inst_slt | inst_srl  | inst_sra | inst_mul  | inst_mulh | inst_mulhu| inst_mulhsu|inst_mulw|inst_div  |inst_divu| inst_rem | inst_remu
                | inst_divw| inst_divuw| inst_remw| inst_remuw);
wire S_type   =  (inst_sd | inst_sw | inst_sb | inst_sh);

//decode one bit instruction from opcode & fun3
wire  inst_ld =    ~opcode[2] & ~opcode[3] & ~opcode[4] & ~opcode[5] & ~opcode[6]
                 & func3[0] & func3[1] & ~func3[2];

wire inst_addi   =   ~opcode[2] & ~opcode[3] & opcode[4] & ~opcode[5] & ~opcode[6]
                 & ~func3[0] & ~func3[1] & ~func3[2];

wire  inst_ld    =    ~opcode[2] & ~opcode[3] & ~opcode[4] & ~opcode[5] & ~opcode[6]
		             & func3[0] & func3[1] & ~func3[2];

wire  inst_lui   =    opcode[2] & ~opcode[3] & opcode[4] & opcode[5] & ~opcode[6] ;

wire  inst_addiw =    ~opcode[2] & opcode[3] & opcode[4] & ~opcode[5] & ~opcode[6]
                 & ~func3[0] & ~func3[1] & ~func3[2];

wire  inst_slli  =    ~opcode[2] & ~opcode[3] & opcode[4] & ~opcode[5] & ~opcode[6]
                 & func3[0] & ~func3[1] & ~func3[2]
                 & ~func7[1] & ~func7[2]& ~func7[3]& ~func7[4]& ~func7[5]& ~func7[6];

wire  inst_bne   =    ~opcode[2] & ~opcode[3] & ~opcode[4] & opcode[5] & opcode[6]
                 & func3[0] & ~func3[1] & ~func3[2];

wire  inst_jal	 =     opcode[2] & opcode[3] & ~opcode[4] & opcode[5] & opcode[6] ;

wire  inst_auipc =    opcode[2] & ~opcode[3] & opcode[4] & ~opcode[5] & ~opcode[6] ;

wire  inst_add   =   ~opcode[2] & ~opcode[3] & opcode[4] & opcode[5] & ~opcode[6]
                 & ~func3[0] & ~func3[1] & ~func3[2] 
                 & ~func7[0] & ~func7[1] & ~func7[2]& ~func7[3]& ~func7[4]& ~func7[5]& ~func7[6];

wire  inst_addw  =   ~opcode[2] & opcode[3] & opcode[4] & opcode[5] & ~opcode[6]
                 & ~func3[0] & ~func3[1] & ~func3[2]     
                 & ~func7[0] & ~func7[1] & ~func7[2]& ~func7[3]& ~func7[4]& ~func7[5]& ~func7[6];

wire  inst_andi  =   ~opcode[2] & ~opcode[3] & opcode[4] & ~opcode[5] & ~opcode[6]
                 & func3[0] & func3[1] & func3[2];

wire  inst_and   =   ~opcode[2] & ~opcode[3] & opcode[4] &  opcode[5] & ~opcode[6]
                 & func3[0] & func3[1] & func3[2]
                 & ~func7[0] & ~func7[1] & ~func7[2]& ~func7[3]& ~func7[4]& ~func7[5]& ~func7[6];

wire  inst_beq   =  ~opcode[2] & ~opcode[3] & ~opcode[4] &  opcode[5] & opcode[6]
                 & ~func3[0] & ~func3[1] & ~func3[2];

wire  inst_bge   =  ~opcode[2] & ~opcode[3] & ~opcode[4] &  opcode[5] & opcode[6]
                 & func3[0] & ~func3[1] & func3[2];

wire  inst_bgeu  =  ~opcode[2] & ~opcode[3] & ~opcode[4] &  opcode[5] & opcode[6]
                 & func3[0] & func3[1] & func3[2];

wire  inst_blt   =  ~opcode[2] & ~opcode[3] & ~opcode[4] &  opcode[5] & opcode[6]
                 & ~func3[0] & ~func3[1] & func3[2];

wire  inst_bltu  =  ~opcode[2] & ~opcode[3] & ~opcode[4] &  opcode[5] & opcode[6]
                 & ~func3[0] & func3[1] & func3[2];

wire  inst_jalr  =  opcode[2] & ~opcode[3] & ~opcode[4] &  opcode[5] & opcode[6]
                 & ~func3[0] & ~func3[1] & ~func3[2];

wire  inst_sub   =  ~opcode[2] & ~opcode[3] & opcode[4] &  opcode[5] & ~opcode[6]
                 & ~func3[0] & ~func3[1] & ~func3[2]      
                 & ~func7[0] & ~func7[1] & ~func7[2]& ~func7[3]& ~func7[4]& func7[5]& ~func7[6];

wire  inst_or    =  ~opcode[2] & ~opcode[3] & opcode[4] &  opcode[5] & ~opcode[6]
                 & ~func3[0] & func3[1] & func3[2]   
                 & ~func7[0] & ~func7[1] & ~func7[2]& ~func7[3]& ~func7[4]& ~func7[5]& ~func7[6];

wire  inst_ori   =  ~opcode[2] & ~opcode[3] & opcode[4] &  ~opcode[5] & ~opcode[6]
                 & ~func3[0] & func3[1] & func3[2]        ;

wire  inst_slliw =  ~opcode[2] & opcode[3] & opcode[4] &  ~opcode[5] & ~opcode[6]
                 & func3[0] & ~func3[1] & ~func3[2]       
                 & ~func7[0] & ~func7[1] & ~func7[2]& ~func7[3]& ~func7[4]& ~func7[5]& ~func7[6];

wire  inst_sllw  =  ~opcode[2] & opcode[3] & opcode[4] &  opcode[5] & ~opcode[6]
                 & func3[0] & ~func3[1] & ~func3[2]        
                 & ~func7[0] & ~func7[1] & ~func7[2]& ~func7[3]& ~func7[4]& ~func7[5]& ~func7[6];

wire  inst_sll  =  ~opcode[2] & ~opcode[3] & opcode[4] &  opcode[5] & ~opcode[6]
                 & func3[0] & ~func3[1] & ~func3[2]        
                 & ~func7[0] & ~func7[1] & ~func7[2]& ~func7[3]& ~func7[4]& ~func7[5]& ~func7[6];

wire  inst_slt  =  ~opcode[2] & ~opcode[3] & opcode[4] &  opcode[5] & ~opcode[6]
                 & ~func3[0] & func3[1] & ~func3[2]        
                 & ~func7[0] & ~func7[1] & ~func7[2]& ~func7[3]& ~func7[4]& ~func7[5]& ~func7[6];

wire  inst_slti =  ~opcode[2] & ~opcode[3] & opcode[4] &  ~opcode[5] & ~opcode[6]
                 & ~func3[0] & func3[1] & ~func3[2]        ;

wire  inst_sltiu=  ~opcode[2] & ~opcode[3] & opcode[4] &  ~opcode[5] & ~opcode[6]
                 & func3[0] & func3[1] & ~func3[2]        ;

wire  inst_sltu =  ~opcode[2] & ~opcode[3] & opcode[4] &  opcode[5] & ~opcode[6]
                 & func3[0] & func3[1] & ~func3[2]        
                 & ~func7[0] & ~func7[1] & ~func7[2]& ~func7[3]& ~func7[4]& ~func7[5]& ~func7[6];

wire  inst_srai =  ~opcode[2] & ~opcode[3] & opcode[4] &  ~opcode[5] & ~opcode[6]
                 & func3[0] & ~func3[1] & func3[2] 
                 & ~func7[1] & ~func7[2]& ~func7[3]& ~func7[4]& func7[5]& ~func7[6];

wire  inst_sraiw =  ~opcode[2] & opcode[3] & opcode[4] &  ~opcode[5] & ~opcode[6]
                 & func3[0] & ~func3[1] & func3[2]
                 & ~func7[0] & ~func7[1] & ~func7[2]& ~func7[3]& ~func7[4]& func7[5]& ~func7[6];

wire  inst_sra   =  ~opcode[2] & ~opcode[3] & opcode[4] &  opcode[5] & ~opcode[6]
                 & func3[0] & ~func3[1] & func3[2] & inst_12[30]       ;

wire  inst_sraw  =  ~opcode[2] & opcode[3] & opcode[4] &  opcode[5] & ~opcode[6]
                 & func3[0] & ~func3[1] & func3[2]
                 & ~func7[0]&~func7[1] & ~func7[2]& ~func7[3]& ~func7[4]& func7[5]& ~func7[6];

wire  inst_srli  =  ~opcode[2] & ~opcode[3] & opcode[4] &  ~opcode[5] & ~opcode[6]
                 & func3[0] & ~func3[1] & func3[2] 
                 & ~func7[1] & ~func7[2]& ~func7[3]& ~func7[4]& ~func7[5]& ~func7[6];

wire  inst_srliw =  ~opcode[2] & opcode[3] & opcode[4] &  ~opcode[5] & ~opcode[6]
                 & func3[0] & ~func3[1] & func3[2] 
                 & ~func7[0]& ~func7[1] & ~func7[2]& ~func7[3]& ~func7[4]& ~func7[5]& ~func7[6];
wire  inst_srl   =  ~opcode[2] & ~opcode[3] & opcode[4] &  opcode[5] & ~opcode[6]
                 & func3[0] & ~func3[1] & func3[2] & ~inst_12[30]       ;

wire  inst_srlw  =  ~opcode[2] & opcode[3] & opcode[4] &  opcode[5] & ~opcode[6]
                 & func3[0] & ~func3[1] & func3[2]
                 & ~func7[0]& ~func7[1] & ~func7[2]& ~func7[3]& ~func7[4]& ~func7[5]& ~func7[6];

wire  inst_subw  =  ~opcode[2] & opcode[3] & opcode[4] &  opcode[5] & ~opcode[6]
                 & ~func3[0] & ~func3[1] & ~func3[2]    
                 & ~func7[0] & ~func7[1] & ~func7[2]& ~func7[3]& ~func7[4]& func7[5]& ~func7[6];

wire  inst_xor  =  ~opcode[2] & ~opcode[3] & opcode[4] &  opcode[5] & ~opcode[6]
                 & ~func3[0] & ~func3[1] & func3[2] 
                 & ~func7[0] & ~func7[1] & ~func7[2]& ~func7[3]& ~func7[4]& ~func7[5]& ~func7[6];

wire  inst_xori =  ~opcode[2] & ~opcode[3] & opcode[4] &  ~opcode[5] & ~opcode[6]
                 & ~func3[0] & ~func3[1] & func3[2]     ;

wire  inst_ld =  ~opcode[2] & ~opcode[3] & ~opcode[4] &  ~opcode[5] & ~opcode[6]
                 & func3[0] & func3[1] & ~func3[2]     ;

wire  inst_lb =  ~opcode[2] & ~opcode[3] & ~opcode[4] &  ~opcode[5] & ~opcode[6]
                 & ~func3[0] & ~func3[1] & ~func3[2]     ;

wire  inst_lbu =  ~opcode[2] & ~opcode[3] & ~opcode[4] &  ~opcode[5] & ~opcode[6]
                 & ~func3[0] & ~func3[1] & func3[2]     ;

wire  inst_lh =  ~opcode[2] & ~opcode[3] & ~opcode[4] &  ~opcode[5] & ~opcode[6]
                 & func3[0] & ~func3[1] & ~func3[2]     ;

wire  inst_lhu =  ~opcode[2] & ~opcode[3] & ~opcode[4] &  ~opcode[5] & ~opcode[6]
                 & func3[0] & ~func3[1] & func3[2]     ;

wire  inst_lw =  ~opcode[2] & ~opcode[3] & ~opcode[4] &  ~opcode[5] & ~opcode[6]
                 & ~func3[0] & func3[1] & ~func3[2]     ;

wire  inst_lwu =  ~opcode[2] & ~opcode[3] & ~opcode[4] &  ~opcode[5] & ~opcode[6]
                 & ~func3[0] & func3[1] & func3[2]     ;

wire  inst_sd =  ~opcode[2] & ~opcode[3] & ~opcode[4] &  opcode[5] & ~opcode[6]
                 & func3[0] & func3[1] & ~func3[2]     ;

wire  inst_sw =  ~opcode[2] & ~opcode[3] & ~opcode[4] &  opcode[5] & ~opcode[6]
                 & ~func3[0] & func3[1] & ~func3[2]     ;

wire  inst_sh =  ~opcode[2] & ~opcode[3] & ~opcode[4] &  opcode[5] & ~opcode[6]
                 & func3[0] & ~func3[1] & ~func3[2]     ;

wire  inst_sb =  ~opcode[2] & ~opcode[3] & ~opcode[4] &  opcode[5] & ~opcode[6]
                 & ~func3[0] & ~func3[1] & ~func3[2]     ;

wire  inst_mul=  ~opcode[2] & ~opcode[3] & opcode[4] &  opcode[5] & ~opcode[6]
                 & ~func3[0] & ~func3[1] & ~func3[2]     
                 & func7[0]  & ~func7[1] & ~func7[2]& ~func7[3]& ~func7[4]& ~func7[5]& ~func7[6];

wire  inst_mulh= ~opcode[2] & ~opcode[3] & opcode[4] &  opcode[5] & ~opcode[6]
                 & func3[0] & ~func3[1] & ~func3[2]     
                 & func7[0]  & ~func7[1] & ~func7[2]& ~func7[3]& ~func7[4]& ~func7[5]& ~func7[6];

wire  inst_mulhu= ~opcode[2] & ~opcode[3] & opcode[4] &  opcode[5] & ~opcode[6]
                 & func3[0] & func3[1] & ~func3[2]     
                 & func7[0]  & ~func7[1] & ~func7[2]& ~func7[3]& ~func7[4]& ~func7[5]& ~func7[6];                 

wire  inst_mulhsu= ~opcode[2] & ~opcode[3] & opcode[4] &  opcode[5] & ~opcode[6]
                 & ~func3[0] & func3[1] & ~func3[2]     
                 & func7[0]  & ~func7[1] & ~func7[2]& ~func7[3]& ~func7[4]& ~func7[5]& ~func7[6];

wire  inst_mulw= ~opcode[2] & opcode[3] & opcode[4] &  opcode[5] & ~opcode[6]
                 & func3[0] & func3[1]  & func3[2]     
                 & func7[0] & ~func7[1] & ~func7[2]& ~func7[3]& ~func7[4]& ~func7[5]& ~func7[6];

wire  inst_div = ~opcode[2] & ~opcode[3] & opcode[4] &  opcode[5] & ~opcode[6]
                 & ~func3[0] & ~func3[1]  & func3[2]     
                 & func7[0] & ~func7[1] & ~func7[2]& ~func7[3]& ~func7[4]& ~func7[5]& ~func7[6];

wire  inst_divu = ~opcode[2] & ~opcode[3] & opcode[4] &  opcode[5] & ~opcode[6]
                 & func3[0]  & ~func3[1]  & func3[2]     
                 & func7[0] & ~func7[1] & ~func7[2]& ~func7[3]& ~func7[4]& ~func7[5]& ~func7[6];

wire  inst_rem  = ~opcode[2] & ~opcode[3] & opcode[4] &  opcode[5] & ~opcode[6]
                 & ~func3[0]  & func3[1]  & func3[2]     
                 & func7[0] & ~func7[1] & ~func7[2]& ~func7[3]& ~func7[4]& ~func7[5]& ~func7[6];

wire  inst_remu= ~opcode[2] & ~opcode[3] & opcode[4] &  opcode[5] & ~opcode[6]
                 & func3[0] & func3[1]  & func3[2]     
                 & func7[0] & ~func7[1] & ~func7[2]& ~func7[3]& ~func7[4]& ~func7[5]& ~func7[6];

wire  inst_divw= ~opcode[2] & opcode[3] & opcode[4] &  opcode[5] & ~opcode[6]
                 & ~func3[0]  & ~func3[1]  & func3[2]     
                 & func7[0] & ~func7[1] & ~func7[2]& ~func7[3]& ~func7[4]& ~func7[5]& ~func7[6];

wire  inst_divuw= ~opcode[2] & opcode[3] & opcode[4] &  opcode[5] & ~opcode[6]
                 & func3[0] & ~func3[1] & func3[2]     
                 & func7[0] & ~func7[1] & ~func7[2]& ~func7[3]& ~func7[4]& ~func7[5]& ~func7[6];

wire  inst_remw = ~opcode[2] & opcode[3] & opcode[4] &  opcode[5] & ~opcode[6]
                 & ~func3[0] & func3[1]  & func3[2]     
                 & func7[0] & ~func7[1] & ~func7[2]& ~func7[3]& ~func7[4]& ~func7[5]& ~func7[6];

wire  inst_remuw= ~opcode[2] & opcode[3] & opcode[4] &  opcode[5] & ~opcode[6]
                 & func3[0]  & func3[1]  & func3[2]     
                 & func7[0] & ~func7[1] & ~func7[2]& ~func7[3]& ~func7[4]& ~func7[5]& ~func7[6];

endmodule