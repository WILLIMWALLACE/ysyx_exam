#ifndef __SDL_VIDEO_H__
#define __SDL_VIDEO_H__

#define SDL_HWSURFACE 0x1
#define SDL_PHYSPAL 0x2
#define SDL_LOGPAL 0x4
#define SDL_SWSURFACE  0x8
#define SDL_PREALLOC  0x10
#define SDL_FULLSCREEN 0x20
#define SDL_RESIZABLE  0x40

#define DEFAULT_RMASK 0x00ff0000
#define DEFAULT_GMASK 0x0000ff00
#define DEFAULT_BMASK 0x000000ff
#define DEFAULT_AMASK 0xff000000

typedef struct {
	int16_t x, y;
	uint16_t w, h;
} SDL_Rect;

typedef union {
  struct {
    uint8_t r, g, b, a;
  };
  uint32_t val;
} SDL_Color;

typedef struct {
	int ncolors;
	SDL_Color *colors;
} SDL_Palette;//调色板结构体

typedef struct {
	SDL_Palette *palette;//调色板参数,当BitsPerPixel>8时，为NULL。
	uint8_t BitsPerPixel;//每个像素的位数8,16,24,32
	uint8_t BytesPerPixel;//每个像素的字节数，1~4
	uint8_t Rloss, Gloss, Bloss, Aloss; //每个颜色分量的精度损失（2[RGBA]loss）指数形式
	uint8_t Rshift, Gshift, Bshift, Ashift;//每个像素分量在 像素pxiels中 的 二进制左移
	uint32_t Rmask, Gmask, Bmask, Amask;   //像素掩码
} SDL_PixelFormat;

typedef struct {
	uint32_t flags; 
	SDL_PixelFormat *format; //存储在surface中的像素格式/只读
	int w, h;		//宽、高，以像素为单位
	uint16_t pitch;		//一行像素的长度，以字节为单位
	uint8_t *pixels;	//指向实际象素数据
} SDL_Surface;

SDL_Surface* SDL_CreateRGBSurfaceFrom(void *pixels, int width, int height, int depth,
    int pitch, uint32_t Rmask, uint32_t Gmask, uint32_t Bmask, uint32_t Amask);
SDL_Surface* SDL_CreateRGBSurface(uint32_t flags, int width, int height, int depth,
    uint32_t Rmask, uint32_t Gmask, uint32_t Bmask, uint32_t Amask);
SDL_Surface* SDL_SetVideoMode(int width, int height, int bpp, uint32_t flags);
void SDL_FreeSurface(SDL_Surface *s);
void SDL_BlitSurface(SDL_Surface *src, SDL_Rect *srcrect, SDL_Surface *dst, SDL_Rect *dstrect);
void SDL_FillRect(SDL_Surface *dst, SDL_Rect *dstrect, uint32_t color);
void SDL_UpdateRect(SDL_Surface *s, int x, int y, int w, int h);
void SDL_SoftStretch(SDL_Surface *src, SDL_Rect *srcrect, SDL_Surface *dst, SDL_Rect *dstrect);
void SDL_SetPalette(SDL_Surface *s, int flags, SDL_Color *colors, int firstcolor, int ncolors);
SDL_Surface *SDL_ConvertSurface(SDL_Surface *src, SDL_PixelFormat *fmt, uint32_t flags);
uint32_t SDL_MapRGBA(SDL_PixelFormat *fmt, uint8_t r, uint8_t g, uint8_t b, uint8_t a);
int SDL_LockSurface(SDL_Surface *s);
void SDL_UnlockSurface(SDL_Surface *s);

#endif
