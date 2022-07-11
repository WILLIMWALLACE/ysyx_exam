#include <am.h>
#include <nemu.h>

static uint64_t start_time=0;
void __am_timer_init() {
  uint32_t time_h,time_l;
  time_l = inl(RTC_ADDR);
  time_h = inl(RTC_ADDR+0x4); //offset 4byte(4c-48),mei.ci.du.chu.32bit
  start_time = (((uint64_t) time_h << 32) + time_l);
}

void __am_timer_uptime(AM_TIMER_UPTIME_T *uptime) {
  uint32_t time_h,time_l;
  time_l = inl(RTC_ADDR);
  time_h = inl(RTC_ADDR+0x4); //offset 4byte(4c-48),mei.ci.du.chu.32bit
  uptime->us = (((uint64_t) time_h << 32) + time_l)  - start_time ;
}

void __am_timer_rtc(AM_TIMER_RTC_T *rtc) {
  rtc->second = 0;
  rtc->minute = 0;
  rtc->hour   = 0;
  rtc->day    = 0;
  rtc->month  = 0;
  rtc->year   = 1900;
}
