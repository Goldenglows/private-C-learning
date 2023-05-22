#include <stdio.h>
#include <stdlib.h>

//求大根堆
void big_dui(int arr[], int n, int i)
{
    int larger = i;
    int lc = 2 * i + 1;
    int rc = 2 * i + 2;

    // 找出最大的子节点
    if (lc < n && arr[lc] > arr[larger])
        larger = lc;
    if (rc < n && arr[rc] > arr[larger])
        larger = rc;

    // 如果最大子节点不是当前节点，则交换它们并继续堆化
    if (larger != i)
    {
        int temp = arr[i];
        arr[i] = arr[larger];
        arr[larger] = temp;
        big_dui(arr, n, larger);
    }
}

// 堆排序算法
void heap_sort(int arr[], int n)
{
    int i;
    // 构建最大堆
    for (i = n / 2 - 1; i >= 0; i--)
        big_dui(arr, n, i);

    for(i = 0;i<n;i++)
    printf("%d ", arr[i]);

    printf("\n");

    // 依次取出堆顶元素并重构堆
    for ( i = n - 1; i >= 0; i--)
    {
        // 将堆顶元素与最后一个元素交换
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // 重构堆
        big_dui(arr, i, 0);
    }
    //for (i = 0; i < n; i++)
    //    printf("%d ", arr[i]);

    //printf("\n");

}


// 求众数
void find_mode(int arr[], int n)
{  
    int maxnum = 0, count = 0;
    int* flag = (int*)malloc(sizeof(int) * n);
    int i, j;

    printf("\n");

    for (i = 0; i < n; i++)
    {
        count = 0;
        for ( j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
            }
        }
        if (count > maxnum)
        {
            flag[0] = arr[i];
            maxnum = count;
        }
        else if (count == maxnum)
        {
            flag[maxnum] = arr[i];
        }
    }

    if (maxnum == 0)
    {
        for (i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);
        }
    }
    else
    {
        for (i = 0; i <= maxnum; i++)
        {
            if (flag[i] != 0) {
                printf("%d ", flag[i]);
            }
        }
    }


}

int main()
{
    int n;
    int i;

    //输入个数
    scanf("%d", &n);

    int* arr = malloc(sizeof(int) * n);

    //输入数组的元素
    for ( i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    heap_sort(arr, n);

    for ( i = 0; i < n; i++)
        printf("%d ", arr[i]);

    find_mode(arr, n);

    free(arr);
    return 0;
}