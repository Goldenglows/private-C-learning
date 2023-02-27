#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef int ElementType;
typedef struct shunxubiao_1{
    ElementType data[MAXSIZE];
    int len;
};

void Initlist(struct shunxubiao_1 *L){
    //初始化
    L->len = 0;
}

int Insertlist(struct shunxubiao_1 *L,int i,ElementType e)
{               //顺序表    插入位置    插入的元素
    if (L->len >= MAXSIZE){
        return -1;
        //判满
    }
    if(i<1||i>L->len+1){
        //插入位置错误
        return -2;
    }
    for(int j=L->len;j>=i;j--){
        //从i之后的元素全部后移动一格
        L->data[j] = L->data[j-1];
    }
    L->data[i-1] = e;
    //在此处插入元素
    L->len++;
    //表长度变大一格
    return 0;
};
 
 int Deletelist (struct shunxubiao_1 *L, int i, ElementType *e){
    //删除元素
    if(L->len == 0){
        //判空
        return -1;
    }
    if(i < 1 || i > L -> len){
        //位置无效
        return -2;
    }
    *e = L->data[i-1];
    //将删除的元素赋值给e
    for (int j = i; j<L->len;j++){
        //遍历所有元素，所有元素后移一个
        L-> data [j-1] = L->data[j];
    }
    L->len --;
    //长度减一
    return 0;
 }

int Find_list(struct shunxubiao_1 *L,ElementType e){
    for (int i = 0; i<L->len;i++){
        //遍历
        if(L->data[i]==e){
            return i+1;
            //返回查找到的位置
        }
    }
    return -1;
    //查找失败
}

void Print_list (struct shunxubiao_1 *L){
    for (int i = 0; i<L->len; i++){
        printf ("%d", L->data[i]);
    }
    printf("\n");
}












