#include"stdio.h"
#define M 6
#define P (M+1)
typedef struct HashTable
{
	int key;      //关键字 
	int EmptyFlag;//占用（冲突）标志，0表示没被占用，1表示被占用 
}HashTable;

void CreateHashTable( HashTable *tbl, int *data, int m, int p );
int SearchHashTable( HashTable *tbl, int key, int p );

int main()
{
	HashTable HashTbl[P];
	int data[M] = { 10, 8, 14, 15, 20, 31 };
	int i, loc;
	printf( "初始数据：\n" );
	for( i=0; i<M; i++ )
	{
		printf( "data[%d] = %5d\n", i, data[i] );
	}
	printf( "\n" );
	CreateHashTable( HashTbl, data, M, P );
	printf( "哈希表：  \n" );
	for( i=0; i<M; i++ )
	{
		printf( "tbl[%d] = %5d\n", i, HashTbl[i].key );
	}
	printf( "\n" );
	for( i=0; i<M; i++ )
	{
		loc = SearchHashTable( HashTbl, data[i], P );
		printf( "%5d 's loc = %5d\n", data[i], loc );
	}
	
	return 0;
}
void CreateHashTable( HashTable *tbl, int *data, int m, int p )
{
	int i, addr, k;
	for( i=0; i<p; i++ ) //把哈希表被占用标志置为0 
	{
		tbl[i].EmptyFlag = 0;
	}
	for( i=0; i<m; i++ )
	{
		addr = data[i] % p;//计算哈希地址 
		k = 0;//记录冲突次数 
		while( k++ < p )
		{
			if( tbl[addr].EmptyFlag == 0 )
			{
				tbl[addr].EmptyFlag = 1;//表示该位置已经被占用 
				tbl[addr].key   = data[i];
				break;
			}
			else
			{
				addr =  ( addr + 1 ) % p; //处理冲突 
			}
		}	
	}
}

int SearchHashTable( HashTable *tbl, int key, int p )
{
	int addr, k, loc;//loc表示查找位置下标，如果为0则表示查找失败 
	addr = key % P;//计算Hash地址 
	loc = -1; 
	k = 0;//记录冲突次数 
	while( k++ < p )
	{
		if( tbl[addr].key == key )
		{
			loc = addr;
			break;
		}
		else
		{
			addr =  ( addr + 1 ) % p; //处理冲突 
		}	
	}
	return loc;
}
