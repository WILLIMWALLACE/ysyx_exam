`include "ysyx_22040365_defines.v"
module ysyx_22040365_cpu_top(
input                                    rst,
input                                    clk,

//output for 3rd difftest
output [`ysyx_22040365_REG_BUS]          regs_o[0:31],
output                                   B_flush,
output                                   stall_mem_ex,
output                                   stall_mem_ex1,
output                                   stall_mem_ex2,
output [`ysyx_22040365_REG_BUS]          pc_83,
output [31: 0]                           inst_83,
output                                   rd_en_83,
output [4 : 0]                           rd_addr_83,
output [`ysyx_22040365_REG_BUS]          result_83
);

////////////// Interconnection conductor///////////////////
//wire [`ysyx_22040365_REG_BUS]           regs_o[0:31];

wire [`ysyx_22040365_REG_BUS]           pc_12;
wire [31: 0]                            inst_12;

wire                                    if_flush;

wire                                    rs1_en_23;
wire [4 : 0]                            rs1_addr_23;
wire                                    rs2_en_23;
wire [4 : 0]                            rs2_addr_23;
wire                                    rd_en_23;
wire [4 : 0]                            rd_addr_23;
wire [`ysyx_22040365_REG_BUS]           imm_23;
wire [`ysyx_22040365_REG_BUS]           pc_23;
wire [31: 0]                            inst_23;
wire [7 : 0]                            inst_opcode_23;
wire [6 : 0]                            inst_type_23;

wire [`ysyx_22040365_REG_BUS]           rs1_data_34;
wire [`ysyx_22040365_REG_BUS]           rs2_data_34;
wire [4 : 0]                            rs1_addr_34;
wire [4 : 0]                            rs2_addr_34;
wire                                    rd_en_34;
wire [4 : 0]                            rd_addr_34;
wire [`ysyx_22040365_REG_BUS]           imm_34;
wire [`ysyx_22040365_REG_BUS]           pc_34;
wire [31: 0]                            inst_34;
wire [7 : 0]                            inst_opcode_34;
wire [6 : 0]                            inst_type_34;

wire [3 : 0]                            op_type_45;
wire [`ysyx_22040365_REG_BUS]           op1_45;
wire [`ysyx_22040365_REG_BUS]           op2_45;
wire [`ysyx_22040365_REG_BUS]           op3_45;
wire                                    bit_w;
wire [6 : 0]                            inst_type_45;
wire [7 : 0]                            inst_opcode_45;
wire                                    rd_en_45;
wire [4 : 0]                            rd_addr_45;       
wire [31: 0]                            inst_45;
wire [`ysyx_22040365_REG_BUS]           pc_45;

wire [7 : 0]                            inst_opcode_56;
wire                                    rd_en_56;
wire [4 : 0]                            rd_addr_56;       
wire [31: 0]                            inst_56;
wire [`ysyx_22040365_REG_BUS]           pc_56;
wire [`ysyx_22040365_REG_BUS]           ex_data_56;
wire [`ysyx_22040365_REG_BUS]           store_data_56;

wire                                    store_67;
wire                                    load_67;
wire [`ysyx_22040365_REG_BUS]           wmask_67;
wire [`ysyx_22040365_REG_BUS]           store_data_67;
wire [`ysyx_22040365_REG_BUS]           ex_data_67;
wire [7 : 0]                            inst_opcode_67;
wire                                    rd_en_67;
wire [4 : 0]                            rd_addr_67;
wire [31: 0]                            inst_67;
wire [`ysyx_22040365_REG_BUS]           pc_67;           

