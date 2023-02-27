#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

#define ERROR 0
#define OK 1
#define MAXSTRLEN 40
typedef char SString[MAXSTRLEN+1];//0号单元存放串的长度

int StrAssign(SString T,char *chars)
{//生成一个其值等于chars的串T
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
{//返回串的元素个数
	return S[0];
}

void get_next(SString T,int next[])
{//求模式串T的next函数值并存入数组next
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
{//利用模式串T的next函数求T在主串S中第pos个字符之后的位置的KMP算法
//其中，T非空，1<=pos<=StrLength(S)
	int i=pos,j=1;
	while(i<=S[0]&&j<=T[0])
	{
		if(j==0||S[i]==T[j])//继续比较后继字符
		{
			++i;
			++j;
		}
		else//模式串向后移动
			j=next[j];
	}
	if(j>T[0])//匹配成功
		return i-T[0];
	else
		return 0;
}

void get_nextval(SString T,int nextval[])
{//求模式串next函数修正值
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
{//输出字符串T
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
	printf("主串为：");
	StrPrint(s1);
	StrAssign(s2,"aaaab");
	printf("子串为");
	StrPrint(s2);

	i=StrLength(s2);
	p=(int*)malloc((i+1)*sizeof(int));

	get_next(s2,p);
	printf("子串的next函数为：");
	for(j=1;j<=i;j++)
		printf("%d",*(p+j));
	printf("\n");

	get_nextval(s2,p);
	printf("子串的nextval函数为：");
	for(j=1;j<=i;j++)
		printf("%d",*(p+j));
	printf("\n");

	b=Index_KMP(s1,s2,1,p);
	if(b)
		printf("主串和子串在第%d个字符处首次匹配\n",b);
	else
		printf("匹配失败！\n");

	getchar();
	getchar();
}