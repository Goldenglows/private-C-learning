#include <stdio.h>
#include <string.h>

void horspool(char* text, char* pattern) {
    int n = strlen(text);
    int m = strlen(pattern);

    int i;
    // 预处理 Bad Character 规则
    int T[128]; // ASCII 码共有 128 个字符
    for (i = 0; i < 128; i++) {
        T[i] = m; // 初始化为模式串长度
    }
    for (i = 0; i < m - 1; i++) {
        T[(int)pattern[i]] = m - 1 - i; // 计算需要右移的距离
    }

    // 在文本中搜索模式串
    int positions[n]; // 记录匹配位置
    int count = 0; // 匹配次数
    i = m - 1; // 从文本中最后一个可能匹配的位置开始
    while (i < n) {
        int k = 0;
        while (k < m && text[i - k] == pattern[m - 1 - k]) {
            k++;
        }
        if (k == m) {
            positions[count++] = i - m + 1;
        }
        i += T[(int)text[i]]; // 根据 Bad Character 规则移动位置
    }

    // 输出 Bad Character 规则
    for (i = 0; i < m - 1; i++) {
        printf("%c:%d\n", pattern[i], T[(int)pattern[i]]);
    }

    // 计算其他字符的移动距离
    int other = 0; // 记录为模式串中没有出现的字符的移动距离之和
    for (i = 0; i < 128; i++) {
        if (T[i] == m) {
            other += 1;
        }
    }
    printf("else:%d\n", other);

    if (count == 0) {
        printf("false\n");
        return;
    }

    // 输出模式每次出现的位序
    for (i = 0; i < count; i++) {
        printf("%d ", positions[i]);
    }
    printf("\n");
}

int main() {
    char text[1001];
    char pattern[1001];
    scanf("%s%s", text, pattern);
    horspool(text, pattern);
    return 0;
}