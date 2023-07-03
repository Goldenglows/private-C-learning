#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// 计算两个磁块之间的距离
int calculateDistance(int currentPos, int targetPos) {
    return abs(targetPos - currentPos);
}

// 找到下一个要访问的磁块位置
int findNextBlock(int *requestQueue, int diskTotal, int currentPos, bool *visited, bool scanDirection) {
    int nextBlock = -1;
    int minDistance = INT_MAX;

    for (int i = 0; i < diskTotal; i++) {
        if (!visited[i]) {
            int distance = calculateDistance(currentPos, requestQueue[i]);

            // 根据扫描方向选择距离最小或最大的磁块
            if ((scanDirection && requestQueue[i] >= currentPos && distance < minDistance) ||
                (!scanDirection && requestQueue[i] <= currentPos && distance < minDistance)) {
                minDistance = distance;
                nextBlock = i;
            }
        }
    }

    return nextBlock;
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
    bool scanDirection = true;  // 扫描方向，true表示向外扫描，false表示向内扫描
    bool *visited = (bool *)malloc(diskTotal * sizeof(bool));
    for (int i = 0; i < diskTotal; i++) {
        visited[i] = false;
    }

    printf("磁盘调度顺序为：");
    while (true) {
        int nextBlock = findNextBlock(requestQueue, diskTotal, currentPos, visited, scanDirection);
        if (nextBlock == -1) {
            // 如果没有找到下一个磁块，则改变扫描方向并继续寻找
            scanDirection = !scanDirection;
            continue;
        }

        visited[nextBlock] = true;

        printf("%d ", requestQueue[nextBlock]);

        currentPos = requestQueue[nextBlock];
    }
    printf("\n");

    free(requestQueue);
    free(visited);
    return 0;
}