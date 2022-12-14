module yihuo(                                                                                                                                                                                            
     input  [7:0]  sw,
     input  clk,
     input  rst,
     output [15:0] ledr
   );
    
       reg        f;
       reg [31:0] count;
       reg [7:0] led;
      
       assign f =  sw[0] ^ sw[1];
  
       always @(posedge clk) begin
        if (rst) begin led <= 1; count <= 0; end
        else begin
          if (count == 0) led <= {led[6:0], led[7]};
          count <= (count >= 5000000 ? 32'b0 : count + 1);
       end
      end
    
      assign ledr = {led, sw[7:2], 1'b1, f};
  
  endmodule
