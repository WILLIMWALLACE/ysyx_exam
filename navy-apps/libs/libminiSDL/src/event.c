#include <NDL.h>
#include <SDL.h>
#include <string.h>
#include <assert.h>
#define keyname(k) #k,

static uint8_t keystate[83]={0};

static const char *keyname[] = {
  "NONE",
  _KEYS(keyname)
};

int SDL_PushEvent(SDL_Event *ev) {
  printf("not immplement SDL_PushEvent\n");
  assert(0);
  return 0;
}

int SDL_PollEvent(SDL_Event *ev) {
  //printf("enter SDL_PollEvent\n");
  char key_buf[60];
  char NDL_key_type[20];
  char key_name[40]; //there is 82 names; 
  
  memset(key_buf,0,60);
  //printf("finish memset\n");
  NDL_PollEvent(key_buf, sizeof(key_buf));//obtain key infomation
  //printf("finish NDL_PollEvent\n");
  //printf("key_buf = %s\n",key_buf);
  if(*key_buf == 0){ return 0;} 
  else{
  //printf("enter identify key!\n");
  memset(NDL_key_type,0,20); 
  memset(key_name,0,40);
  sscanf(key_buf,"%s %s",NDL_key_type,key_name);
   if(strcmp(NDL_key_type,"kd")==0){
    ev->type           = SDL_KEYDOWN;
    for(int i=0;i<83;i++){
      if(strcmp(key_name,keyname[i])==0)
      { 
        keystate[i]        = 1;
        ev->key.keysym.sym = i;
        printf("poll event %d\n",i); 
        break;
      }
    }
   }
   else if(strcmp(NDL_key_type,"ku")==0){
    ev->type           = SDL_KEYUP;
    for(int i=0;i<83;i++){
      if(strcmp(key_name,keyname[i])==0)
      { keystate[i]        = 1;
        ev->key.keysym.sym = i;
        printf("poll event %d\n",i); 
        break;}
    }
   }
   else{
    ev->type = SDL_USEREVENT;
    printf("can not identify user_event\n");
    assert(0);
   }
   //printf("exit SDL_PollEvent!\n");
  return 1;
  }
}

int SDL_WaitEvent(SDL_Event *event) {
  printf("enter SDL_WaitEvent\n");
  char key_buf[60];
  char NDL_key_type[20];
  char key_name[40]; //there is 82 names; 
  
  NDL_PollEvent(key_buf, sizeof(key_buf));//obtain key infomation
  memset(NDL_key_type,0,20); 
  memset(key_name,0,40);
  sscanf(key_buf,"%s %s",NDL_key_type,key_name);
   //printf("NDL_key_type == %s,   key_name==%s\n",NDL_key_type,key_name);
  if(strcmp(NDL_key_type,"kd")==0){
   // printf("NDL_key_type == %s,   key_name==%s\n",NDL_key_type,key_name);
   //printf("SIZE=%d\n",(sizeof(key_name)/sizeof(char)));
    event->type           = SDL_KEYDOWN;
    for(int i=0;i<83;i++){
      if(strcmp(key_name,keyname[i])==0)
      { keystate[i]           = 1;
        event->key.keysym.sym = i;
        printf("wait event %d\n",i);
        break;}
    }
  }
  if(strcmp(NDL_key_type,"ku")==0){
    event->type           = SDL_KEYUP;
    for(int i=0;i<83;i++){
      if(strcmp(key_name,keyname[i])==0)
      {event->key.keysym.sym = i;break;}
    }
  }
  return 1;
}

int SDL_PeepEvents(SDL_Event *ev, int numevents, int action, uint32_t mask) {
  printf("not immplement SDL_PeepEvents\n");
  assert(0);
  return 0;
}

uint8_t* SDL_GetKeyState(int *numkeys) {
 // printf("enter SDL_GetKeyState\n");
  //for(int i=0;i<83;i++){
  //printf("keystate= 0x%lx\n",keystate);
  //printf("leng=%ld\n",sizeof(keystate));
  //}
  //assert(0);
  return keystate;
}
