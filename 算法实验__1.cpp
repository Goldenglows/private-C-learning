#include<iostream>
#include<stdio.h>
using namespace std; 

#define MaxInt 32767 
#define MVNum 100   
#define OK 1
#define ERROR -1;

typedef char VType; 
typedef int AType; 
typedef int status;

bool visited[MVNum];
typedef struct{
	VType vexs[MVNum] {'a','b','c','d','e','f','g','h','i','j'};//节点表
	AType arcs[MVNum][MVNum];//邻接表（肯定是个正方形的矩阵）
	int vexnum = 10,arcnum = 12;//该邻接矩阵的节点数、边数  
}AMG; 

int LocateV(AMG G, VType v){
	int i;
	for(i=0;i<G.vexnum;i++){
		if(G.vexs[i]==v){
			return i;
		}
	} 
	return ERROR;
}

status Cudn(AMG &G){//创建无向图 	
int i,j;
	for( i=0;i<G.vexnum;i++){
		for( j=0;j<G.vexnum;j++){
			if(i==j){
				G.arcs[i][j] = 0;
			}else
				G.arcs[i][j] = MaxInt;//初始状态全部节点之间相互不可达
		}
	}
	G.arcs[0][3]=1;
	G.arcs[2][3]=1;
	G.arcs[0][2]=1;
	G.arcs[0][4]=1;
	G.arcs[2][5]=1;
	G.arcs[4][5]=1;
    G.arcs[1][4]=1;
	G.arcs[1][5]=1;
	G.arcs[6][7]=1;
	G.arcs[6][9]=1;
	G.arcs[8][9]=1;
	G.arcs[7][8]=1;
    /*
    a0 b1 c2 d3 e4 f5 g6 h7 i8 j9
    ad cd ac ae cf ef eb fb gh gj ji ih 
    03 23 02 04 25 45 14 15 67 69 98 78
    */
	for(int i=0;i<G.vexnum;i++){
		for(int j=i+1;j<G.vexnum;j++){
			if(G.arcs[i][j]==1){
				G.arcs[j][i] = 1;
			} 
		}
	} 
	return OK; 
}

VType Transform(AMG G, int vn){
	return G.vexs[vn]; 
}

int First(AMG G,VType v){
	int vi = LocateV(G,v);
    int i;
	for( i=0;i<G.vexnum;i++){
		if(!visited[i]&&G.arcs[vi][i]==1){
			return i;
		}
	} 
	return ERROR;
}

int Next(AMG G,VType v ,int vn){
	int vi = LocateV(G,v);
	int i;
	for( i=vn+1;i<G.vexnum;i++){
		if(!visited[i]&&G.arcs[vi][i]==1){
			return i;
		}
	} 
	return ERROR;
}

void DFS(AMG &G,VType v){
	int vi = LocateV(G,v);
	cout<<G.vexs[vi];
	visited[vi] = true;
    int vn;
	for( vn=First(G,v);vn>=0;vn=Next(G,v,vn)){ 
		if(!visited[vn]){
			VType V = Transform(G,vn);
			DFS(G,V);
		} 
	} 
} 

void DFSTraverse(AMG &G){
    int i;
	for( i=0;i<G.vexnum;i++){
		if(!visited[i]){
			VType V = Transform(G,i);
			DFS(G,V);
		}
	}	
} 

int main(){
	char input;
	scanf("%c",&input);
	AMG G;
	Cudn(G);
	DFSTraverse(G);
	return 0;
}
