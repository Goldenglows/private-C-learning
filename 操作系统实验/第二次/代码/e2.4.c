#include <pthread.h>
#include <unistd.h>
#include <stdio.h>

int n = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

static void * newThread(void * arg){
	printf("I'm the new thread, my TID is %lu, the PID of the process is %d\n", pthread_self(), getpid());
	for(int i = 0; i < 100000; i++){
		pthread_mutex_lock(&mutex);
		n++;
		pthread_mutex_unlock(&mutex);
	}
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
	for(int i = 0; i < 100000; i++){
		pthread_mutex_lock(&mutex);
		n++;
		pthread_mutex_unlock(&mutex);
	}

	pthread_join(tidp, & retval);
	printf("The global variable n equals to %d\n", n);
	return 0;
}
