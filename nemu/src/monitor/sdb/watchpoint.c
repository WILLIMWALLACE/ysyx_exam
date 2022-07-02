#include "sdb.h"

//#define NR_WP 32

//typedef zai tou wen jian <sdb.h>

//WP* new_wp();
//void free_wp(WP *wp);
/////////////qu  diao static////////////////////
 static WP wp_pool[NR_WP] = {};
 static WP *head = NULL, *free_ = NULL;
 ////////////////////////////////////////
 //WP wp_pool[NR_WP] = {};
 //WP *head = NULL, *free_ = NULL;

void init_wp_pool() {
  int i;
  for (i = 0; i < NR_WP; i ++) {
    wp_pool[i].NO     = i;
    wp_pool[i].next   = (i == NR_WP - 1 ? NULL : &wp_pool[i + 1]);
    wp_pool[i].occupy = false;    //flag
    //wp_pool[i].expr   = NULL;     //raw expr
    wp_pool[i].value_new  = 0;        //resutl
    wp_pool[i].value_old  = 0;
  }
  head = NULL;
  free_ = wp_pool;
  //printf("zhixingchushihua\n");
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
    new->value_old  = new->value_new;
    new->value_new  = val;
    int i =0;
    while(e[i]!='\0'){        //bao cun expr & result
    new->expr[i]=e[i]; 
      i++;
    }
    new->occupy = true;       //zhan yong
    if(head == NULL)// head_pool cha ru new(lian biao tou bu cha ru)
    {head = new;}
    else
    {new->next = head;  head = new;  }
  }
  printf("occupy=%d,%s=%d,head.no=%d",head->occupy,new->expr,head->value_new,head->NO);
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
    if(wp->occupy==true){
      free(wp);          //wp->expr=NULL;//bi mian 'ye zhi zhen'
      wp->value_new = 0;
      wp->value_old = 0;     
      wp->occupy = false; 
      wp->next = free_;  
      free_ = wp;   //huan gei free_  pool(tou bu cha ru)
      printf("shan chu cheng gong\n");
      }
    else{
      printf("wp.occupy=%d,wp.NO=%d,head.NO=%d\n",wp->occupy,wp->NO,head->NO);
      assert(0);
    }
  }
}

void delete_watchpoint(int NO){
  WP *dele=NULL;
  for(dele=head;dele!=NULL;dele=dele->next){
    if(dele->NO==NO)
    {break;}
  }
  head = dele->next;
  printf("shanchu de NO wei:%d\n",NO);
  free_wp(dele);
}

void watch_display(){
    printf("watch.no=%d,express=%s,\nnew=%d,old=%d\n",
    head->NO,head->expr,head->value_new,head->value_old);
}

int scan_wp(){
  WP *p=head;
  printf("zhixingsaomiao\n");
  //for(p=head;p!=NULL;p=p->next){
   // printf("value=%d\n",p->value);
   p->value_old = p->value_new;
   printf("\nexpress==%s,value_new=%d,value_old=%d,NO=%d\n",
   head->expr,head->value_new,head->value_old,head->NO);
   bool success = true;
   p->value_new = expr(p->expr,&success);
  
   printf("head.value_new=%d,head.value_old=%d\n",head->value_new,head->value_old);
    if(p->value_new!=p->value_old){
      return 1;
      printf("tui chu sao miao\n");
    }
 // }
   //printf("wei jian ce dao jian shi dian gia bian\n");
  return 0;
}
////////////////////////////////////////////////////////////

