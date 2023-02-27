#include"stdio.h"
#define MAX 6     //���鳤��
#define LEN (MAX+1) //��ϣ����
typedef struct HashTable
{
	int key;      //�ؼ��� 
	int EmptyFlag;//ռ�ã���ͻ����־��0��ʾû��ռ�ã�1��ʾ��ռ�� 
}HashTable;

void CreateHashTable(HashTable* HT, int* data, int m, int p)
{
	int i, n, k;
	for (i = 0; i < p; i++) //�ѹ�ϣ��ռ�ñ�־��Ϊ0 
	{
		HT[i].EmptyFlag = 0;
	}
	for (i = 0; i < m; i++)
	{
		n = data[i] % p;//�����ϣ��ַ 
		k = 0;//��¼��ͻ���� 
		while (k++ < p)
		{
			if (HT[n].EmptyFlag == 0)
			{
				HT[n].EmptyFlag = 1;//��ʾ��λ���Ѿ���ռ�� 
				HT[n].key = data[i];
				break;
			}
			else
			{
				n = (n + 1) % p; //�����ͻ 
			}
		}
	}
}

//����ȡ�෨
int SearchHashTable(HashTable* tbl, int key, int p)
{
	int n, k, loc;//loc��ʾ����λ���±꣬���Ϊ0���ʾ����ʧ�� 
	n = key % LEN;//����Hash��ַ 
	loc = -1;
	k = 0;//��¼��ͻ���� 
	while (k++ < p)
	{
		if (tbl[n].key == key)
		{
			loc = n;
			break;
		}
		else
		{
			n = (n + 1) % p; //�����ͻ 
		}
	}
	return loc;
}


int main()
{
	HashTable HashTbl[LEN];
	int data[MAX] = { 2,4,6,8,10,12 };
	int i, loc;
	printf("��ʼ���ݣ�\n");
	for (i = 0; i < MAX; i++)
	{
		printf("data[%d] = %5d\n", i, data[i]);
	}

	printf("\n");
	CreateHashTable(HashTbl, data, MAX, LEN);

	printf("��ϣ��  \n");
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
