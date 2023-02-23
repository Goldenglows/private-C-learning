#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#define MAX_VERTEX_NUM 20  //最大顶点数 


typedef struct {
	char vexs[MAX_VERTEX_NUM]; //一维数组存储顶点集 
	int AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];  //邻接表存储边集 
	int vexnum, arcnum;  //图中顶点数和弧的数量 
} MGraph;

//定位顶点在图中的位置
int LocateVex(MGraph G, char vex) {
	for (int i = 0; i < G.vexnum; i++) {
		if (G.vexs[i] == vex)
			return i;
	}
	return -1;
}


//创建图
void CreateGraph(MGraph& G) {
	//初始化
	//输入图中顶点 
	printf("请输入图中顶点数量：");
	scanf("%d", &G.vexnum);
	for (int i = 0; i < G.vexnum; i++) {
		printf("请输入第%d个顶点:", i + 1);
		scanf(" %c", &G.vexs[i]);
	}
	//输入图中的边 
	printf("请输入图中边的数量：");
	scanf("%d", &G.arcnum);
	//初始化邻接矩阵
	for (int i = 0; i < G.vexnum; i++) {
		for (int j = 0; j < G.vexnum; j++) {
			G.AdjMatrix[i][j] = 0;
			//初始化时顶点间都不存在边 
		}
	}
	//构造邻接矩阵
	for (int k = 0; k < G.arcnum; k++) {
		char v1, v2;
		printf("请输入第%d条边（如：AB):", k + 1);
		scanf(" %c%c", &v1, &v2);
		int i = LocateVex(G, v1);  //获取边第一个顶点在图中的位置 
		int j = LocateVex(G, v2);  //获取边第二个顶点在图中的位置 
		G.AdjMatrix[i][j] = 1;  //存在边就设置为1 
		G.AdjMatrix[j][i] = 1;  //由于是无向图所以相反反向也存在边 
	}
	printf("图创建成功！\n");
}

void visit(MGraph G, int v) {
	printf("%c ", G.vexs[v]);
}

