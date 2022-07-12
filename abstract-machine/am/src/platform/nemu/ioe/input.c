#include <am.h>
#include <nemu.h>
#include <klib.h>
#define KEYDOWN_MASK 0x8000

void __am_input_keybrd(AM_INPUT_KEYBRD_T *kbd) {
  //int32_t  flag;
  uint32_t key_input =  inl(KBD_ADDR);
  //flag = key_input & KEYDOWN_MASK;
   // printf("key_down = %d\n",kbd->keydown);
    if((key_input & KEYDOWN_MASK) == KEYDOWN_MASK){
      if(kbd->keydown){
      kbd->keydown = key_input & KEYDOWN_MASK;
      kbd->keycode = key_input & (~KEYDOWN_MASK);
     // flag = 0;
      //printf("key_input = %d\n",key_input);
      }
      else {
      //printf("jin ru\n");
      kbd->keydown = false;
      kbd->keycode = key_input & (~KEYDOWN_MASK);
      }
    //printf("key_input = %d\n",key_input);
    //kbd->keycode = AM_KEY_NONE;
    }
    else {
      kbd->keydown = false;
      kbd->keycode = AM_KEY_NONE;
    }
}
