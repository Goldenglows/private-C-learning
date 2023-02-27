#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100 // 散列表的最大长度

//顺序查找
/*
从表的一端开始，顺序扫描线性表，
依次将扫描到的元素和给定值进行比较，直到找到与给定值相等的元素为止，
或者扫描完整个表都没有找到。
*/
/*
int sequentialSearch(int arr[], int n, int target) {
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i] == target) {//将数组之中的每一个元素依次与target进行对比
            return i; // 返回目标元素的下标
        }
    }
    return -1; // 如果没有找到，返回-1
}
*/

//折半查找
/*
也称为二分查找，是一种高效的查找算法。
折半查找的前提是线性表中的元素必须按照关键字大小有序排列
具体的实现过程是：首先确定待查记录所在的范围，然后逐步缩小范围，
直到找到目标记录或者确定目标记录不存在为止。
*/
int binarySearch(int arr[], int n, int target) {
    int low = 0; // 数组的左边界
    int high = n - 1; // 数组的右边界
    while (low <= high) {
        int mid = (low + high) / 2; // 取中间位置
        if (arr[mid] == target) {
            return mid; // 找到目标元素，返回下标
        }
        else if (arr[mid] < target) {
            low = mid + 1; // 目标元素在右半边
        }
        else {
            high = mid - 1; // 目标元素在左半边
        }
    }
    return -1; // 没有找到目标元素，返回-1
}

//分块查找
/*
是一种对于有序数据的查找算法，
它的特点是将有序数据分成若干个块，然后在块内进行查找，
从而避免了对整个数据集合进行查找的高昂代价。
具体实现过程是：首先将数据分成块，每个块内的元素都有序排列，
然后在块内查找，最终找到目标元素或者确定不存在目标元素为止。
*/
/*
int blockSearch(int arr[], int n, int block_size, int target) {
    int block_count = ceil((double)n / block_size); // 计算块数
    int block_idx = -1; // 块编号
    for (int i = 0; i < block_count; i++) {
        int block_start = i * block_size; // 块的起始位置
        int block_end = (i + 1) * block_size - 1; // 块的结束位置
        if (block_end >= n) {
            block_end = n - 1; // 最后一个块的结束位置可能超出数组长度
        }
        if (target >= arr[block_start] && target <= arr[block_end]) {
            block_idx = i; // 目标元素在当前块内
            break;
        }
    }
    if (block_idx == -1) {
        return -1; // 目标元素不存在
    }
    int block_start = block_idx * block_size; // 目标块的起始位置
    int block_end = (block_idx + 1) * block_size - 1; // 目标块的结束位置
    if (block_end >= n) {
        block_end = n - 1; // 最后一个块的结束位置可能超出数组长度
    }
    for (int i = block_start; i <= block_end; i++) {
        if (arr[i] == target) {
            return i; // 找到目标元素，返回下标
        }
    }
    return -1; // 目标元素不存在
}
*/

//散列查找
/*
是一种基于散列表的查找算法，
它将关键字映射到一个散列表中，并在散列表中进行查找。
具体实现过程是：首先定义一个散列表，然后将关键字作为散列函数的输入
，将输出的散列值作为散列表的下标，将关键字存储在散列表的相应位置上。
当需要查找一个关键字时，将关键字作为散列函数的输入，得到输出的散列值，
然后在散列表中查找该散列值所对应的位置是否存在该关键字。
*/
/*
typedef struct {
    int key; // 关键字
    char* value; // 值
} HashNode;

typedef struct {
    HashNode* nodes[MAX_SIZE]; // 散列表
    int size; // 散列表的大小
} HashTable;

int hash(int key, int size) {
    return key % size; // 取余散列函数
}

void initHashTable(HashTable* table, int size) {
    table->size = size;
    memset(table->nodes, 0, sizeof(table->nodes)); // 将散列表中的节点全部置空
}

void insert(HashTable* table, int key, char* value) {
    int index = hash(key, table->size); // 计算散列值
    HashNode* node = (HashNode*)malloc(sizeof(HashNode));
    node->key = key;
    node->value = value;
    table->nodes[index] = node; // 将节点插入散列表
}

char* search(HashTable* table, int key) {
    int index = hash(key, table->size); // 计算散列值
    if (table->nodes[index] == NULL) {
        return NULL; // 未找到关键字
    }
    if (table->nodes[index]->key == key) {
        return table->nodes[index]->value; // 找到关键字，返回值
    }
    return NULL; // 未找到关键字
}
*/


int main() 
{
    int arr[] = { 1,2,3,4,5,6,7,8,9 };
    int n = sizeof(arr) / sizeof(arr[0]); // 计算数组的长度
 
    //顺序查找
    /*
    int target = 3;
    int index = sequentialSearch(arr, n, target);
	printf("顺序查找的结果是：");
    if (index != -1)
    {
        printf("元素%d，在表中的下标为：%d\n",target,index);
    }
    else 
    {
        printf("表中没有元素%d\n",target);
    }
    */
       
    //折半查找
    int target1 = 6;
    int index1 = binarySearch(arr, n, target1);
	printf("折半查找的结果是：");
    if (index1 != -1)
    {
        printf("元素%d，在表中的下标为：%d\n",target1,index1);
    }
    else
    {
        printf("表中没有该元素%d\n", target1);
    }

    //分块查找
    /*
    int block_size = 3; // 每个块的大小
    int target3 = 7;
    int index3 = blockSearch(arr, n, block_size, target3);
    printf("分块查找的结果是：");
    if (index3 != -1) 
    {
        printf("目标元素 %d 的下标是 %d\n", target3, index3);
    }
    else 
    {
        printf("没有找到目标元素 %d\n", target3);
    }
    */

    //散列查找
	/*printf("散列查找的结果是：");
    HashTable table;
    initHashTable(&table, MAX_SIZE);
    insert(&table, 1, "apple");
    insert(&table, 2, "banana");
    insert(&table, 3, "orange");
    char* value = search(&table, 2);
    if (value != NULL) {
        printf("关键字 2 对应的值是 %s\n", value);
    }
    else {
        printf("未找到关键字 2\n");
    }
    */
    return 0;

}
