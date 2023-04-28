#include <pthread.h>
#include <unistd.h>
#include <stdio.h>

int n = 0;

static void * newThread(void * arg){
	printf("I'm the new thread, my TID is %lu, the PID of the process is %d\n", pthread_self(), getpid());
	for(int i = 0; i < 100000; i++)
		n++;
	return ((void *)0);
}

int main(){
	pthread_t tidp;
	void * retval;

	if(pthread_create(&tidp, NULL, newThread, NULL) != 0){
		printf("pthread_create error\n");
		return -1;
	}

	printf("I'm the main thread, my TID is %lu, the PID of the process is %d\n", pthread_self(), getpid());
	for(int i = 0; i < 100000; i++)
		n++;

	pthread_join(tidp, & retval);
	printf("The global variable n equals to %d\n", n);
	return 0;
}
