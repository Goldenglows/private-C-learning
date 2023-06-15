#include <stdio.h>

#define maxnum 46 

int main()
{
    int n;
    scanf("%d", &n);

    // 初始化状态数组
    int dp[maxnum+1]; 
    dp[1] = 1;
    dp[2] = 2;

    int i;

    // 递推计算状态数组
    for (i = 3; i <= n; i++) {

        dp[i] = dp[i-1] + dp[i-2];

    }

    // 输出结果
    printf("%d格子\n", dp[n]);

    return 0;
}