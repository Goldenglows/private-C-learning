#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <sys/shm.h>

#define BUF_SIZE 10

struct ShareDataStructure{
	pthread_mutex_t Mutex;
	sem_t Empty, Full;
	int Top, Bottom;
	int Buffer[BUF_SIZE];
};

int main(){
	int Shmid = shmget((key_t)1234, sizeof(struct ShareDataStructure), 0666 | IPC_CREAT);
	void *Shm = shmat(Shmid, 0, 0);

	struct ShareDataStructure * SD = (struct ShareDataStructure *)Shm;
	SD->Top = 0;
	SD->Bottom = 0;

	SD->Mutex = PTHREAD_MUTEX_INITIALIZER;

	sem_init(&SD->Empty, 1, BUF_SIZE);
	sem_init(&SD->Full, 1, 0);

	pid_t PID = fork();

	if(PID < 0){
		printf("fork error\n");
		return -1;
	}		
	
	//Producer process
	else if(PID == 0){
		printf("Hello");	
	}

	//Consumer process
	else{
		printf("World");
	}
	
	sem_destroy(&(SD->Full));
	sem_destroy(&(SD->Empty));
	return 0;
}
