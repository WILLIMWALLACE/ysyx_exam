#include <stdio.h>
#include <assert.h>
#include <sys/time.h>
int main() {
	printf("jinru timer\n");
    struct timeval time;
    while(1){
	    printf("jinru xun huan\n");
    gettimeofday(&time,NULL);
    uint64_t us = time.tv_sec * 1000;
	printf("user_time=%d\n",time.tv_sec);
	if(us%500==0){
  	printf("The time of day is %ld s!\n",time.tv_sec);
	}
    }
  return 0;
}
