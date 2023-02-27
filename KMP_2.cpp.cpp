#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

void kmp_next(int *next, int n, const char *p) {
	int j = 0, k = -1;
	next[0] = -1;
	while (j < n) {
		if (k == -1 || p[j] == p[k]) {
			next[j + 1] = k + 1;
			j++;
			k++;
		} else {
			k = next[k];
		}
	}
}

int kmp(const char *str1, const char *str2) {
	int i = 0, j = 0;
	int len = (int)strlen(str2);
	//next����
	int *next = (int *)malloc(len * sizeof(int));
	assert(next);
	kmp_next(next, len - 1, str2);
	while (str2[j]) {
		if (j == -1 || str1[i] == str2[j]) { //jΪ-1ʱ��λ���µ�i����ƥ��ɹ���������һ��ƥ��
			i++;
			j++;
		} else {
			j = next[j];
		}
		if (str1[i] == '\0') {
			free(next);
			next = NULL;
			return -1;
		}
	}
	free(next);
	next = NULL;
	return i;
}

int main() {
	char arr[] = "abaabcdabcab";
	char arr2[] = "abc";
	printf("%d\n", kmp(arr, brr));
	return 0;
}
