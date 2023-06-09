#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM 100000
#define MAX_RANGE 200000

void CountSort(int nums[], int n)
{
    int i, j, count[MAX_RANGE] = {0}, sorted_nums[20000];

    for (i = 0; i < n; i++) {
        count[nums[i]+MAX_NUM]++;
    }

    for (i = 1; i < MAX_RANGE; i++) {
        count[i] += count[i-1];
    }

    for (j = n-1; j >= 0; j--) {
        sorted_nums[count[nums[j]+MAX_NUM]-1] = nums[j];
        count[nums[j]+MAX_NUM]--;
    }

    for (i = 0; i < n; i++) {
        nums[i] = sorted_nums[i];
    }
}

int main()
{
    int n, nums[MAX_RANGE] = {0};
    scanf("%d", &n);

    int i;
    for (i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    CountSort(nums, n);

    int j, k = 1, count = 1;
    printf("1 ");
    for (j = 1; j < n; j++) {
        if (nums[j] == nums[j-1]) {
            count++;
        } else {
            printf("%d ", count);
            k++;
            count = 1;
        }
    }
    printf("%d\n", count);

    for (i = 0; i < n; i++) {
        printf("%d ", nums[i]);
    }

    return 0;
}