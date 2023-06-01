#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// ����ڴ��������
#define MAX_NUM 5

// ��ǰ�ڴ��������
int count = 0;

// �ڴ�ֿ�ṹ��: ��ʼ��ַ����С��ռ�����
typedef struct NeiCun {
    int start;
    int size;
    bool fenpei;
} memory_s;

// �ڴ�ֿ�����
memory_s Neicun_space[MAX_NUM];

// ����ڴ�ֿ�
void Add_Neicun(int start, int size, bool is_used)
{
    memory_s block = { start, size, is_used };
    if (count < MAX_NUM)
    {
        Neicun_space[count] = block;
        count++;
    }
}

// ��ʼ���ڴ沼�֣�����5�����п�
void init_Neicun()
{
    Add_Neicun(100, 60, false);
    Add_Neicun(240, 120, false);
    Add_Neicun(500, 100, false);
    Add_Neicun(760, 80, false);
    Add_Neicun(960, 40, false);
}

// ������ʼ��ַ�����ڴ�ֿ�
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

// �����ڴ��пտ�����
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


// BF �ڴ�����㷨
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
        // û���ҵ����ʵĿ��п飬����ʧ��
        printf("����ʧ��\n");
        return NULL;
    }
    memory_s* block = &Neicun_space[start3];
    if (block->size == size)
    {
        // ���п��С���õ��������С������Ҫ�ָ�
        block->fenpei = true;
        printf("�ɹ�������ʼ��ַΪ %d����СΪ %d\n", block->start, block->size);
        return block;
    }
    // �ָ���п�
    memory_s new_block = { block->start + size, block->size - size, false };
    if (count < MAX_NUM)
    {
        // ���·���Ŀ��п���ӵ��ڴ����������
        for (int i = count; i > start3 + 1; i--)
        {
            Neicun_space[i] = Neicun_space[i - 1];
        }
        Neicun_space[start3 + 1] = new_block;
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

// �޸��ڴ�ֿ�����,д��
void wspace(int start, int size, const char* data)
{
    memory_s* space = find_start(start);
    if (space != NULL && space->fenpei && space->size >= size)
    {
        // ����ҵ����ڴ�ֿ鲢��δ��ռ�ã������޸�����
        const char* val = data;
        for (int i = 0; i < size; i++)
        {
            *(char*)(start + i) = *val;
            val++;
        }
        printf("�ɹ�д����%d�ֽڵ����ݵ���ַΪ%d���ڴ����\n", size, start);
    }
    else
    {
        printf("����ʧ��\n");
    }
}

// �ͷ���ռ�õ��ڴ�ֿ飬�ͷ�
void fspace(int start)
{
    memory_s* space2 = find_start(start);
    if (space2 != NULL && space2->fenpei)
    {
        // �ҵ����ڴ�ֿ鲢���ѱ�ռ�ã������ͷ�
        space2->fenpei = false;
        // ���ڵĿ��п������Ҫ�ϲ�
        if (count > 1)
        {
            for (int i = 0; i < count; i++)
            {
                if (i < count - 1)
                {
                    memory_s* space3 = &Neicun_space[i + 1];
                    if (!space2->fenpei && !space3->fenpei)
                    {
                        // ���ڵ������鶼�ǿ��п飬��Ҫ�ϲ�
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
        printf("�ɹ��ͷţ���ַΪ��%d\n", start);
    }
    else
    {
        printf("����ʧ��\n");
    }
}

int main()
{
    init_Neicun();
    printf("--------------\n");
    printf("1. ����BF \n");
    printf("2. ����WF \n");
    printf("3. �޸�����\n");
    printf("4. �ͷ��ڴ�\n");
    printf("5. �˳�\n");
    printf("--------------\n");

    while (true)
    {
        int choice, size, start;
        char data[100];

        printf("��������Ҫ�Ĳ�����");
        scanf("%d", &choice);
        switch (choice)
        {

        case 1:
            printf("��ѡ����BF,�������������ڴ���С��B����");
            scanf("%d", &size);
            BF(size);
            break;

        case 2:
            printf("��ѡ����WF���������������ڴ���С��B����");
            scanf("%d", &size);
            WF(size);
            break;

        case 3:
            printf("��������Ҫ�޸ĵ��ڴ�����ʼ��ַ��");
            scanf("%d", &start);
            printf("��������Ҫд������ݣ�������100���ַ�����");
            scanf("%s", data);
            size = strlen(data);
            wspace(start, size, data);
            break;

        case 4:
            printf("��������Ҫ�ͷŵ��ڴ�����ʼ��ַ��");
            scanf("%d", &start);
            fspace(start);
            break;

        case 5:
            return 0;

        default:
            printf("�������\n");
            break;
        }
    }
}

