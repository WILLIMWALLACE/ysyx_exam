#include <am.h>
#include <nemu.h>
#include <string.h>
#include <stdio.h>
#define SYNC_ADDR (VGACTL_ADDR + 4)

#define RMASK 0x00ff0000
#define GMASK 0x0000ff00
#define BMASK 0x000000ff
#define AMASK 0x00000000

#define WMASK 0xffff0000
#define HMASK 0x0000ffff
static  uint32_t  total_w;
static  uint32_t  total_h; 

int my_min(int a, int b){
  if(a <= b){
    return a;
  }
  else {
    return b;
  }
}

void __am_gpu_init() {
  //int i;
  uint32_t screen_size = inl(VGACTL_ADDR);
  total_w = (screen_size & WMASK) >> 16;
  total_h = screen_size & HMASK;
 /* uint32_t *fb = (uint32_t *)(uintptr_t)FB_ADDR;
  for(i=0; i<total_w*total_h; i++) fb[i] = i;
  outl(SYNC_ADDR,1);*/
}

void __am_gpu_config(AM_GPU_CONFIG_T *cfg) {
  *cfg = (AM_GPU_CONFIG_T) {
    .present = true, .has_accel = false,
    .width   = total_w,
    .height  = total_h,
    .vmemsz  = 0
  };
}

void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *ctl) {
  //pixel's  zuo.biao, kuan.chang
  int x = ctl->x, y = ctl->y, w = ctl->w, h = ctl->h;
  //printf("x=%d  ,y=%d,  w=%d,  h=%d\n",x,y,w,h);
  //store address  similar to _am_gpu_init
  uint32_t *fb = (uint32_t *)(uintptr_t) FB_ADDR; 
  //di.zhi.da.xiao..shi..'uintptr_r',zhi.zhen.bian.liang..shi..32.wei.
  //pixel == 0, wu.xiao
  if (w == 0 || h == 0) {return;}
  //zhi.zhen.cun.ru, xiang.su
  uint32_t *pixels = ctl->pixels;
  //screen kuan.chang 
  //int total_w =  inl(VGACTL_ADDR) & WMASK;
  //int total_h =  inl(VGACTL_ADDR) & HMASK;
  //printf("total_w=%d,   total_h=%d\n",total_w,total_h);
 
  //main logic
  /*uint32_t scan_addr;
  for(int i=0;i<h && y+i<total_h;i++){
    scan_addr = (y+i)*total_w + x;
    fb[scan_addr]  = *pixels;
    pixels += w ;
  }*/
   //copy size
  int size_copy = sizeof(uint32_t) * my_min(total_w-x,w);
  for(int i=0;i<h&&y+i<total_h;i++){
      memcpy(&fb[(y+i)*total_w +x], pixels,size_copy);
      printf("address=%d\n",(y+i)*total_w+x);
      //pixels ++;
      pixels += w;    
  }
  if (ctl->sync) {
    outl(SYNC_ADDR, 1);
  }
}

void __am_gpu_status(AM_GPU_STATUS_T *status) {
  status->ready = true;
}
