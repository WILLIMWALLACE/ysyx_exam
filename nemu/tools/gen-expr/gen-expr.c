#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>

// this should be enough
static char buf[65536] = {};
static char code_buf[65536 + 128] = {}; // a little larger than `buf`
static char *code_format =
"#include <stdio.h>\n"
"int main() { "
"  unsigned result = gen_rand_expr(); "
"  printf(\"%%u\", result); "
"  return 0; "
"}";

static int choose(int n){
  u_int32_t seed=time(NULL);
  srand(seed);
  return rand()%n;
}

static int gen_op(){
  int branch=choose(4);
  switch(branch){
    case 0: return  '+'; break;
    case 1: return  '-'; break;
    case 2: return  '*'; break;
    case 3: return  '/'; break;
    default:assert(0);
  }
}
static void gen_rand_expr() {
  //buf[0] = '\0';
  int i;
    for(i=0;i<100;){
    switch(choose(3)){
      case 0:   buf[i]=choose(100); i++; break; //gen_num
      case 1:   buf[i]='('; buf[i+1]=;buf[i+2]=')';
                i=i+2;                   break; //gen(  \  )  \  ()
      default:      ;break;//gen_op,gen_expr
    }
    }
}

int main(int argc, char *argv[]) {
  int seed = time(0);
  srand(seed);
  int loop = 1;
  if (argc > 1) {
    sscanf(argv[1], "%d", &loop);
  }
  int i;
  for (i = 0; i < loop; i ++) {
    gen_rand_expr();

    sprintf(code_buf, code_format, buf);

    FILE *fp = fopen("/tmp/.code.c", "w");
    assert(fp != NULL);
    fputs(code_buf, fp);
    fclose(fp);

    int ret = system("gcc /tmp/.code.c -o /tmp/.expr");
    if (ret != 0) continue;

    fp = popen("/tmp/.expr", "r");
    assert(fp != NULL);

    int result;
    fscanf(fp, "%d", &result);
    pclose(fp);

    printf("%u %s\n", result, buf);
  }
  return 0;
}