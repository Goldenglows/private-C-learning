#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100 // ͼ����󶥵���

int adjMatrix[MAX_VERTICES][MAX_VERTICES]; // �ڽӾ���
bool visited[MAX_VERTICES]; // ��¼ÿ�������Ƿ��Ѿ�������

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

