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


typedef struct BiTNode
{
	char data;
	BiTNode *lchild,*rchild;//左右孩子指针
}BiNode,*BiTree;

typedef struct
{
	BiTNode *base;
	BiTNode *top;
	int stacksize;//栈可用的最大容量
}SqStack;

void Destroy(BiTree &T)
{//销毁二叉树
	if(T)//非空
	{
		if(T->lchild)//有左孩子
			Destroy(T->lchild);
		if(T->rchild)//有右孩子
			Destroy(T->rchild);
		free(T);
		T=NULL;
	}
}

int InitBiTree(BiTree &T)
{//构造空二叉树
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
		T=new BiTNode;//生成根节点
		T->data=ch;
		CreateBiTree(T->lchild);//构造左子树
		CreateBiTree(T->rchild);//构造右子树
	}
}

void PreOrderTraverse(BiTree T)
{//先序遍历
	if(T)
	{
		cout<<T->data;
		printf("\t");
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
	}
}

void InOrderTraverse(BiTree T)
{//中序遍历，递归算法
	if(T)
	{
		InOrderTraverse(T->lchild);
		cout<<T->data;
		printf("\t");
		InOrderTraverse(T->rchild);
	}
}

int InitStack(SqStack &S)//构造一个空栈
{
	S.base=new BiTNode[MAXSIZE];
	if(!S.base)
		exit(OVERFLOW);
	S.top=S.base;//空栈。top和base的值相等
	S.stacksize=MAXSIZE;//
	return OK;
}
int StackEmpty(SqStack S)//判断S是否为空栈
{
	if(S.top==S.base)
		return TRUE;
	else
		return FALSE;
}

int Push(SqStack &S,BiTNode e)//入栈，即在栈顶插入一个新元素
{
	if(S.top-S.base==S.stacksize)//栈满
		return ERROR;
	*S.top=e;//元素e压入栈顶，栈顶指针加1
	S.top++;
	return OK;
}

int Pop(SqStack &S,BiTNode &e)//出栈，删除S的栈顶元素，并用e返回其值
{
	if(S.top==S.base)
		return ERROR;
	
	e=*--S.top;
	return OK;
}


int InOrderTraverse1(BiTree T)
{//中序遍历，非递归
	SqStack S;
	InitStack(S);
	BiTNode *p,*q;
	p=T;
	q=new BiTNode;
	while(p||!StackEmpty(S))
	{
		if(p)
		{//根指针进栈，遍历左子树
			Push(S,*p);
			p=p->lchild;
		}
		else
		{//根指针退栈，访问根节点，遍历右子树
			Pop(S,*q);
			cout<<q->data<<"\t";
			p=q->rchild;
		}
	}
	printf("\n");
	return OK;
}

int PreOrderTraverse1(BiTree T)
{//前序遍历，非递归
	SqStack S;
	InitStack(S);
	BiTNode *p,*q;
	p=T;
	q=new BiTNode;
	while(p||!StackEmpty(S))
	{

		if(p)
		{//根指针进栈，遍历左子树
			Push(S,*p);
			cout<<p->data<<"\t";
			p=p->lchild;
		}
		else
		{//根指针退栈，访问根节点，遍历右子树
			
			Pop(S,*q);
			p=q->rchild;
		}
	}
	printf("\n");
	return OK;
}

void PostOrderTraverse(BiTree T)
{//后序递归遍历
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
	printf("请先序输入二叉树：\n");
	CreateBiTree(T);
	
	printf("先序递归遍历二叉树：\n");
	PreOrderTraverse(T);
	printf("\n");

	printf("中序递归遍历二叉树：\n");
	InOrderTraverse(T);
	printf("\n");

	printf("后序递归遍历二叉树：\n");
	PostOrderTraverse(T); 
	printf("\n");

	printf("先序非递归遍历二叉树：\n");
	PreOrderTraverse1(T);
	printf("\n");

	printf("中序非递归遍历二叉树：\n");
	InOrderTraverse1(T);
	printf("\n");

	//printf("后序非递归遍历二叉树：\n");
	//PostOrderTraverse_nonrecursion(T);
	//printf("\n");

	getchar();
	getchar();
}