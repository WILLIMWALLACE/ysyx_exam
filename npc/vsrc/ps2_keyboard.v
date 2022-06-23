module ps2_keyboard(
    input 	clk,
    input 	resetn,
    input 	ps2_clk,
    input 	ps2_data,
    input	nextdata_n,
    output [7:0]	data,
    output reg		ready,
    output reg 		overflow
    );

    reg [9:0] buffer;        // ps2_data bits
    reg [3:0] count;  // count ps2_data bits
    reg [2:0] ps2_clk_sync;
    reg [7:0] fifo[7:0];
    reg [2:0] w_ptr,r_ptr;

    always @(posedge clk) begin//采集psclk以供抓取边沿
        ps2_clk_sync <=  {ps2_clk_sync[1:0],ps2_clk};
    end

    wire sampling = ps2_clk_sync[2] & ~ps2_clk_sync[1];//抓下降沿

    always @(posedge clk) begin
        if (resetn == 0) begin // reset
            count<=0; w_ptr<=0; r_ptr<=0; overflow<=0; ready<=0;
        end
    	else begin
            if ( ready ) begin // read to output next data
                if(nextdata_n == 1'b0) //read next data
                begin
                    r_ptr <= r_ptr + 3'b1;
                    if(w_ptr==(r_ptr+1'b1)) //empty
                        ready <= 1'b0;
                end
            end
            if (sampling) begin
              if (count == 4'd10) begin
                if ((buffer[0] == 0) &&  // start bit
                    (ps2_data)       &&  // stop bit
                    (^buffer[9:1])) begin      // odd  parity
                    fifo[w_ptr] <= buffer[8:1];  // kbd scan code
                    w_ptr <= w_ptr+3'b1;
                    ready <= 1'b1;
                    overflow <= overflow | (r_ptr == (w_ptr + 3'b1));
                end
                count <= 0;     // for next
              end 
	      else begin
                buffer[count] <= ps2_data;  // store ps2_data
                count <= count + 3'b1;
              end
            end
        end
    end
    assign data = fifo[r_ptr]; //always set output data
endmodule

