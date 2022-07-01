#ifndef __SDB_H__
#define __SDB_H__

#include <common.h>
#define NR_WP 32

typedef struct watchpoint {
  int                NO;
  struct watchpoint *next;
  bool              occupy;
  char              *expr;
  u_int32_t         value;

  /* TODO: Add more members if necessary */
} WP;
 WP wp_pool[NR_WP] = {};
 WP *head = NULL, *free_ = NULL;
//void init_wp_pool();
word_t expr(char *e, bool *success);
WP* new_wp(char *e,u_int32_t val);
void free_wp(WP *wp);
#endif
