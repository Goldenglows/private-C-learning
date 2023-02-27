#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTEX_NUM 20 // ͼ����ඥ����

// ����
typedef struct {
	int data[MAX_VERTEX_NUM];
	int front;
	int rear;
} Queue;

// ��ʼ������
void initQueue(Queue *queue) {
	queue->front = 0;
	queue->rear = 0;
}

// ���
void enQueue(Queue *queue, int value) {
	queue->data[queue->rear] = value;
	queue->rear = (queue->rear + 1) % MAX_VERTEX_NUM;
}

// ����
int deQueue(Queue *queue) {
	int value = queue->data[queue->front];
	queue->front = (queue->front + 1) % MAX_VERTEX_NUM;
	return value;
}

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

	// ���
