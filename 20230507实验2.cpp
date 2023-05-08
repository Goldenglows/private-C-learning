#include <stdio.h>

int lower_bound(int *nums,int numsSize,int target)
{
    int left=0,right=numsSize-1,ans=numsSize;
    while(left<=right)
    {
        int mid = left+(right-left)/2;
        if(nums[mid]>=target)
        {
            right = mid-1;
            ans = mid;
        }
        else 
        {
            left = mid+1;
        }
    }
    return ans;
}

int high_bound(int *nums,int numsSize,int target)
{
    int left=0,right=numsSize-1,ans=numsSize;
    while(left<=right)
    {
        int mid = left+(right-left)/2;
        if(nums[mid]>target)
        {
            right = mid-1;
            ans = mid;
        }
        else 
        {
            left = mid+1;
        }
    }
    return ans;     
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
    
    int ft, ed;
    ft = lower_bound (arr,n,target);
    ed = high_bound (arr,n,target)-1;
    if(ft<n && ed<n)
    printf("%d %d",ft,ed);
    else
    printf("-1 -1");
}