#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

#define OK 1
#define ERROR 0
#define ElemType int
#define TRUE 1
#define FALSE 0

typedef struct Lnode
{
	ElemType data;
	struct Lnode *next;
}LNode,*LinkList;

int InitList(LinkList &L)//初始化
{
	L=new LNode;//生成新结点作为头结点，用头指针L指向头结点
	L->next=NULL;//头结点的指针域置空
	return OK;
}

int DestroyList(LinkList &L)
{//线性表L已存在，销毁线性表
	LinkList p;
	while(L)
	{
		p=L->next;
		delete L;
		L=p;
	}
	return OK;
}

int ClearList(LinkList L)//不改变L
{//线性表L已存在  将L重置为空表
	LinkList p,q;
	p=L->next;
	while(p)//没到表尾
	{
		q=p->next;
		free(p);
		p=q;
	}
	L->next=NULL;//头结点指针域为空
	return OK;
}

int ListEmpty(LinkList L)//判断是否为空表
{//线性表L已经存在   若L为空表，则返回TRUE,否则返回FALSE
	if(L->next)//非空
		return FALSE;
	else
		return TRUE;
}

int ListLength(LinkList L)
{//返回L中数据元素的个数
	int i=0;
	LinkList p;
	p=L->next;
	while(p)//没到表尾
	{
		++i;
		p=p->next;
	}
	return i;
}

int GetElem(LinkList L,int i,ElemType &e)//获取第i个元素的值并返回
{
	LinkList p;
	p=L->next;
	int j=1;
	while(p&&j<i)
	{
		p=p->next;
		++j;
	}
	if(!p||j>i)//i值不合法，i>n或者i<=0
		return ERROR;
	e=p->data;
	return OK;
}


int LocateList(LinkList L,ElemType e)
{//查找第一个值为e的元素，并返回该元素的位置序号
	int i=1;
	LinkList p;
	p=new LNode;
	p=L->next;
	while(p&&p->data!=e)//向后扫描，直到p为空或者p的数据域为e
	{
		++i;
		p=p->next;
	}
	if(!p)
	    return ERROR;
	return i;
}

int ListInsert(LinkList &L,int i,ElemType e)
{//在带头结点的单链表中第i个位置插入元素e
	LinkList p,s;
	int j=0;
	p=L;
	while(p&&j<i-1)//查找第i-1个结点，p指向该结点
	{
		p=p->next;
		++j;
	}
	if(!p||j>i-1)
		return ERROR;

	s=new LNode;
	s->data=e;
	s->next=p->next;
	p->next=s;

	return OK;
}

int ListDelete(LinkList &L,int i)
{//在带头结点的单链表中删除第i个元素，头结点的位置是0哦！
	LinkList p,q;
	int j=0;
	p=L;
	while(p&&j<i-1)//查找第i-1个结点，p指向该结点
	{
		p=p->next;
		++j;
	}
	if(!p||j>i-1)
		return ERROR;

	q=p->next;//删除并释放结点
	p->next=p->next->next;
	free(q);
	return OK;
}

int ListTraverse(LinkList L)
{
	LinkList p;
	p=L->next;
	while(p)
	{
		printf("%d\t",p->data);
		p=p->next;
	}
	printf("\n");
	return OK;
}

void main()
{
	LinkList L;
	int i,a,d,e;

	InitList(L);
	for(i=1;i<6;i++)
		ListInsert(L,i,i);

	printf("在L中依次插入1-5后：L=\n");
	ListTraverse(L);

	printf("L是否为空表：%d(1:是  0:否)\n",ListEmpty(L));

	printf("L表长为%d\n",ListLength(L));
	
	GetElem(L,3,e);
	printf("第3个元素的值为：%d\n",e);

	d=LocateList(L,6);
	printf("元素6的位置为:");
	if(d==0)
		printf("该元素不存在！\n");
	else
		printf("%d\n",d);


	a=ListDelete(L,3);
	printf("删除第3个元素:\n");
	if(a==0)
		printf("删除元素失败!\n");
	else
	{
		printf("删除元素成功,删除第3个元素之后的线性表为\n");
		ListTraverse(L);
	}

	DestroyList(L);
	printf("L已销毁");

	getchar();
	getchar();
}