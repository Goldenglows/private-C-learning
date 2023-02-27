#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

#define OVERFLOW -2
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 10//最大队列长度（对于循环队列，最大队列长度要减1）

#define MAXSIZE1 100//存储空间的初始分配量
#define SElemType int

#define MVNum 100//最大顶点数
typedef struct ArcNode//边结点
{
	int adjvex;//，该边所指向的顶点位置，存储顶点的下标
	struct ArcNode * nextarc;//指向下一条边的指针，连接下一个邻点
}ArcNode;

typedef struct VNode//顶点表结点
{
	int data;//顶点的值
	ArcNode *firstarc;//相连的顶点的值，指向第一条依附于该顶点的边的值
}VNode,AdjList[MVNum];

typedef struct
{//邻接表
	AdjList vertices;
	int vexnum,arcnum;//顶点数，边数
}ALGraph;

bool visited[MVNum];

typedef struct
{
	SElemType *base;
	SElemType *top;
	int stacksize;//栈可用的最大容量
}SqStack;

int InitStack(SqStack &S)//构造一个空栈
{
	S.base=new SElemType[MAXSIZE1];
	if(!S.base)
		exit(OVERFLOW);
	S.top=S.base;//空栈。top和base的值相等
	S.stacksize=MAXSIZE1;//
	return OK;
}

int StackEmpty(SqStack S)//判断S是否为空栈
{
	if(S.top==S.base)
		return TRUE;
	else
		return FALSE;
}

int GetTop(SqStack S,int &e)//返回S栈顶的元素，不修改栈顶指针，并用e保存
{
	if(S.top!=S.base)//栈非空
	{
		e= *(S.top-1);
		return OK;
	}
	else 
		return ERROR;
}

int Push(SqStack &S,int e)//入栈，即在栈顶插入一个新元素
{
	if(S.top-S.base==S.stacksize)//栈满
		return ERROR;
	*S.top=e;//元素e压入栈顶，栈顶指针加1
	S.top++;
	return OK;
}

int Pop(SqStack &S,int &e)//出栈，删除S的栈顶元素，并用e返回其值
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
{//采用邻接表表示法，创建无向图G
	int i,j,k;
	cout<<"请输入顶点和边的个数：";
	cin>>G.vexnum>>G.arcnum;//输入总顶点数，总边数

	for(i=0;i<G.vexnum;++i)//输入各点，创建表头节点表
	{
		cout<<"请输入顶点：";
		cin>>G.vertices[i].data;//输入顶点
		G.vertices[i].firstarc=NULL;//初始化表头节点的指针域为NULL
	}

	int v1,v2;
	ArcNode *p1,*p2;
	
	for(k=0;k<G.arcnum;++k)//输入各边，构造邻接表
	{
		cout<<"请输入一条边依附的两个顶点,v1 v2：";
		cin>>v1>>v2;//输入一条边依附的两个顶点
		i=LocateVex(G,v1);
		j=LocateVex(G,v2);//确定v1，v2在G中的位置，即顶点在G.vertices中的序号
		
		p1=new ArcNode;//生成一个新的边结点*p1
		p1->adjvex=j;//邻接点序号为j
		p1->nextarc=G.vertices[i].firstarc;
		G.vertices[i].firstarc=p1;//头插法，将新结点*p1插入顶点vi的边表头部

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

	visited[i]=true;//表示该点已经访问过
	cout<<G.vertices[i].data<<"\t";
	Push(S,i);
	while(!StackEmpty(S))
	{//栈非空
		GetTop(S,e);//取栈顶元素
		p=G.vertices[e].firstarc;
		while(p&&visited[p->adjvex])//在序号为e顶点的边表中找未被访问过的顶点
		{
			p=p->nextarc;
		}
		if(!p)
			Pop(S,j);//没找到，说明该顶点对应的边表遍历完了，弹出该顶点
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
	printf("请输入从第几个顶点开始遍历：");

	cin>>v;
	DFS1(G,v);
	printf("\n");

	getchar();
	getchar();
}