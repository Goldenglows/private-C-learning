#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <limits.h>

// 计算两个磁块之间的距离
int Distance(int block1, int block2){
    return abs(block2 - block1);
}

// 找到下一个要访问的磁块位置
int Find_next(int* block_list, int disk_num, int current_block, bool* visited, bool scan){
    int next_block = -1;
    int min_distance = INT_MAX;

    for (int i = 0; i < disk_num; i++){
        if (!visited[i]) {
            int distance = Distance(current_block, block_list[i]);

            // 根据扫描方向选择距离最小或最大的磁块
            if ((scan && block_list[i] >= current_block && distance < min_distance) ||
                (!scan && block_list[i] <= current_block && distance < min_distance)) {
                min_distance = distance;
                next_block = i;
            }
        }
    }

    return next_block;
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
    int* disk_lisk = (int*)malloc(disk_num * sizeof(int));
    printf("随机生成的磁块序列为：");
    for (int i = 0; i < disk_num; i++) {
        disk_lisk[i] = rand() % disk_range;
        printf("%d ", disk_lisk[i]);
    }
    printf("\n");

    // 计算磁盘调度顺序
    int current_block = 0;
    bool scan = true;  // 扫描方向，true表示向外扫描，false表示向内扫描
    bool* visited = (bool*)malloc(disk_num * sizeof(bool));
    for (int i = 0; i < disk_num; i++) {
        visited[i] = false;
    }

    printf("磁盘调度顺序为：");
    while (true) {
        int next = Find_next(disk_lisk, disk_num, current_block, visited, scan);
        if (next == -1) {
            // 如果没有找到下一个磁块，则改变扫描方向并继续寻找
            scan = !scan;
            continue;
        }

        visited[next] = true;

        printf("%d ", disk_lisk[next]);

        current_block = disk_lisk[next];
    }
    printf("\n");

    free(disk_lisk);
    free(visited);
    return 0;
}