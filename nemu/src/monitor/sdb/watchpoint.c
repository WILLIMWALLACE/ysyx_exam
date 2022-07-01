#include "sdb.h"

#define NR_WP 32

//typedef zai tou wen jian <sdb.h>

//WP* new_wp();
//void free_wp(WP *wp);
static WP wp_pool[NR_WP] = {};
static WP *head = NULL, *free_ = NULL;

void init_wp_pool() {
  int i;
  for (i = 0; i < NR_WP; i ++) {
    wp_pool[i].NO     = i;
    wp_pool[i].next   = (i == NR_WP - 1 ? NULL : &wp_pool[i + 1]);
    wp_pool[i].occupy = false;    //flag
    wp_pool[i].expr   = NULL;     //raw expr
    wp_pool[i].value  = 0;        //resutl
  }
  head = NULL;
  free_ = wp_pool;
}
///////////watchpoint pool manager//////////////////////////
//chuang jian yi ge xin de 'jian shi dian'
WP* new_wp(char *e,u_int32_t val){
  if(free_==NULL){
    printf("free_ is NULL,Now is executing the init_wp_pool()\n");
    //assert(0);
    init_wp_pool();
  }
  WP* new=free_;    //cong free_(wp_pool) zhong na chu wei zhi,chuang jian 'new'
  if(new->occupy==true){
    printf("All wp are occupied!\n");
    assert(0);
  }
  else if(new->occupy==false){
    //new       = free_;
    free_       = free_->next;//lian biao shun xu yi dong,free_ jian shao yi ge
    new->value  = val;        //bao cun expr & result
    new->expr   = e; 
    new->occupy = true;       //zhan yong
    if(head == NULL)// head_pool cha ru new(lian biao tou bu cha ru)
    {head = new;}
    else
    {new->next = head;  head = new;  }
  }
  printf("occupy=%d,%s=%d",new->occupy,new->expr,new->value);
  return new;
}
//shi fang 'head' zhong de 'jian shi dian',huan gei free_ 
void free_wp(WP *wp){
  if(wp<wp_pool||wp>(wp_pool+NR_WP)){
    printf("beyond the wp_pool\n");
    assert(0);
  }
  else if(head==NULL){
    printf("There is no watchpoint\n");
    assert(0);
  }
  else{
    if(wp->occupy==true && wp->NO==head->NO){
      free(wp);          wp->expr=NULL;//bi mian 'ye zhi zhen'
      wp->value = 0;     wp->occupy = false; 
      wp->next = free_;  free_ = wp;   //huan gei free_  pool(tou bu cha ru)
      }
    else{
      printf("wp.occupy=%d,wp.NO=%d,head.NO=%d\n",wp->occupy,wp->NO,head->NO);
      assert(0);
    }
  }
 
}
////////////////////////////////////////////////////////////


