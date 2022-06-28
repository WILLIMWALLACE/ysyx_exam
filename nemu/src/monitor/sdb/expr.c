#include <isa.h>

/* We use the POSIX regex functions to process regular expressions.
 * Type 'man regex' for more information about POSIX regex functions.
 */
#include <regex.h>

enum {
  TK_NOTYPE = 256, TK_OR = 257, TK_EQ=258, TK_NUMD=259,

  /* TODO: Add more token types */

};

static struct rule {
  const char *regex;
  int token_type;
} rules[] = {

  /* TODO: Add more rules.
   * Pay attention to the precedence level of different rules.
   */

  {" +", TK_NOTYPE},    // spaces
  {"\\(", '('},         //  (
  {"\\)", ')'},         //  )
  {"\\+", '+'},         // plus
  {"\\-", '-'},         //sub
  {"\\*", '*'},         //multi
  {"/", '/'},         //divide  
  {"\\|\\|", TK_OR},  //   || or
  {"==", TK_EQ},        // equal
  {"[0-9]+", TK_NUMD},
};

#define NR_REGEX ARRLEN(rules)

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
  char* str[32];
} Token;

static Token tokens[32] __attribute__((used)) = {};
static int nr_token __attribute__((used))  = 0;

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
        /* TODO: Now a new token is recognized with rules[i]. Add codes
         * to record the token in the array `tokens'. For certain types
         * of tokens, some extra actions should be performed.
         */
        int j;
        switch (rules[i].token_type) {
          case TK_NOTYPE:{tokens->type=rules[i].token_type; break;}  
          case '(':      {tokens->type=rules[i].token_type; 
            for(j=0;j<substr_len;j++){tokens->str[j] = (substr_start+j);}
              tokens->str[j] = '\0';                        break;} 
          case ')':      {tokens->type=rules[i].token_type; 
            for(j=0;j<substr_len;j++){tokens->str[j] = (substr_start+j);}
              tokens->str[j] = '\0';                        break;}  
          case '-':      {tokens->type=rules[i].token_type; 
          for(j=0;j<substr_len;j++){tokens->str[j] = (substr_start+j);}
              tokens->str[j] = '\0';                        break;}  
          case '*':      {tokens->type=rules[i].token_type; 
           for(j=0;j<substr_len;j++){tokens->str[j] = (substr_start+j);}
              tokens->str[j] = '\0';                        break;}  
          case '+':      {tokens->type=rules[i].token_type; 
          for(j=0;j<substr_len;j++){tokens->str[j] = (substr_start+j);}
              tokens->str[j] = '\0';                        break;}  
          case '/':      {tokens->type=rules[i].token_type; 
           for(j=0;j<substr_len;j++){tokens->str[j] = (substr_start+j);}
              tokens->str[j] = '\0';                        break;}  
          case TK_NUMD:  {tokens->type=rules[i].token_type; 
           for(j=0;j<substr_len;j++){tokens->str[j] = (substr_start+j);}
              //tokens->str[j] = '\0';          
                            break;}  
          default: TODO();
        }
        printf("%d\n%.*s\n",tokens->type,substr_len,tokens->str[3]);
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


word_t expr(char *e, bool *success) {
  if (!make_token(e)) {
    *success = false;
    return 0;
  }

  /* TODO: Insert codes to evaluate the expression. */
  int result = 6;
  //TODO();

  return result;
}
