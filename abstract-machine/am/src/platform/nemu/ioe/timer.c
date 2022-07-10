#include <am.h>
#include <nemu.h>

void __am_timer_init() {

}

void __am_timer_uptime(AM_TIMER_UPTIME_T *uptime) {
  int32_t time_h,time_l;
  time_l = inl(RTC_ADDR);
  time_h = inl(RTC_ADDR+0x4); //offset 4byte(4c-48),mei.ci.du.chu.32bit
  uptime->us = (((int64_t) time_h << 32) + time_l) ;
}

void __am_timer_rtc(AM_TIMER_RTC_T *rtc) {
  rtc->second = 0;
  rtc->minute = 0;
  rtc->hour   = 0;
  rtc->day    = 0;
  rtc->month  = 0;
  rtc->year   = 1900;
}
