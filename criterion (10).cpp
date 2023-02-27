#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

#define MAXSIZE 20
//typedef struct
//{
//	int key;//关键字项
//}RedType;//记录类型
//
//typedef struct
//{
//	RedType r[MAXSIZE+1];//r[0]闲置或用作哨兵单元
//	int length;//顺序表长度
//}SqList;//顺序表类型

int Partition(int L[],int low,int high)
{//对顺序表L中的子表r[low...high]进行一趟排序，返回枢纽位置
	int pivotery;

	L[0]=L[low];//用子表的第一个记录做枢纽记录
	pivotery=L[low];//枢纽记录关键字保存在pivotery中
	while(low<high)
	{
		while(low<high&&L[high]>=pivotery)
			--high;
		L[low]=L[high];//将比枢纽记录小的记录移到低端
		while(low<high&&L[low]<=pivotery)
			--low;
		L[high]=L[low];//将比枢纽记录大的记录移到高端
	}
	L[low]=L[0];//
	return low;//返回枢纽位置
}

void QSort(int r[],int low,int high)
{//调用前初值，low=1,high=length,
	int pivortloc;

	if(low<high)//长度大于1
	{
		pivortloc=Partition(r,low,high);//将r[low,high]一分为二，pivortloc是枢纽位置
		QSort(r,low,pivortloc-1);//对左子表递归排序
		QSort(r,pivortloc+1,high);//对右子表递归排序
	}
}

//void QuickSort(int L[])
//{//对顺序表L做快速排序
//	QSort(L,1,length);
//}

void mian()
{
	int i,n;
	int r[MAXSIZE+1];
	cout<<"请输入顺序表的长度："<<endl;
	cin>>n;

	cout<<"请输入待排序的顺序表元素："<<endl;
	for(i=1;i<=n;i++)
	{
		cin>>r[i];
	}

	QSort(r,1,n);
	cout<<"快速排序后的顺序表元素："<<endl;
	for(i=1;i<=n;i++)
	{
		cout<<r[i]<<"\t";
	}
	cout<<endl;

	getchar();
	getchar();
}