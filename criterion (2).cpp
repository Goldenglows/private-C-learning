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


typedef struct BiTNode
{
	char data;
	BiTNode *lchild,*rchild;//���Һ���ָ��
}BiNode,*BiTree;

typedef struct
{
	BiTNode *base;
	BiTNode *top;
	int stacksize;//ջ���õ��������
}SqStack;

void Destroy(BiTree &T)
{//���ٶ�����
	if(T)//�ǿ�
	{
		if(T->lchild)//������
			Destroy(T->lchild);
		if(T->rchild)//���Һ���
			Destroy(T->rchild);
		free(T);
		T=NULL;
	}
}

int InitBiTree(BiTree &T)
{//����ն�����
	T=NULL;
	return OK;
}

void CreateBiTree(BiTree &T)
{
	char ch;
	cin>>ch;
	if(ch=='#')
		T=NULL;
	else
	{
		T=new BiTNode;//���ɸ��ڵ�
		T->data=ch;
		CreateBiTree(T->lchild);//����������
		CreateBiTree(T->rchild);//����������
	}
}

void PreOrderTraverse(BiTree T)
{//�������
	if(T)
	{
		cout<<T->data;
		printf("\t");
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
	}
}

void InOrderTraverse(BiTree T)
{//����������ݹ��㷨
	if(T)
	{
		InOrderTraverse(T->lchild);
		cout<<T->data;
		printf("\t");
		InOrderTraverse(T->rchild);
	}
}

int InitStack(SqStack &S)//����һ����ջ
{
	S.base=new BiTNode[MAXSIZE];
	if(!S.base)
		exit(OVERFLOW);
	S.top=S.base;//��ջ��top��base��ֵ���
	S.stacksize=MAXSIZE;//
	return OK;
}
int StackEmpty(SqStack S)//�ж�S�Ƿ�Ϊ��ջ
{
	if(S.top==S.base)
		return TRUE;
	else
		return FALSE;
}

int Push(SqStack &S,BiTNode e)//��ջ������ջ������һ����Ԫ��
{
	if(S.top-S.base==S.stacksize)//ջ��
		return ERROR;
	*S.top=e;//Ԫ��eѹ��ջ����ջ��ָ���1
	S.top++;
	return OK;
}

int Pop(SqStack &S,BiTNode &e)//��ջ��ɾ��S��ջ��Ԫ�أ�����e������ֵ
{
	if(S.top==S.base)
		return ERROR;
	
	e=*--S.top;
	return OK;
}


int InOrderTraverse1(BiTree T)
{//����������ǵݹ�
	SqStack S;
	InitStack(S);
	BiTNode *p,*q;
	p=T;
	q=new BiTNode;
	while(p||!StackEmpty(S))
	{
		if(p)
		{//��ָ���ջ������������
			Push(S,*p);
			p=p->lchild;
		}
		else
		{//��ָ����ջ�����ʸ��ڵ㣬����������
			Pop(S,*q);
			cout<<q->data<<"\t";
			p=q->rchild;
		}
	}
	printf("\n");
	return OK;
}

int PreOrderTraverse1(BiTree T)
{//ǰ��������ǵݹ�
	SqStack S;
	InitStack(S);
	BiTNode *p,*q;
	p=T;
	q=new BiTNode;
	while(p||!StackEmpty(S))
	{

		if(p)
		{//��ָ���ջ������������
			Push(S,*p);
			cout<<p->data<<"\t";
			p=p->lchild;
		}
		else
		{//��ָ����ջ�����ʸ��ڵ㣬����������
			
			Pop(S,*q);
			p=q->rchild;
		}
	}
	printf("\n");
	return OK;
}

void PostOrderTraverse(BiTree T)
{//����ݹ����
	if(T)
	{
		PostOrderTraverse(T->lchild);
		PostOrderTraverse(T->rchild);
		cout<<T->data;
		printf("\t");
	}
}

void main()
{
	
	BiTree T;
	
	InitBiTree(T);
	printf("�����������������\n");
	CreateBiTree(T);
	
	printf("����ݹ������������\n");
	PreOrderTraverse(T);
	printf("\n");

	printf("����ݹ������������\n");
	InOrderTraverse(T);
	printf("\n");

	printf("����ݹ������������\n");
	PostOrderTraverse(T); 
	printf("\n");

	printf("����ǵݹ������������\n");
	PreOrderTraverse1(T);
	printf("\n");

	printf("����ǵݹ������������\n");
	InOrderTraverse1(T);
	printf("\n");

	//printf("����ǵݹ������������\n");
	//PostOrderTraverse_nonrecursion(T);
	//printf("\n");

	getchar();
	getchar();
}