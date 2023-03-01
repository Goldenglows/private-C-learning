#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef struct{
    //查找表的数据结构（顺序表）
    ElemType *elem;
    //动态数组基址
    int TableLen;
    //表的长度
}SSTable;

//有哨兵的顺序查找
int Search_Seq(SSTable ST, ElemType key){
    ST.elem[0]=key;
    //定义哨兵
    //哨兵存放在0位置，查找时从最后一位往前搜索
    //若查到第0个位置
    int i;
    for(i=ST.TableLen;ST.elem[i]!=key;--i);
    return i;
    //查找成功，返回元素下标；失败了，会返回0
    //和无哨兵的相比，无需判断是否越界效率更高
}

//无哨兵的顺序查找实现
int Search_Seq(SSTable ST,ElemType key){
    int i;
    for(i=0;i<ST.TableLen && ST.elem[i] != key; ++i);
    //需要界定查找的位置范围，从0开始
    return i==ST.TableLen ? -1 : i ;
    //查找成功，则返回元素的下标，查找失败则返回-1
}