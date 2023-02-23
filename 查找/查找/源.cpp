#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100 // ɢ�б����󳤶�

//˳�����
/*
�ӱ��һ�˿�ʼ��˳��ɨ�����Ա�
���ν�ɨ�赽��Ԫ�غ͸���ֵ���бȽϣ�ֱ���ҵ������ֵ��ȵ�Ԫ��Ϊֹ��
����ɨ����������û���ҵ���
*/
/*
int sequentialSearch(int arr[], int n, int target) {
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i] == target) {//������֮�е�ÿһ��Ԫ��������target���жԱ�
            return i; // ����Ŀ��Ԫ�ص��±�
        }
    }
    return -1; // ���û���ҵ�������-1
}
*/

//�۰����
/*
Ҳ��Ϊ���ֲ��ң���һ�ָ�Ч�Ĳ����㷨��
�۰���ҵ�ǰ�������Ա��е�Ԫ�ر��밴�չؼ��ִ�С��������
�����ʵ�ֹ����ǣ�����ȷ�������¼���ڵķ�Χ��Ȼ������С��Χ��
ֱ���ҵ�Ŀ���¼����ȷ��Ŀ���¼������Ϊֹ��
*/
int binarySearch(int arr[], int n, int target) {
    int low = 0; // �������߽�
    int high = n - 1; // ������ұ߽�
    while (low <= high) {
        int mid = (low + high) / 2; // ȡ�м�λ��
        if (arr[mid] == target) {
            return mid; // �ҵ�Ŀ��Ԫ�أ������±�
        }
        else if (arr[mid] < target) {
            low = mid + 1; // Ŀ��Ԫ�����Ұ��
        }
        else {
            high = mid - 1; // Ŀ��Ԫ��������
        }
    }
    return -1; // û���ҵ�Ŀ��Ԫ�أ�����-1
}

//�ֿ����
/*
��һ�ֶ����������ݵĲ����㷨��
�����ص��ǽ��������ݷֳ����ɸ��飬Ȼ���ڿ��ڽ��в��ң�
�Ӷ������˶��������ݼ��Ͻ��в��ҵĸ߰����ۡ�
����ʵ�ֹ����ǣ����Ƚ����ݷֳɿ飬ÿ�����ڵ�Ԫ�ض��������У�
Ȼ���ڿ��ڲ��ң������ҵ�Ŀ��Ԫ�ػ���ȷ��������Ŀ��Ԫ��Ϊֹ��
*/
/*
int blockSearch(int arr[], int n, int block_size, int target) {
    int block_count = ceil((double)n / block_size); // �������
    int block_idx = -1; // ����
    for (int i = 0; i < block_count; i++) {
        int block_start = i * block_size; // �����ʼλ��
        int block_end = (i + 1) * block_size - 1; // ��Ľ���λ��
        if (block_end >= n) {
            block_end = n - 1; // ���һ����Ľ���λ�ÿ��ܳ������鳤��
        }
        if (target >= arr[block_start] && target <= arr[block_end]) {
            block_idx = i; // Ŀ��Ԫ���ڵ�ǰ����
            break;
        }
    }
    if (block_idx == -1) {
        return -1; // Ŀ��Ԫ�ز�����
    }
    int block_start = block_idx * block_size; // Ŀ������ʼλ��
    int block_end = (block_idx + 1) * block_size - 1; // Ŀ���Ľ���λ��
    if (block_end >= n) {
        block_end = n - 1; // ���һ����Ľ���λ�ÿ��ܳ������鳤��
    }
    for (int i = block_start; i <= block_end; i++) {
        if (arr[i] == target) {
            return i; // �ҵ�Ŀ��Ԫ�أ������±�
        }
    }
    return -1; // Ŀ��Ԫ�ز�����
}
*/

