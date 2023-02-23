#include"stdio.h"
#define MAX 6     //数组长度
#define LEN (MAX+1) //哈希表长度
typedef struct HashTable
{
	int key;      //关键字 
	int EmptyFlag;//占用（冲突）标志，0表示没被占用，1表示被占用 
}HashTable;

void CreateHashTable(HashTable* HT, int* data, int m, int p)
{
	int i, n, k;
	for (i = 0; i < p; i++) //把哈希表被占用标志置为0 
	{
		HT[i].EmptyFlag = 0;
	}
	for (i = 0; i < m; i++)
	{
		n = data[i] % p;//计算哈希地址 
		k = 0;//记录冲突次数 
		while (k++ < p)
		{
			if (HT[n].EmptyFlag == 0)
			{
				HT[n].EmptyFlag = 1;//表示该位置已经被占用 
				HT[n].key = data[i];
				break;
			}
			else
			{
				n = (n + 1) % p; //处理冲突 
			}
		}
	}
}

//除留取余法
int SearchHashTable(HashTable* tbl, int key, int p)
{
	int n, k, loc;//loc表示查找位置下标，如果为0则表示查找失败 
	n = key % LEN;//计算Hash地址 
	loc = -1;
	k = 0;//记录冲突次数 
	while (k++ < p)
	{
		if (tbl[n].key == key)
		{
			loc = n;
			break;
		}
		else
		{
			n = (n + 1) % p; //处理冲突 
		}
	}
	return loc;
}


int main()
{
	HashTable HashTbl[LEN];
	int data[MAX] = { 2,4,6,8,10,12 };
	int i, loc;
	printf("初始数据：\n");
	for (i = 0; i < MAX; i++)
	{
		printf("data[%d] = %5d\n", i, data[i]);
	}

	printf("\n");
	CreateHashTable(HashTbl, data, MAX, LEN);

	printf("哈希表：  \n");
	for (i = 0; i < MAX; i++)
	{
		printf("HT[%d] = %5d\n", i, HashTbl[i].key);
	}
	printf("\n");

	for (i = 0; i < MAX; i++)
	{
		loc = SearchHashTable(HashTbl, data[i], LEN);
		printf("%5d 's loc = %5d\n", data[i], loc);
	}

	return 0;
}
