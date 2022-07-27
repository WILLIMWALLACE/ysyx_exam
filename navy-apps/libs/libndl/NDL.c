#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <assert.h>

static int evtdev = -1;
static int fbdev = -1;
static int screen_w = 0, screen_h = 0;

uint32_t NDL_GetTicks() {
  struct timeval tv;
  gettimeofday(&tv, NULL);
  uint64_t ms = tv.tv_sec * 1000 + tv.tv_usec / 1000;
  return ms;
}
// 读出一条事件信息, 将其写入`buf`中, 最长写入`len`字节
// 若读出了有效的事件, 函数返回1, 否则返回0
int NDL_PollEvent(char *buf, int len) {
  FILE *fp;
  fp = fopen("/dev/events","r");
  if(fp == NULL){printf("bu cun zai wen jian\n");assert(0);} 
  else{
    //fread(buf,len,1,fp);
    int fd = fileno(fp);
    //*buf = NULL;
    memset(buf,0,strlen(buf));
    //printf("finish open\n");
    int flag = read(fd,buf,0);
    //printf("finish read\n");
    //if(buf!=NULL){ printf("receive key = %s\n",buf);}
    fclose(fp);
    if(flag == 0){return 0;}
    else{return 1;}
  }
  //return 0;
}
// 打开一张(*w) X (*h)的画布
// 如果*w和*h均为0, 则将系统全屏幕作为画布, 并将*w和*h分别设为系统屏幕的大小
void NDL_OpenCanvas(int *w, int *h) {
  ///////////////// add /////////////////////
    FILE *fp;
    fp = fopen("/proc/dispinfo","r");
    if(fp == NULL){printf("bu cun zai wen jian\n");assert(0);} 
    else{
    int fd = fileno(fp);
    char buffer[60]; 
    char key_info[60];
    int read_w,read_h;
    memset(buffer,0,60); memset(key_info,0,60);
    read(fd, buffer, 0);
    sscanf(buffer,"%s %d %s %d",key_info,&read_w,key_info,&read_h);
   // printf("key_info = %s,read_w=%d\n",key_info,read_w);
   
    if(*w<read_w && *w!=0){ screen_w = *w; }
    if(*h<read_h && *h!=0){ screen_h = *h; }
    if(*w>=read_w || *w==0) { screen_w = read_w; *w=read_w;}
    if(*h>=read_h || *h==0) { screen_h = read_h; *h=read_h;}

    fclose(fp);
    }
    //////////////////  add  ////////////////////
  if (getenv("NWM_APP")) {
    int fbctl = 4;
    fbdev = 5;
    //screen_w = *w; 
    //screen_h = *h;
    char buf[64];
    int len = sprintf(buf, "%d %d", screen_w, screen_h);
    // let NWM resize the window and create the frame buffer
    write(fbctl, buf, len);
    while (1) {
      // 3 = evtdev
      int nread = read(3, buf, sizeof(buf) - 1);
      if (nread <= 0) continue;
      buf[nread] = '\0';
      if (strcmp(buf, "mmap ok") == 0) break;
    }
    close(fbctl);
  }
}
// 向画布`(x, y)`坐标处绘制`w*h`的矩形图像, 并将该绘制区域同步到屏幕上
// 像素按行优先方式存储在`pixels`中, 每个像素用32位整数以`00RRGGBB`的方式描述颜色
void NDL_DrawRect(uint32_t *pixels, int x, int y, int w, int h) {
  uint32_t *buffer[w*4];//every address present one byte
   FILE *fp;
   fp = fopen("/dev/fb","r");
   if(fp == NULL){printf("bu cun zai wen jian\n");assert(0);} 
   int fd = fileno(fp);
   memset(buffer,0,w*4);
    lseek(5,0,SEEK_SET);
  for(int i=0;i<h;i++,pixels+=w){
    //printf("jin ru fu zhi\n");
    //printf("len_pixels=%d\n",sizeof(uint32_t));
    //printf("&buffer[y+i]=%d,pixels=%d,w=%d\n",&buffer[y+i], pixels, w);
    //memcpy(&buffer[(y+i)*w], pixels, w*4);
    //printf("x=%d,y=%d\n",x,y);
    memcpy(buffer, pixels, w*4);
    //printf("buffer=%d,pixels=%s\n",*buffer,pixels);
    //printf("fu zhi wan cheng\n");
    write(fd,buffer,w);
    //printf("w****=%d\n",w);
    //printf("system call write\n");
  }  
   fclose(fp);
}

void NDL_OpenAudio(int freq, int channels, int samples) {
}

void NDL_CloseAudio() {
}

int NDL_PlayAudio(void *buf, int len) {
  return 0;
}

int NDL_QueryAudio() {
  return 0;
}

int NDL_Init(uint32_t flags) {
  if (getenv("NWM_APP")) {
    evtdev = 3;
  }
  return 0;
}

void NDL_Quit() {
}
