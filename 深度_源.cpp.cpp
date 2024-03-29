
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTEX_NUM 20

////// 存储边信息的结构体
typedef struct ArcNode {
	int adjvex;                // 目标顶点编号
	struct ArcNode* nextarc;   // 指向下一条边的指针
} ArcNode;
////
////// 存储顶点信息的结构体
typedef struct VNode {
	char data;                 // 顶点信息
	ArcNode* firstarc;         // 指向第一条边的指针
} VNode, AdjList[MAX_VERTEX_NUM];

// 图的结构体
typedef struct {
	AdjList vertices;          // 存储顶点信息的数组
	int vexnum, arcnum;        // 顶点数和边数
	int visited[MAX_VERTEX_NUM];  // 记录顶点是否已被访问过
} Graph;

// 初始化图
void initGraph(Graph* G) {
	int i;
	for (i = 0; i < MAX_VERTEX_NUM; i++) {
		G->vertices[i].data = ' ';
		G->vertices[i].firstarc = NULL;
		G->visited[i] = 0;
	}
	G->vexnum = G->arcnum = 0;
}

// 添加边
void addEdge(Graph* G, int i, int j) {
	ArcNode* p = (ArcNode*)malloc(sizeof(ArcNode));
	p->adjvex = j;
	p->nextarc = G->vertices[i].firstarc;
	G->vertices[i].firstarc = p;
	G->arcnum++;
}

// 深度优先遍历
void DFS(Graph* G, int v) {
	printf("%c ", G->vertices[v].data);
	G->visited[v] = 1;
	ArcNode* p = G->vertices[v].firstarc;
	while (p != NULL) {
		int w = p->adjvex;
		if (G->visited[w] == 0) {
			DFS(G, w);
		}
		p = p->nextarc;
	}
}

// 遍历图的所有连通分量
void DFSTraverse(Graph* G) {
	int v;
	for (v = 0; v < G->vexnum; v++) {
		if (G->visited[v] == 0) {
			DFS(G, v);
		}
	}
}

int main() {
	Graph G;
	initGraph(&G);
	G.vexnum = 6;
	G.vertices[0].data = 'A';
	G.vertices[1].data = 'B';
	G.vertices[2].data = 'C';
	G.vertices[3].data = 'D';
	G.vertices[4].data = 'E';
	G.vertices[5].data = 'F';

	addEdge(&G, 0, 1);
	addEdge(&G, 0, 2);
	addEdge(&G, 1, 3);
	addEdge(&G, 1, 4);
	addEdge(&G, 2, 4);
	addEdge(&G, 3, 5);
	addEdge(&G, 4, 5);

	printf("DFS traversal: ");
}