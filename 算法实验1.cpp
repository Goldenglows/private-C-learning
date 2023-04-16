#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

typedef struct{
    char vexs[MAXSIZE];
    int arcs[MAXSIZE][MAXSIZE];
    int vn, an;
}Graph;

int get_index(char* arr,char m)
{
    int i = 0;
    for(i = 0; i < MAXSIZE; i++)
    {
        if(arr[i] == m)return i;
    }
    return -1;
}
 
void CreatGraph(Graph* G)
{
    int i,j = 0;
    for(i = 0; i < G->vn; i++)
    {
        for(j = 0; j < G->vn; j++)
            {
                G->arcs[i][j] = 0;
            }
 
    }
 
    G->vexs[0]='a';
    G->vexs[1]='b';
    G->vexs[2]='c';
    G->vexs[3]='d';
    G->vexs[4]='e';
    G->vexs[5]='f';
    G->vexs[6]='g';
    G->vexs[7]='h';
    G->vexs[8]='i';
    G->vexs[9]='j';

    //gh
    G->arcs[get_index(G->vexs,'g')][get_index(G->vexs,'h')] = 1;
    G->arcs[get_index(G->vexs,'h')][get_index(G->vexs,'g')] = 1;

    //hi
    G->arcs[get_index(G->vexs,'i')][get_index(G->vexs,'h')] = 1;
    G->arcs[get_index(G->vexs,'h')][get_index(G->vexs,'i')] = 1;

    //ij
    G->arcs[get_index(G->vexs,'i')][get_index(G->vexs,'j')] = 1;
    G->arcs[get_index(G->vexs,'j')][get_index(G->vexs,'i')] = 1;

    //jg
    G->arcs[get_index(G->vexs,'g')][get_index(G->vexs,'j')] = 1;
    G->arcs[get_index(G->vexs,'j')][get_index(G->vexs,'g')] = 1;

    //ad
    G->arcs[get_index(G->vexs,'a')][get_index(G->vexs,'d')] = 1;
    G->arcs[get_index(G->vexs,'d')][get_index(G->vexs,'a')] = 1;

    //dc
    G->arcs[get_index(G->vexs,'d')][get_index(G->vexs,'c')] = 1;
    G->arcs[get_index(G->vexs,'c')][get_index(G->vexs,'d')] = 1;

    //ac
    G->arcs[get_index(G->vexs,'a')][get_index(G->vexs,'c')] = 1;
    G->arcs[get_index(G->vexs,'c')][get_index(G->vexs,'a')] = 1;

    //ae
    G->arcs[get_index(G->vexs,'a')][get_index(G->vexs,'e')] = 1;
    G->arcs[get_index(G->vexs,'e')][get_index(G->vexs,'a')] = 1;

    //cf
    G->arcs[get_index(G->vexs,'c')][get_index(G->vexs,'f')] = 1;
    G->arcs[get_index(G->vexs,'f')][get_index(G->vexs,'c')] = 1;

    //fe
    G->arcs[get_index(G->vexs,'f')][get_index(G->vexs,'e')] = 1;
    G->arcs[get_index(G->vexs,'e')][get_index(G->vexs,'f')] = 1;

    //eb
    G->arcs[get_index(G->vexs,'e')][get_index(G->vexs,'b')] = 1;
    G->arcs[get_index(G->vexs,'b')][get_index(G->vexs,'e')] = 1;

    //fb
    G->arcs[get_index(G->vexs,'f')][get_index(G->vexs,'b')] = 1;
    G->arcs[get_index(G->vexs,'b')][get_index(G->vexs,'f')] = 1;
 
}

void DPS(Graph G, int v, int*visited)
{
    int i = 0;
    visited[v] = 1;
    printf("%c", G.vexs[v]);
    for(i = 0; i < G.vn; i++)
    {
        if((G.arcs[v][i] == 1)&&(visited[i]!=1))
            DPS(G, i,visited);
    }
}
int main()
{
    Graph G;
    CreatGraph(&G);
    char input;
    int visited[MAXSIZE] = {0};
    scanf("%c",&input);
    DPS(G, get_index(G.vexs, input),visited);
    return 0;
 
}