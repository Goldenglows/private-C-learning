#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 计算两个磁块之间的距离
int calculateDistance(int currentPos, int targetPos, int diskRange) {
    return (targetPos - currentPos + diskRange) % diskRange;
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

    int currentPos = 0;

    // 排序磁块序列
    for (int i = 0; i < diskTotal - 1; i++) {
        for (int j = 0; j < diskTotal - i - 1; j++) {
            if (requestQueue[j] > requestQueue[j+1]) {
                int temp = requestQueue[j];
                requestQueue[j] = requestQueue[j+1];
                requestQueue[j+1] = temp;
            }
        }
    }

    printf("磁盘调度顺序为：");

    // 使用CLOOK算法输出磁块序列
    int startPos = currentPos;
    while (1) {
        int targetPos = -1;
        int minDistance = diskRange;

        // 在当前位置往外扫描，找到下一个距离最小的磁块
        for (int i = 0; i < diskTotal; i++) {
            if (requestQueue[i] >= currentPos && calculateDistance(currentPos, requestQueue[i], diskRange) < minDistance) {
                targetPos = i;
                minDistance = calculateDistance(currentPos, requestQueue[i], diskRange);
            }
        }

        // 如果当前位置找不到更小的磁块，则将磁头移动到最边界并重新扫描
        if (targetPos == -1) {
            currentPos = startPos;
            continue;
        }

        printf("%d ", requestQueue[targetPos]);
        currentPos = requestQueue[targetPos];

        // 移除已经访问过的磁块
        for (int i = targetPos; i < diskTotal - 1; i++) {
            requestQueue[i] = requestQueue[i+1];
        }
        diskTotal--;
    }

    printf("\n");

    free(requestQueue);
    return 0;
}