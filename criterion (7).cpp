#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

#define ERROR 0
#define OK 1
#define MAXSTRLEN 40
typedef char SString[MAXSTRLEN+1];//0�ŵ�Ԫ��Ŵ��ĳ���

int StrAssign(SString T,char *chars)
{//����һ����ֵ����chars�Ĵ�T
	int i;
	if(strlen(chars)>MAXSTRLEN)
		return ERROR;
	else
	{
		T[0]=strlen(chars);
		for(i=1;i<=T[0];i++)
			T[i]=*(chars+i-1);
		return OK;
	}
}

int StrLength(SString S)
{//���ش���Ԫ�ظ���
	return S[0];
}

void get_next(SString T,int next[])
{//��ģʽ��T��next����ֵ����������next
	int i=1,j=0;
	next[1]=0;
	while(i<T[0])
	{
		if(j==0||T[i]==T[j])
		{																						
			++i;
			++j;
			next[i]=j;
		}
		else
			j=next[j];
	}
}

int Index_KMP(SString S,SString T,int pos,int next[])
{//����ģʽ��T��next������T������S�е�pos���ַ�֮���λ�õ�KMP�㷨
//���У�T�ǿգ�1<=pos<=StrLength(S)
	int i=pos,j=1;
	while(i<=S[0]&&j<=T[0])
	{
		if(j==0||S[i]==T[j])//�����ȽϺ���ַ�
		{
			++i;
			++j;
		}
		else//ģʽ������ƶ�
			j=next[j];
	}
	if(j>T[0])//ƥ��ɹ�
		return i-T[0];
	else
		return 0;
}

void get_nextval(SString T,int nextval[])
{//��ģʽ��next��������ֵ
	int i=1,j=0;
	nextval[1]=0;
	while(i<T[0])
	{
		if(j==0||T[i]==T[j])
		{
		 ++i;
		 ++j;
		if(T[i]!=T[j])
			nextval[i]=j;
		else
			nextval[i]=nextval[j];
		}
		else
			j=nextval[j];
	}
}

void StrPrint(SString T)
{//����ַ���T
	int i;
	for(i=1;i<=T[0];i++)
		printf("%c",T[i]);
	printf("\n");
}

void main()
{
	int i,j,*p,a,b;
	SString s1,s2;

	StrAssign(s1,"aaabaaaab");
	printf("����Ϊ��");
	StrPrint(s1);
	StrAssign(s2,"aaaab");
	printf("�Ӵ�Ϊ");
	StrPrint(s2);

	i=StrLength(s2);
	p=(int*)malloc((i+1)*sizeof(int));

	get_next(s2,p);
	printf("�Ӵ���next����Ϊ��");
	for(j=1;j<=i;j++)
		printf("%d",*(p+j));
	printf("\n");

	get_nextval(s2,p);
	printf("�Ӵ���nextval����Ϊ��");
	for(j=1;j<=i;j++)
		printf("%d",*(p+j));
	printf("\n");

	b=Index_KMP(s1,s2,1,p);
	if(b)
		printf("�������Ӵ��ڵ�%d���ַ����״�ƥ��\n",b);
	else
		printf("ƥ��ʧ�ܣ�\n");

	getchar();
	getchar();
}