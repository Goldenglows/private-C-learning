#include"ͼ����.h"

//������ȱ���
void DFS(MGraph G, int* visited, int v) {
	visited[v] = 1;  //�����ʵĽ������Ϊ1 
	//��������������
	visit(G, v);
	//Ѱ��������������ڵ�������� 
	for (int k = 0; k < G.vexnum; k++) {
		if (G.AdjMatrix[v][k] == 1) {  //�б� 
			if (visited[k] == 0) {  //�ж��Ƿ񱻷��ʹ� 
				DFS(G, visited, k);//�ݹ�
			}
		}
	}
}
int main() {
	int visited[MAX_VERTEX_NUM];
	//��ʼ�����ʱ������ �������������Ϊ1 
	for (int i = 0; i < MAX_VERTEX_NUM; i++) {
		visited[i] = 0;
	}
	MGraph G;
	CreateGraph(G);//����ͼ
	DFS(G, visited, 0);//�ӵ�һ����ʼ
}

/*
A - B   C - D
|   |   |   |
E   F - G   H

8������ 7����

��A��ʼ 
AEBFGCDH
ABFGCDHE

*/