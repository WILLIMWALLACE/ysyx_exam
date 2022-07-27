#include <stdio.h>
#include <assert.h>
#include <sys/time.h>
uint32_t NDL_GetTicks();
int main() {
//	printf("jinru timer\n");
  //  struct timeval time,start_time;
  //  gettimeofday(&start_time,NULL);
    uint64_t ms = 0;
    uint64_t start_ms = NDL_GetTicks();
    //uint64_t cnt=0;
    //uint64_t flag=0;
   while(1){
//	    printf("jinru xun huan\n");
    //	gettimeofday(&time,NULL);
	ms = NDL_GetTicks() - start_ms;
//	printf("user_time=%d\n",time.tv_sec);
	//cnt++;
	if(ms%500==0){
	  //flag = cnt;
  	  printf("The time of day is %ld s!\n",ms);
	}
    }
  return 0;
}
