#include <stdio.h>

// nums是已经排序好的数组
// target是目标数字
// 寻找数组中目标数字第一次出现的位置，没有则返回-1
int findFirstPosition(int nums[], int target) {
        int left = 0;
        int right = nums.length - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                // ① 不可以直接返回，应该继续向左边找，即 [left..mid - 1] 区间里找
                right = mid - 1;
            } else if (nums[mid] < target) {
                // 应该继续向右边找，即 [mid + 1, right] 区间里找
                left = mid + 1;
            } else {
                // 此时 nums[mid] > target，应该继续向左边找，即 [left..mid - 1] 区间里找
                right = mid - 1;
            }
        }
        // 此时 left 和 right 的位置关系是 [right, left]，注意上面的 ①，此时 left 才是第 1 次元素出现的位置
        // 因此还需要特别做一次判断
        if (left != nums.length && nums[left] == target) {
            return left;
        }
        
        return -1;
    }




// nums是已经排序好的数组
// target是目标数字
// 寻找数组中目标数字最后一次次出现的位置，没有则返回-1
 int findLastPosition(int nums[],int target) {
    int left = 0;
    int right = nums.length - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            // 只有这里不一样：不可以直接返回，应该继续向右边找，即 [mid + 1, right] 区间里找
            left = mid + 1;
        } else if (nums[mid] < target) {
            // 应该继续向右边找，即 [mid + 1, right] 区间里找
            left = mid + 1;
        } else {
            // 此时 nums[mid] > target，应该继续向左边找，即 [left, mid - 1] 区间里找
            right = mid - 1;
        }
    }
    // 此时 left 和 right 的位置关系是 [right, left]，此时 right 才是最后一次元素出现的位置
    // 因此还需要特别做一次判断
    if (right >= 0 && nums[right] == target) {
            return right;
    }
    return -1;
}

int main()
{
    //定义变量
    int target,n;
    int arr[200];

    //接收输入的变量
    scanf("%d %d",&target,&n);
    int i;
    for(i=0 ; i<n ; i++ )
    {
        scanf("%d",&arr[i]);
    }



}