module top(
//  input a,
//  input b,
  input clk,
  input rst,
  output f
);
 // assign f = (rst == 1'b0) ? (a ^ b) : (1'b0);
  assign f = (rst == 1'b0) ? (1'b1) : (1'b0);

endmodule

