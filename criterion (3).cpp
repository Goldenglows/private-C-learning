#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

#define MAXSIZE 100
#define OVERFLOW -2
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef struct
{
	int *elem;
	int length;
}SqList;

int InitList(SqList &L)//��ʼ��
{
	L.elem=new int[MAXSIZE];
	if(!L.elem)
		exit(OVERFLOW);
	L.length=0;
	return OK;
}

int GetElem(SqList L,int i,int &e)//ȡ��i��Ԫ�ص�ֵ
{
	if (i<1||i>L.length)
		return ERROR;

	e=L.elem[i-1];

	return OK;
}

void ListTraverse(SqList L)
{
	int i;
	for(i=0;i<L.length;i++)
	printf("%d\t",L.elem[i]);
	printf("\n");
}

int LocateElem(SqList L,int e)//����˳����е�һ����e��ȵ�Ԫ���ڱ��е�λ�����
{
	for( int i=0;i<L.length-1;++i)
		if(e==L.elem[i])
			return i+1;
	return 0;
}

int ListInsert(SqList &L,int i,int e)//��i��λ�ò���Ԫ��
{
	if((i<1)||(i>L.length+1))
		return ERROR;
	if(L.length==MAXSIZE)
		return ERROR;
	for(int j=L.length-1;j>=i-1;--j)
	{
		L.elem[j+1]=L.elem[j];
	}
	L.elem[i-1]=e;
	++L.length;
	return OK;
}

int ListDelete(SqList &L,int i)//ɾ����i��Ԫ��
{
	int j;
	if((i<1)||(i>L.length))
		return ERROR;
	for(j=i;j<L.length;j++)
		L.elem[j-1]=L.elem[j];
	--L.length;
	return OK;
}

int ListLength(SqList L)//��
{
	return L.length;
}

int ListEmpty(SqList L)//�ж��Ƿ�Ϊ�ձ�
{
	if(L.length==0)
		return TRUE;
	else
		return FALSE;
}

void DestroyList(SqList &L)
{
	if(L.elem)
		delete L.elem;
}

int main()
{
	SqList L;
	int i,c,a,d;
	
	InitList(L);
	for(i=1;i<6;i++)
	{
		ListInsert(L,i,i);
	}
	printf("��L�����β���1-5��L=\n");
	ListTraverse(L);

	//b=ListEmpty(L);
	//printf("L�Ƿ�Ϊ�ձ�%d(1:��  0:��)\n",b);
	printf("L��Ϊ%d\n",ListLength(L));
	printf("�ڵ�5��λ�ò�������10,");
	ListInsert(L,5,10);
	printf("��ʱLΪ��\n");
	ListTraverse(L);

	a=ListDelete(L,3);
	printf("ɾ����3��Ԫ��\n");
	if(a==0)
		printf("ɾ��Ԫ��ʧ��\n");
	else
	{
		printf("ɾ��Ԫ�سɹ�,ɾ����3��Ԫ��֮������Ա�Ϊ\n");
		ListTraverse(L);
	}

	printf("L�Ƿ�Ϊ�ձ�%d(1:��  0:��)\n",ListEmpty(L));

	d=LocateElem(L,6);
	printf("Ԫ��6��λ��Ϊ:");
	if(d==0)
		printf("��Ԫ�ز����ڣ�\n");
	else
		printf("%d\n",d);
	/*ListTraverse(L);*/

	DestroyList(L);
	printf("����L��LΪ\n");
	ListTraverse(L);

	getchar();
	getchar();
}
