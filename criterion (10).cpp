#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

#define MAXSIZE 20
//typedef struct
//{
//	int key;//�ؼ�����
//}RedType;//��¼����
//
//typedef struct
//{
//	RedType r[MAXSIZE+1];//r[0]���û������ڱ���Ԫ
//	int length;//˳�����
//}SqList;//˳�������

int Partition(int L[],int low,int high)
{//��˳���L�е��ӱ�r[low...high]����һ�����򣬷�����Ŧλ��
	int pivotery;

	L[0]=L[low];//���ӱ�ĵ�һ����¼����Ŧ��¼
	pivotery=L[low];//��Ŧ��¼�ؼ��ֱ�����pivotery��
	while(low<high)
	{
		while(low<high&&L[high]>=pivotery)
			--high;
		L[low]=L[high];//������Ŧ��¼С�ļ�¼�Ƶ��Ͷ�
		while(low<high&&L[low]<=pivotery)
			--low;
		L[high]=L[low];//������Ŧ��¼��ļ�¼�Ƶ��߶�
	}
	L[low]=L[0];//
	return low;//������Ŧλ��
}

void QSort(int r[],int low,int high)
{//����ǰ��ֵ��low=1,high=length,
	int pivortloc;

	if(low<high)//���ȴ���1
	{
		pivortloc=Partition(r,low,high);//��r[low,high]һ��Ϊ����pivortloc����Ŧλ��
		QSort(r,low,pivortloc-1);//�����ӱ�ݹ�����
		QSort(r,pivortloc+1,high);//�����ӱ�ݹ�����
	}
}

//void QuickSort(int L[])
//{//��˳���L����������
//	QSort(L,1,length);
//}

void mian()
{
	int i,n;
	int r[MAXSIZE+1];
	cout<<"������˳���ĳ��ȣ�"<<endl;
	cin>>n;

	cout<<"������������˳���Ԫ�أ�"<<endl;
	for(i=1;i<=n;i++)
	{
		cin>>r[i];
	}

	QSort(r,1,n);
	cout<<"����������˳���Ԫ�أ�"<<endl;
	for(i=1;i<=n;i++)
	{
		cout<<r[i]<<"\t";
	}
	cout<<endl;

	getchar();
	getchar();
}