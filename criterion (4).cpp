#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

#define OVERFLOW -2
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 10//�����г��ȣ�����ѭ�����У������г���Ҫ��1��

#define MAXSIZE1 100//�洢�ռ�ĳ�ʼ������
#define SElemType int

#define MVNum 100//��󶥵���
typedef struct ArcNode//�߽��
{
	int adjvex;//���ñ���ָ��Ķ���λ�ã��洢������±�
	struct ArcNode * nextarc;//ָ����һ���ߵ�ָ�룬������һ���ڵ�
}ArcNode;

typedef struct VNode//�������
{
	int data;//�����ֵ
	ArcNode *firstarc;//�����Ķ����ֵ��ָ���һ�������ڸö���ıߵ�ֵ
}VNode,AdjList[MVNum];

typedef struct
{//�ڽӱ�
	AdjList vertices;
	int vexnum,arcnum;//������������
}ALGraph;

bool visited[MVNum];

typedef struct
{
	SElemType *base;
	SElemType *top;
	int stacksize;//ջ���õ��������
}SqStack;

int InitStack(SqStack &S)//����һ����ջ
{
	S.base=new SElemType[MAXSIZE1];
	if(!S.base)
		exit(OVERFLOW);
	S.top=S.base;//��ջ��top��base��ֵ���
	S.stacksize=MAXSIZE1;//
	return OK;
}

int StackEmpty(SqStack S)//�ж�S�Ƿ�Ϊ��ջ
{
	if(S.top==S.base)
		return TRUE;
	else
		return FALSE;
}

int GetTop(SqStack S,int &e)//����Sջ����Ԫ�أ����޸�ջ��ָ�룬����e����
{
	if(S.top!=S.base)//ջ�ǿ�
	{
		e= *(S.top-1);
		return OK;
	}
	else 
		return ERROR;
}

int Push(SqStack &S,int e)//��ջ������ջ������һ����Ԫ��
{
	if(S.top-S.base==S.stacksize)//ջ��
		return ERROR;
	*S.top=e;//Ԫ��eѹ��ջ����ջ��ָ���1
	S.top++;
	return OK;
}

int Pop(SqStack &S,int &e)//��ջ��ɾ��S��ջ��Ԫ�أ�����e������ֵ
{
	if(S.top==S.base)
		return ERROR;
	
	e=*--S.top;
	return OK;
}

int LocateVex(ALGraph G,int u)
{
	int i;
	for(i=0;i<G.vexnum;++i)
	{
		if(u==G.vertices[i].data)
			return i;
	}
	return -1;
}

int CreateUDG(ALGraph &G)
{//�����ڽӱ��ʾ������������ͼG
	int i,j,k;
	cout<<"�����붥��ͱߵĸ�����";
	cin>>G.vexnum>>G.arcnum;//�����ܶ��������ܱ���

	for(i=0;i<G.vexnum;++i)//������㣬������ͷ�ڵ��
	{
		cout<<"�����붥�㣺";
		cin>>G.vertices[i].data;//���붥��
		G.vertices[i].firstarc=NULL;//��ʼ����ͷ�ڵ��ָ����ΪNULL
	}

	int v1,v2;
	ArcNode *p1,*p2;
	
	for(k=0;k<G.arcnum;++k)//������ߣ������ڽӱ�
	{
		cout<<"������һ������������������,v1 v2��";
		cin>>v1>>v2;//����һ������������������
		i=LocateVex(G,v1);
		j=LocateVex(G,v2);//ȷ��v1��v2��G�е�λ�ã���������G.vertices�е����
		
		p1=new ArcNode;//����һ���µı߽��*p1
		p1->adjvex=j;//�ڽӵ����Ϊj
		p1->nextarc=G.vertices[i].firstarc;
		G.vertices[i].firstarc=p1;//ͷ�巨�����½��*p1���붥��vi�ı߱�ͷ��

		p2=new ArcNode;
		p2->adjvex=i;
		p2->nextarc=G.vertices[j].firstarc;
		G.vertices[j].firstarc=p2;
	}
	return OK;
}

void DFS1(ALGraph &G,int i)
{
	SqStack S;
	InitStack(S);
	ArcNode *p;
	int j,e;

	visited[i]=true;//��ʾ�õ��Ѿ����ʹ�
	cout<<G.vertices[i].data<<"\t";
	Push(S,i);
	while(!StackEmpty(S))
	{//ջ�ǿ�
		GetTop(S,e);//ȡջ��Ԫ��
		p=G.vertices[e].firstarc;
		while(p&&visited[p->adjvex])//�����Ϊe����ı߱�����δ�����ʹ��Ķ���
		{
			p=p->nextarc;
		}
		if(!p)
			Pop(S,j);//û�ҵ���˵���ö����Ӧ�ı߱�������ˣ������ö���
		else
		{
			Push(S,p->adjvex);
			cout<<G.vertices[p->adjvex].data<<"\t";
			visited[p->adjvex]=true;
		}
	}
}

void main()
{
	int v;
	ALGraph G;
	
	CreateUDG(G);
	printf("������ӵڼ������㿪ʼ������");

	cin>>v;
	DFS1(G,v);
	printf("\n");

	getchar();
	getchar();
}