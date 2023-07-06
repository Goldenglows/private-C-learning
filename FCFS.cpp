#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int diskTotal, diskRange;

    printf("请输入磁盘总数：");
    scanf("%d", &diskTotal);

    printf("请输入磁块范围：");
    scanf("%d", &diskRange);

    // 初始化随机数种子
    srand(time(NULL));

    // 生成随机磁块序列
    int *requestQueue = (int *)malloc(diskTotal * sizeof(int));
    printf("随机生成的磁块序列为：");
    for (int i = 0; i < diskTotal; i++) {
        requestQueue[i] = rand() % diskRange;
        printf("%d ", requestQueue[i]);
    }
    printf("\n");

    // 计算磁盘调度顺序
    printf("磁盘调度顺序为：");
    for (int i = 0; i < diskTotal; i++) {
        printf("%d ", requestQueue[i]);
    }
    printf("\n");

    free(requestQueue);
    return 0;
}