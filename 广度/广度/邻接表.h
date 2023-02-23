#include "队列.h"

typedef struct ANode
{
	int adjvex;//该边所指向的顶点的位置 
	struct ANode* next;//该向下一条边的指针 
	int weight;//权值 
}ArcNode;
typedef struct VNode//顶点信息 
{
	char data;//顶点名称 
	ANode* first;//指向第一条依附该顶点的边的指针 
}VNode, AdjList[VMAX];//AdjList表示邻接表类型 
typedef struct//邻接表 
{
	AdjList vertices;
	int vexnum, arcnum;//图的当前顶点数和边数 
}ALGraph;

void InitGraph(ALGraph& G)//图的初始化 
{
	int i;
	for (i = 0; i < VMAX; i++)
		G.vertices[i].first = NULL;//使所有的第一个结点都置空，也就是后面设定的尾指针的判空操作 
}


void CreateGraph(ALGraph& G)//图的创建 
{
	int i;//记录次数 
	char a;//顶点变量 
	printf("请输入顶点数和边数:");
	scanf("%d %d", &G.vexnum, &G.arcnum);//顶点数和边数的赋值 
	Interrupt();//该函数用于检测并吸收换行符 
	printf("请输入顶点名称（连续输入）：");
	for (i = 0; i < G.vexnum; i++)//利用循环输入图中顶点名称 
	{
		scanf("%c", &a);
		G.vertices[i].data = a;//第i个顶点的命名 
	}
	Interrupt();//该函数用于检测并吸收换行符
	char b, c;//顶点变量 
	int w, j, k;//w为权值变量，j和k是用来记录次数的 
	for (i = 0; i < G.arcnum; i++)//利用循环输入所有边的两个顶点和权值 
	{
		printf("请输入边的两个顶点:");
		scanf("%c %c", &b, &c);//输入 
		Interrupt();//该函数用于检测并吸收换行符
		for (j = 0; j < G.arcnum; j++)//该操作为书上的函数LocateVex操作 
		{
			if (G.vertices[j].data == b)//找到输入的顶点b的位置 
				break;
		}
		for (k = 0; k < G.arcnum; k++)
		{
			if (G.vertices[k].data == c)//找到输入的顶点c的位置 
				break;
		}
		ANode* p1, * p2;//创建两个野结点 
		p1 = (ANode*)malloc(sizeof(ANode));
		p1->adjvex = k;
		p1->weight = 1;//权值赋值 
		p1->next = G.vertices[j].first;//类似于头插法 
		G.vertices[j].first = p1;//并使头结点永远放在第一位 
		p2 = (ANode*)malloc(sizeof(ANode));
		p2->adjvex = j;
		p2->weight = 1;
		p2->next = G.vertices[k].first;
		G.vertices[k].first = p2;
	}
}

void InputGraph(ALGraph G)//邻接表的输出 
{
	int i, j;//记录次数 
	ANode* p1;//用于遍历链表 
	printf("邻接表为：\n");
	for (i = 0; i < G.vexnum; i++)//利用循环输出 
	{
		printf("%c", G.vertices[i].data);
		p1 = G.vertices[i].first;
		while (p1)//当p为空时，结束循环 
		{
			printf(" --> %d", p1->adjvex);
			p1 = p1->next;//p指向p的下一个结点 
		}
		printf("\n");
	}
}

ANode* p;//创建一个全局变量，以便于进行查找 
int FirstAdjVex(ALGraph G, int u)//表示u的第一个邻接点 
{
	p = G.vertices[u].first;//全局变量的赋值 
	if (p == NULL)//如果头结点的下一个结点为空，返回负数，否则返回p结点的值 
		return -1;
	else
		return p->adjvex;
}
int NextAdjVex(ALGraph G)//下一个邻接点 
{
	p = p->next;//由于p为全局变量，这里直接指向下一个便是 
	if (p == NULL)//如果头结点的下一个结点为空，返回负数，否则返回p结点的值  
		return -1;
	else
		return p->adjvex;
}
bool visited[VMAX];//访问标志数组 ,其初始值为false 
void InitVisited(bool* visited)//标志数组初始化 
{
	for (int i = 0; i < VMAX; i++)
		visited[i] = false;
}