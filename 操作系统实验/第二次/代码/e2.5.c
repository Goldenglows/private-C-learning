#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <semaphore.h>

int n = 0;
sem_t sem;

static void * newThread(void * arg){
	printf("I'm the new thread, my TID is %lu, the PID of the process is %d\n", pthread_self(), getpid());
	for(int i = 0; i < 100000; i++){
		sem_wait(&sem);
		n++;
		sem_post(&sem);
	}
	return ((void *)0);
}

int main(){
	pthread_t tidp;
	void * retval;

	if(sem_init(&sem, 0, 1) == -1){
		printf("sem_init error\n");
		return -2;
	}

	if(pthread_create(&tidp, NULL, newThread, NULL) != 0){
		printf("pthread_create error\n");
		return -1;
	}

	printf("I'm the main thread, my TID is %lu, the PID of the process is %d\n", pthread_self(), getpid());
	for(int i = 0; i < 100000; i++){
		sem_wait(&sem);
		n++;
		sem_post(&sem);
	}

	pthread_join(tidp, & retval);
	sem_destroy(&sem);
	printf("The global variable n equals to %d\n", n);
	return 0;
}
