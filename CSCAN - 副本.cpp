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

    // 排序磁块序列
    for (int i = 0; i < disk_num - 1; i++) {
        for (int j = 0; j < disk_num - i - 1; j++) {
            if (disk_list[j] > disk_list[j + 1]) {
                int temp = disk_list[j];
                disk_list[j] = disk_list[j + 1];
                disk_list[j + 1] = temp;
            }
        }
    }

    // 计算磁盘调度顺序
    int current_block = 0;
    printf("磁盘调度顺序为：");

    // 扫描方向向前
    for (int i = current_block; i <= disk_range; i++) {
        for (int j = 0; j < disk_num; j++) {
            if (disk_list[j] >= current_block) {
                printf("%d ", disk_list[j]);
                current_block = disk_list[j];
            }
        }
    }

    // 从0开始扫描到当前位置的最大值
    for (int i = 0; i <= current_block; i++) {
        for (int j = 0; j < disk_num; j++) {
            if (disk_list[j] <= current_block) {
                printf("%d ", disk_list[j]);
                current_block = disk_list[j];
            }
        }
    }

    printf("\n");

    free(disk_list);
    return 0;
}