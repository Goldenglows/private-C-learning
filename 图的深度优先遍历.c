#include <stdio.h>
#include <stdlib.h>

#define SQSTACKMAXSIZE 10

struct adjacentNode{
	int adjacentNodeNum;
	struct adjacentNode * next;
};

struct graphNode{
	int nodeNum;
	struct adjacentNode * next;
	int visited;
};

struct sqStack{
	int * base;
	int top;
};


struct graphNode * initGraph(int nodeNum);
void dispGraph(struct graphNode * p, int nodeNum);
void DFS(int startNodeNum, struct graphNode * p, struct sqStack * s);
int firstUnvisitedAdjacentNode(struct graphNode * p, int nodeIndex);

struct sqStack * initSqStack();
void push(struct sqStack * s, int data);
int pop(struct sqStack * s);

int main(){
	printf("输入图顶点数量：");
	int nNodes;
	scanf("%d", &nNodes);
	
	struct graphNode * p = initGraph(nNodes);
	dispGraph(p, nNodes);
	
	struct sqStack * s = initSqStack();
	DFS(0, p, s);
	
	return 0;
}

struct graphNode * initGraph(int nNodes){
	
	struct graphNode * p = (struct graphNode *)malloc(nNodes * sizeof(struct graphNode));
	for(int i = 0; i < nNodes; i++){
		p[i].nodeNum = i;
		p[i].next = NULL;
		p[i].visited = 0;
	}
	
	for(int i = 0; i < nNodes; i++){
		printf("输入%d号顶点邻接顶点数：", i);
		int nAdjacentNodes;
		scanf("%d", &nAdjacentNodes);
		
		for(int j = 0; j < nAdjacentNodes; j++){
			printf("输入%d号顶点第%d个邻接顶点的顶点号：", i, j + 1);
			int adjacentNodeNum;
			scanf("%d", &adjacentNodeNum);
			struct adjacentNode * temp = p[i].next;
			p[i].next = (struct adjacentNode *)malloc(sizeof(struct adjacentNode));
			p[i].next->adjacentNodeNum = adjacentNodeNum;
			p[i].next->next = temp;
		}
	}
	
	return p;
}

void dispGraph(struct graphNode * p, int nodeNum){
	
	printf("\n新建图的邻接表为：\n");
	for(int i = 0; i < nodeNum; i++){
		printf("| %d | -> ", p[i].nodeNum);
		struct adjacentNode * temp = p[i].next;
		while(temp != NULL){
			printf("%d -> ", temp->adjacentNodeNum);
			temp = temp->next;
		}
		printf("NULL\n");
	}
	
	printf("\n");
}

struct sqStack * initSqStack(){
	struct sqStack * p = (struct sqStack *)malloc(sizeof(struct sqStack));
	p->top = 0;
	p->base = (int *)malloc(SQSTACKMAXSIZE * sizeof(int));
	return p;
}

void push(struct sqStack * s, int data){
	if(s->top > SQSTACKMAXSIZE){
		printf("栈满，入栈失败\n");
		exit(0);
	}
	s->base[s->top++] = data;
}

int pop(struct sqStack * s){
	if(s->top == 0){
		printf("栈空，出栈失败\n");
		exit(0);
	}
	return s->base[--s->top];
}

void DFS(int startNodeNum, struct graphNode * p, struct sqStack * s){
	printf("深度优先遍历序列:");
	push(s, startNodeNum);
	printf("%d ", startNodeNum);	
	p[startNodeNum].visited = 1;
	
	int temp = startNodeNum;
	int index = firstUnvisitedAdjacentNode(p, temp);
	
	while(s->top != 0 || index != -1){
		if(index != -1){
			push(s, index);
			printf("%d ", index);
			p[index].visited = 1;
			temp = index;
		}
	
		else
			temp = pop(s);
		
		index = firstUnvisitedAdjacentNode(p, temp);
	}
}

int firstUnvisitedAdjacentNode(struct graphNode * p, int nodeIndex){
	struct adjacentNode * temp = p[nodeIndex].next;
	while(temp !=NULL){
		if(p[temp->adjacentNodeNum].visited == 0){
			return temp->adjacentNodeNum;
		}
		temp = temp->next;
	}
	return -1;
}
