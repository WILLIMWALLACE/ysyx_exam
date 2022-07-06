module ysyx_22040365_regfile  (
  input clk,
  input [63:0] wdata,
  input [4:0] waddr,
  input wen,
  input ren_rs1,
  input [4:0] raddr,
  output[63:0] rdata
);
  reg [63:0] rf [4:0];
  always @(posedge clk) begin
    if(wen) rf[waddr] <= wdata;
  end
// always @(*) begin
//    if(ren_rs1) rdata     = rf[raddr]; 
// end
assign rdata = (ren_rs1==1'b1) ? rf[raddr] : 0;


endmodule

