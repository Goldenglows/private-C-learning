#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

struct queue_1{
    int data[MAXSIZE];
    int front;
    int rear;
};

void Initqueue(struct queue_1 *q){
    //初始化队列
    q->front = 0;
    q->rear = 0;
}

int is_empty(struct queue_1 *q){
    return (q->front == 0 && q->rear == 0);
}

int is_full(struct queue_1 *q){
    return ((q->rear + 1) % MAXSIZE == q -> front);
}

int Enqueue(struct queue_1 *q, int x){
    //入队
    if(is_full(q)){
        printf("Queue is full");
        return -1;
    }
    q->rear = (q->rear +1) % MAXSIZE;
    //队尾往后调一格子
    q->data[q->rear] = x;
    //队尾导入x的数据
}

int Dequeue (struct queue_1 *q){
    if(is_empty(q)){
        printf("Queue is empty\n");
        return -1;
    }
    int x = q->data[q->front];
    q->front = (q->front + 1) % MAXSIZE;
}

