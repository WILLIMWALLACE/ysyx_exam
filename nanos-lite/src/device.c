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
    }
  //c->GPRx = ret_cnt;
  return ret_cnt;
}

size_t events_read(void *buf, size_t offset, size_t len) {
  AM_INPUT_KEYBRD_T ev = io_read(AM_INPUT_KEYBRD);
  if (ev.keycode == AM_KEY_NONE) {
     memset(buf,0,strlen(buf)); free(buf);return 0;}
  else{ 
    
    if(ev.keydown){ // down
      memset(buf,0,strlen(buf));
      char temp_down[60]="kd";

      strcat(temp_down," ");
      strcat(temp_down,keyname[ev.keycode]);
      strcat(temp_down,"\n");

      memcpy(buf,temp_down,strlen(temp_down));  
      memset(buf+strlen(temp_down),0,60-strlen(temp_down));

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
      memset(buf+strlen(temp_up),0,60-strlen(temp_up));
      memset(temp_up,0,strlen(temp_up));
       return 1;
    }
    else{assert(0);}
  //return ret_cnt;
  }
}

//将文件的len字节写到buf中(我们认为这个文件不支持lseek, 可忽略offset).
size_t dispinfo_read(void *buf, size_t offset, size_t len) {
  int w = io_read(AM_GPU_CONFIG).width ;
  int h = io_read(AM_GPU_CONFIG).height ;
  sprintf((char*)buf,"WIDTE: %d\nHEIGHT: %d\n",w,h);
  return 1;
}

size_t fb_write(const void *buf, size_t offset, size_t len) {
  int total_w = io_read(AM_GPU_CONFIG).width ;
  int x = offset%total_w;
  int y = offset/total_w;
  printf("x=%d,y=%d\n",x,y);
  io_write(AM_GPU_FBDRAW, x , y , (uint32_t*)buf, 1, 1, true);
  return 0;  // len = w
}

void init_device() {
  Log("Initializing devices...");
  ioe_init();
}
