#include <am.h>
#include <nemu.h>
#include <klib.h>
#define KEYDOWN_MASK 0x8000

void __am_input_keybrd(AM_INPUT_KEYBRD_T *kbd) {
  int32_t  flag;
  uint32_t key_input =  inl(KBD_ADDR);
  flag = key_input & KEYDOWN_MASK;
   // printf("key_down = %d\n",kbd->keydown);
    if(flag == KEYDOWN_MASK){
      kbd->keydown = true;
      kbd->keycode = key_input & (~KEYDOWN_MASK);
      flag = 0;
      //printf("key_input = %d\n",key_input);
    }
    else {
      printf("jin ru\n");
      kbd->keydown = false;
      kbd->keycode = AM_KEY_NONE;
    }
    //printf("key_input = %d\n",key_input);
    //kbd->keycode = AM_KEY_NONE;
}
