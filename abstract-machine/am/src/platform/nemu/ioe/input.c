#include <am.h>
#include <nemu.h>
#include <klib.h>
#define KEYDOWN_MASK 0x8000

void __am_input_keybrd(AM_INPUT_KEYBRD_T *kbd) {
  //int flag = 0;
  uint32_t key_input =  inl(KBD_ADDR);
  kbd->keydown = key_input & KEYDOWN_MASK;
    //printf("key_down = %d\n",kbd->keydown);
  if(kbd->keydown == 1){
    kbd->keycode = key_input & (~KEYDOWN_MASK);
    kbd->keydown = true;
    //printf("key_input = %d\n",key_input);
  }
  else {
     //printf("flag = %d\n",flag);
    kbd->keydown = false;
    kbd->keycode = AM_KEY_NONE;
  }
  //printf("key_input = %d\n",key_input);
  //kbd->keycode = AM_KEY_NONE;
}
