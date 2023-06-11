#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 1000

void horspool(char text[], char pattern[]) {
    int n = strlen(text), m = strlen(pattern); // 获取文本串和模式串的长度
    int T[256]; // 坏字符表，用于记录每个字符在模式串中出现的最右位置
    int ans[maxnum], cnt = 0; // ans用于记录模式串在文本串中的位置，cnt为计数器

    int i;
    // 初始化坏字符表
    for (i = 0; i < 256; i++) {
        T[i] = m;
    }
    for (i = 0; i < m - 1; i++) {
        T[pattern[i]] = m - 1 - i;
    }

    // 打印T表
    for (i = 0; i < m - 1; i++) {
        printf("%c:%d\n", pattern[i], T[pattern[i]]);
    }
    printf("else:%d\n", m);

    // 在文本串中查找模式串
    i = m - 1;
    int j;
    while (i < n) {
        for (j = 0; j < m; j++) {
            if (text[i - j] != pattern[m - 1 - j]) { // 如果出现不匹配，则将模式串向右移动T['不匹配字符']位
                i += T[text[i - j]];
                break;
            }
        }
        if (j == m) { // 如果模式串匹配成功
            ans[cnt++] = i - m + 1; // 记录匹配的位置
            i++; // 向右移动一个字符，继续查找下一个匹配位置
        }
    }

    if (cnt == 0) { // 如果模式串未出现在文本串中
        printf("false\n");
    } else {
        for (i = 0; i < cnt; i++) { // 输出所有匹配位置
            ans[i]+=1;
            printf("%d", ans[i]);
            if (i != cnt - 1) {
                printf(" "); // 最后一个位置后面不需要添加空格
            }
        }
        printf("\n");
    }
}

int main() {
    char text[maxnum + 5], pattern[maxnum + 5];
    fgets(text, maxnum + 5, stdin); // 读取文本串
    fgets(pattern, maxnum + 5, stdin); // 读取模式串
    text[strcspn(text, "\r\n")] = '\0'; // 将读取到的字符串结尾的换行符替换为'\0'
    pattern[strcspn(pattern, "\r\n")] = '\0';

    horspool(text, pattern);

    return 0;
}