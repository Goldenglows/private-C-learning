#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <limits.h>

// 计算两个磁块之间的距离
int Distance(int current, int tar_block, int disk_range) {
    return abs((tar_block - current + disk_range) % disk_range);
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

    int current_block = 0;

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

    printf("磁盘调度顺序为：");

    //输出磁块序列
    int start = current_block;
    while (1) {
        int tar_block = -1;
        int min_distance = disk_range;

        // 在当前位置往外扫描，找到下一个距离最小的磁块
        for (int i = 0; i < disk_num; i++) {
            if (disk_list[i] >= current_block && Distance(current_block, disk_list[i], disk_range) < min_distance) {
                tar_block = i;
                min_distance = Distance(current_block, disk_list[i], disk_range);
            }
        }

        // 如果当前位置找不到更小的磁块，则将磁头移动到最边界并重新扫描
        if (tar_block == -1) {
            current_block = start;
            continue;
        }

        printf("%d ", disk_list[tar_block]);
        current_block = disk_list[tar_block];

        // 移除已经访问过的磁块
        for (int i = tar_block; i < disk_num - 1; i++) {
            disk_list[i] = disk_list[i + 1];
        }
        disk_num--;
    }

    printf("\n");

    free(disk_list);
    return 0;
}