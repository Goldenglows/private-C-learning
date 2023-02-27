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

int InitList(LinkList &L)//��ʼ��
{
	L=new LNode;//�����½����Ϊͷ��㣬��ͷָ��Lָ��ͷ���
	L->next=NULL;//ͷ����ָ�����ÿ�
	return OK;
}

int DestroyList(LinkList &L)
{//���Ա�L�Ѵ��ڣ��������Ա�
	LinkList p;
	while(L)
	{
		p=L->next;
		delete L;
		L=p;
	}
	return OK;
}

int ClearList(LinkList L)//���ı�L
{//���Ա�L�Ѵ���  ��L����Ϊ�ձ�
	LinkList p,q;
	p=L->next;
	while(p)//û����β
	{
		q=p->next;
		free(p);
		p=q;
	}
	L->next=NULL;//ͷ���ָ����Ϊ��
	return OK;
}

int ListEmpty(LinkList L)//�ж��Ƿ�Ϊ�ձ�
{//���Ա�L�Ѿ�����   ��LΪ�ձ��򷵻�TRUE,���򷵻�FALSE
	if(L->next)//�ǿ�
		return FALSE;
	else
		return TRUE;
}

int ListLength(LinkList L)
{//����L������Ԫ�صĸ���
	int i=0;
	LinkList p;
	p=L->next;
	while(p)//û����β
	{
		++i;
		p=p->next;
	}
	return i;
}

int GetElem(LinkList L,int i,ElemType &e)//��ȡ��i��Ԫ�ص�ֵ������
{
	LinkList p;
	p=L->next;
	int j=1;
	while(p&&j<i)
	{
		p=p->next;
		++j;
	}
	if(!p||j>i)//iֵ���Ϸ���i>n����i<=0
		return ERROR;
	e=p->data;
	return OK;
}


int LocateList(LinkList L,ElemType e)
{//���ҵ�һ��ֵΪe��Ԫ�أ������ظ�Ԫ�ص�λ�����
	int i=1;
	LinkList p;
	p=new LNode;
	p=L->next;
	while(p&&p->data!=e)//���ɨ�裬ֱ��pΪ�ջ���p��������Ϊe
	{
		++i;
		p=p->next;
	}
	if(!p)
	    return ERROR;
	return i;
}

int ListInsert(LinkList &L,int i,ElemType e)
{//�ڴ�ͷ���ĵ������е�i��λ�ò���Ԫ��e
	LinkList p,s;
	int j=0;
	p=L;
	while(p&&j<i-1)//���ҵ�i-1����㣬pָ��ý��
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
{//�ڴ�ͷ���ĵ�������ɾ����i��Ԫ�أ�ͷ����λ����0Ŷ��
	LinkList p,q;
	int j=0;
	p=L;
	while(p&&j<i-1)//���ҵ�i-1����㣬pָ��ý��
	{
		p=p->next;
		++j;
	}
	if(!p||j>i-1)
		return ERROR;

	q=p->next;//ɾ�����ͷŽ��
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

	printf("��L�����β���1-5��L=\n");
	ListTraverse(L);

	printf("L�Ƿ�Ϊ�ձ�%d(1:��  0:��)\n",ListEmpty(L));

	printf("L��Ϊ%d\n",ListLength(L));
	
	GetElem(L,3,e);
	printf("��3��Ԫ�ص�ֵΪ��%d\n",e);

	d=LocateList(L,6);
	printf("Ԫ��6��λ��Ϊ:");
	if(d==0)
		printf("��Ԫ�ز����ڣ�\n");
	else
		printf("%d\n",d);


	a=ListDelete(L,3);
	printf("ɾ����3��Ԫ��:\n");
	if(a==0)
		printf("ɾ��Ԫ��ʧ��!\n");
	else
	{
		printf("ɾ��Ԫ�سɹ�,ɾ����3��Ԫ��֮������Ա�Ϊ\n");
		ListTraverse(L);
	}

	DestroyList(L);
	printf("L������");

	getchar();
	getchar();
}