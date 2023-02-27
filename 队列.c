#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 5

struct SqQueue{
	int *base;
	int front;
	int rear;
};

void InitSqQueue(struct SqQueue *p);
int EnSqQueue(struct SqQueue *p, int data);
int SqQueueLength(struct SqQueue *p);
int DeSqQueue(struct SqQueue *p);

int main(){
	
	struct SqQueue * p = (struct SqQueue *)malloc(sizeof(struct SqQueue));
	InitSqQueue(p);
	
	for(int i = 0; i < 6; i++){
		int data;
		printf("Input data:");
		scanf("%d", &data);
		EnSqQueue(p, data);
		printf("Length:%d\n", SqQueueLength(p));
	}
	
	for(int i = 0; i < 6; i++){
		int data = DeSqQueue(p);
		if(data != -1)
			printf("Fetch data:%d\n", data);
		printf("Length:%d\n", SqQueueLength(p));
	}
		
}

void InitSqQueue(struct SqQueue * p){
	p->base = (int *)malloc(MAXSIZE * sizeof(int));
	p->front = 0;
	p->rear = 0;
}

int EnSqQueue(struct SqQueue *p, int data){
	if((p->front + 1) % MAXSIZE == p->rear){
		printf("SqQueue is full!\n");
		return -1;		
	}
	
	p->base[p->front] = data;
	printf("Data: %d is stored in position: %d\n",data, p->front);
	p->front = (p->front + 1) % MAXSIZE;
	return 1;	
}

int SqQueueLength(struct SqQueue *p){
	return (p->rear - p->front + MAXSIZE) % MAXSIZE;
}

int DeSqQueue(struct SqQueue *p){
	if(p->front == p->rear){
		printf("SqQueue is empty!\n");
		return -1;
	} 
	
	int data = p->base[p->rear];
	p->rear = (p->rear + 1) % MAXSIZE;
	return data;
}
