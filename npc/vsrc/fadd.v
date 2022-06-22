module fadd ( 
  output reg[3:0]	sum,//数据累加和本位
  output reg		cout,//输出进位
  output 		overflow,
  input     [3:0]	a,b,//需要相加的数
  input       		cin,//输入进位
  input 		clk,
  input			rst
 );
  wire	 [4:0]   g,p,c;//分别对应Gi、Pi和Ci
  
  assign  c[0] = cin;//最低进位为输入进位
  assign  p = a | b;// Pi = Ai+Bi
  assign  g = a & b;// Gi = Ai.Bi
  assign  c[1] = g[0] | (p[0] & c[0]);//对应图中 C1
  assign  c[2] = g[1] | (p[1] & (g[0] | (p[0] & c[0])));
  assign  c[3] = g[2] | (p[2] &(g[1] | (p[1] &(g[0]|(p[0]&c[0])))));
  assign  c[4] = g[3] | (p[3] &(g[2] | (p[2] &(g[1]|(p[1]&(g[0]|(p[0]&c[0])))))));
  assign  overflow = (c[4] == c[3]) ? 1'b0 : 1'b1;

  always@(posedge clk) begin
	if(rst)	begin
	sum	<= 4'd0;
	cout	<= 1'b0; 
		end
	else	begin
	sum	<= p ^ c[3:0]; 
	cout	<= c[4];
		end
  end


 /* assign  sum = p ^ c[3:0];  
  assign  cout = c[4];*/

endmodule
