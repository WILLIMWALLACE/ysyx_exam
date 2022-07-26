#include <NDL.h>
#include <sdl-video.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
//for test
#include <stdio.h>
// 将一张画布中的指定矩形区域复制到另一张画布的指定位置
//to output BDF char pixels infomation
void SDL_BlitSurface(SDL_Surface *src, SDL_Rect *srcrect, SDL_Surface *dst, SDL_Rect *dstrect) {
  //printf("jin ru fu zhi hui tu\n");
  assert(dst && src);
  assert(dst->format->BitsPerPixel == src->format->BitsPerPixel);
  //SDL_Rect temp_src;
  //SDL_Rect temp_dst;
  //  if rect==NULL,rect=full screen
  if(srcrect==NULL){
    srcrect->w = src->w;
    srcrect->h = src->h;
    srcrect->x = 0;
    srcrect->y = 0;
  }  
  if(dstrect==NULL){
    dstrect->w = dst->w;
    dstrect->h = dst->h;
    dstrect->x = 0;
    dstrect->y = 0;
  }  
  //draw picture
  //偏移到画布中的  某一块举行区域rect
  int screen_offset_src = (srcrect->y * src->w) + srcrect->x;
  int screen_offset_dst = (dstrect->y * dst->w) + dstrect->x;
  //在矩形区域内遍历赋值
  //printf("offset: src-position=%d,dst-position=%d\n",screen_offset_src,screen_offset_dst);
  //printf("src_rect:w=%x,h=%x\n",srcrect->w,srcrect->h);
  //printf("dst_rect:w=%d,h=%d\n",dstrect->w,dstrect->h);
  for(int i=0;i<srcrect->h;i++){
    for(int j=0;j<srcrect->w;j++){
      *((uint32_t *)dst->pixels+(i*dst->w+j + screen_offset_dst)) =  *((uint32_t *)src->pixels+(i*src->w+j + screen_offset_src));
      //dst->pixels += (i*dst->w+j + screen_offset_dst);
      //src->pixels += (i*src->w+j + screen_offset_src);
    }
  }
}
//快速以指定颜色填充矩形区域
void SDL_FillRect(SDL_Surface *dst, SDL_Rect *dstrect, uint32_t color) {
  //printf("jinru fill\n");
  SDL_Rect temp_rect;
  if(dstrect==NULL){
     //printf("fu zhi cheng gong\n");    
    temp_rect.w = dst->w;
    temp_rect.h = dst->h;
    temp_rect.x = 0;
    temp_rect.y = 0;
    dstrect      = &temp_rect;   
    //printf("fu zhi cheng gong\n");    
  }//printf("dst: x=0,y=0,w=%d,h=%d\n",dst->w,dst->h);
  //printf("temp_rect: x=%d,y=%d,w=%d,h=%d\n",temp_rect.x,temp_rect.y,temp_rect.w,temp_rect.h);
  printf("dstrect: x=%d,y=%d,w=%d,h=%d\n",dstrect->x,dstrect->y,dstrect->w,dstrect->h);
  uint32_t rect_size = (dstrect->h)*(dstrect->w);
  for(int i=0;i<rect_size;i++){
    *((uint32_t *)dst->pixels+i) = color;
  }
NDL_DrawRect((uint32_t *)dst->pixels,dstrect->x,dstrect->y,dstrect->w,dstrect->h);
}

void SDL_UpdateRect(SDL_Surface *s, int x, int y, int w, int h) {
   // printf("enter the NDL_draw\n");
   int full_screen = (x==0) && (y==0) && (w==0) && (h==0);
   int real_w = full_screen ? s->w : w;
   int real_h = full_screen ? s->h : h ;
    NDL_DrawRect((uint32_t *)s->pixels,x,y,real_w,real_h);
    //lseek(5,0,SEEK_SET);
    //printf("finish update\n");printf("w=%d,h=%d\n",w,h);
}

// APIs below are already implemented.

static inline int maskToShift(uint32_t mask) {
  switch (mask) {
    case 0x000000ff: return 0;
    case 0x0000ff00: return 8;
    case 0x00ff0000: return 16;
    case 0xff000000: return 24;
    case 0x00000000: return 24; // hack
    default: assert(0);
  }
}

SDL_Surface* SDL_CreateRGBSurface(uint32_t flags, int width, int height, int depth,
    uint32_t Rmask, uint32_t Gmask, uint32_t Bmask, uint32_t Amask) {
  assert(depth == 8 || depth == 32);
  SDL_Surface *s = malloc(sizeof(SDL_Surface));
  assert(s);
  s->flags = flags;
  s->format = malloc(sizeof(SDL_PixelFormat));
  assert(s->format);
  if (depth == 8) {
    s->format->palette = malloc(sizeof(SDL_Palette));
    assert(s->format->palette);
    s->format->palette->colors = malloc(sizeof(SDL_Color) * 256);
    assert(s->format->palette->colors);
    memset(s->format->palette->colors, 0, sizeof(SDL_Color) * 256);
    s->format->palette->ncolors = 256;
  } else {
    s->format->palette = NULL;
    s->format->Rmask = Rmask; s->format->Rshift = maskToShift(Rmask); s->format->Rloss = 0;
    s->format->Gmask = Gmask; s->format->Gshift = maskToShift(Gmask); s->format->Gloss = 0;
    s->format->Bmask = Bmask; s->format->Bshift = maskToShift(Bmask); s->format->Bloss = 0;
    s->format->Amask = Amask; s->format->Ashift = maskToShift(Amask); s->format->Aloss = 0;
  }

  s->format->BitsPerPixel = depth;
  s->format->BytesPerPixel = depth / 8;

  s->w = width;
  s->h = height;
  s->pitch = width * depth / 8;
  assert(s->pitch == width * s->format->BytesPerPixel);

  if (!(flags & SDL_PREALLOC)) {
    s->pixels = malloc(s->pitch * height);
    assert(s->pixels);
  }

  return s;
}

