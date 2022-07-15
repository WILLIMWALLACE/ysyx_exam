#include <klib.h>
#include <klib-macros.h>
#include <stdint.h>
//#include <>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)
//calculate length
size_t strlen(const char *s) {
  int cnt=0;
  if(s==NULL){ 
    printf("invalid string!\n");
    assert(0);
  }
  while (*s != '\0')
  {  s++; cnt++;  }
  return cnt;
  //panic("Not implemented");
}
//string copy
char *strcpy(char *dst, const char *src) { 
  if(src==NULL||dst==NULL){
    printf("invalid string\n");
    assert(0);    
  }
  char *dst_start=dst; //store start_address
  while (*src != '\0')
  {
    *dst++ = *src++;
  }    
  *dst++ = '\0';
  return dst_start;
  //panic("Not implemented");
}
//set n bit for string copy
char *strncpy(char *dst, const char *src, size_t n) {
  if(src==NULL||dst==NULL){
    printf("invalid string\n");
    assert(0);    
  }
  int over_cnt = 0;
  int add_zero = 0;
  char *dst_start=dst; //store start_address
  if(n>strlen(src)){
    over_cnt = n-strlen(src);
    n = strlen(src);
  }
  if(n<strlen(src)){
    add_zero = 1;
  }
  if(add_zero==1){
    while(n>1){
    *dst++ = *src++;
     n--;
    }
    *dst++ = '\0';
  }
  if(add_zero==0){
    while (n--)
    {
      *dst++ = *src++;
    }
    while (over_cnt--)
    {
      *dst++ = '\0';
    }
  }
  return dst_start;
  //panic("Not implemented");
}
//combine string
char *strcat(char *dst, const char *src) {
  if(src==NULL||dst==NULL){
    printf("invalid string\n");
    assert(0);    
  }
  char *dst_start = dst;
  while(*dst!='\0'){  dst++;}
  while(*src!='\0'){ *dst++ = *src++;}
   *dst++ = '\0';
  return dst_start;
  //panic("Not implemented");
}
//string compare 1 0 -1
int strcmp(const char *s1, const char *s2) {
  if(s1==NULL||s2==NULL){
    printf("invalid string\n");
    assert(0);    
  }
  while (*s1 == *s2)
  {
    if(*s1=='\0'&&*s2=='\0')
    {   return 0; }  
    s1++; s2++;
  }
  return *s1-*s2;
  //panic("Not implemented");
}

int strncmp(const char *s1, const char *s2, size_t n) {
  if(s1==NULL||s2==NULL||n==0){
    printf("invalid input\n");
    assert(0);    
  }
  while ((*s1 == *s2) && n!=0)
  {
    if(*s1=='\0'&&*s2=='\0')
    {   return 0; }  
    s1++; s2++;n--;
  }
  return *s1-*s2;

  //panic("Not implemented");
}
//set 'c' to s_addr ----- s_addr+n
void *memset(void *s, int c, size_t n) {
  if(s==NULL){
    printf("invalid input.n=%d,s=%s\n",n,s);
    assert(0);
  }
  char *s_temp = (char*) s;
  while(n!=0){
    *s_temp++ = c;
    n--;
  }
  return s;
  //panic("Not implemented");
}
//cpoy *src's[0-n] to *dst,this can defend the memory overlap
void *memmove(void *dst, const void *src, size_t n) {
  if(src==NULL||dst==NULL||n==0){
    printf("invalid input\n");
    assert(0);
  }
  char *dst_temp = (char*) dst;
  char *src_temp = (char*) src;
  if((dst_temp>src_temp)&&(dst_temp<src_temp+n)){
    //overlap/  cong hou xiang qian
    while (n!=0)
    {
      *(dst_temp+n) = *(src_temp+n);
      n--;
    }
  }  
  else{
    while (n!=0)
    {
       *dst_temp++ = *src_temp++;
       n--;
    }
  }
  return dst;
  //panic("Not implemented");
}
//cpoy *src's[0-n] to *dst, just copy
void *memcpy(void *out, const void *in, size_t n) {
  if(n==0||in==NULL){
    printf("invalid input\n");
    assert(0);
  }
  char *out_temp = out;
  const char *in_temp  =in;  //improve ;donot change the source&dest 
  while(n!=0){
    *out_temp++ = *in_temp++;
    n--;
  }
  return  out; 
  //panic("Not implemented");
}
//
int memcmp(const void *s1, const void *s2, size_t n) {
  if(n==0||s1==NULL||s2==NULL){
    printf("invalid input\n");
    assert(0);
  }
  char *s1_temp = (char*) s1;
  char *s2_temp = (char*) s2;
  while(n--){
    if(*s1_temp>*s2_temp)
    { return 1;}
    else if(*s1_temp<*s2_temp)
    { return -1;}
    else
    { s1_temp++; s2_temp++; }
  }
  return 0;
  //panic("Not implemented");
}

#endif