wire [`ysyx_22040365_REG_BUS]           result_78;
wire                                    rd_en_78;
wire [4 : 0]                            rd_addr_78;
wire [31: 0]                            inst_78;
wire [`ysyx_22040365_REG_BUS]           pc_78;
/*
wire [`ysyx_22040365_REG_BUS]           result_83;
wire                                    rd_en_83;
wire [4 : 0]                            rd_addr_83;
wire [31: 0]                            inst_83;
wire [`ysyx_22040365_REG_BUS]           pc_83;

wire                                    stall_mem_ex;
wire                                    stall_mem_ex1;
wire                                    stall_mem_ex2;

wire                                    B_flush;
*/
wire [`ysyx_22040365_REG_BUS]           pc_change;

////////////// Interconnection conductor///////////////////
//fetch instruction
ysyx_22040365_if      u1_ysyx_22040365_if(
    .clk             (clk),
    .rst             (rst),
    //for flush
    .B_flush         (B_flush),
    .pc_change       (pc_change),
    //memory stall
    .stall_mem_ex    (stall_mem_ex),
    .stall_mem_ex1   (stall_mem_ex1),
    .stall_mem_ex2   (stall_mem_ex2),
    .if_flush        (if_flush),
    //pipelin signal
    .pc_12           (pc_12),
    .inst_12         (inst_12));
//first decode 
ysyx_22040365_ifid_reg u2_ysyx_22040365_ifid_reg(
    .rst             (rst),
    .clk             (clk),
    .B_flush         (B_flush),
    .if_flush        (if_flush),
    .stall_mem_ex    (stall_mem_ex),
    .pc_12           (pc_12),
    .inst_12         (inst_12),
    .rs1_en_23       (rs1_en_23),
    .rs1_addr_23     (rs1_addr_23),
    .rs2_en_23       (rs2_en_23),
    .rs2_addr_23     (rs2_addr_23),
    .rd_en_23        (rd_en_23),
    .rd_addr_23      (rd_addr_23),
    .imm_23          (imm_23),
    .pc_23           (pc_23),
    .inst_23         (inst_23),
    //decode instruction                
    .inst_opcode_23  (inst_opcode_23),
    .inst_type_23    (inst_type_23));
//regfiles
ysyx_22040365_regfile  u3_ysyx_22040365_regfile(
    .clk             (clk),
    .rst             (rst),
    .stall_mem_ex    (stall_mem_ex),
    .stall_mem_ex1   (stall_mem_ex1),
    //from rd(mem/wb_reg)	83
    .w_ena           (rd_en_83), 
    .w_addr          (rd_addr_83),
    .w_data          (result_83),
    //rs1 (from if/id_reg  to id/ex_reg)
    .rs1_en_23       (rs1_en_23),
    .rs1_addr_23     (rs1_addr_23),
    //output
    .rs1_addr_34     (rs1_addr_34),
    .rs1_data_34     (rs1_data_34),
    //rs2 (from if/id_reg  to id/ex_reg)
    .rs2_en_23       (rs2_en_23),
    .rs2_addr_23     (rs2_addr_23),
    //output
    .rs2_addr_34     (rs2_addr_34),
    .rs2_data_34     (rs2_data_34),
    //just ****pipeline signal******
    .rd_en_23        (rd_en_23),
    .rd_addr_23      (rd_addr_23),
    .imm_23          (imm_23),
    .pc_23           (pc_23),
    .inst_23         (inst_23),
    .inst_opcode_23  (inst_opcode_23),
    .inst_type_23    (inst_type_23),
    //output
    .rd_en_34        (rd_en_34),
    .rd_addr_34      (rd_addr_34),
    .imm_34          (imm_34),
    .pc_34           (pc_34),
    .inst_34         (inst_34),
    .inst_opcode_34  (inst_opcode_34),
    .inst_type_34    (inst_type_34),
    .regs_o          (regs_o));
//second decode
ysyx_22040365_idex_reg u4_ysyx_22040365_idex_reg(
    .rst             (rst),
    .clk             (clk),
    .B_flush         (B_flush), // change from pc_reset
    .stall_mem_ex    (stall_mem_ex),
    .stall_mem_ex1   (stall_mem_ex1), 
    //to create operate num/type
    .rs1_data_34     (rs1_data_34),
    .rs2_data_34     (rs2_data_34),
    .imm_34          (imm_34),
    .pc_34           (pc_34),
    .inst_opcode_34  (inst_opcode_34),
    .inst_type_34    (inst_type_34),
    //output
    .op_type_45      (op_type_45),
    .op1_45          (op1_45),
    .op2_45          (op2_45),
    .op3_45          (op3_45),
    .bit_w           (bit_w),
    .inst_type_45    (inst_type_45),
    //just pipeline
    .rd_en_34        (rd_en_34),
    .rd_addr_34      (rd_addr_34),    
    .inst_34         (inst_34),
    //output
    .inst_opcode_45  (inst_opcode_45),
    .rd_en_45        (rd_en_45),
    .rd_addr_45      (rd_addr_45),    
    .inst_45         (inst_45),
    .pc_45           (pc_45), 
    //for bypass input from reg_files        
    .rs1_addr_34     (rs1_addr_34),
    .rs2_addr_34     (rs2_addr_34),
    .rd_en_56        (rd_en_56),
    .rd_addr_56      (rd_addr_56),
    .ex_data_56      (ex_data_56),  
    .result_78       (result_78),
    .rd_en_78        (rd_en_78),
    .rd_addr_78      (rd_addr_78));
//exe stage
ysyx_22040365_ex    u5_ysyx_22040365_ex(
    .rst             (rst),
    .clk             (clk),
    .stall_mem_ex    (stall_mem_ex),
    .stall_mem_ex1   (stall_mem_ex1),
    //input operate signal
    .op_type_45      (op_type_45),
    .op1_45          (op1_45),
    .op2_45          (op2_45),
    .op3_45          (op3_45),
    .bit_w           (bit_w),
    .inst_type_45    (inst_type_45),
    //input pipeline signal
    .inst_opcode_45  (inst_opcode_45),
    .rd_en_45        (rd_en_45),
    .rd_addr_45      (rd_addr_45),       
    .inst_45         (inst_45),
    .pc_45           (pc_45),
    //output pipeline signal
    .inst_opcode_56  (inst_opcode_56),
    .rd_en_56        (rd_en_56),
    .rd_addr_56      (rd_addr_56),       
    .inst_56         (inst_56),
    .pc_56           (pc_56),
    //generate result & memory operation num/type
    .ex_data_56      (ex_data_56),
    .store_data_56   (store_data_56),     
    //for jump or branch instruction to change next pc
    .B_flush         (B_flush),
    .pc_change       (pc_change));
//ex/mem_reg
ysyx_22040365_exmem_reg u6_ysyx_22040365_exmem_reg(
    .rst             (rst),
    .clk             (clk),
    .inst_opcode_56  (inst_opcode_56),
    .ex_data_56      (ex_data_56    ),
    .store_data_56   (store_data_56 ),
    .store_67        (store_67      ),
    .load_67         (load_67       ),
    .wmask_67        (wmask_67      ),
    .store_data_67   (store_data_67 ),
    .ex_data_67      (ex_data_67    ),
    .rd_en_56        (rd_en_56      ),
    .rd_addr_56      (rd_addr_56    ),
    .inst_56         (inst_56       ),
    .pc_56           (pc_56         ),
    .inst_opcode_67  (inst_opcode_67),
    .rd_en_67        (rd_en_67      ),
    .rd_addr_67      (rd_addr_67    ),
    .inst_67         (inst_67       ), 
    .pc_67           (pc_67         ));    
//mem stage
ysyx_22040365_mem   u7_ysyx_22040365_mem(
    .rst             (rst           ),
    .clk             (clk           ),
    .store_67        (store_67      ),
    .load_67         (load_67       ),
    .wmask_67        (wmask_67      ),
    .store_data_67   (store_data_67 ),
    .ex_data_67      (ex_data_67    ),
    .inst_opcode_67  (inst_opcode_67),
    .rd_en_67        (rd_en_67      ),
    .rd_addr_67      (rd_addr_67    ),
    .inst_67         (inst_67       ), 
    .pc_67           (pc_67         ),      
    .result_78       (result_78     ),
    .rd_en_78        (rd_en_78      ),
    .rd_addr_78      (rd_addr_78    ),
    .inst_78         (inst_78       ),
    .pc_78           (pc_78         ));
//mem/wb_reg
ysyx_22040365_memwb_reg u8_ysyx_22040365_memwb_reg(
    .rst             (rst         ),
    .clk             (clk         ),
    .result_78       (result_78   ),
    .rd_en_78        (rd_en_78    ),
    .rd_addr_78      (rd_addr_78  ),
    .inst_78         (inst_78     ),
    .pc_78           (pc_78       ),
    .result_83       (result_83   ),
    .rd_en_83        (rd_en_83    ),
    .rd_addr_83      (rd_addr_83  ),
    .inst_83         (inst_83     ),
    .pc_83           (pc_83       ));
//stall control
ysyx_22040365_stall u_ysyx_22040365_stall(
    .rst             (rst           ),
    .clk             (clk           ),
    .rs1_addr_34     (rs1_addr_34   ),
    .rs2_addr_34     (rs2_addr_34   ),  
    .rd_addr_56      (rd_addr_56    ),
    .inst_opcode_56  (inst_opcode_56),
    .stall_mem_ex    (stall_mem_ex  ),
    .stall_mem_ex1   (stall_mem_ex1 ),
    .stall_mem_ex2   (stall_mem_ex2 ));

endmodule
