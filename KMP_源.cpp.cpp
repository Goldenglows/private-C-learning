#include <stdio.h>
#include <string.h>

void next(char* arr, int M, int* arrr) {
    int len = 0;
    arrr[0] = 0;
    int i = 1;
    while (i < M) {
        if (arr[i] == arr[len]) {
            len++;
            arrr[i] = len;
            i++;
        }
        else {
            if (len != 0) {
                len = arrr[len - 1];
            }
            else {
                arrr[i] = 0;
                i++;
            }
        }
    }
}

void kmp(char* s1, char* s2) {
    int m = strlen(s1);
    int n = strlen(s2);

    int arr[20];
    next(s1, m, arr);

    int i = 0;
    int j = 0;
    while (i < n) {
        if (s1[j] == s2[i]) {
            i++;
            j++;
        }
        if (j == m) {
            printf("查找成功，位置为%d\n", i - j);
            j = arr[j - 1];
        }
        else if (i < n && s1[j] != s2[i]) {
            if (j != 0) {
                j = arr[j - 1];
            }
            else {
                i++;
            }
        }
    }
}

int main() {
    char s1[] = "googlogooglegoolo";
    char s2[] = "google";
    kmp(s2, s1);
    return 0;
}
