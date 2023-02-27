#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTEX_NUM 20 // 图中最多顶点数

// 邻接表节点
typedef struct Node {
	int adjvex; // 邻接顶点编号
	struct Node *next; // 下一个邻接顶点
} Node;

// 邻接表头结点
typedef struct VertexNode {
	int data; // 顶点数据
	Node *first; // 指向第一个邻接顶点
} VertexNode;

// 图
typedef struct {
	VertexNode adjList[MAX_VERTEX_NUM]; // 邻接表
	int vertexNum; // 顶点数
	int edgeNum; // 边数
} Graph;

// 初始化图
void initGraph(Graph *graph) {
	graph->vertexNum = 0;
	graph->edgeNum = 0;
	for (int i = 0; i < MAX_VERTEX_NUM; i++) {
		graph->adjList[i].data = 0;
		graph->adjList[i].first = NULL;
	}
}

// 添加顶点
void addVertex(Graph *graph, int vertex) {
	graph->adjList[graph->vertexNum].data = vertex;
	graph->vertexNum++;
}

// 添加边
void addEdge(Graph *graph, int start, int end) {
	Node *newNode1 = (Node *)malloc(sizeof(Node));
	newNode1->adjvex = end;
	newNode1->next = graph->adjList[start].first;
	graph->adjList[start].first = newNode1;

	Node *newNode2 = (Node *)malloc(sizeof(Node));
	newNode2->adjvex = start;
	newNode2->next = graph->adjList[end].first;
	graph->adjList[end].first = newNode2;

	graph->edgeNum++;
}

// 深度优先遍历
void DFS(Graph *graph, int v, bool *visited) {
	visited[v] = true;
	printf("%d ", graph->adjList[v].data);
	Node *p = graph->adjList[v].first;
	while (p) {
		if (!visited[p->adjvex]) {
			DFS(graph, p->adjvex, visited);
		}
		p = p->next;
	}
}

int main() {
	Graph graph;
	initGraph(&graph);

	// 添加顶点
	for (int i = 1; i <= 6; i++) {
		addVertex(&graph, i);
	}

	// 添加边
	addEdge(&graph, 1, 2);
	addEdge(&graph, 1, 3);
	addEdge(&graph, 2, 4);
	addEdge(&graph, 2, 5);
	addEdge(&graph, 3, 5);
	addEdge(&graph, 4, 6);
	addEdge(&graph, 5, 6);

	bool visited[MAX_VERTEX_NUM] = { false };
	for (int i = 0; i < graph.vertexNum; i++) {
		if (!visited[i]) {
			DFS(&graph, i, visited);
		}
	}

	return 0;
}
