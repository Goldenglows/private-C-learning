#include "����.h"

typedef struct ANode
{
	int adjvex;//�ñ���ָ��Ķ����λ�� 
	struct ANode* next;//������һ���ߵ�ָ�� 
	int weight;//Ȩֵ 
}ArcNode;
typedef struct VNode//������Ϣ 
{
	char data;//�������� 
	ANode* first;//ָ���һ�������ö���ıߵ�ָ�� 
}VNode, AdjList[VMAX];//AdjList��ʾ�ڽӱ����� 
typedef struct//�ڽӱ� 
{
	AdjList vertices;
	int vexnum, arcnum;//ͼ�ĵ�ǰ�������ͱ��� 
}ALGraph;

void InitGraph(ALGraph& G)//ͼ�ĳ�ʼ�� 
{
	int i;
	for (i = 0; i < VMAX; i++)
		G.vertices[i].first = NULL;//ʹ���еĵ�һ����㶼�ÿգ�Ҳ���Ǻ����趨��βָ����пղ��� 
}


void CreateGraph(ALGraph& G)//ͼ�Ĵ��� 
{
	int i;//��¼���� 
	char a;//������� 
	printf("�����붥�����ͱ���:");
	scanf("%d %d", &G.vexnum, &G.arcnum);//�������ͱ����ĸ�ֵ 
	Interrupt();//�ú������ڼ�Ⲣ���ջ��з� 
	printf("�����붥�����ƣ��������룩��");
	for (i = 0; i < G.vexnum; i++)//����ѭ������ͼ�ж������� 
	{
		scanf("%c", &a);
		G.vertices[i].data = a;//��i����������� 
	}
	Interrupt();//�ú������ڼ�Ⲣ���ջ��з�
	char b, c;//������� 
	int w, j, k;//wΪȨֵ������j��k��������¼������ 
	for (i = 0; i < G.arcnum; i++)//����ѭ���������бߵ����������Ȩֵ 
	{
		printf("������ߵ���������:");
		scanf("%c %c", &b, &c);//���� 
		Interrupt();//�ú������ڼ�Ⲣ���ջ��з�
		for (j = 0; j < G.arcnum; j++)//�ò���Ϊ���ϵĺ���LocateVex���� 
		{
			if (G.vertices[j].data == b)//�ҵ�����Ķ���b��λ�� 
				break;
		}
		for (k = 0; k < G.arcnum; k++)
		{
			if (G.vertices[k].data == c)//�ҵ�����Ķ���c��λ�� 
				break;
		}
		ANode* p1, * p2;//��������Ұ��� 
		p1 = (ANode*)malloc(sizeof(ANode));
		p1->adjvex = k;
		p1->weight = 1;//Ȩֵ��ֵ 
		p1->next = G.vertices[j].first;//������ͷ�巨 
		G.vertices[j].first = p1;//��ʹͷ�����Զ���ڵ�һλ 
		p2 = (ANode*)malloc(sizeof(ANode));
		p2->adjvex = j;
		p2->weight = 1;
		p2->next = G.vertices[k].first;
		G.vertices[k].first = p2;
	}
}

void InputGraph(ALGraph G)//�ڽӱ����� 
{
	int i, j;//��¼���� 
	ANode* p1;//���ڱ������� 
	printf("�ڽӱ�Ϊ��\n");
	for (i = 0; i < G.vexnum; i++)//����ѭ����� 
	{
		printf("%c", G.vertices[i].data);
		p1 = G.vertices[i].first;
		while (p1)//��pΪ��ʱ������ѭ�� 
		{
			printf(" --> %d", p1->adjvex);
			p1 = p1->next;//pָ��p����һ����� 
		}
		printf("\n");
	}
}

ANode* p;//����һ��ȫ�ֱ������Ա��ڽ��в��� 
int FirstAdjVex(ALGraph G, int u)//��ʾu�ĵ�һ���ڽӵ� 
{
	p = G.vertices[u].first;//ȫ�ֱ����ĸ�ֵ 
	if (p == NULL)//���ͷ������һ�����Ϊ�գ����ظ��������򷵻�p����ֵ 
		return -1;
	else
		return p->adjvex;
}
int NextAdjVex(ALGraph G)//��һ���ڽӵ� 
{
	p = p->next;//����pΪȫ�ֱ���������ֱ��ָ����һ������ 
	if (p == NULL)//���ͷ������һ�����Ϊ�գ����ظ��������򷵻�p����ֵ  
		return -1;
	else
		return p->adjvex;
}
bool visited[VMAX];//���ʱ�־���� ,���ʼֵΪfalse 
void InitVisited(bool* visited)//��־�����ʼ�� 
{
	for (int i = 0; i < VMAX; i++)
		visited[i] = false;
}