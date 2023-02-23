#include"图创建.h"

//深度优先遍历
void DFS(MGraph G, int* visited, int v) {
	visited[v] = 1;  //将访问的结点设置为1 
	//访问这个这个顶点
	visit(G, v);
	//寻找与这个顶点相邻的其他结点 
	for (int k = 0; k < G.vexnum; k++) {
		if (G.AdjMatrix[v][k] == 1) {  //有边 
			if (visited[k] == 0) {  //判断是否被访问过 
				DFS(G, visited, k);//递归
			}
		}
	}
}
int main() {
	int visited[MAX_VERTEX_NUM];
	//初始化访问标记数组 顶点访问则设置为1 
	for (int i = 0; i < MAX_VERTEX_NUM; i++) {
		visited[i] = 0;
	}
	MGraph G;
	CreateGraph(G);//创建图
	DFS(G, visited, 0);//从第一个开始
}

/*
A - B   C - D
|   |   |   |
E   F - G   H

8个顶点 7条边

从A开始 
AEBFGCDH
ABFGCDHE

*/