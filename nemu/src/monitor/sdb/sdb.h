#ifndef __SDB_H__
#define __SDB_H__

#include <common.h>

typedef struct watchpoint {
  int                NO;
  struct watchpoint *next;
  bool              occupy;
  char              *expr;
  u_int32_t         value;

  /* TODO: Add more members if necessary */
} WP;

word_t expr(char *e, bool *success, char *express);
WP* new_wp(char *e,u_int32_t val);
void free_wp(WP *wp);

#endif
