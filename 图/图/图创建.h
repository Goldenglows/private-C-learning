#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#define MAX_VERTEX_NUM 20  //��󶥵��� 


typedef struct {
	char vexs[MAX_VERTEX_NUM]; //һά����洢���㼯 
	int AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];  //�ڽӱ�洢�߼� 
	int vexnum, arcnum;  //ͼ�ж������ͻ������� 
} MGraph;

//��λ������ͼ�е�λ��
int LocateVex(MGraph G, char vex) {
	for (int i = 0; i < G.vexnum; i++) {
		if (G.vexs[i] == vex)
			return i;
	}
	return -1;
}


//����ͼ
void CreateGraph(MGraph& G) {
	//��ʼ��
	//����ͼ�ж��� 
	printf("������ͼ�ж���������");
	scanf("%d", &G.vexnum);
	for (int i = 0; i < G.vexnum; i++) {
		printf("�������%d������:", i + 1);
		scanf(" %c", &G.vexs[i]);
	}
	//����ͼ�еı� 
	printf("������ͼ�бߵ�������");
	scanf("%d", &G.arcnum);
	//��ʼ���ڽӾ���
	for (int i = 0; i < G.vexnum; i++) {
		for (int j = 0; j < G.vexnum; j++) {
			G.AdjMatrix[i][j] = 0;
			//��ʼ��ʱ����䶼�����ڱ� 
		}
	}
	//�����ڽӾ���
	for (int k = 0; k < G.arcnum; k++) {
		char v1, v2;
		printf("�������%d���ߣ��磺AB):", k + 1);
		scanf(" %c%c", &v1, &v2);
		int i = LocateVex(G, v1);  //��ȡ�ߵ�һ��������ͼ�е�λ�� 
		int j = LocateVex(G, v2);  //��ȡ�ߵڶ���������ͼ�е�λ�� 
		G.AdjMatrix[i][j] = 1;  //���ڱ߾�����Ϊ1 
		G.AdjMatrix[j][i] = 1;  //����������ͼ�����෴����Ҳ���ڱ� 
	}
	printf("ͼ�����ɹ���\n");
}

void visit(MGraph G, int v) {
	printf("%c ", G.vexs[v]);
}

