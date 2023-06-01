#include <stdio.h>
#include <stdbool.h>

// �ڴ�ֿ�ṹ��: ��ʼ��ַ����С��ռ�����
typedef struct memory_s {
    int start;
    int size;
    bool fenpei;
} MemoryBlock;

#define MAX_NUM 5 // ����ڴ��������
memory_s Neicun_space[MAX_NUM]; // �ڴ�ֿ�����
int count = 0; // ��ǰ�ڴ��������

// ����ڴ�ֿ�
void add_mem_block(int start, int size, bool is_used) {
    memory_s block = { start, size, is_used };
    if (count < MAX_NUM) {
        Neicun_space[count] = block;
        count++;
    }
}

// ��ʼ���ڴ沼�֣�����5�����п�
void init_memory_layout() {
    add_mem_block(100, 60, false);
    add_mem_block(240, 120, false);
    add_mem_block(500, 100, false);
    add_mem_block(760, 80, false);
    add_mem_block(960, 40, false);
}

// ������ʼ��ַ�����ڴ�ֿ�
memory_s* find_mem_block_by_start(int start) {
    for (int i = 0; i < count; i++) {
        if (Neicun_space[i].start == start) {
            return &Neicun_space[i];
        }
    }
    return NULL;
}

// �����ڴ��пտ�����
int count_free_blocks() {
    int count = 0;
    for (int i = 0; i < MAX_NUM; i++) {
        if (!Neicun_space[i].fenpei) {
            count++;
        }
    }
    return count;
}

// BF �ڴ�����㷨
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
        // û���ҵ����ʵĿ��п飬����ʧ��
        printf("����ʧ��\n");
        return NULL;
    }
    memory_s* block = &Neicun_space[start2];
    // ���п��С���õ��������С������Ҫ�ָ�
    if (block->size == size) 
    {
        
        block->fenpei = true;
        printf("�ɹ�������ʼ��ַΪ %d����СΪ %d\n", block->start, block->size);
        return block;
    }
    // �ָ���п�
    memory_s new_space = { block->start + size, block->size - size, false };
    if (count < MAX_NUM) 
    {
        // ���·���Ŀ��п���ӵ��ڴ����������
        for (int i = count; i > start2 + 1; i--) 
        {
            Neicun_space[i] = Neicun_space[i - 1];
        }
        Neicun_space[start2 + 1] = new_space;
        count++;
        block->size = size;
        block->fenpei = true;
        printf("�ɹ�������ʼ��ַΪ %d����СΪ %d\n", block->start, block->size);
        return block;
    }
    else {
        // �ڴ������������������ʧ��
        printf("����ʧ��\n");
        return NULL;
    }
}

// WF �ڴ�����㷨
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
        // û���ҵ����ʵĿ��п飬����ʧ��
        return NULL;
    }
    memory_s* block = &Neicun_space[start_index];
    if (block->size == size) {
        // ���п��С���õ��������С������Ҫ�ָ�
        block->fenpei = true;
        return block;
    }
    // �ָ���п�
    memory_s new_block = { block->start + size, block->size - size, false };
    if (count < MAX_NUM) {
        // ���·���Ŀ��п���ӵ��ڴ����������
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
        // �ڴ������������������ʧ��
        return NULL;
    }
}

// �޸��ڴ�ֿ�����
void write_data_to_mem_block(int start, int size, char* data) {
    memory_s* block = find_mem_block_by_start(start);
    if (block != NULL && block->fenpei && block->size >= size) {
        // ����ҵ����ڴ�ֿ鲢��δ��ռ�ã������޸�����
        char* ptr = &data[0];
        for (int i = 0; i < size; i++) {
            *(char*)(start + i) = *ptr;
            ptr++;
        }
    }
}

// �ͷ���ռ�õ��ڴ�ֿ�
void free_mem_block(int start) {
    memory_s* block = find_mem_block_by_start(start);
    if (block != NULL && block->fenpei) {
        // �ҵ����ڴ�ֿ鲢���ѱ�ռ�ã������ͷ�
        block->fenpei = false;
        // ���ڵĿ��п������Ҫ�ϲ�
        if (count > 1) {
            for (int i = 0; i < count; i++) {
                if (i < count - 1) {
                    memory_s* next_block = &Neicun_space[i + 1];
                    if (!block->fenpei && !next_block->fenpei) {
                        // ���ڵ������鶼�ǿ��п飬��Ҫ�ϲ�
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
    memory_s* block1 = FF(50); // ʹ�� BF �㷨�����ڴ�
    memory_s* block2 = allocate_WF(80); // ʹ�� WF �㷨�����ڴ�
    memory_s* block3 = FF(40); // ʹ�� BF �㷨�����ڴ�
    write_data_to_mem_block(block1->start, 50, "Hello world!");
    write_data_to_mem_block(block2->start, 80, "This is my memory.");
    write_data_to_mem_block(block3->start, 40, "C language.");
    free_mem_block(block1->start); // �ͷ�һ���ڴ����
    block1 = allocate_WF(100); // ʹ�� WF �㷨���·����ڴ�
    if (block1 != NULL) {
        write_data_to_mem_block(block1->start, 100, "New data.");
    }
    return 0;