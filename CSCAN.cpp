#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 计算两个磁块之间的距离
int calculateDistance(int currentPos, int targetPos, int diskRange) {
    return abs(targetPos - currentPos);
}

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
        requestQueue[i] = rand() % (diskRange + 1);
        printf("%d ", requestQueue[i]);
    }
    printf("\n");

    // 排序磁块序列
    for (int i = 0; i < diskTotal-1; i++) {
        for (int j = 0; j < diskTotal-i-1; j++) {
            if (requestQueue[j] > requestQueue[j+1]) {
                int temp = requestQueue[j];
                requestQueue[j] = requestQueue[j+1];
                requestQueue[j+1] = temp;
            }
        }
    }

    // 计算磁盘调度顺序
    int currentPos = 0;
    printf("磁盘调度顺序为：");

    // 扫描方向向前
    for (int i = currentPos; i <= diskRange; i++) {
        for (int j = 0; j < diskTotal; j++) {
            if (requestQueue[j] >= currentPos) {
                printf("%d ", requestQueue[j]);
                currentPos = requestQueue[j];
            }
        }
    }

    // 从0开始扫描到当前位置的最大值
    for (int i = 0; i <= currentPos; i++) {
        for (int j = 0; j < diskTotal; j++) {
            if (requestQueue[j] <= currentPos) {
                printf("%d ", requestQueue[j]);
                currentPos = requestQueue[j];
            }
        }
    }

    printf("\n");

    free(requestQueue);
    return 0;
}