#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 最大内存分区数量
#define MAX_NUM 5

// 当前内存分区数量
int count = 0;

// 内存分块结构体: 起始地址、大小、占用情况
typedef struct NeiCun {
    int start;
    int size;
    bool fenpei;
} memory_s;

// 内存分块数组
memory_s Neicun_space[MAX_NUM];

// 添加内存分块
void Add_Neicun(int start, int size, bool is_used)
{
    memory_s block = { start, size, is_used };
    if (count < MAX_NUM)
    {
        Neicun_space[count] = block;
        count++;
    }
}

// 初始化内存布局，包括5个空闲块
void init_Neicun()
{
    Add_Neicun(100, 60, false);
    Add_Neicun(240, 120, false);
    Add_Neicun(500, 100, false);
    Add_Neicun(760, 80, false);
    Add_Neicun(960, 40, false);
}

// 根据起始地址查找内存分块
memory_s* find_start(int start)
{
    for (int i = 0; i < count; i++)
    {
        if (Neicun_space[i].start == start)
        {
            return &Neicun_space[i];
        }
    }
    return NULL;
}

// 计算内存中空块数量
int empty_space()
{
    int count = 0;
    for (int i = 0; i < MAX_NUM; i++)
    {
        if (!Neicun_space[i].fenpei)
        {
            count++;
        }
    }
    return count;
}


// BF 内存分配算法
memory_s* BF(int size)
{
    int start2 = -1;
    int minsize = 1001;
    for (int i = 0; i < count; i++)
    {
        if (!Neicun_space[i].fenpei && Neicun_space[i].size >= size)
        {
            if (Neicun_space[i].size < minsize)
            {
                minsize = Neicun_space[i].size;
                start2 = i;
            }
        }
    }
    if (start2 == -1)
    {
        // 没有找到合适的空闲块，分配失败
        printf("分配失败\n");
        return NULL;
    }
    memory_s* block = &Neicun_space[start2];
    // 空闲块大小正好等于请求大小，不需要分割
    if (block->size == size)
    {

        block->fenpei = true;
        printf("成功啦，起始地址为 %d，大小为 %d\n", block->start, block->size);
        return block;
    }
    // 分割空闲块
    memory_s new_space = { block->start + size, block->size - size, false };
    if (count < MAX_NUM)
    {
        // 把新分配的空闲块添加到内存分区数组中
        for (int i = count; i > start2 + 1; i--)
        {
            Neicun_space[i] = Neicun_space[i - 1];
        }
        Neicun_space[start2 + 1] = new_space;
        count++;
        block->size = size;
        block->fenpei = true;
        printf("成功啦，起始地址为 %d，大小为 %d\n", block->start, block->size);
        return block;
    }
    else {
        // 内存分区数组已满，分配失败
        printf("分配失败\n");
        return NULL;
    }
}

// WF 内存分配算法
memory_s* WF(int size)
{
    int start3 = -1;
    int minsize = 1001;
    for (int i = 0; i < count; i++)
    {
        if (!Neicun_space[i].fenpei && Neicun_space[i].size >= size)
        {
            if (Neicun_space[i].size - size < minsize)
            {
                minsize = Neicun_space[i].size - size;
                start3 = i;
            }
        }
    }
    if (start3 == -1) {
        // 没有找到合适的空闲块，分配失败
        printf("分配失败\n");
        return NULL;
    }
    memory_s* block = &Neicun_space[start3];
    if (block->size == size)
    {
        // 空闲块大小正好等于请求大小，不需要分割
        block->fenpei = true;
        printf("成功啦，起始地址为 %d，大小为 %d\n", block->start, block->size);
        return block;
    }
    // 分割空闲块
    memory_s new_block = { block->start + size, block->size - size, false };
    if (count < MAX_NUM)
    {
        // 把新分配的空闲块添加到内存分区数组中
        for (int i = count; i > start3 + 1; i--)
        {
            Neicun_space[i] = Neicun_space[i - 1];
        }
        Neicun_space[start3 + 1] = new_block;
        count++;
        block->size = size;
        block->fenpei = true;
        printf("成功啦，起始地址为 %d，大小为 %d\n", block->start, block->size);
        return block;
    }
    else {
        // 内存分区数组已满，分配失败
        printf("分配失败\n");
        return NULL;
    }
}

// 修改内存分块数据,写入
void wspace(int start, int size, const char* data)
{
    memory_s* space = find_start(start);
    if (space != NULL && space->fenpei && space->size >= size)
    {
        // 如果找到该内存分块并且未被占用，可以修改数据
        const char* val = data;
        for (int i = 0; i < size; i++)
        {
            *(char*)(start + i) = *val;
            val++;
        }
        printf("成功写入了%d字节的数据到地址为%d的内存块中\n", size, start);
    }
    else
    {
        printf("分配失败\n");
    }
}

// 释放已占用的内存分块，释放
void fspace(int start)
{
    memory_s* space2 = find_start(start);
    if (space2 != NULL && space2->fenpei)
    {
        // 找到该内存分块并且已被占用，可以释放
        space2->fenpei = false;
        // 相邻的空闲块可能需要合并
        if (count > 1)
        {
            for (int i = 0; i < count; i++)
            {
                if (i < count - 1)
                {
                    memory_s* space3 = &Neicun_space[i + 1];
                    if (!space2->fenpei && !space3->fenpei)
                    {
                        // 相邻的两个块都是空闲块，需要合并
                        space2->size += space3->size;
                        for (int j = i + 1; j < count - 1; j++)
                        {
                            Neicun_space[j] = Neicun_space[j + 1];
                        }
                        count--;
                    }
                }
            }
        }
        printf("成功释放，地址为：%d\n", start);
    }
    else
    {
        printf("分配失败\n");
    }
}

int main()
{
    init_Neicun();
    printf("--------------\n");
    printf("1. 利用BF \n");
    printf("2. 利用WF \n");
    printf("3. 修改数据\n");
    printf("4. 释放内存\n");
    printf("5. 退出\n");
    printf("--------------\n");

    while (true)
    {
        int choice, size, start;
        char data[100];

        printf("请输入想要的操作：");
        scanf("%d", &choice);
        switch (choice)
        {

        case 1:
            printf("您选择了BF,请您输入所需内存块大小（B）：");
            scanf("%d", &size);
            BF(size);
            break;

        case 2:
            printf("您选择了WF，请您输入所需内存块大小（B）：");
            scanf("%d", &size);
            WF(size);
            break;

        case 3:
            printf("请您输入要修改的内存块的起始地址：");
            scanf("%d", &start);
            printf("请您输入要写入的数据（不超过100个字符）：");
            scanf("%s", data);
            size = strlen(data);
            wspace(start, size, data);
            break;

        case 4:
            printf("请您输入要释放的内存块的起始地址：");
            scanf("%d", &start);
            fspace(start);
            break;

        case 5:
            return 0;

        default:
            printf("输入错误\n");
            break;
        }
    }
}

