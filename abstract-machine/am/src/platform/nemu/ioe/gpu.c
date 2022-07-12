#include <am.h>
#include <nemu.h>

#define SYNC_ADDR (VGACTL_ADDR + 4)

#define RMASK 0x00ff0000
#define GMASK 0x0000ff00
#define BMASK 0x000000ff
#define AMASK 0x00000000

#define WMASK 0xff00
#define HMASK 0x00ff

void __am_gpu_init() {
  int i;
  int w = 800;
  int h = 100;
  uint32_t *fb = (uint32_t *)(uintptr_t)FB_ADDR;
  for(i=0; i<w*h; i++) fb[i] = i;
  outl(SYNC_ADDR,1);
}

void __am_gpu_config(AM_GPU_CONFIG_T *cfg) {
  *cfg = (AM_GPU_CONFIG_T) {
    .present = true, .has_accel = false,
    .width   = inl(VGACTL_ADDR) & WMASK,
    .height  = inl(VGACTL_ADDR) & HMASK,
    .vmemsz  = 0
  };
}

void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *ctl) {
  if (ctl->sync) {
    outl(SYNC_ADDR, 1);
  }
}

void __am_gpu_status(AM_GPU_STATUS_T *status) {
  status->ready = true;
}
