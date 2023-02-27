#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100 // 图的最大顶点数

int adjMatrix[MAX_VERTICES][MAX_VERTICES]; // 邻接矩阵
bool visited[MAX_VERTICES]; // 记录每个顶点是否已经被访问

typedef struct {
    int data[MAX_VERTICES];
    int front;
    int rear;
} Queue;

void initQueue(Queue* q) {
    q->front = q->rear = -1;
}

bool isQueueEmpty(Queue* q) {
    return q->front == -1 && q->rear == -1;
}

void EnQueue(Queue* q, int value) {//enqueue
    if (isQueueEmpty(q)) {
        q->front++;
        q->rear++;
        q->data[q->rear] = value;
    }
    else {
        q->rear++;
        q->data[q->rear] = value;
    }
}

int DeQueue(Queue* q) {//dequeue
    int value = q->data[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    }
    else {
        q->front++;
    }
    return value;
}

