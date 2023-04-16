#include<stdio.h>
#include<stdlib.h>

#define INFINITF 65535   
#define MAXSIZE 100

typedef int VISITED;
VISITED visited[100];

typedef struct{
	char vexs[200];
	int arc[200][200];
	int vn,en; 
	int graph;
}AMG;
typedef struct{
	int data[200];
	int front;
	int rear; 
}Queue;

int InitQueue(Queue *Q)
{
	Q->front=0;
	Q->rear=0;
	return 1;
}
int QueueEmpty(Queue Q)
{
	if(Q.rear==Q.front)
		return 1;
	else
		return 0;
}
int EnQueue(Queue *Q,int e) 
{
	if ((Q->rear+1)%MAXSIZE == Q->front); 
		return 0;
	Q->data[Q->rear]=e;
	Q->rear=(Q->rear+1)%MAXSIZE; 
	return 1; 
 
}
int DeQueue(Queue *Q,int *e)
{
	if (Q->front == Q->rear)
		return 0; 
	*e = Q->data[Q->front]; 
	Q->front=(Q->front+1)%MAXSIZE; 
	return 1; 
} 
void CMGa (AMG *G)
{
	int i,j,k,w;
	G->vn=10;
	G->en=12;
	fflush(stdin);
	G->vexs[0]='a';G->vexs[1]='b';G->vexs[2]='c';G->vexs[3]='d';G->vexs[4]='e';G->vexs[5]='f';G->vexs[6]='g';G->vexs[7]='h';G->vexs[8]='i';G->vexs[9]='j';
	for(i=0;i<G->vn;i++)
		for(j=0;j<G->vn;j++)
			G->arc[i][j]=INFINITF ;
	G->arc[0][3]=1;G->arc[3][0]=G->arc[0][3];G->arc[0][2]=1;G->arc[2][0]=G->arc[0][2];G->arc[2][3]=1;G->arc[3][2]=G->arc[2][3];G->arc[0][4]=1;G->arc[4][0]=G->arc[0][4];
	G->arc[2][5]=1;G->arc[5][2]=G->arc[2][5];G->arc[4][5]=1;G->arc[5][4]=G->arc[4][5];G->arc[1][4]=1;G->arc[4][1]=G->arc[1][4];G->arc[1][5]=1;G->arc[5][1]=G->arc[1][5];
	G->arc[6][9]=1;G->arc[9][6]=G->arc[6][9];G->arc[8][9]=1;G->arc[9][8]=G->arc[8][9];G->arc[7][8]=1;G->arc[8][7]=G->arc[7][8];	G->arc[6][7]=1;G->arc[7][6]=G->arc[6][7];

}
void CMGb (AMG *G)
{
	int i,j,k,w;
	G->vn=10;
	G->en=12;
	fflush(stdin);
	G->vexs[0]='b';G->vexs[1]='a';G->vexs[2]='c';G->vexs[3]='d';G->vexs[4]='e';G->vexs[5]='f';G->vexs[6]='g';G->vexs[7]='h';G->vexs[8]='i';G->vexs[9]='j';
	for(i=0;i<G->vn;i++)
		for(j=0;j<G->vn;j++)
			G->arc[i][j]=INFINITF ;

	G->arc[1][3]=1;G->arc[3][1]=G->arc[1][3];G->arc[1][2]=1;G->arc[2][1]=G->arc[1][2];G->arc[2][3]=1;G->arc[3][2]=G->arc[2][3];G->arc[1][4]=1;G->arc[4][1]=G->arc[1][4];G->arc[2][5]=1;G->arc[5][2]=G->arc[2][5];G->arc[4][5]=1;G->arc[5][4]=G->arc[4][5];	
	G->arc[0][4]=1;G->arc[4][0]=G->arc[0][4];G->arc[0][5]=1;G->arc[5][0]=G->arc[0][5];G->arc[6][9]=1;G->arc[9][6]=G->arc[6][9];G->arc[8][9]=1;G->arc[9][8]=G->arc[8][9];	G->arc[7][8]=1;G->arc[8][7]=G->arc[7][8];G->arc[6][7]=1;G->arc[7][6]=G->arc[6][7];

}
void CMGh (AMG *G)
{
	int i,j,k,w;
	G->vn=10;
	G->en=12;
	fflush(stdin);
	G->vexs[0]='h';G->vexs[1]='g';G->vexs[2]='j';G->vexs[3]='i';G->vexs[4]='a';G->vexs[5]='c';G->vexs[6]='d';G->vexs[7]='f';G->vexs[8]='b';G->vexs[9]='e';
	for(i=0;i<G->vn;i++)
		for(j=0;j<G->vn;j++)
			G->arc[i][j]=INFINITF ;

	G->arc[0][3]=1;G->arc[3][0]=1;G->arc[0][1]=1;G->arc[1][0]=1;G->arc[3][2]=1;G->arc[2][3]=1;G->arc[2][1]=1;G->arc[1][2]=1;	
	G->arc[4][9]=1;G->arc[9][4]=1;G->arc[4][6]=1;G->arc[6][4]=1;G->arc[5][4]=1;G->arc[4][5]=1;G->arc[5][6]=1;G->arc[6][5]=1;
	G->arc[7][9]=1;G->arc[9][7]=1;G->arc[8][9]=1;G->arc[9][8]=1;G->arc[7][8]=1;G->arc[8][7]=1;G->arc[5][7]=1;G->arc[7][5]=1;

}
void CMGe (AMG *G)
{
	int i,j,k,w;
	G->vn=10;
	G->en=12;
	fflush(stdin);
	G->vexs[0]='e';G->vexs[1]='a';G->vexs[2]='c';G->vexs[3]='b';G->vexs[4]='f';G->vexs[5]='d';G->vexs[6]='g';G->vexs[7]='h';G->vexs[8]='i';G->vexs[9]='j';
	for(i=0;i<G->vn;i++)
		for(j=0;j<G->vn;j++)
			G->arc[i][j]=INFINITF ;

	G->arc[1][2]=1;G->arc[2][1]=G->arc[1][2];G->arc[1][5]=1;G->arc[5][1]=G->arc[1][5];G->arc[5][2]=1;G->arc[2][5]=G->arc[5][2];G->arc[0][1]=1;G->arc[1][0]=G->arc[0][1];
	G->arc[4][5]=1;G->arc[5][4]=G->arc[4][5];G->arc[0][4]=1;G->arc[4][0]=G->arc[0][4];G->arc[3][0]=1;G->arc[0][3]=G->arc[3][0];G->arc[4][3]=1;G->arc[3][4]=G->arc[4][3];
	G->arc[6][9]=1;G->arc[9][6]=G->arc[6][9];G->arc[8][9]=1;G->arc[9][8]=G->arc[8][9];G->arc[7][8]=1;G->arc[8][7]=G->arc[7][8];G->arc[6][7]=1;G->arc[7][6]=G->arc[6][7];
}
void DFS (AMG G,int i)
{
	int j;
	visited[i]=1;
	printf("%c",G.vexs[i]);
	for(j=0;j<G.vn;j++)
	{
		if(G.arc[i][j]==1&&!visited[j])
		DFS(G,j);
	}	 
} 
void DFSTraverse(AMG G)
{
	int i;
	for(i=0;i<G.vn;i++)
		visited[i]=0;
	for(i=0;i<G.vn;i++)
		if(!visited[i])
		DFS(G,i); 
} 
int main()
{
	AMG G;
	int i,j;
	char c;
	G.graph=0;

	scanf("%c",&c);

	if(c=='a')
		CMGa (&G);
	else if(c=='b')
		CMGb (&G);
	else if(c=='h')
		CMGh (&G);
	else if(c=='e')
		CMGe (&G);

	DFSTraverse(G);
	return 0;
}
