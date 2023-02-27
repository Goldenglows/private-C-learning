#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTEX_NUM 20 // 图中最多顶点数

// 队列
typedef struct {
	int data[MAX_VERTEX_NUM];
	int front;
	int rear;
} Queue;

// 初始化队列
void initQueue(Queue *queue) {
	queue->front = 0;
	queue->rear = 0;
}

// 入队
void enQueue(Queue *queue, int value) {
	queue->data[queue->rear] = value;
	queue->rear = (queue->rear + 1) % MAX_VERTEX_NUM;
}

// 出队
int deQueue(Queue *queue) {
	int value = queue->data[queue->front];
	queue->front = (queue->front + 1) % MAX_VERTEX_NUM;
	return value;
}

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

// 广度优先遍历
void BFS(Graph *graph, int start, bool *visited) {
	Queue queue;
	initQueue(&queue);
	enQueue(&queue, start);
	visited[start] = true;

	while (queue.front != queue.rear) {
		int vertex = deQueue(&queue);
		printf("%d ", graph->adjList[vertex].data);

		Node *p = graph->adjList[vertex].first;
		while (p) {
			if (!visited[p->adjvex]) {
				enQueue(&queue, p->adjvex);
				visited[p->adjvex] = true;
			}
			p = p->next;
		}
	}
}

int main() {
	Graph graph;
	initGraph(&graph);

	// 添加
