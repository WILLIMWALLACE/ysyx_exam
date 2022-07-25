#define SDL_malloc  malloc
#define SDL_free    free
#define SDL_realloc realloc

#define SDL_STBIMAGE_IMPLEMENTATION
#include "SDL_stbimage.h"

SDL_Surface* IMG_Load_RW(SDL_RWops *src, int freesrc) {
  assert(src->type == RW_TYPE_MEM);
  assert(freesrc == 0);
  return NULL;
}
SDL_Surface* IMG_Load(const char *filename) {
  printf("IMG_Load:%s\n",filename);
  FILE *fp = fopen(filename, "r+");
  assert(fp!=NULL);

  fseek(fp,0,SEEK_END);
  int size=ftell(fp);
  printf("SDL_Surface* IMG_Load:%d\n",size);
  uint8_t *buf=(uint8_t *)malloc(size);
  fseek(fp,0,SEEK_SET);
  assert(fread(buf,size,1,fp)==1);
  SDL_Surface* screen=STBIMG_LoadFromMemory(buf, size);
  assert(screen!=NULL);
  free(buf);
  printf("=====================SDL_Surface* IMG_Load\n");
  return screen;
}
/*SDL_Surface* IMG_Load(const char *filename) {
  FILE *fp = fopen(filename, "r");
  if(fp==NULL){ printf("fp==NULL,invalid filename!\n"); assert(0);}
  //fp will move to the end of file
  fseek(fp,0,SEEK_END);
  //obtain the num(char) of string ,from start to presetn fp
  int len = ftell(fp);
  printf("file len = %d\n",len);
  uint8_t *pixels = malloc(len*sizeof(uint8_t));  
  assert(pixels!=NULL);
  printf("finish malloc\n");
  fseek(fp,0,SEEK_SET);

  assert(1==fread(pixels,len,1,fp));
  printf("pixel=%s\n",pixels);
  SDL_Surface *surface = STBIMG_LoadFromMemory(pixels,len);
  printf("finish STBIMG_LoadFromMemory\n");
  if(surface==NULL) 
  {printf("surface==NULL,STBIMG_LoadFromMemory failed\n"); assert(0);}
  
  free(pixels);
  fclose(fp);
  
  return surface;
}*/

int IMG_isPNG(SDL_RWops *src) {
  return 0;
}

SDL_Surface* IMG_LoadJPG_RW(SDL_RWops *src) {
  return IMG_Load_RW(src, 0);
}

char *IMG_GetError() {
  return "Navy does not support IMG_GetError()";
}
