`include "ysyx_22040365_defines.v"
module ysyx_22040365_regfile  (
  input                                   clk,
	input                                   rst,
	input                                   stall_mem_ex,
  input                                   stall_mem_ex1,
	//from rd(mem/wb_reg)	
  input   		                            w_ena, //rd_en_83
	input        [4  : 0]                   w_addr,//rd_addr_83
	input        [`ysyx_22040365_REG_BUS]   w_data,//rd_data_83
	//rs1 (from if/id_reg  to id/ex_reg)
  input   		                            rs1_en_23,
	input        [4  : 0]                   rs1_addr_23,
  output reg   [4  : 0]                   rs1_addr_34,
  output reg   [`ysyx_22040365_REG_BUS]   rs1_data_34,
	//rs2 (from if/id_reg  to id/ex_reg)
  input   		                            rs2_en_23,
	input        [4  : 0]                   rs2_addr_23,
  output reg   [4  : 0]                   rs2_addr_34,
  output reg   [`ysyx_22040365_REG_BUS]   rs2_data_34,
  //just ****pipeline signal******
  input  	                                 rd_en_23,
  input        [4 : 0]                     rd_addr_23,
  input        [`ysyx_22040365_REG_BUS]    imm_23,
  input        [`ysyx_22040365_REG_BUS]	   pc_23,
  input        [31: 0]	                   inst_23,
  input        [7 : 0]                     inst_opcode_23,
  input        [6 : 0]                     inst_type_23,

  output reg                               rd_en_34,
  output reg   [4 : 0]                     rd_addr_34,
  output reg   [`ysyx_22040365_REG_BUS]    imm_34,
  output reg   [`ysyx_22040365_REG_BUS]	   pc_34,
  output reg   [31: 0]	                   inst_34,
  output reg   [7 : 0]                     inst_opcode_34,
  output reg   [6 : 0]                     inst_type_34,
  output wire  [`ysyx_22040365_REG_BUS]    regs_o[0 : 31] // difftest
);

// 32 registers
	reg [`ysyx_22040365_REG_BUS] 	regs[0:31];

//if/id_reg read *rs1* data to id/ex_reg 
  always @(posedge clk) begin
    if(rst) begin
      rs1_data_34 <= `ysyx_22040365_ZERO_WORD;
    end
    else if(stall_mem_ex)begin
      rs1_data_34 <= rs1_data_34;
    end
    else if((rs1_en_23==1'b1) &&(rs1_addr_23!=5'd0))begin
      if((w_ena==1'b1)&&(w_addr==rs1_addr_23))begin
        rs1_data_34 <= w_data;
      end
      else begin
        rs1_data_34 <= regs[rs1_addr_23];
      end
    end
    else begin
      rs1_data_34 <= `ysyx_22040365_ZERO_WORD;
    end
  end

//if/id_reg read *rs2* data to id/ex_reg 
  always @(posedge clk) begin
    if(rst) begin
      rs2_data_34 <= `ysyx_22040365_ZERO_WORD;
    end
    else if(stall_mem_ex)begin
      rs2_data_34 <= rs2_data_34;
    end
    else if((rs2_en_23==1'b1)&&(rs2_addr_23!=5'd0))begin
      if((w_ena==1'b1)&&(w_addr==rs2_addr_23))begin
        rs2_data_34 <= w_data;
      end
      else begin
        rs2_data_34 <= regs[rs2_addr_23];
      end
    end
    else begin
      rs2_data_34 <= `ysyx_22040365_ZERO_WORD;
    end
  end

//pipeline signal determined by stall ctl
  always @(posedge clk) begin
    if(!stall_mem_ex) begin //normal pipe; not stall
      rd_en_34        <=  rd_en_23;
      rd_addr_34      <=  rd_addr_23;
      imm_34          <=  imm_23;
      pc_34           <=  pc_23;
      inst_34         <=  inst_23;
      inst_opcode_34  <=  inst_opcode_23;
      inst_type_34    <=  inst_type_23;
      //for data bypass
      rs1_addr_34     <=  rs1_addr_23;
      rs2_addr_34     <=  rs2_addr_23;
    end
    else begin //stall the pipelin , signal be latched
      rd_en_34        <=  rd_en_34;
      rd_addr_34      <=  rd_addr_34;
      imm_34          <=  imm_34;
      pc_34           <=  pc_34;
      inst_34         <=  inst_34;
      inst_opcode_34  <=  inst_opcode_34;
      inst_type_34    <=  inst_type_34;
      //for data bypass
      rs1_addr_34     <=  rs1_addr_34;
      rs2_addr_34     <=  rs2_addr_34;
    end
  end

//mem/wb_reg write data to regfile 
  always @(posedge clk) begin
    if(rst) begin
    	regs[ 0] <= `ysyx_22040365_ZERO_WORD;
			regs[ 1] <= `ysyx_22040365_ZERO_WORD;
			regs[ 2] <= `ysyx_22040365_ZERO_WORD;
			regs[ 3] <= `ysyx_22040365_ZERO_WORD;
			regs[ 4] <= `ysyx_22040365_ZERO_WORD;
			regs[ 5] <= `ysyx_22040365_ZERO_WORD;
			regs[ 6] <= `ysyx_22040365_ZERO_WORD;
			regs[ 7] <= `ysyx_22040365_ZERO_WORD;
			regs[ 8] <= `ysyx_22040365_ZERO_WORD;
			regs[ 9] <= `ysyx_22040365_ZERO_WORD;
			regs[10] <= `ysyx_22040365_ZERO_WORD;
			regs[11] <= `ysyx_22040365_ZERO_WORD;
			regs[12] <= `ysyx_22040365_ZERO_WORD;
			regs[13] <= `ysyx_22040365_ZERO_WORD;
			regs[14] <= `ysyx_22040365_ZERO_WORD;
			regs[15] <= `ysyx_22040365_ZERO_WORD;
			regs[16] <= `ysyx_22040365_ZERO_WORD;
			regs[17] <= `ysyx_22040365_ZERO_WORD;
			regs[18] <= `ysyx_22040365_ZERO_WORD;
			regs[19] <= `ysyx_22040365_ZERO_WORD;
			regs[20] <= `ysyx_22040365_ZERO_WORD;
			regs[21] <= `ysyx_22040365_ZERO_WORD;
			regs[22] <= `ysyx_22040365_ZERO_WORD;
			regs[23] <= `ysyx_22040365_ZERO_WORD;
			regs[24] <= `ysyx_22040365_ZERO_WORD;
			regs[25] <= `ysyx_22040365_ZERO_WORD;
			regs[26] <= `ysyx_22040365_ZERO_WORD;
			regs[27] <= `ysyx_22040365_ZERO_WORD;
			regs[28] <= `ysyx_22040365_ZERO_WORD;
			regs[29] <= `ysyx_22040365_ZERO_WORD;
			regs[30] <= `ysyx_22040365_ZERO_WORD;
			regs[31] <= `ysyx_22040365_ZERO_WORD;
    end
    else begin
			if ((w_ena == 1'b1) && (w_addr != 5'h00))	
				regs[w_addr] <= w_data;
		end
  end
//for difftest
genvar i;
	generate
		for (i = 0; i < 32; i = i + 1) begin
			assign regs_o[i] = (w_ena & w_addr == i & i != 0) ? w_data : regs[i];
		end
	endgenerate

endmodule
