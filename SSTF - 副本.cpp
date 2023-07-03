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

// 找到最接近当前位置的磁块
int Nearest(int* block_list, int disk_num, int current_block, bool* visited) {
    int near_cikuai = -1;
    int min_distance = INT_MAX;

    for (int i = 0; i < disk_num; i++) {
        if (!visited[i]) {
            int distance = Distance(current_block, block_list[i]);
            if (distance < min_distance) {
                min_distance = distance;
                near_cikuai = i;
            }
        }
    }

    return near_cikuai;
}

int main() {
    int disk_num, disk_range;

    printf("请输入磁盘总数：");
    scanf("%d", &disk_num);

    printf("请输入磁块范围：");
    scanf("%d", &disk_range);

    // 初始化随机数种子
    srand(time(NULL));

    // 生成随机磁块序列
    int* disk_list = (int*)malloc(disk_num * sizeof(int));
    printf("随机生成的磁块序列为：");
    for (int i = 0; i < disk_num; i++) {
        disk_list[i] = rand() % disk_range;
        printf("%d ", disk_list[i]);
    }
    printf("\n");

    // 计算磁盘调度顺序
    int val = 0;
    bool* visited = (bool*)malloc(disk_num * sizeof(bool));
    for (int i = 0; i < disk_num; i++) {
        visited[i] = false;
    }

    printf("磁盘调度顺序为：");
    for (int i = 0; i < disk_num; i++) {
        int nearest = Nearest(disk_list, disk_num, val, visited);
        visited[nearest] = true;

        printf("%d ", disk_list[nearest]);

        val = disk_list[nearest];
    }
    printf("\n");

    free(disk_list);
    free(visited);
    return 0;
}