//ɢ�в���
/*
��һ�ֻ���ɢ�б�Ĳ����㷨��
�����ؼ���ӳ�䵽һ��ɢ�б��У�����ɢ�б��н��в��ҡ�
����ʵ�ֹ����ǣ����ȶ���һ��ɢ�б�Ȼ�󽫹ؼ�����Ϊɢ�к���������
���������ɢ��ֵ��Ϊɢ�б���±꣬���ؼ��ִ洢��ɢ�б����Ӧλ���ϡ�
����Ҫ����һ���ؼ���ʱ�����ؼ�����Ϊɢ�к��������룬�õ������ɢ��ֵ��
Ȼ����ɢ�б��в��Ҹ�ɢ��ֵ����Ӧ��λ���Ƿ���ڸùؼ��֡�
*/
/*
typedef struct {
    int key; // �ؼ���
    char* value; // ֵ
} HashNode;

typedef struct {
    HashNode* nodes[MAX_SIZE]; // ɢ�б�
    int size; // ɢ�б�Ĵ�С
} HashTable;

int hash(int key, int size) {
    return key % size; // ȡ��ɢ�к���
}

void initHashTable(HashTable* table, int size) {
    table->size = size;
    memset(table->nodes, 0, sizeof(table->nodes)); // ��ɢ�б��еĽڵ�ȫ���ÿ�
}

void insert(HashTable* table, int key, char* value) {
    int index = hash(key, table->size); // ����ɢ��ֵ
    HashNode* node = (HashNode*)malloc(sizeof(HashNode));
    node->key = key;
    node->value = value;
    table->nodes[index] = node; // ���ڵ����ɢ�б�
}

char* search(HashTable* table, int key) {
    int index = hash(key, table->size); // ����ɢ��ֵ
    if (table->nodes[index] == NULL) {
        return NULL; // δ�ҵ��ؼ���
    }
    if (table->nodes[index]->key == key) {
        return table->nodes[index]->value; // �ҵ��ؼ��֣�����ֵ
    }
    return NULL; // δ�ҵ��ؼ���
}
*/


int main() 
{
    int arr[] = { 1,2,3,4,5,6,7,8,9 };
    int n = sizeof(arr) / sizeof(arr[0]); // ��������ĳ���
 
    //˳�����
    /*
    int target = 3;
    int index = sequentialSearch(arr, n, target);
	printf("˳����ҵĽ���ǣ�");
    if (index != -1)
    {
        printf("Ԫ��%d���ڱ��е��±�Ϊ��%d\n",target,index);
    }
    else 
    {
        printf("����û��Ԫ��%d\n",target);
    }
    */
       
    //�۰����
    int target1 = 6;
    int index1 = binarySearch(arr, n, target1);
	printf("�۰���ҵĽ���ǣ�");
    if (index1 != -1)
    {
        printf("Ԫ��%d���ڱ��е��±�Ϊ��%d\n",target1,index1);
    }
    else
    {
        printf("����û�и�Ԫ��%d\n", target1);
    }

    //�ֿ����
    /*
    int block_size = 3; // ÿ����Ĵ�С
    int target3 = 7;
    int index3 = blockSearch(arr, n, block_size, target3);
    printf("�ֿ���ҵĽ���ǣ�");
    if (index3 != -1) 
    {
        printf("Ŀ��Ԫ�� %d ���±��� %d\n", target3, index3);
    }
    else 
    {
        printf("û���ҵ�Ŀ��Ԫ�� %d\n", target3);
    }
    */

    //ɢ�в���
	/*printf("ɢ�в��ҵĽ���ǣ�");
    HashTable table;
    initHashTable(&table, MAX_SIZE);
    insert(&table, 1, "apple");
    insert(&table, 2, "banana");
    insert(&table, 3, "orange");
    char* value = search(&table, 2);
    if (value != NULL) {
        printf("�ؼ��� 2 ��Ӧ��ֵ�� %s\n", value);
    }
    else {
        printf("δ�ҵ��ؼ��� 2\n");
    }
    */
    return 0;

}
