#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

#define OVERFLOW -2
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 5//最大队列长度（对于循环队列，最大队列长度要减1）
struct SqQueue
{
	int *base;//存储空间的基地址，即存储首元素的地址
	int front;//头指针，若队列不空，指向队列头元素
	int rear;//尾指针，若队列不空，指向队列尾元素的下一个位置
};

//采用循环结构可以充分利用存储空间，只要队列长度不大于MAXSIZE-1即可

int InitQueue(SqQueue &Q)
{
	Q.base=new int[MAXSIZE];//为队列分配一个最大容量为MAXSIZE的数组空间
	if(!Q.base)
		exit(OVERFLOW);
	Q.front=Q.rear=0;//初始化时，头指针和尾指针置为零，队列为空
	return OK;
}

int DestroyQueue(SqQueue &Q)
{//销毁队列Q,Q不再存在
	if(Q.base)
		free(Q.base);
	Q.base=NULL;
	Q.front=Q.rear=0;
	return OK;
}

int ClearQueue(SqQueue &Q)
{//将Q清为空队列
	Q.front=Q.rear=0;
	return OK;
}

int QueueEmpty(SqQueue Q)
{//判断队列是否为空
	if(Q.front==Q.rear)
		return TRUE;
	else 
		return FALSE;
}

int QueueLength(SqQueue Q)
{//对于非循环队列，尾指针和头指针和头指针的差值就是队列长度
//而对于循环队列，差值可能为负数，所以需要加上MAXSIZE
	return(Q.rear-Q.front+MAXSIZE)%MAXSIZE;
}

int GetHead(SqQueue Q,int &e)
{//返回队列的队头元素，不修改队头指针
	if(Q.front!=Q.rear)
		return Q.base[Q.front];
}

int EnQueue(SqQueue &Q,int e)
{//插入元素e为Q的新队尾元素
	if((Q.rear+1)%MAXSIZE==Q.front)//尾指针在循环意义上加1后等于头指针，表明队满
		return ERROR;
	Q.base[Q.rear]=e;//新元素插入队尾
	Q.rear=(Q.rear+1)%MAXSIZE;//尾指针加一
	return OK;
}

int DeQueue(SqQueue &Q,int &e)
{//删除Q的队头元素，用e返回其值
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
		printf("成功构造一个空队列\n");
	printf("该队列是否为空？%d（1：是  0：否）\n",QueueEmpty(Q));

	for(i=1;i<6;++i)
		EnQueue(Q,2*i);
	printf("插入2，4,6,8后，该队列元素为：\n");
	QueueTraverse(Q);

	printf("队头元素是：%d\n",GetHead(Q,e));

	printf("连续%d次从队头删除元素，队尾插入元素：\n",MAXSIZE);
	for(a=1;a<MAXSIZE;a++)
	{
		DeQueue(Q,e);
		printf("删除的元素是%d,请输入待插入的元素：",e);
		scanf("%d",&e);
		EnQueue(Q,e);
	}
	printf("此时该队列为：\n");
	QueueTraverse(Q);

	printf("该队列的长度是%d\n",QueueLength(Q));

	printf("此时该队列为：\n");
	QueueTraverse(Q);

	printf("新的队头元素是：%d\n",GetHead(Q,e));

	if(ClearQueue(Q)==1)
	printf("清空队列\n");
	printf("该队列是否为空？%d（1：是  0：否）\n",QueueEmpty(Q));

	b=DestroyQueue(Q);
	if(b==1)
	printf("队列已销毁");

	getchar();
	getchar();
}