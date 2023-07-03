#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 计算两个磁块之间的距离
int calculateDistance(int currentPos, int targetPos) {
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
    for (int i = 0; i < diskTotal - 1; i++) {
        for (int j = 0; j < diskTotal - i - 1; j++) {
            if (requestQueue[j] > requestQueue[j+1]) {
                int temp = requestQueue[j];
                requestQueue[j] = requestQueue[j+1];
                requestQueue[j+1] = temp;
            }
        }
    }

    int currentPos = 0;
    int direction = 1; // 磁头移动的方向，1表示向外，-1表示向内

    printf("磁盘调度顺序为：");

    // 根据LOOK算法输出磁块序列
    while (1) {
        int targetPos = -1;
        for (int i = 0; i < diskTotal; i++) {
            if ((requestQueue[i] - currentPos) * direction >= 0) {
                targetPos = i;
                break;
            }
        }
        if (targetPos == -1) break;

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