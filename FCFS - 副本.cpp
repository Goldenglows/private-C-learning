#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int disk_num, disk_range;

    printf("请输入磁盘总数：");
    scanf("%d", &disk_num);

    printf("请输入磁块范围：");
    scanf("%d", &disk_range);

    if (disk_num <= 0 || disk_range <= 0) {
        printf("输入无效！磁盘总数和磁块范围必须大于零。\n");
        return 1;
    }

    // 初始化随机数种子
    srand((unsigned int)time(NULL));

    // 生成随机磁块序列
    int* disk_list = (int*)malloc(disk_num * sizeof(int));
    if (disk_list == NULL) {
        printf("内存分配失败！\n");
        return 1;
    }

    printf("随机生成的磁块序列为：");
    for (int i = 0; i < disk_num; i++) {
        disk_list[i] = rand() % disk_range;
        printf("%d ", disk_list[i]);
    }
    printf("\n");

    // 计算磁盘调度顺序
    printf("磁盘调度顺序为：");
    for (int i = 0; i < disk_num; i++) {
        printf("%d ", disk_list[i]);
    }
    printf("\n");

    free(disk_list);
    return 0;
}