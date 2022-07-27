#include <NDL.h>
#include <sdl-timer.h>
#include <stdio.h>

SDL_TimerID SDL_AddTimer(uint32_t interval, SDL_NewTimerCallback callback, void *param) {
  printf("NOT IMMPLEMENT\n");//assert(0);
  return NULL;
}

int SDL_RemoveTimer(SDL_TimerID id) {
  printf("NOT IMMPLEMENT\n");//assert(0);
  return 1;
}

uint32_t SDL_GetTicks() {
  printf("sdl_getticks\n");
uint32_t ms = NDL_GetTicks(); 
  return ms;
}

void SDL_Delay(uint32_t ms) {
}
