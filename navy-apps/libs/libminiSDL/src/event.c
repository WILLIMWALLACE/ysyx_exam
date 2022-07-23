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
  char key_buf[60];
  char NDL_key_type[20];
  char key_name[40]; //there is 82 names; 
  
  NDL_PollEvent(key_buf, sizeof(key_buf));//obtain key infomation
  //memset(NDL_key_type,0,20); 
  //memset(key_name,0,40);
  sscanf(key_buf,"%s %s",NDL_key_type,key_name);
   //printf("NDL_key_type == %s,   key_name==%s\n",NDL_key_type,key_name);
  if(strcmp(NDL_key_type,"kd")==0){
    printf("NDL_key_type == %s,   key_name==%s\n",NDL_key_type,key_name);
    event->type           = SDL_KEYDOWN;
    for(int i=0;i<(sizeof(key_name)/sizeof(char));i++){
      if(strcmp(key_name,keyname[i])==0)
      {event->key.keysym.sym = i;printf("receive key_id=%d\n",i);break;}
    }
  }
  if(NDL_key_type == "ku"){
    event->type           = SDL_KEYUP;
    for(int i=0;i<(sizeof(key_name)/sizeof(char));i++){
      if(strcmp(key_name,keyname[i])==0)
      {event->key.keysym.sym = i;printf("receive key_id=%d\n",i);break;}
    }
  }
  return 1;
}

int SDL_PeepEvents(SDL_Event *ev, int numevents, int action, uint32_t mask) {
  return 0;
}

uint8_t* SDL_GetKeyState(int *numkeys) {
  return NULL;
}
