module fadd ( 
  output [3:0]sum;//数据累加和本位
  output		  cout;//输出进位
  input  [3:0]a,b;//需要相加的数
  input       cin;//输入进位
 );
  wire	 [3:0]g,p,c;//分别对应Gi、Pi和Ci
  
  assign  c[0] = din;//最低进位为输入进位
  assign  P = a | b;// Pi = Ai·Bi
  assign  g = a & b;// Gi = Ai+Bi
  assign  c[1] = g[0] | (p[0] & c[0]);//对应图中 C1
  assign  c[2] = g[1] | (p[1] &(g[0] | (p[0] & c[0]) );
  assign  c[3] = g[2] | (p[2] &(g[1] | (p[1] &(g[0]|(p[0]&c[0])))));
  assign  c[4] = g[3] | (p[3] &(g[2] | (p[2] &(g[1]|(p[1]&(g[0]|(p[0]&c[0])))))));
  assign  sum = p ^ c[3:0];  
  assign  cout = c[4];
endmodule
