#include <isa.h>

/* We use the POSIX regex functions to process regular expressions.
 * Type 'man regex' for more information about POSIX regex functions.
 */
#include <regex.h>
#include "sdb.h"

enum {
  TK_NOTYPE = 256, TK_OR = 257, TK_EQ=258, TK_NUMD=259,TK_UNEQ=260,
  TK_AND=261,TK_HEX=262,REG=263,DEREF=264,
};

static struct rule {
  const char *regex;
  int token_type;
} rules[] = {
  {" +", TK_NOTYPE},    // spaces
  {"0[xX][0-9A-Fa-f]+", TK_HEX}, // ^(kaitou)xxx*(ling ci huo duo ci)$(mowei)
  {"\\(", '('},         //  (
  {"\\)", ')'},         //  )
  {"\\+", '+'},         // plus
  {"\\-", '-'},         //sub
  {"\\*", '*'},         //multi
  {"/", '/'},         //divide  
  {"\\|\\|", TK_OR},  //   || or
  {"==", TK_EQ},        // equal
  {"[0-9]+", TK_NUMD}, // shi jin zhi num
  {"!=", TK_UNEQ}, // 
  {"&&", TK_AND}, // 
  {"\\$0",REG},
  {"\\$ra",REG},
  {"\\$s[0-9]+",REG},
  {"\\$t[0-6]",REG},
  {"\\$[sgt]p",REG},
  {"\\$a[0-7]",REG},
};
///operator priority; the larger num,the lower priority
static struct priority{
  int   op_type;
  int   level;
}priorities[]={

  {TK_AND, 5},
  {TK_UNEQ, 4},
  {TK_EQ, 4},
  {'+', 3},
  {'-', 3},
  {'*', 2},
  {'/', 2},
  {DEREF,1},  //{zhi zhen deference}

};

#define NR_REGEX ARRLEN(rules)
#define NR_PRIORITY ARRLEN(priorities)

static regex_t re[NR_REGEX] = {};

/* Rules are used for many times.
 * Therefore we compile them only once before any usage.
 */
void init_regex() {
  int i;
  char error_msg[128];
  int ret;

  for (i = 0; i < NR_REGEX; i ++) {
    ret = regcomp(&re[i], rules[i].regex, REG_EXTENDED);
    if (ret != 0) {
      regerror(ret, &re[i], error_msg, 128);
      panic("regex compilation failed: %s\n%s", error_msg, rules[i].regex);
    }
  }
}

typedef struct token {
  int type;
  char str[32];
} Token;
static Token tokens[32] __attribute__((used)) = {};
static int nr_token __attribute__((used))  = 0;
//static int nr_token;

