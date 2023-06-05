#include <stdio.h>
#include <string.h>

void horspool(char* text, char* pattern) {
    int n = strlen(text);
    int m = strlen(pattern);

    int i;
    // Ԥ���� Bad Character ����
    int T[128]; // ASCII �빲�� 128 ���ַ�
    for (i = 0; i < 128; i++) {
        T[i] = m; // ��ʼ��Ϊģʽ������
    }
    for (i = 0; i < m - 1; i++) {
        T[(int)pattern[i]] = m - 1 - i; // ������Ҫ���Ƶľ���
    }

    // ���ı�������ģʽ��
    int positions[n]; // ��¼ƥ��λ��
    int count = 0; // ƥ�����
    i = m - 1; // ���ı������һ������ƥ���λ�ÿ�ʼ
    while (i < n) {
        int k = 0;
        while (k < m && text[i - k] == pattern[m - 1 - k]) {
            k++;
        }
        if (k == m) {
            positions[count++] = i - m + 1;
        }
        i += T[(int)text[i]]; // ���� Bad Character �����ƶ�λ��
    }

    // ��� Bad Character ����
    for (i = 0; i < m - 1; i++) {
        printf("%c:%d\n", pattern[i], T[(int)pattern[i]]);
    }

    // ���������ַ����ƶ�����
    int other = 0; // ��¼Ϊģʽ����û�г��ֵ��ַ����ƶ�����֮��
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

    // ���ģʽÿ�γ��ֵ�λ��
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