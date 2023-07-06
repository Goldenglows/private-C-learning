#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <limits.h>

// 计算两个磁块之间的距离
int Distance(int block1, int block2) {
    return abs(block2 - block1);
}

int main() {
    int disk_num, disk_range;

    printf("请输入磁盘总数：");
    scanf("%d", &disk_num);

    printf("请输入磁块范围：");
    scanf("%d", &disk_range);

    // 初始化随机数种子
    srand((unsigned int)time(NULL));

    // 生成随机磁块序列
    int* disk_list = (int*)malloc(disk_num * sizeof(int));
    printf("随机生成的磁块序列为：");
    for (int i = 0; i < disk_num; i++) {
        disk_list[i] = rand() % (disk_range + 1);
        printf("%d ", disk_list[i]);
    }
    printf("\n");

    // 初始化队列
    int* queue1 = (int*)malloc(disk_num * sizeof(int));
    int* queue2 = (int*)malloc(disk_num * sizeof(int));
    int front1 = 0, rear1 = 0;
    int front2 = 0, rear2 = 0;

    // 将请求按照扫描方向分配到两个队列
    int current_block = 0;
    for (int i = 0; i < disk_num; i++) {
        if (disk_list[i] < current_block) {
            queue1[rear1++] = disk_list[i];
        }
        else {
            queue2[rear2++] = disk_list[i];
        }
    }

    // 对两个队列分别进行排序
    for (int i = front1; i < rear1 - 1; i++) {
        for (int j = front1; j < rear1 - i - 1; j++) {
            if (queue1[j] < queue1[j + 1]) {
                int temp = queue1[j];
                queue1[j] = queue1[j + 1];
                queue1[j + 1] = temp;
            }
        }
    }

    for (int i = front2; i < rear2 - 1; i++) {
        for (int j = front2; j < rear2 - i - 1; j++) {
            if (queue2[j] > queue2[j + 1]) {
                int temp = queue2[j];
                queue2[j] = queue2[j + 1];
                queue2[j + 1] = temp;
            }
        }
    }

    printf("磁盘调度顺序为：");

    // 先输出队列2中的磁块序列
    for (int i = front2; i < rear2; i++) {
        printf("%d ", queue2[i]);
        current_block = queue2[i];
    }

    // 再输出队列1中的磁块序列
    for (int i = front1; i < rear1; i++) {
        printf("%d ", queue1[i]);
        current_block = queue1[i];
    }

    printf("\n");

    free(disk_list);
    free(queue1);
    free(queue2);
    return 0;
}