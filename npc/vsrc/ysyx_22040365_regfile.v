module ysyx_22040365_regfile #(ADDR_WIDTH = 1, DATA_WIDTH = 1) (
  input clk,
  input [DATA_WIDTH-1:0] wdata,
  input [ADDR_WIDTH-1:0] waddr,
  input wen,
  input ren_rs1,
  input [ADDR_WIDTH-1:0] raddr,
  output[DATA_WIDTH-1:0] rdata
);
  reg [DATA_WIDTH-1:0] rf [ADDR_WIDTH-1:0];
  always @(posedge clk) begin
    if(wen) rf[waddr] <= wdata;
  end
 always @(*) begin
    if(ren_rs1) rdata     <= rf[raddr]; 
 end
endmodule

