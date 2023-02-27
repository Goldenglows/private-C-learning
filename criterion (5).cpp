#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

#define OVERFLOW -2
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 100//�洢�ռ�ĳ�ʼ������
#define SElemType int

typedef struct
{
	SElemType *base;
	SElemType *top;
	int stacksize;//ջ���õ��������
}SqStack;

int InitStack(SqStack &S)//����һ����ջ
{
	S.base=new SElemType[MAXSIZE];
	if(!S.base)
		exit(OVERFLOW);
	S.top=S.base;//��ջ��top��base��ֵ���
	S.stacksize=MAXSIZE;//
	return OK;
}

int DestroyStack(SqStack &S)//����ջS��S���ٴ���
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

int ClearStack(SqStack &S)//��S��Ϊ��ջ
{
	S.base=S.top;
	return OK;
}

int StackEmpty(SqStack S)//�ж�S�Ƿ�Ϊ��ջ
{
	if(S.top==S.base)
		return TRUE;
	else
		return FALSE;
}

int StackLength(SqStack S)//����S��Ԫ�ظ�������ջ�ĳ���
{
	return S.top-S.base;
}

int GetTop(SqStack S,int &e)//����Sջ����Ԫ�أ����޸�ջ��ָ�룬����e����
{
	if(S.top!=S.base)//ջ�ǿ�
	{
		e= *(S.top-1);
		return OK;
	}
	else 
		return ERROR;
}

int Push(SqStack &S,int e)//��ջ������ջ������һ����Ԫ��
{
	if(S.top-S.base==S.stacksize)//ջ��
		return ERROR;
	*S.top=e;//Ԫ��eѹ��ջ����ջ��ָ���1
	S.top++;
	return OK;
}

int Pop(SqStack &S,int &e)//��ջ��ɾ��S��ջ��Ԫ�أ�����e������ֵ
{
	if(S.top==S.base)
		return ERROR;
	
	e=*--S.top;
	return OK;
}

int StackTraverse(SqStack S)//��ջ�׵�ջ���������ÿ��Ԫ��
{
	while(S.top!=S.base)
		printf("%d\t",*S.base++);
	printf("\n");
	return OK;
}

int LocateStack(SqStack S,int e)
{//��ջ�׵�ջ����ʼ���������ҵ�һ��Ϊe��Ԫ��
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
	printf("ջ��Ԫ�������ǣ�\n");
	StackTraverse(S);

	a=LocateStack(S,6);
	printf("Ԫ��6��λ���ǣ�");
	if(a==0)
		printf("��Ԫ�ز����ڣ�\n");
	else
		printf("%d\n",a);

	Pop(S,e);
	printf("������ջ��Ԫ���� %d\n",e);

	printf("ջ�Ƿ�Ϊ�գ�%d��1:��  0����\n",StackEmpty(S));
	printf("ջ��Ԫ�������ǣ�\n");
	StackTraverse(S);

	printf("ջ�ĳ���Ϊ%d\n",StackLength(S));

	GetTop(S,e);
	printf("�µ�ջ��Ԫ��Ϊ%d\n",e);

	ClearStack(S);
	printf("���ջ��ջ�Ƿ�Ϊ�գ�%d��1:��  0����\n",StackEmpty(S));

	//b=DestroyStack(S);
	//if(b=1)
	//printf("ջ������\n");//�ڴ����������⣬�ͷ��Ѿ��ͷŹ����ڴ�

	getchar();
	getchar();
}