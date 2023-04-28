#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>

//记录正在读文件读者数量
int readCount = 0;

//初始化信号量
sem_t rMutex, wMutex;

//读者线程
static void * readerThread(void * arg);

//写着线程
static void * writerThread(void * arg);

int main(){
	//初始化信号量
	if(sem_init(&rMutex, 0, 1) == -1 || sem_init(&wMutex, 0, 1) == -1){
		printf("sem_init error\n");
		return -1;
	}


	//创建3个读者线程，1个写着线程
	pthread_t reader1TIDP, reader2TIDP, reader3TIDP, writerTIDP;
	void * retValr1, * retValr2, * retValr3, * retValw;
	
	if(pthread_create(&reader1TIDP, NULL, readerThread, NULL) != 0 || \
			pthread_create(&reader2TIDP, NULL, readerThread, NULL) != 0 || \
			pthread_create(&reader3TIDP, NULL, readerThread, NULL) != 0 || \
			pthread_create(&writerTIDP, NULL, writerThread, NULL) != 0){
		printf("pthread_create error\n");
		return -2;
	}
	
	//等待线程结束
	pthread_join(reader1TIDP, &retValr1);
	pthread_join(reader2TIDP, &retValr2);
	pthread_join(reader3TIDP, &retValr3);
	pthread_join(writerTIDP, &retValw);

	//销毁信号量
	sem_destroy(&rMutex);
	sem_destroy(&wMutex);
	
	return 0;
}

static void * readerThread(void * arg){
	printf("Reader thread is created, the TID is %lu\n", pthread_self());
	//随机数种子
	srand((unsigned int) time (0));

	for(int i = 0; i < 10; i++){

		//wait读者互斥信号量
		sem_wait(&rMutex);
		//没有读者，wait读者写者互斥信号量
		if(readCount == 0)
			sem_wait(&wMutex);
		readCount ++;
   		printf("线程号为%lu的读者线程开始读，当前共有%d个读者\n", pthread_self(), readCount);

		//signal读者互斥信号量
		sem_post(&rMutex);
		
		//随机休眠1-5秒时间模拟读书过程
		int readTime = rand() % 4 + 1;
		sleep(readTime);
	
		sem_wait(&rMutex);
		readCount --;
		printf("线程号为%lu的读者线程读完，当前剩余%d个读者\n", pthread_self(), readCount);
		
		//没有读者在读，signal读者写者互斥信号量
		if(readCount == 0)
			sem_post(&wMutex);
		sem_post(&rMutex);

		//读完后休息一会，让写着线程能申请到信号量
		sleep(rand() % 4 + 1);
	}
}

static void * writerThread(void * arg){
	printf("Writer thread is created, the TID is %lu\n", pthread_self());
	srand((unsigned int) time (0));

	for(int i = 0; i < 10; i++){
		sem_wait(&wMutex);
		int writeTime = rand() % 4 + 1;
		printf("写者线程开始写，共需写%d秒\n", writeTime);
		sleep(writeTime);
		sem_post(&wMutex);

		//写完休息一会，让读者线程能申请到信号量
		sleep(rand() % 4 + 1);
	}
}