static bool make_token(char *e) {
  int position = 0;
  int i;
  regmatch_t pmatch;
  nr_token = 0;

  while (e[position] != '\0') {
    /* Try all rules one by one. */
    for (i = 0; i < NR_REGEX; i ++) {
      if (regexec(&re[i], e + position, 1, &pmatch, 0) == 0 && pmatch.rm_so == 0) {
        char *substr_start = e + position;
        int substr_len = pmatch.rm_eo;

        Log("match rules[%d] = \"%s\" at position %d with len %d: %.*s",
            i, rules[i].regex, position, substr_len, substr_len, substr_start);

        position += substr_len;
        
        int j;
        switch (rules[i].token_type) {
          case TK_NOTYPE:
          {tokens[nr_token].type=rules[i].token_type;        break;}  
          case TK_HEX:  {tokens[nr_token].type=rules[i].token_type; 
              for(j=0;j<substr_len;j++){tokens[nr_token].str[j] = *(substr_start+j);}
              tokens[nr_token].str[j] = '\0';   nr_token++ ;                break;}     
          case '(':      {tokens[nr_token].type=rules[i].token_type; 
              for(j=0;j<substr_len;j++){tokens[nr_token].str[j] = *(substr_start+j);}
              tokens[nr_token].str[j] = '\0';   nr_token++ ;                break;}  
          case ')':      {tokens[nr_token].type=rules[i].token_type; 
              for(j=0;j<substr_len;j++){tokens[nr_token].str[j] = *(substr_start+j);}
              tokens[nr_token].str[j] = '\0';   nr_token++ ;                break;}  
          case '-':    {tokens[nr_token].type=rules[i].token_type; 
              for(j=0;j<substr_len;j++){tokens[nr_token].str[j] = *(substr_start+j);}
              tokens[nr_token].str[j] = '\0';   nr_token++ ;                break;}   
          case '*':      {tokens[nr_token].type=rules[i].token_type; 
              for(j=0;j<substr_len;j++){tokens[nr_token].str[j] = *(substr_start+j);}
              tokens[nr_token].str[j] = '\0';   nr_token++ ;                break;}  
          case '+':      {tokens[nr_token].type=rules[i].token_type; 
          for(j=0;j<substr_len;j++){tokens[nr_token].str[j] = *(substr_start+j);}
              tokens[nr_token].str[j] = '\0';   nr_token++ ;                break;}  
          case '/':      {tokens[nr_token].type=rules[i].token_type; 
              for(j=0;j<substr_len;j++){tokens[nr_token].str[j] = *(substr_start+j);}
              tokens[nr_token].str[j] = '\0';   nr_token++ ;                break;}   
          case TK_NUMD:  {tokens[nr_token].type=rules[i].token_type; 
              for(j=0;j<substr_len;j++){tokens[nr_token].str[j] = *(substr_start+j);}
              tokens[nr_token].str[j] = '\0';   nr_token++ ;                break;}  
          case TK_AND:  {tokens[nr_token].type=rules[i].token_type; 
              for(j=0;j<substr_len;j++){tokens[nr_token].str[j] = *(substr_start+j);}
              tokens[nr_token].str[j] = '\0';   nr_token++ ;                break;}    
          case TK_UNEQ:  {tokens[nr_token].type=rules[i].token_type; 
              for(j=0;j<substr_len;j++){tokens[nr_token].str[j] = *(substr_start+j);}
              tokens[nr_token].str[j] = '\0';   nr_token++ ;                break;}    
          case TK_EQ:  {tokens[nr_token].type=rules[i].token_type; 
              for(j=0;j<substr_len;j++){tokens[nr_token].str[j] = *(substr_start+j);}
              tokens[nr_token].str[j] = '\0';   nr_token++ ;                break;}   
          case REG:  {tokens[nr_token].type=rules[i].token_type; 
              for(j=0;j<substr_len;j++){tokens[nr_token].str[j] = *(substr_start+j);}
              tokens[nr_token].str[j] = '\0';   nr_token++ ;                break;}          
          default: TODO();
        }
        //printf("type=%d  str=%.*s\n",tokens->type,substr_len,tokens->str);
        break;
      }
    }
    if (i == NR_REGEX) {
      printf("no match at position %d\n%s\n%*.s^\n", position, e, position, "");
      return false;
    }
  }
  return true;
}

