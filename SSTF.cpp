#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// 计算两个磁块之间的距离
int calculateDistance(int currentPos, int targetPos) {
    return abs(targetPos - currentPos);
}

// 找到最接近当前位置的磁块
int findClosestBlock(int *requestQueue, int diskTotal, int currentPos, bool *visited) {
    int closestBlock = -1;
    int minDistance = INT_MAX;

    for (int i = 0; i < diskTotal; i++) {
        if (!visited[i]) {
            int distance = calculateDistance(currentPos, requestQueue[i]);
            if (distance < minDistance) {
                minDistance = distance;
                closestBlock = i;
            }
        }
    }

    return closestBlock;
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
        requestQueue[i] = rand() % diskRange;
        printf("%d ", requestQueue[i]);
    }
    printf("\n");

    // 计算磁盘调度顺序
    int currentPos = 0;
    bool *visited = (bool *)malloc(diskTotal * sizeof(bool));
    for (int i = 0; i < diskTotal; i++) {
        visited[i] = false;
    }

    printf("磁盘调度顺序为：");
    for (int i = 0; i < diskTotal; i++) {
        int closestBlock = findClosestBlock(requestQueue, diskTotal, currentPos, visited);
        visited[closestBlock] = true;

        printf("%d ", requestQueue[closestBlock]);

        currentPos = requestQueue[closestBlock];
    }
    printf("\n");

    free(requestQueue);
    free(visited);
    return 0;
}