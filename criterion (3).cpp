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

int InitList(SqList &L)//初始化
{
	L.elem=new int[MAXSIZE];
	if(!L.elem)
		exit(OVERFLOW);
	L.length=0;
	return OK;
}

int GetElem(SqList L,int i,int &e)//取第i个元素的值
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

int LocateElem(SqList L,int e)//查找顺序表中第一个与e相等的元素在表中的位置序号
{
	for( int i=0;i<L.length-1;++i)
		if(e==L.elem[i])
			return i+1;
	return 0;
}

int ListInsert(SqList &L,int i,int e)//第i个位置插入元素
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

int ListDelete(SqList &L,int i)//删除第i个元素
{
	int j;
	if((i<1)||(i>L.length))
		return ERROR;
	for(j=i;j<L.length;j++)
		L.elem[j-1]=L.elem[j];
	--L.length;
	return OK;
}

int ListLength(SqList L)//表长
{
	return L.length;
}

int ListEmpty(SqList L)//判断是否为空表
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
	printf("在L中依次插入1-5后：L=\n");
	ListTraverse(L);

	//b=ListEmpty(L);
	//printf("L是否为空表：%d(1:是  0:否)\n",b);
	printf("L表长为%d\n",ListLength(L));
	printf("在第5个位置插入数字10,");
	ListInsert(L,5,10);
	printf("此时L为：\n");
	ListTraverse(L);

	a=ListDelete(L,3);
	printf("删除第3个元素\n");
	if(a==0)
		printf("删除元素失败\n");
	else
	{
		printf("删除元素成功,删除第3个元素之后的线性表为\n");
		ListTraverse(L);
	}

	printf("L是否为空表：%d(1:是  0:否)\n",ListEmpty(L));

	d=LocateElem(L,6);
	printf("元素6的位置为:");
	if(d==0)
		printf("该元素不存在！\n");
	else
		printf("%d\n",d);
	/*ListTraverse(L);*/

	DestroyList(L);
	printf("销毁L后：L为\n");
	ListTraverse(L);

	getchar();
	getchar();
}
