#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

#define OVERFLOW -2
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 100//存储空间的初始分配量
#define SElemType int

typedef struct
{
	SElemType *base;
	SElemType *top;
	int stacksize;//栈可用的最大容量
}SqStack;

int InitStack(SqStack &S)//构造一个空栈
{
	S.base=new SElemType[MAXSIZE];
	if(!S.base)
		exit(OVERFLOW);
	S.top=S.base;//空栈。top和base的值相等
	S.stacksize=MAXSIZE;//
	return OK;
}

int DestroyStack(SqStack &S)//销毁栈S，S不再存在
{
	if(S.base)
	{
		free(S.base);
		S.base=NULL;
		S.top=NULL;
		S.stacksize=0;
	}
	return OK;
}

int ClearStack(SqStack &S)//把S置为空栈
{
	S.base=S.top;
	return OK;
}

int StackEmpty(SqStack S)//判断S是否为空栈
{
	if(S.top==S.base)
		return TRUE;
	else
		return FALSE;
}

int StackLength(SqStack S)//返回S的元素个数，即栈的长度
{
	return S.top-S.base;
}

int GetTop(SqStack S,int &e)//返回S栈顶的元素，不修改栈顶指针，并用e保存
{
	if(S.top!=S.base)//栈非空
	{
		e= *(S.top-1);
		return OK;
	}
	else 
		return ERROR;
}

int Push(SqStack &S,int e)//入栈，即在栈顶插入一个新元素
{
	if(S.top-S.base==S.stacksize)//栈满
		return ERROR;
	*S.top=e;//元素e压入栈顶，栈顶指针加1
	S.top++;
	return OK;
}

int Pop(SqStack &S,int &e)//出栈，删除S的栈顶元素，并用e返回其值
{
	if(S.top==S.base)
		return ERROR;
	
	e=*--S.top;
	return OK;
}

int StackTraverse(SqStack S)//从栈底到栈顶依次输出每个元素
{
	while(S.top!=S.base)
		printf("%d\t",*S.base++);
	printf("\n");
	return OK;
}

int LocateStack(SqStack S,int e)
{//从栈底到栈顶开始计数，查找第一个为e的元素
	int i=1;
	while((S.base!=S.top)&&(*S.base!=e))
	{
		S.base++;
		++i;
	}
	if(S.base==S.top)
		return ERROR;
	return i;
}

void main()
{
	SqStack S;
	int a,b,e,i;
	if(InitStack(S)==1)
		for(i=1;i<10;i++)
			Push(S,2*i);
	printf("栈中元素依次是：\n");
	StackTraverse(S);

	a=LocateStack(S,6);
	printf("元素6的位置是：");
	if(a==0)
		printf("该元素不存在！\n");
	else
		printf("%d\n",a);

	Pop(S,e);
	printf("弹出的栈顶元素是 %d\n",e);

	printf("栈是否为空：%d（1:是  0：否）\n",StackEmpty(S));
	printf("栈中元素依次是：\n");
	StackTraverse(S);

	printf("栈的长度为%d\n",StackLength(S));

	GetTop(S,e);
	printf("新的栈顶元素为%d\n",e);

	ClearStack(S);
	printf("清空栈后，栈是否为空：%d（1:是  0：否）\n",StackEmpty(S));

	//b=DestroyStack(S);
	//if(b=1)
	//printf("栈已销毁\n");//内存管理出现问题，释放已经释放过的内存

	getchar();
	getchar();
}