`include "ysyx_22040365_defines.v"
module SimTop(
    input         clock,
    input         reset,

    input  [63:0] io_logCtrl_log_begin,
    input  [63:0] io_logCtrl_log_end,
    input  [63:0] io_logCtrl_log_level,
    input         io_perfInfo_clean,
    input         io_perfInfo_dump,

    output        io_uart_out_valid,
    output [7:0]  io_uart_out_ch,
    output        io_uart_in_valid,
    input  [7:0]  io_uart_in_ch
);


wire [`ysyx_22040365_REG_BUS]           regs[0:31];
wire [`ysyx_22040365_REG_BUS]           result_83;
wire                                    rd_en_83;
wire [4 : 0]                            rd_addr_83;
wire [31: 0]                            inst_83;
wire [`ysyx_22040365_REG_BUS]           pc_83;

wire                                    stall_mem_ex;
wire                                    stall_mem_ex1;
wire                                    stall_mem_ex2;
wire                                    B_flush;

ysyx_22040365_cpu_top u_ysyx_22040365_cpu_top(
    .rst                   (reset        ),
    .clk                   (clock        ),
    //control commit  
    .B_flush               (B_flush      ),
    .stall_mem_ex          (stall_mem_ex ),
    .stall_mem_ex1         (stall_mem_ex1),
    .stall_mem_ex2         (stall_mem_ex2),
    //commit data to difftest
    .pc_83                 (pc_83        ),
    .inst_83               (inst_83      ),
    .rd_en_83              (rd_en_83     ),
    .rd_addr_83            (rd_addr_83   ),
    .result_83             (result_83    ),
    .regs_o                (regs         ));
/////// pipeline control signal////////////
reg   B_flush1,B_flush2,B_flush3,B_flush4,B_flush5,B_flush6,B_flush7;
wire  ctrl_B_flush;
reg   stall_mem_ex3,stall_mem_ex4,stall_mem_ex5,stall_mem_ex6;
wire  ctrl_stall;
wire  flush_stall;
wire  ld_jalr;

//stall_mem_ex6,stall_mem_ex7;
assign  ctrl_B_flush = (B_flush3!=1'b1) && (B_flush4!=1'b1);
                     //(B_flush2!=1'b1)&&
                     //&&(B_flush5!=1'b1)&&(B_flush6!=1'b1)&&(B_flush7!=1'b1);
