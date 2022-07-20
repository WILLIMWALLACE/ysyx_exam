#include <common.h>

#if defined(MULTIPROGRAM) && !defined(TIME_SHARING)
# define MULTIPROGRAM_YIELD() yield()
#else
# define MULTIPROGRAM_YIELD()
#endif

#define NAME(key) \
  [AM_KEY_##key] = #key,

static const char *keyname[256] __attribute__((used)) = {
  [AM_KEY_NONE] = "NONE",
  AM_KEYS(NAME)
};

size_t serial_write(const char *buf, size_t offset, size_t len) {
   int ret_cnt=0;
    while(len!=0){
        putch(*buf);
      buf++; len--; ret_cnt++;
      //printf("da yin zi fu chuan\n");
    }
  //c->GPRx = ret_cnt;
  return ret_cnt;
}

size_t events_read(void *buf, size_t offset, size_t len) {
  AM_INPUT_KEYBRD_T ev = io_read(AM_INPUT_KEYBRD);
  if (ev.keycode == AM_KEY_NONE) {memset(buf,0,1); return 0;}
  else{ 
    memset(buf,0,1);
    int ret_cnt=0;
    if(ev.keydown){ // down
      char *temp_down = "kd";
      //memset(temp_down,"kd",);
      strcat(temp_down," ");
      strcat(temp_down,keyname[ev.keycode]);
     // strcat(temp_down,"\n");
      //memset(temp_down,'\n',1);
      //printf("keyname=%d\n",keyname[ev.keycode]);
      ret_cnt=0;
      while(*temp_down!='\n'){
        *(char*)buf = *temp_down; 
        buf++; temp_down++;
        ret_cnt++;
      }  
      return ret_cnt;
    }
    else if(!ev.keydown){ //up
      //char *temp_up = {"ku",ev.keycode};
      char *temp_up = "ku";
      strcat(temp_up," ");
      strcat(temp_up,keyname[ev.keycode]);
     // strcat(temp_up,"\n");
     // memset(temp_up+2,(char)ev.keycode,32);
      ret_cnt = 0;
      while(*temp_up!='\n'){
        *(char*)buf = *temp_up;
        printf("[buf]%s\t[tmp]%s\n",buf,temp_up);
        buf++ ;temp_up++;
        ret_cnt++;
      }
      return ret_cnt;
    }
    else{assert(0);}
  //return ret_cnt;
  }
}

size_t dispinfo_read(void *buf, size_t offset, size_t len) {
  return 0;
}

size_t fb_write(const void *buf, size_t offset, size_t len) {
  return 0;
}

void init_device() {
  Log("Initializing devices...");
  ioe_init();
}
