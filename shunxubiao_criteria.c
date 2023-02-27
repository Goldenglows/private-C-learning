#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef int ElementType;
typedef struct {
    ElementType data[MAXSIZE];
    int length;
} SqList;

// 初始化
void InitList(SqList *L) {
    L->length = 0;
}

// 插入元素
int InsertList(SqList *L, int i, ElementType e) {
    if (L->length >= MAXSIZE) {
        return -1; // 表示表满
    }
    if (i < 1 || i > L->length + 1) {
        return -2; // 表示插入位置无效
    }
    for (int j = L->length; j >= i; j--) {
        L->data[j] = L->data[j-1];
    }
    L->data[i-1] = e;
    L->length++;
    return 0; // 插入成功
}

// 删除元素
int DeleteList(SqList *L, int i, ElementType *e) {
    if (L->length == 0) {
        return -1; // 表示表空
    }
    if (i < 1 || i > L->length) {
        return -2; // 表示删除位置无效
    }
    *e = L->data[i-1];
    for (int j = i; j < L->length; j++) {
        L->data[j-1] = L->data[j];
    }
    L->length--;
    return 0; // 删除成功
}

// 查找元素
int FindList(SqList *L, ElementType e) {
    for (int i = 0; i < L->length; i++) {
        if (L->data[i] == e) {
            return i+1; // 返回查找到的位置
        }
    }
    return -1; // 查找失败
}

// 输出元素
void PrintList(SqList L) {
    for (int i = 0; i < L.length; i++) {
        printf("%d ", L.data[i]);
    }
    printf("\n");
}

int main() {
    SqList L;
    InitList(&L);
    InsertList(&L, 1, 1);
    InsertList(&L, 2, 2);
    InsertList(&L, 3, 3);
    InsertList(&L, 4, 4);
    PrintList(L);
    ElementType e;
    DeleteList(&L, 2, &e);
    printf("delete: %d\n", e);
    PrintList(L);
    int pos = FindList(&L, 3);
    printf("find: %d\n", pos);
    return 0;
}
