#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define VMAX 100 //最大顶点数 
//创建一个中断函数 
void Interrupt(void)//创建一个中断函数 
{
	while (1)//用于检测换行符，使函数脱离scanf的连续输出 
		if (getchar() == '\n')
			break;
}
//引入队列，这里是顺序队列 
typedef struct
{
	int data[VMAX];//分配给队列一个数组空间 
	int front;//队列头 
	int rear;//队列尾 
}SqQueue;

void InitQueue(SqQueue& Q)//初始化队列 
{
	Q.front = Q.rear = 0;//使队列头和队列尾都为0 
}

void EnQueue(SqQueue& Q, int e)//入队 ，由于是循环队列，故少用一个元素空间，该函数在有MAXSIZE-1个元素时便已判断为满 
{
	if ((Q.rear + 1) % VMAX == Q.front)//判断队列是否为满 ，这里是循环队列队列满的条件是 (Q.rear+1)%MAXSIZE == Q.front
	{
		printf("队列已满！\n");
	}
	else
	{
		if (Q.rear == VMAX)//如果队尾超出最大值但队列又不满，便使其对最大值求余运算 
			Q.rear = Q.rear % VMAX;
		Q.data[Q.rear] = e;//使变量e的值入队 
		Q.rear++;//并使队尾加一 
	}
}

bool QueueEmpty(SqQueue Q)//队列判空操作 
{
	if (Q.front == Q.rear)//如果队列为空，返回true，否则返回false 
		return true;
	else
		return false;
}

int DeQueue(SqQueue& Q)//出队 
{
	int a = 0;
	if (QueueEmpty(Q))//首先判断队列是否为空，队列为空的条件是 Q.front == Q.rear
		printf("队列为空！\n");
	else
	{
		a = Q.data[Q.front];//导出队头元素数据 
		Q.front++;//使队头加一 
		if (!QueueEmpty(Q))//在队列非空的情况下，如果队头等于最大值，也对最大值做求余运算 
			Q.front = Q.front % VMAX;
	}
	return a;
}