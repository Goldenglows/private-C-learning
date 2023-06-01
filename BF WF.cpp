#include <stdio.h>
#include <stdbool.h>

// 内存分块结构体: 起始地址、大小、占用情况
typedef struct memory_s {
    int start;
    int size;
    bool fenpei;
} MemoryBlock;

#define MAX_NUM 5 // 最大内存分区数量
memory_s Neicun_space[MAX_NUM]; // 内存分块数组
int count = 0; // 当前内存分区数量

// 添加内存分块
void add_mem_block(int start, int size, bool is_used) {
    memory_s block = { start, size, is_used };
    if (count < MAX_NUM) {
        Neicun_space[count] = block;
        count++;
    }
}

// 初始化内存布局，包括5个空闲块
void init_memory_layout() {
    add_mem_block(100, 60, false);
    add_mem_block(240, 120, false);
    add_mem_block(500, 100, false);
    add_mem_block(760, 80, false);
    add_mem_block(960, 40, false);
}

// 根据起始地址查找内存分块
memory_s* find_mem_block_by_start(int start) {
    for (int i = 0; i < count; i++) {
        if (Neicun_space[i].start == start) {
            return &Neicun_space[i];
        }
    }
    return NULL;
}

// 计算内存中空块数量
int count_free_blocks() {
    int count = 0;
    for (int i = 0; i < MAX_NUM; i++) {
        if (!Neicun_space[i].fenpei) {
            count++;
        }
    }
    return count;
}

// BF 内存分配算法
memory_s* FF(int size) 
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
memory_s* allocate_WF(int size) {
    int start_index = -1;
    int min_size = 1001;
    for (int i = 0; i < count; i++) {
        if (!Neicun_space[i].fenpei && Neicun_space[i].size >= size) {
            if (Neicun_space[i].size - size < min_size) {
                min_size = Neicun_space[i].size - size;
                start_index = i;
            }
        }
    }
    if (start_index == -1) {
        // 没有找到合适的空闲块，分配失败
        return NULL;
    }
    memory_s* block = &Neicun_space[start_index];
    if (block->size == size) {
        // 空闲块大小正好等于请求大小，不需要分割
        block->fenpei = true;
        return block;
    }
    // 分割空闲块
    memory_s new_block = { block->start + size, block->size - size, false };
    if (count < MAX_NUM) {
        // 把新分配的空闲块添加到内存分区数组中
        for (int i = count; i > start_index + 1; i--) {
            Neicun_space[i] = Neicun_space[i - 1];
        }
        Neicun_space[start_index + 1] = new_block;
        count++;
        block->size = size;
        block->fenpei = true;
        return block;
    }
    else {
        // 内存分区数组已满，分配失败
        return NULL;
    }
}

// 修改内存分块数据
void write_data_to_mem_block(int start, int size, char* data) {
    memory_s* block = find_mem_block_by_start(start);
    if (block != NULL && block->fenpei && block->size >= size) {
        // 如果找到该内存分块并且未被占用，可以修改数据
        char* ptr = &data[0];
        for (int i = 0; i < size; i++) {
            *(char*)(start + i) = *ptr;
            ptr++;
        }
    }
}

// 释放已占用的内存分块
void free_mem_block(int start) {
    memory_s* block = find_mem_block_by_start(start);
    if (block != NULL && block->fenpei) {
        // 找到该内存分块并且已被占用，可以释放
        block->fenpei = false;
        // 相邻的空闲块可能需要合并
        if (count > 1) {
            for (int i = 0; i < count; i++) {
                if (i < count - 1) {
                    memory_s* next_block = &Neicun_space[i + 1];
                    if (!block->fenpei && !next_block->fenpei) {
                        // 相邻的两个块都是空闲块，需要合并
                        block->size += next_block->size;
                        for (int j = i + 1; j < count - 1; j++) {
                            Neicun_space[j] = Neicun_space[j + 1];
                        }
                        count--;
                    }
                }
            }
        }
    }
}

int main() {
    init_memory_layout();
    memory_s* block1 = FF(50); // 使用 BF 算法分配内存
    memory_s* block2 = allocate_WF(80); // 使用 WF 算法分配内存
    memory_s* block3 = FF(40); // 使用 BF 算法分配内存
    write_data_to_mem_block(block1->start, 50, "Hello world!");
    write_data_to_mem_block(block2->start, 80, "This is my memory.");
    write_data_to_mem_block(block3->start, 40, "C language.");
    free_mem_block(block1->start); // 释放一个内存分区
    block1 = allocate_WF(100); // 使用 WF 算法重新分配内存
    if (block1 != NULL) {
        write_data_to_mem_block(block1->start, 100, "New data.");
    }
    return 0;