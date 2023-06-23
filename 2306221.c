#include <stdio.h>
#define maxsize 5  // 寄存器的容量

// LRU页面置换算法
void LRU(int pages[], int n) {
    int registers[maxsize] = {0};  // 寄存器数组，初始值为0
    int i, j, index;
    int pages = 0;

    // 遍历页面请求
    for (i = 0; i < n; i++) {
        index = pages[i];

        // 检查页面是否已在寄存器中
        int found = 0;
        
        for (j = 0; j < maxsize; j++) {
            if (registers[j] == index) {
                found = 1;
                break;
            }
        }

        // 页面不在寄存器中，发生缺页中断，进行页面置换
        if (!found) {
            pages++;

            // 寄存器已满，移除最久未使用的页面
            if (i >= maxsize) {
                for (j = 0; j < maxsize - 1; j++) {
                    registers[j] = registers[j+1];
                }
            }

            // 将新页面加入寄存器末尾
            registers[maxsize - 1] = index;
        }

        // 输出当前寄存器状态
        printf("当前寄存器状态：");
        for (j = 0; j < maxsize; j++) {
            printf("%d ", registers[j]);
        }
        printf("\n");
    }

    printf("总缺页次数：%d\n", pages);
}

int main() {
    int n;
    printf("请输入页面请求序列长度：");
    scanf("%d", &n);

    int pages[n];
    printf("请输入页面请求序列：");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    LRU(pages, n);

    return 0;
}