/************************qiu  zhi    ;    evaluate express**************************/
static bool check_parentheses(int p, int q){
	int i,j=0;
	for(i=p;i<q;i++)
	{
		if(tokens[i].type=='(')
			j++;
		else if(tokens[i].type==')')
			j--;
		if(j==0)
			return false;
	}
	if(tokens[q].type==')')
		j--;
	return (j==0)&&(tokens[p].type=='(')&&(tokens[q].type==')');
}
//pan daun express shifou youxiao
/*static bool valid_epxr(int p,int q){
  int i,j=0;
  for(i=p;i<q;i++)
	{
		if(tokens[i].type=='(')
			j++;
		else if(tokens[i].type==')')
			j--;
    if(j<0)             //you kuo hao duo, feifa 
      return false;
	}
	if(tokens[q].type==')')
		{j--;}
  if(j==0){
    return true;
  }
  else{
    return false;    //zuo kuo hao  duo,feifa
  }
}*/
static  int  op_flag(int i){
  if(tokens[i].type=='+'||tokens[i].type=='-'
    ||tokens[i].type=='*'||tokens[i].type=='/'
    ||tokens[i].type==TK_EQ||tokens[i].type==TK_UNEQ
    ||tokens[i].type==TK_AND)
  {return 1;}
  else
  {return 0;}
}
static uint32_t eval(int p,int q){
  if (p>q)
  {
   // *valid = false;q
    //printf("jin ru cuo wu zhuang tai\n");
    printf("q=%d,nr_token=%d\n",q,nr_token);
    assert(0);
    return 0;
  }
  else if(p==q){
    //printf("jian ce dao num");
    uint32_t result=0;
   // *valid = true;
    if(tokens[p].type == TK_NUMD){      //shi jin  zhi   shu
			sscanf(tokens[p].str,"%d",&result);
      //printf("%d\n",result);
			return result;}
    else if(tokens[p].type==REG){  
      //word_t reg_value=0;
      bool reg_success;

      return isa_reg_str2val(tokens[p].str, &reg_success);
      //else{printf("reg_success=0\n"); return 0;}
      } 
    else{                              //hou xu tian jia qi ta lei  xing
     // sscanf(tokens[p].str,"%d",&result);
			return 0;}
  }
  else if(check_parentheses(p,q)){
   // bool  flag=true;
    //printf("chu fa kuo hao\n");
    return eval(p+1,q-1);//throw away the parentheses
  }
  else{                        //oprator_priority_most > save() and caculate(switch)
   //printf("chu fa ji suan\n");
  int i=0;
  int priority=0; 
  int ch_op=0;
 
    for(i=p;i<=q;i++){
      //kuo hao nei bu shi zhu yun suan fu,xun huan tiao guo kuo hao
      // printf("jin ru cuo wu zhuang tai\n");
      if(tokens[i].type=='('){
        int k = 1;
       // printf("jin ru cuo wu zhuang tai\n");
        while(k!=0){        //valid_expr,ze zui hou yi ding hui tiao chu xun huan
          i=i+1;
           //printf("%d\n",k);
          if(tokens[i].type=='(')         k++;
          else if(tokens[i].type==')')    k--;
        }  
      }
     
      if(op_flag(i)==1){      //que ren shi yun suan fu > operator
      int j;
      for(j=0;j<NR_PRIORITY;j++)
        {if(priorities[j].op_type == tokens[i].type)
              break; }        //shi yong dang qian i dui ying de type de  you xian ji qu bi jiao
        if(priorities[j].level>=priority){
          priority = priorities[j].level;
          ch_op = i;
          //printf("zhu cao zuo fu = %d\n",priorities[j].op_type);
          //printf("%d\n",ch_op);
      }
      }
    }   //for sao miao wan cheng,zhu yun suan fu wei zhi  shi ch_op
  int op_type = tokens[ch_op].type;
  //printf("**************");
  //printf("%d\n",op_type);
  u_int32_t val_op1=0;
  u_int32_t val_op2=0;
  //long *defref=NULL;
  //bool      valid = true;
  //if(op_type!=DEREF){
    val_op1 = eval(p,ch_op-1);
    val_op2 = eval(ch_op+1,q);//}
    //printf("val_op1=%d\nval_op2=%d\n",val_op1,val_op2);
    //printf("**************\n");
    switch (op_type)
    {
    case '+': return val_op1+val_op2;   break;
    case '-': return val_op1-val_op2;   break;
    case '*': return val_op1*val_op2;   break;
    case '/': return val_op1/val_op2;   break;
    case TK_AND:  return (val_op1&&val_op2);  break;
    case TK_EQ :  return (val_op1==val_op2);  break;
    case TK_UNEQ: return (val_op1!=val_op2);  break;
    //case DEREF  : *defref=(CONFIG_MBASE+val_op2); return *defref;
    default :assert(0);  break;
    }
  }  //zhu ti else de  kuo hao
}    //han shu  de  kuo hao
//strtol(tokens[ch_op+1].str,NULL,16)
word_t expr(char *e, bool *success) {
  if (!make_token(e)) {
    *success = false;
    printf("make_toke cuo wu\n");
    return 0;
  }
  make_token(e);
  //u_int32_t result=0;
  *success  = true;
  //int i=0;
  /*for(i=0;i<nr_token;i++){
    if(tokens[i].type=='*'&&(i==0||op_flag(i-1)))
    tokens[i].type = DEREF;
    printf("type=%d",tokens[i].type);
  }*/
  //result = eval(0,nr_token-1);
  //bool valid=1;
  //printf("nr_token=%d\n",nr_token);
 // for(int i=0;i<32;i++){
    //express[i] = tokens[i].str;
   // printf("tokens[%d].type=%d\n",i,tokens[i].type);
   // printf("tokens[%d].str=%s\n",i,tokens[i].str);
  //}   
  //printf("%d\n",valid);
  /*if(success)
  {*success = true;
  return result;}
  else
  {*success = false;
  printf("success cuo wu \n");
  return 0;}*/
  return eval(0,nr_token-1);
}
