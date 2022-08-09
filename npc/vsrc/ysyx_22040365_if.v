`include "ysyx_22040365_defines.v"
module ysyx_22040365_if(
  input                               clk           ,
  input                               rst           ,

  input	                              B_flush       ,
  input  [`ysyx_22040365_REG_BUS]     pc_change     ,
  input 	                            stall_mem_ex  ,
  input                               stall_mem_ex1 ,
  input                               stall_mem_ex2 ,
  output                              if_flush      ,

  output reg [`ysyx_22040365_REG_BUS] pc_12         ,
  output reg [31 : 0]                 inst_12
);

parameter PC_START_RESET = `ysyx_22040365_PC_START - 4;

//for ld->jalr judge ///// is a latency
reg   B_flush1;
wire  flush_valid_lj;   //load + jal(r)
wire  stall_valid;
wire  flush_valid_lb;//load + b type
wire  ch_pc_valid;

always@(posedge clk)begin
  B_flush1  <=  B_flush;
end

assign flush_valid_lj = (stall_mem_ex2) ? B_flush1 : B_flush;
assign flush_valid_lb = B_flush && stall_mem_ex2;
assign ch_pc_valid    = flush_valid_lj || flush_valid_lb;

assign stall_valid    = (stall_mem_ex == 1'b1)||(stall_mem_ex1 == 1'b1);
//&&B_flush==1'b1);
assign if_flush       = (stall_mem_ex1)||((stall_mem_ex2)&&(B_flush1));
// fetch an instruction
always@( posedge clk )
begin
  if(rst)
  begin 
    pc_12 <= PC_START_RESET;
  end
  //else if(stall_mem_ex != 1'b1)
  else if(!stall_valid)
  begin
 	 case(ch_pc_valid)
 	 1'b0:   begin    pc_12 <= pc_12 + 4;  end
	 1'b1:   begin    pc_12 <= pc_change;  end
	 default:         pc_12 <= pc_12 + 4;
	 endcase
  end
  else begin
	pc_12 <= pc_12;
  end
end

// Access memory
reg [63:0] rdata;
RAMHelper RAMHelper(
  .clk              (clk),
  .en               (1),
  .rIdx             ((pc_12 - `ysyx_22040365_PC_START) >> 3),
  .rdata            (rdata),
  .wIdx             (0),
  .wdata            (0),
  .wmask            (0),
  .wen              (0)
);

assign inst_12 = pc_12[2] ? rdata[63 : 32] : rdata[31 : 0];

endmodule
