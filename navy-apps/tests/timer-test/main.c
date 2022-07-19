#include <stdio.h>
#include <assert.h>
#include <sys/time.h>
int main() {
    struct timeval time;
    while(1){
    gettimeofday(&time,NULL);
    uint64_t us = time.tv_sec * 1000;
	if(us%500==0){
  	printf("The time of day is %ld s!\n",time.tv_sec);
	}
    
    }
  return 0;
}
