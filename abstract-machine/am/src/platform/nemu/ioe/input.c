#include <am.h>
#include <nemu.h>
#include <klib.h>
#define KEYDOWN_MASK 0x8000

void __am_input_keybrd(AM_INPUT_KEYBRD_T *kbd) {
 
  uint32_t key_input =  inl(KBD_ADDR);
  kbd->keydown = key_input >> 31;
  kbd->keycode = key_input ;
  printf("key_input = %d\n",key_input);
  //kbd->keycode = AM_KEY_NONE;
}
