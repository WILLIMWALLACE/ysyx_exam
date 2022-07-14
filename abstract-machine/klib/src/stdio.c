#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdarg.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

//zhi.shu 
static uint64_t my_pow(int x, int y){
  uint64_t sum = 1;
  while (y--)
  {
    sum *= x;
  }
  return sum;
}
//jin.zhi.zhuan.huan
static char *base_convert(uint64_t num,int base){
  static char num_lib[]="0123456789";  //ke.xuan.can.shu
  
  static char buf[60];                 //
  char *str;                           //huan.cun
  str = &buf[59];
  *str = '\0';                          //mo.wei.tian.jia '\0',jie.shu.biao.zhi
  do{
    *--str = num_lib[num%base];
    num   /= base;
  }while(num!=0);
  return (str);
}

int printf(const char *fmt, ...) {
  va_list exp_val;//printf yin hao hou mian shi ji zhi
  int num_val,rnum_val; //for %d
  char *ptr = NULL;      //for %s
  char count,single_h;   //calculate the length of num_val,dan.ge. cong.gao.dao.di
  va_start(exp_val,fmt); //initial exp_val->'a' ***printf("%c",'a');

  while (*fmt != '\0')
  {
    if(*fmt == '%')
    {
      fmt++;
      switch(*fmt){
        case 'd': 
        num_val  = va_arg(exp_val,int); //return exp_val de xia.yi.ge int lei.xing
        rnum_val = num_val;            //huan.cun shu zhi
        count    = 0;
        while(rnum_val){   //calculate the length of num_val
          count++;
          rnum_val /= 10;
        }
        rnum_val = num_val; //chong.xin.huo.qu.'num'.de.shi.ji.zhi
        while(count){

          if(my_pow(10,count-1)==0){printf("div 0 yi chu\n"); assert(0);}
          
          single_h = rnum_val/my_pow(10,count-1);//mei.ci.qu.chu.gao.wei.
          rnum_val %= my_pow(10,count-1); //yu.shu.->sheng.xia.de.di.wei.shu.zhi
          putch(single_h+'0');
          count--;
        }   break;
        case 's':
        ptr = va_arg(exp_val,char *);
        putstr(ptr);  break;
        //case 'c':
      }   
    }
    else if(*fmt == '\n'){
      putch('\n');
    }
    else{
      putch(*fmt); 
    }
    fmt++;
  }
  va_end(exp_val);
  return 0;
  //panic("Not implemented");
}
/////////////////////////////////
/*char str[11];
char tab[16] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};

char *out_num(long num,int base,char leader_m,int minwidth){
  int i=0;
  int len=0;
  long num_;
  //num_ is positive num
  if(num<0){
    num_ = -num;
  }else{
    num_ = num;
  }
  //num_ = 0
  if(num_==0){
    if(minwidth==0){
      str[0] = '0';
      str[1] = '\0';
    } else{
      str[minwidth]   = '\0';
      str[minwidth-1] = '0' ;
      int width = minwidth - 2;
      for(;width>=0;width--){
        str[width] = leader_m;
      }
    }
  }
  //num_ != 0
  else{
    for(i=1;num_/i!=0;i*=base)
    len++;
    if(len<minwidth){
      str[minwidth]   = '\0';
      for(;num_!=0;num_/= base){
        minwidth -= 1;
        str[minwidth] = tab[num_ % base];
      }
      for(minwidth-=1;minwidth!=0;minwidth--){
        str[minwidth] = leader_m;
      }
      if(num>0) str[minwidth] = leader_m;
      else str[minwidth] = '-';
    }else{
      if(num>0){
        str[len] = '\0';
        for(len-=1;len>=0;len--){
          str[len] = tab[num_%base];
          num_ /= base;
        }
      }else{
        str[len+1] = '\0';
        for(;len!=0;len--){
          str[len] = tab[num_%base];
          num_ /= base;
        }
        str[len] = '-';
      }
    }
  }
  return str;
}


int printf(const char *fmt, ...) {
  va_list ap;
  va_start(ap,fmt);
  while(*fmt!='\0'){
    switch(*fmt){
      case '%':{  
        fmt++;
        int minwidth = 0;
        char leader_m = ' ';
        //leader mark
        if(*fmt == '0'){
          leader_m = '0';
          fmt++;
        }
        //the length of data
        while(*fmt>'0' && *fmt<'9'){
          minwidth *= 10;
          minwidth += *fmt -'0';
          fmt++;
        }
        switch(*fmt){
          case'c':{
            putch (va_arg(ap,int));
            fmt++;
            break;
          }
          case's':{
            char* str= va_arg(ap,char*);
            while(*str!='\0' && str!=NULL){
              putch (*str);
              str++; 
            }
            fmt++;
            break;
          }
          case'd':{
            char* str_num = out_num(va_arg(ap,int),10,leader_m, minwidth);
            while(*str_num!='\0'){
              putch (*str_num);
              str_num++; 
            }
            fmt++;
            break;
          }
          case'o':{
            char* str_num = out_num(va_arg(ap,unsigned int),8,leader_m, minwidth);
            while(*str_num!='\0'){
              putch (*str_num);
              str_num++; 
            }
            fmt++;
            break;
          }
          case'u':{
            char* str_num = out_num(va_arg(ap,unsigned int),10,leader_m, minwidth);
            while(*str_num!='\0'){
              putch (*str_num);
              str_num++; 
            }
            fmt++;
            break;
          }
          case'x':{
            char* str_num = out_num(va_arg(ap,unsigned int),16,leader_m, minwidth);
            while(*str_num!='\0'){
              putch (*str_num);
              str_num++; 
            }
            fmt++;
            break;
          }
          case'%':{
            putch(*fmt);
            fmt++;
            break;
          }
        }
        break;
      } 
      default:{
      putch(*fmt);
      fmt++;
      break;
      }
    }
    
  }
  va_end(ap);
  return 0;
}
*/



/////////////////////////////////////
int vsprintf(char *out, const char *fmt, va_list ap) {
  panic("Not implemented");
}

int sprintf(char *out, const char *fmt, ...) {
  va_list exp_val;
  int num_val;
  char *ptr  = NULL;
  //char *temp = NULL;

  va_start(exp_val,fmt);  //ti.qu
  for(;*fmt != '\0'; fmt++)
  {
    while (*fmt != '%')
    {
      *out = *fmt;   
      if(*fmt == '\0'){ break; }
      out++;  fmt++;     //bu.shi.guan.jian.zi, zhi.jie.bao.cun.  
    }
    if(*fmt == '\0') {  break; }
    fmt++;              //chu.xian.'%', xiang.hou.yi.wei, de.dao.'csd'deng.
    switch(*fmt){
      case 'd':
      num_val = va_arg(exp_val,int); //bao.cun.shi.jin.zhi.shu
      if(num_val<0){
        num_val = -num_val;
        *out    = '-';
        out++;
      }
      ptr = base_convert(num_val,10); //int -> char'01231'
      while(*ptr != '\0'){
        *out = *ptr; ptr++; out++;
      }break;
      case 's':
      ptr = va_arg(exp_val,char *);
      while(*ptr != '\0'){
        *out = *ptr; ptr++; out++;
      }  break;
      default:printf("need %s or %d\n"); assert(0); 
    }
  }
  *out = '\0';
  va_end(exp_val);
  return 0;
  //panic("Not implemented");
}

int snprintf(char *out, size_t n, const char *fmt, ...) {
  panic("Not implemented");
}

int vsnprintf(char *out, size_t n, const char *fmt, va_list ap) {
  panic("Not implemented");
}

#endif
