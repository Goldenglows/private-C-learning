#include "邻接表.h" 

//广度优先搜索遍历 

void BFS(ALGraph G,int v)//广度优先搜索遍历 ，非递归形式 
{
	int n;
	printf("%c",G.vertices[v].data);
	visited[v] = true;//访问第v个顶点，并置访问标志数组相应分量值为true 
	SqQueue Q;
	InitQueue(Q);//初始化 
	EnQueue(Q,v);//入队 
	while(!QueueEmpty(Q))//队列非空 
	{
		n = DeQueue(Q);//出队
		for(int w=FirstAdjVex(G,n);w>=0;w=NextAdjVex(G))
		//依次检查u的所有邻接点w,w>=0表示存邻接点
		//函数FirstAdjVex(G,u)表示u的第一个邻接点，函数NextAdjVex(G)表示相对于w的下一个邻接点 
			if(!visited[w])//w为u的尚未访问的邻接点 
			{
				printf("%c",G.vertices[w].data);//访问顶点w
				visited[w] = true;//访问第w个顶点，并置访问标志数组相应分量值为true 
				EnQueue(Q,w);//w入队 
			}
	}
}
/*
  A - B   C - D
  |   |   |   |
  E   F - G - H

  8个顶点 8条边

  从B开始：
  
  BAFEGCHD
  BFAGEHCD
*/

int main()
{
	ALGraph G;
	InitGraph(G);//初始化 
	CreateGraph(G);//邻接表的创建 
	//InputGraph(G);//邻接表的输出 
	BFS(G,1);//广度优先搜索遍历 ，其中的2为测试值，可更换成变量 
	return 0;
}

