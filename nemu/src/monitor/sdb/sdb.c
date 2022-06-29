#include <isa.h>
#include <cpu/cpu.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "sdb.h"
#include <isa-def.h>
#include <memory/paddr.h>
#include <memory/host.h>

static int is_batch_mode = false;

void init_regex();
void init_wp_pool();

/* We use the `readline' library to provide more flexibility to read from stdin. */
static char* rl_gets() {
  static char *line_read = NULL;

  if (line_read) {
    free(line_read);
    line_read = NULL;
  }

  line_read = readline("(nemu) ");

  if (line_read && *line_read) {
    add_history(line_read);
  }

  return line_read;
}
/*********  ming  ling  *******************/
/* zi fu chuan->args*/
static int cmd_c(char *args) {
  cpu_exec(-1);
  return 0;
}
static int cmd_q(char *args) {
  return -1;    //pan duan cmd_q<0 ze fan hui ;;;xia mian  han  shu
}
static int cmd_si(char *args) {
  int step; // dan bu <=10
  if(args == NULL) 
  {step = 1;}                     //mo ren   1
  else
  {sscanf(args,"%d",&step);}      //str,format,save_addr
  cpu_exec(step);
  return 0;     
} 
// info  pan  duan  wei  'r',ze shu chu  regsister
static int cmd_info(char *args) {
  if(strcmp(args,"r") == 0)         // compare args[0] ,r!!! shuang yin hao biao shi char
  {isa_reg_display();}
  else{printf("info need a specific command, like 'r' or '?'");}
  return 0;
}

static int cmd_x(char *args) {
  if (args == NULL) {
    printf("please input true command!\n");
  }
  else {
    int num,  i;
    char *exp;
    uint32_t  addr;
    num = atoi(strtok(NULL, " "));//"1234"->1234 ; char(shu zi) -> int
    exp = strtok(NULL, " ");//strtok(char,"fen ge biao zhi")shou ci yong char s,zhi hou yong NULL
    addr = strtol(exp,NULL,16);
    //printf("%d\n%s\n%x\n",num,exp,addr);
    for (i = 0; i < num; i++) {
      printf("0x%lx\n", paddr_read(addr, 4));
      addr += 4;
    }
  }
  return 0;
}
static int cmd_p(char *args) {
 if (args == NULL) {
    printf("please input true command!\n");
  }
  else {
    init_regex();
    bool success=true;
    u_int32_t result = expr(args,&success);
    if(success){
      printf("result = %d",result);
    } 
    else{
      printf("expression cannot be identified!\n");
    }
  }
  return 0;
}
/***************************************/
static int cmd_help(char *args);

static struct {
  const char *name;
  const char *description;
  int (*handler) (char *);
} cmd_table [] = {
  { "help", "Display informations about all supported commands", cmd_help },
  { "c", "Continue the execution of the program", cmd_c },
  { "q", "Exit NEMU", cmd_q },
  { "si", "Step the execution of the program", cmd_si },
  { "info", "information for regsister", cmd_info },
  { "x", "scan the memory", cmd_x },
  { "p", "evaluate expression", cmd_p },
};

#define NR_CMD ARRLEN(cmd_table)

static int cmd_help(char *args) {
  /* extract the first argument */
  char *arg = strtok(NULL, " ");
  int i;

  if (arg == NULL) {
    /* no argument given */
    for (i = 0; i < NR_CMD; i ++) {
      printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
    }
  }
  else {
    for (i = 0; i < NR_CMD; i ++) {
      if (strcmp(arg, cmd_table[i].name) == 0) {
        printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
        return 0;
      }
    }
    printf("Unknown command '%s'\n", arg);
  }
  return 0;
}

void sdb_set_batch_mode() {
  is_batch_mode = true;
}

void sdb_mainloop() {
  if (is_batch_mode) {
    cmd_c(NULL);
    return;
  }

  for (char *str; (str = rl_gets()) != NULL; ) {
    char *str_end = str + strlen(str);

    /* extract the first token as the command */
    char *cmd = strtok(str, " ");
    if (cmd == NULL) { continue; }

    /* treat the remaining string as the arguments,
     * which may need further parsing
     */
    char *args = cmd + strlen(cmd) + 1;
    if (args >= str_end) {
      args = NULL;
    }

#ifdef CONFIG_DEVICE
    extern void sdl_clear_event_queue();
    sdl_clear_event_queue();
#endif

    int i;
    for (i = 0; i < NR_CMD; i ++) {
      if (strcmp(cmd, cmd_table[i].name) == 0) {
        if (cmd_table[i].handler(args) < 0) { return; }
        break;
      }
    }

    if (i == NR_CMD) { printf("Unknown command '%s'\n", cmd); }
  }
}

void init_sdb() {
  /* Compile the regular expressions. */
  init_regex();

  /* Initialize the watchpoint pool. */
  init_wp_pool();
}
