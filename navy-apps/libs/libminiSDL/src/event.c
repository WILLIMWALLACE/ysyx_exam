#include <NDL.h>
#include <SDL.h>
#include <string.h>
#define keyname(k) #k,

static const char *keyname[] = {
  "NONE",
  _KEYS(keyname)
};

int SDL_PushEvent(SDL_Event *ev) {
  return 0;
}

int SDL_PollEvent(SDL_Event *ev) {
 // printf("NOT IMMPLEMENT\n");assert(0);
  return 0;
}

int SDL_WaitEvent(SDL_Event *event) {
  char *key_buf;
  char NDL_key_type[60];
  int  key_name=0;
  printf("receive key_buf=%s\n",key_buf);
  NDL_PollEvent(key_buf, sizeof(key_buf));//obtain key infomation
  printf("receive key_buf=%s\n",key_buf);
  memset(NDL_key_type,0,60); 
  sscanf(key_buf,"%s %d",NDL_key_type,&key_name);

  if(NDL_key_type == "kd"){
    event->type           = SDL_KEYDOWN;
    event->key.keysym.sym = key_name;
  }
  else if(NDL_key_type == "ku"){
    event->type           = SDL_KEYUP;
    event->key.keysym.sym = key_name;
  }
  printf("receive key_buf=%s\n",key_buf);
  return 1;
}

int SDL_PeepEvents(SDL_Event *ev, int numevents, int action, uint32_t mask) {
  return 0;
}

uint8_t* SDL_GetKeyState(int *numkeys) {
  return NULL;
}
