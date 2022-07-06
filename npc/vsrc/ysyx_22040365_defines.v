`timescale 1ns / 1ps


`define ZERO_WORD  64'h00000000_00000000
`define PC_START   64'h00000000_80000000
`define REG_BUS    63 : 0     

`define RISCV_PRIV_MODE_U   0
`define RISCV_PRIV_MODE_S   1               
`define RISCV_PRIV_MODE_M   3


//`define INST_ADDI   8'b00000001
`define INST_ADDI   	    1'b0
`define INST_EBREAK 	    1'b1