SDL_Surface* SDL_CreateRGBSurfaceFrom(void *pixels, int width, int height, int depth,
    int pitch, uint32_t Rmask, uint32_t Gmask, uint32_t Bmask, uint32_t Amask) {
  SDL_Surface *s = SDL_CreateRGBSurface(SDL_PREALLOC, width, height, depth,
      Rmask, Gmask, Bmask, Amask);
  assert(pitch == s->pitch);
  s->pixels = pixels;
  return s;
}

void SDL_FreeSurface(SDL_Surface *s) {
  if (s != NULL) {
    if (s->format != NULL) {
      if (s->format->palette != NULL) {
        if (s->format->palette->colors != NULL) free(s->format->palette->colors);
        free(s->format->palette);
      }
      free(s->format);
    }
    if (s->pixels != NULL && !(s->flags & SDL_PREALLOC)) free(s->pixels);
    free(s);
  }
}

SDL_Surface* SDL_SetVideoMode(int width, int height, int bpp, uint32_t flags) {
  if (flags & SDL_HWSURFACE) NDL_OpenCanvas(&width, &height);
  //printf("NDL:width=%d,height=%d\n",width,height);
  return SDL_CreateRGBSurface(flags, width, height, bpp,
      DEFAULT_RMASK, DEFAULT_GMASK, DEFAULT_BMASK, DEFAULT_AMASK);
}

void SDL_SoftStretch(SDL_Surface *src, SDL_Rect *srcrect, SDL_Surface *dst, SDL_Rect *dstrect) {
  assert(src && dst);
  assert(dst->format->BitsPerPixel == src->format->BitsPerPixel);
  assert(dst->format->BitsPerPixel == 8);

  int x = (srcrect == NULL ? 0 : srcrect->x);
  int y = (srcrect == NULL ? 0 : srcrect->y);
  int w = (srcrect == NULL ? src->w : srcrect->w);
  int h = (srcrect == NULL ? src->h : srcrect->h);

  assert(dstrect);
  if(w == dstrect->w && h == dstrect->h) {
    /* The source rectangle and the destination rectangle
     * are of the same size. If that is the case, there
     * is no need to stretch, just copy. */
    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;
    SDL_BlitSurface(src, &rect, dst, dstrect);
  }
  else {
    assert(0);
  }
}

void SDL_SetPalette(SDL_Surface *s, int flags, SDL_Color *colors, int firstcolor, int ncolors) {
  assert(s);
  assert(s->format);
  assert(s->format->palette);
  assert(firstcolor == 0);

  s->format->palette->ncolors = ncolors;
  memcpy(s->format->palette->colors, colors, sizeof(SDL_Color) * ncolors);

  if(s->flags & SDL_HWSURFACE) {
    assert(ncolors == 256);
    for (int i = 0; i < ncolors; i ++) {
      uint8_t r = colors[i].r;
      uint8_t g = colors[i].g;
      uint8_t b = colors[i].b;
    }
    //printf("***************\n");
    //printf("s_w=%d,s_h=%d\n",s->w,s->h);
    SDL_UpdateRect(s, 0, 0, s->w, s->h);
  }
}

static void ConvertPixelsARGB_ABGR(void *dst, void *src, int len) {
  int i;
  uint8_t (*pdst)[4] = dst;
  uint8_t (*psrc)[4] = src;
  union {
    uint8_t val8[4];
    uint32_t val32;
  } tmp;
  int first = len & ~0xf;
  for (i = 0; i < first; i += 16) {
#define macro(i) \
    tmp.val32 = *((uint32_t *)psrc[i]); \
    *((uint32_t *)pdst[i]) = tmp.val32; \
    pdst[i][0] = tmp.val8[2]; \
    pdst[i][2] = tmp.val8[0];

    macro(i + 0); macro(i + 1); macro(i + 2); macro(i + 3);
    macro(i + 4); macro(i + 5); macro(i + 6); macro(i + 7);
    macro(i + 8); macro(i + 9); macro(i +10); macro(i +11);
    macro(i +12); macro(i +13); macro(i +14); macro(i +15);
  }

  for (; i < len; i ++) {
    macro(i);
  }
}

SDL_Surface *SDL_ConvertSurface(SDL_Surface *src, SDL_PixelFormat *fmt, uint32_t flags) {
  assert(src->format->BitsPerPixel == 32);
  assert(src->w * src->format->BytesPerPixel == src->pitch);
  assert(src->format->BitsPerPixel == fmt->BitsPerPixel);

  SDL_Surface* ret = SDL_CreateRGBSurface(flags, src->w, src->h, fmt->BitsPerPixel,
    fmt->Rmask, fmt->Gmask, fmt->Bmask, fmt->Amask);

  assert(fmt->Gmask == src->format->Gmask);
  assert(fmt->Amask == 0 || src->format->Amask == 0 || (fmt->Amask == src->format->Amask));
  ConvertPixelsARGB_ABGR(ret->pixels, src->pixels, src->w * src->h);

  return ret;
}

uint32_t SDL_MapRGBA(SDL_PixelFormat *fmt, uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
  assert(fmt->BytesPerPixel == 4);
  uint32_t p = (r << fmt->Rshift) | (g << fmt->Gshift) | (b << fmt->Bshift);
  if (fmt->Amask) p |= (a << fmt->Ashift);
  return p;
}

int SDL_LockSurface(SDL_Surface *s) {
  return 0;
}

void SDL_UnlockSurface(SDL_Surface *s) {
}
