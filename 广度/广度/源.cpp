#include "�ڽӱ�.h" 

//��������������� 

void BFS(ALGraph G,int v)//��������������� ���ǵݹ���ʽ 
{
	int n;
	printf("%c",G.vertices[v].data);
	visited[v] = true;//���ʵ�v�����㣬���÷��ʱ�־������Ӧ����ֵΪtrue 
	SqQueue Q;
	InitQueue(Q);//��ʼ�� 
	EnQueue(Q,v);//��� 
	while(!QueueEmpty(Q))//���зǿ� 
	{
		n = DeQueue(Q);//����
		for(int w=FirstAdjVex(G,n);w>=0;w=NextAdjVex(G))
		//���μ��u�������ڽӵ�w,w>=0��ʾ���ڽӵ�
		//����FirstAdjVex(G,u)��ʾu�ĵ�һ���ڽӵ㣬����NextAdjVex(G)��ʾ�����w����һ���ڽӵ� 
			if(!visited[w])//wΪu����δ���ʵ��ڽӵ� 
			{
				printf("%c",G.vertices[w].data);//���ʶ���w
				visited[w] = true;//���ʵ�w�����㣬���÷��ʱ�־������Ӧ����ֵΪtrue 
				EnQueue(Q,w);//w��� 
			}
	}
}
/*
  A - B   C - D
  |   |   |   |
  E   F - G - H

  8������ 8����

  ��B��ʼ��
  
  BAFEGCHD
  BFAGEHCD
*/

int main()
{
	ALGraph G;
	InitGraph(G);//��ʼ�� 
	CreateGraph(G);//�ڽӱ�Ĵ��� 
	//InputGraph(G);//�ڽӱ����� 
	BFS(G,1);//��������������� �����е�2Ϊ����ֵ���ɸ����ɱ��� 
	return 0;
}

