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
  if (ev.keycode == AM_KEY_NONE) {
     memset(buf,0,strlen(buf)); free(buf);return 0;}
  else{ 
    //memset(buf,0,1);
    //int ret_cnt=0;
    if(ev.keydown){ // down
      memset(buf,0,strlen(buf));
      char temp_down[60]="kd";
      strcat(temp_down," ");
      strcat(temp_down,keyname[ev.keycode]);
      strcat(temp_down,"\n");
      //ret_cnt=0;
      printf("buf_start=%s\n",buf);
      memcpy(buf,temp_down,strlen(temp_down));
      printf("length=%d\n",strlen(temp_down));
      printf("****buf=%s,temp=%s\n",buf,temp_down);
      memset(buf+strlen(buf),0,60-strlen(temp_down));
      printf("60-strlen(temp_down)=%d\n",60-strlen(temp_down));
       memset(temp_down,0,strlen(temp_down));
      //return 60;
      return 1;
    }
    else if(!ev.keydown){ //up
      memset(buf,0,strlen(buf));
      char temp_up[60] = "ku";
      //ret_cnt = 0;
      strcat(temp_up," ");
      strcat(temp_up,keyname[ev.keycode]);
      strcat(temp_up,"\n");
      memcpy(buf,temp_up,strlen(temp_up));
      memset(buf+strlen(buf),0,60-strlen(temp_up));
      memset(temp_up,0,strlen(temp_up));
       return 1;
    }
    else{assert(0);}
  //return ret_cnt;
  }
}

/*down
      while(*temp_down!='\n'){
        *(char*)buf = *temp_down; 
        buf++; temp_down++;
        //ret_cnt++;
      }
  up
      while(*temp_up!='\n'){
        *(char*)buf = *temp_up;
        buf++ ;temp_up++;
        //ret_cnt++;
      }
*/
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
