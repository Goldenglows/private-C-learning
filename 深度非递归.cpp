#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTEX_NUM 20 // ͼ����ඥ����

// �ڽӱ�ڵ�
typedef struct Node {
	int adjvex; // �ڽӶ�����
	struct Node *next; // ��һ���ڽӶ���
} Node;

// �ڽӱ�ͷ���
typedef struct VertexNode {
	int data; // ��������
	Node *first; // ָ���һ���ڽӶ���
} VertexNode;

// ͼ
typedef struct {
	VertexNode adjList[MAX_VERTEX_NUM]; // �ڽӱ�
	int vertexNum; // ������
	int edgeNum; // ����
} Graph;

// ��ʼ��ͼ
void initGraph(Graph *graph) {
	graph->vertexNum = 0;
	graph->edgeNum = 0;
	for (int i = 0; i < MAX_VERTEX_NUM; i++) {
		graph->adjList[i].data = 0;
		graph->adjList[i].first = NULL;
	}
}

// ��Ӷ���
void addVertex(Graph *graph, int vertex) {
	graph->adjList[graph->vertexNum].data = vertex;
	graph->vertexNum++;
}

// ��ӱ�
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

// ������ȱ���
void DFS(Graph *graph, int start, bool *visited) {
	int stack[MAX_VERTEX_NUM];
	int top = 0;
	stack[top] = start;
	visited[start] = true;
	printf("%d ", graph->adjList[start].data);

	while (top >= 0) {
		Node *p = graph->adjList[stack[top]].first;
		bool hasUnvisited = false;
		while (p) {
			if (!visited[p->adjvex]) {
				stack[++top] = p->adjvex;
				visited[p->adjvex] = true;
				printf("%d ", graph->adjList[p->adjvex].data);
				hasUnvisited = true;
				break;
			}
			p = p->next;
		}
		if (!hasUnvisited) {
			top--;
		}
	}
}

int main() {
	Graph graph;
	initGraph(&graph);

	// ��Ӷ���
	for (int i = 1; i <= 6; i++) {
		addVertex(&graph, i);
	}

	// ��ӱ�
	addEdge(&graph, 1, 2);
	addEdge(&graph, 1, 3);
	addEdge(&graph, 2, 4);
	addEdge(&graph, 2, 5);
	addEdge(&graph, 3, 5);
	addEdge(&graph, 4, 6);
	addEdge
