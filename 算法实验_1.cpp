#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define VNUM 20 // 图中最多顶点数

// 邻接表节点
typedef struct Node {
	int vno; // 邻接顶点编号
	struct Node *next; // 下一个邻接顶点
} Node;

// 邻接表头结点
typedef struct VertexNode {
	int data; // 顶点数据
	Node *first; // 指向第一个邻接顶点
} VertexNode;

// 图
typedef struct {
	VertexNode List[VNUM]; // 邻接表
	int VN; // 顶点数
	int EN; // 边数
} Graph;

// 初始化图
void initGraph(Graph *graph) {
	graph->VN = 0;
	graph->EN = 0;
	for (int i = 0; i < VNUM; i++) {
		graph->List[i].data = 0;
		graph->List[i].first = NULL;
	}
}

// 添加顶点
void addVertex(Graph *graph, char vertex) {
	graph->List[graph->VN].data = vertex;
	graph->VN++;
}

// 添加边
void addEdge(Graph *graph, int start, int end) {
	Node *newNode1 = (Node *)malloc(sizeof(Node));
	newNode1->vno = end;
	newNode1->next = graph->List[start].first;
	graph->List[start].first = newNode1;

	Node *newNode2 = (Node *)malloc(sizeof(Node));
	newNode2->vno = start;
	newNode2->next = graph->List[end].first;
	graph->List[end].first = newNode2;

	graph->EN++;
}

// 深度优先遍历
void DFS(Graph *graph, int v, bool *visited) {
	visited[v] = true;
	printf("%d ", graph->List[v].data);
	Node *p = graph->List[v].first;
	while (p) {
		if (!visited[p->vno]) {
			DFS(graph, p->vno, visited);
		}
		p = p->next;
	}
}

int main() {
	Graph graph;
	initGraph(&graph);

    int i;
	// 添加顶点

	addVertex(&graph, 'a');
	addVertex(&graph, 'b');
    addVertex(&graph, 'c');
    addVertex(&graph, 'd');
    addVertex(&graph, 'e');
    addVertex(&graph, 'f');
    addVertex(&graph, 'g');
    addVertex(&graph, 'h');
    addVertex(&graph, 'i');
    addVertex(&graph, 'j');

	// 添加边
	addEdge(&graph, 1, 2);
	addEdge(&graph, 1, 3);
	addEdge(&graph, 2, 4);
	addEdge(&graph, 2, 5);
	addEdge(&graph, 3, 5);
	addEdge(&graph, 4, 6);
	addEdge(&graph, 5, 6);

	bool visited[VNUM] = { false };
	for (int i = 0; i < graph.VN; i++) {
		if (!visited[i]) {
			DFS(&graph, i, visited);
		}
	}

	return 0;
}