assign  ld_jalr      = B_flush5!=1'b1 && stall_mem_ex6!=1'b1;
assign  flush_stall  = (B_flush2!=1'b1)
                       //&&(B_flush5!=1'b1&&stall_mem_ex6!=1'b1)
                       ||(B_flush2==1'b1 && stall_mem_ex3==1'b1);
                    

always@(negedge clock)begin
  B_flush1 <= B_flush;
  B_flush2 <= B_flush1;
  B_flush3 <= B_flush2;
  B_flush4 <= B_flush3;
  B_flush5 <= B_flush4;
 // B_flush6 <= B_flush5;
 // B_flush7 <= B_flush6;
end

always@(negedge clock)begin
  stall_mem_ex3 <= stall_mem_ex2;
  stall_mem_ex4 <= stall_mem_ex3;
  stall_mem_ex5 <= stall_mem_ex4;
  stall_mem_ex6 <= stall_mem_ex5;
  //stall_mem_ex7 <= stall_mem_ex6;
end
assign ctrl_stall = (stall_mem_ex2!=1'b1);
//&&(stall_mem_ex2!=1'b0);
// Difftest
reg cmt_wen;
reg [7:0] cmt_wdest;
reg [`ysyx_22040365_REG_BUS] cmt_wdata;
reg [`ysyx_22040365_REG_BUS] cmt_pc;
reg [31:0] cmt_inst;
reg cmt_valid;
reg trap;
reg [7:0] trap_code;
reg [63:0] cycleCnt;
reg [63:0] instrCnt;
reg [`ysyx_22040365_REG_BUS] regs_diff [0 : 31];

wire inst_valid = ((pc_83 != `ysyx_22040365_PC_START) | (inst_83 != 0))
                && (ctrl_stall) &&(ctrl_B_flush)&&(flush_stall)
                &&(pc_83!=`ysyx_22040365_ZERO_WORD);

always @(negedge clock) begin
  if (reset) begin
    {cmt_wen, cmt_wdest, cmt_wdata, cmt_pc, cmt_inst, cmt_valid, trap, trap_code, cycleCnt, instrCnt} <= 0;
  end
  else if (~trap) begin
    cmt_wen <= rd_en_83;
    cmt_wdest <= {3'd0, rd_addr_83};
    cmt_wdata <= result_83;
    cmt_pc <= pc_83;
    cmt_inst <= inst_83;
    cmt_valid <= inst_valid;

		regs_diff <= regs;

    trap <= inst_83[6:0] == 7'h6b;
    trap_code <= regs[10][7:0];
    cycleCnt <= cycleCnt + 1;
    instrCnt <= instrCnt + inst_valid;
  end
end

DifftestInstrCommit DifftestInstrCommit(
  .clock              (clock),
  .coreid             (0),
  .index              (0),
  .valid              (cmt_valid),
  .pc                 (cmt_pc),
  .instr              (cmt_inst),
  .skip               (0),
  .isRVC              (0),
  .scFailed           (0),
  .wen                (cmt_wen),
  .wdest              (cmt_wdest),
  .wdata              (cmt_wdata)
);

DifftestArchIntRegState DifftestArchIntRegState (
  .clock              (clock),
  .coreid             (0),
  .gpr_0              (regs_diff[0]),
  .gpr_1              (regs_diff[1]),
  .gpr_2              (regs_diff[2]),
  .gpr_3              (regs_diff[3]),
  .gpr_4              (regs_diff[4]),
  .gpr_5              (regs_diff[5]),
  .gpr_6              (regs_diff[6]),
  .gpr_7              (regs_diff[7]),
  .gpr_8              (regs_diff[8]),
  .gpr_9              (regs_diff[9]),
  .gpr_10             (regs_diff[10]),
  .gpr_11             (regs_diff[11]),
  .gpr_12             (regs_diff[12]),
  .gpr_13             (regs_diff[13]),
  .gpr_14             (regs_diff[14]),
  .gpr_15             (regs_diff[15]),
  .gpr_16             (regs_diff[16]),
  .gpr_17             (regs_diff[17]),
  .gpr_18             (regs_diff[18]),
  .gpr_19             (regs_diff[19]),
  .gpr_20             (regs_diff[20]),
  .gpr_21             (regs_diff[21]),
  .gpr_22             (regs_diff[22]),
  .gpr_23             (regs_diff[23]),
  .gpr_24             (regs_diff[24]),
  .gpr_25             (regs_diff[25]),
  .gpr_26             (regs_diff[26]),
  .gpr_27             (regs_diff[27]),
  .gpr_28             (regs_diff[28]),
  .gpr_29             (regs_diff[29]),
  .gpr_30             (regs_diff[30]),
  .gpr_31             (regs_diff[31])
);

DifftestTrapEvent DifftestTrapEvent(
  .clock              (clock),
  .coreid             (0),
  .valid              (trap),
  .code               (trap_code),
  .pc                 (cmt_pc),
  .cycleCnt           (cycleCnt),
  .instrCnt           (instrCnt)
);

DifftestCSRState DifftestCSRState(
  .clock              (clock),
  .coreid             (0),
  .priviledgeMode     (`ysyx_22040365_RISCV_PRIV_MODE_M),
  .mstatus            (0),
  .sstatus            (0),
  .mepc               (0),
  .sepc               (0),
  .mtval              (0),
  .stval              (0),
  .mtvec              (0),
  .stvec              (0),
  .mcause             (0),
  .scause             (0),
  .satp               (0),
  .mip                (0),
  .mie                (0),
  .mscratch           (0),
  .sscratch           (0),
  .mideleg            (0),
  .medeleg            (0)
);

DifftestArchFpRegState DifftestArchFpRegState(
  .clock              (clock),
  .coreid             (0),
  .fpr_0              (0),
  .fpr_1              (0),
  .fpr_2              (0),
  .fpr_3              (0),
  .fpr_4              (0),
  .fpr_5              (0),
  .fpr_6              (0),
  .fpr_7              (0),
  .fpr_8              (0),
  .fpr_9              (0),
  .fpr_10             (0),
  .fpr_11             (0),
  .fpr_12             (0),
  .fpr_13             (0),
  .fpr_14             (0),
  .fpr_15             (0),
  .fpr_16             (0),
  .fpr_17             (0),
  .fpr_18             (0),
  .fpr_19             (0),
  .fpr_20             (0),
  .fpr_21             (0),
  .fpr_22             (0),
  .fpr_23             (0),
  .fpr_24             (0),
  .fpr_25             (0),
  .fpr_26             (0),
  .fpr_27             (0),
  .fpr_28             (0),
  .fpr_29             (0),
  .fpr_30             (0),
  .fpr_31             (0)
);

endmodule