#ifndef __SDB_H__
#define __SDB_H__

#include <common.h>
#define NR_WP 32

typedef struct watchpoint {
  int                NO;
  struct watchpoint *next;
  bool              occupy;
  char              expr[32];
  u_int32_t         value_new;
  u_int32_t         value_old;
  /* TODO: Add more members if necessary */
} WP;

void watch_display();
//void init_wp_pool();
word_t expr(char *e, bool *success);
WP* new_wp(char *e,u_int32_t val);
void free_wp(WP *wp);
void delete_watchpoint(int NO);
#endif
