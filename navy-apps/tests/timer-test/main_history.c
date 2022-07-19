#include <stdio.h>
#include <assert.h>
#include <sys/time.h>
int main() {
//	printf("jinru timer\n");
    struct timeval time,start_time;
    gettimeofday(&start_time,NULL);
    uint64_t ms = 0;
    uint64_t cnt=0;
    uint64_t flag=0;
   while(1){
//	    printf("jinru xun huan\n");
    	gettimeofday(&time,NULL);
	ms = (time.tv_sec-start_time.tv_sec) * 1000;
//	printf("user_time=%d\n",time.tv_sec);
	cnt++;
	if(flag==cnt-500){
	  flag = cnt;
  	  printf("The time of day is %ld s!\n",time.tv_sec);
	}
    }
  return 0;
}
