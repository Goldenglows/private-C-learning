#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define VMAX 100 //��󶥵��� 
//����һ���жϺ��� 
void Interrupt(void)//����һ���жϺ��� 
{
	while (1)//���ڼ�⻻�з���ʹ��������scanf��������� 
		if (getchar() == '\n')
			break;
}
//������У�������˳����� 
typedef struct
{
	int data[VMAX];//���������һ������ռ� 
	int front;//����ͷ 
	int rear;//����β 
}SqQueue;

void InitQueue(SqQueue& Q)//��ʼ������ 
{
	Q.front = Q.rear = 0;//ʹ����ͷ�Ͷ���β��Ϊ0 
}

void EnQueue(SqQueue& Q, int e)//��� ��������ѭ�����У�������һ��Ԫ�ؿռ䣬�ú�������MAXSIZE-1��Ԫ��ʱ�����ж�Ϊ�� 
{
	if ((Q.rear + 1) % VMAX == Q.front)//�ж϶����Ƿ�Ϊ�� ��������ѭ�����ж������������� (Q.rear+1)%MAXSIZE == Q.front
	{
		printf("����������\n");
	}
	else
	{
		if (Q.rear == VMAX)//�����β�������ֵ�������ֲ�������ʹ������ֵ�������� 
			Q.rear = Q.rear % VMAX;
		Q.data[Q.rear] = e;//ʹ����e��ֵ��� 
		Q.rear++;//��ʹ��β��һ 
	}
}

bool QueueEmpty(SqQueue Q)//�����пղ��� 
{
	if (Q.front == Q.rear)//�������Ϊ�գ�����true�����򷵻�false 
		return true;
	else
		return false;
}

int DeQueue(SqQueue& Q)//���� 
{
	int a = 0;
	if (QueueEmpty(Q))//�����ж϶����Ƿ�Ϊ�գ�����Ϊ�յ������� Q.front == Q.rear
		printf("����Ϊ�գ�\n");
	else
	{
		a = Q.data[Q.front];//������ͷԪ������ 
		Q.front++;//ʹ��ͷ��һ 
		if (!QueueEmpty(Q))//�ڶ��зǿյ�����£������ͷ�������ֵ��Ҳ�����ֵ���������� 
			Q.front = Q.front % VMAX;
	}
	return a;
}