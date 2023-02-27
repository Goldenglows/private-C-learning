#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

#define OVERFLOW -2
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 5//�����г��ȣ�����ѭ�����У������г���Ҫ��1��
struct SqQueue
{
	int *base;//�洢�ռ�Ļ���ַ�����洢��Ԫ�صĵ�ַ
	int front;//ͷָ�룬�����в��գ�ָ�����ͷԪ��
	int rear;//βָ�룬�����в��գ�ָ�����βԪ�ص���һ��λ��
};

//����ѭ���ṹ���Գ�����ô洢�ռ䣬ֻҪ���г��Ȳ�����MAXSIZE-1����

int InitQueue(SqQueue &Q)
{
	Q.base=new int[MAXSIZE];//Ϊ���з���һ���������ΪMAXSIZE������ռ�
	if(!Q.base)
		exit(OVERFLOW);
	Q.front=Q.rear=0;//��ʼ��ʱ��ͷָ���βָ����Ϊ�㣬����Ϊ��
	return OK;
}

int DestroyQueue(SqQueue &Q)
{//���ٶ���Q,Q���ٴ���
	if(Q.base)
		free(Q.base);
	Q.base=NULL;
	Q.front=Q.rear=0;
	return OK;
}

int ClearQueue(SqQueue &Q)
{//��Q��Ϊ�ն���
	Q.front=Q.rear=0;
	return OK;
}

int QueueEmpty(SqQueue Q)
{//�ж϶����Ƿ�Ϊ��
	if(Q.front==Q.rear)
		return TRUE;
	else 
		return FALSE;
}

int QueueLength(SqQueue Q)
{//���ڷ�ѭ�����У�βָ���ͷָ���ͷָ��Ĳ�ֵ���Ƕ��г���
//������ѭ�����У���ֵ����Ϊ������������Ҫ����MAXSIZE
	return(Q.rear-Q.front+MAXSIZE)%MAXSIZE;
}

int GetHead(SqQueue Q,int &e)
{//���ض��еĶ�ͷԪ�أ����޸Ķ�ͷָ��
	if(Q.front!=Q.rear)
		return Q.base[Q.front];
}

int EnQueue(SqQueue &Q,int e)
{//����Ԫ��eΪQ���¶�βԪ��
	if((Q.rear+1)%MAXSIZE==Q.front)//βָ����ѭ�������ϼ�1�����ͷָ�룬��������
		return ERROR;
	Q.base[Q.rear]=e;//��Ԫ�ز����β
	Q.rear=(Q.rear+1)%MAXSIZE;//βָ���һ
	return OK;
}

int DeQueue(SqQueue &Q,int &e)
{//ɾ��Q�Ķ�ͷԪ�أ���e������ֵ
	if(Q.front==Q.rear)
		return ERROR;
	e=Q.base[Q.front];
	Q.front=(Q.front+1)%MAXSIZE;
	return OK;
}

int QueueTraverse(SqQueue Q)
{
	int i;
	i=Q.front;
	while(i!=Q.rear)
	{
		printf("%d\t",Q.base[i]);
		i=(i+1)%MAXSIZE;
	}
	printf("\n");
	return OK;
}

void main()
{
	int i,e,a,b;

	SqQueue Q;
	if(InitQueue(Q))
		printf("�ɹ�����һ���ն���\n");
	printf("�ö����Ƿ�Ϊ�գ�%d��1����  0����\n",QueueEmpty(Q));

	for(i=1;i<6;++i)
		EnQueue(Q,2*i);
	printf("����2��4,6,8�󣬸ö���Ԫ��Ϊ��\n");
	QueueTraverse(Q);

	printf("��ͷԪ���ǣ�%d\n",GetHead(Q,e));

	printf("����%d�δӶ�ͷɾ��Ԫ�أ���β����Ԫ�أ�\n",MAXSIZE);
	for(a=1;a<MAXSIZE;a++)
	{
		DeQueue(Q,e);
		printf("ɾ����Ԫ����%d,������������Ԫ�أ�",e);
		scanf("%d",&e);
		EnQueue(Q,e);
	}
	printf("��ʱ�ö���Ϊ��\n");
	QueueTraverse(Q);

	printf("�ö��еĳ�����%d\n",QueueLength(Q));

	printf("��ʱ�ö���Ϊ��\n");
	QueueTraverse(Q);

	printf("�µĶ�ͷԪ���ǣ�%d\n",GetHead(Q,e));

	if(ClearQueue(Q)==1)
	printf("��ն���\n");
	printf("�ö����Ƿ�Ϊ�գ�%d��1����  0����\n",QueueEmpty(Q));

	b=DestroyQueue(Q);
	if(b==1)
	printf("����������");

	getchar();
	getchar();
}