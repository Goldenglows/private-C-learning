// 某社团为庆祝获奖去餐厅聚餐，聚餐可用的最大金额为C元，
// 餐厅有N种菜可以点，每种菜品的价格为Pi，同时，
// 每种菜品对应一个量化的评价分数Vi（表示这个菜可口程度)。
// 问如何选择菜品，使得在可用金额C的范围内能使点到的菜品的总评价分数最大。
// 注意：每种菜最多点一份。

#include <stdio.h>
#include <string.h>
#define maxn 105
#define maxc 1005

int dp[maxn][maxc];

int main() {
    int C, N;
    scanf("%d%d", &C, &N);
    memset(dp, 0, sizeof(dp));
    int i, j;
    for (i = 1; i <= N; i++) {
        int p, v;
        scanf("%d%d", &p, &v);
        for (j = 1; j <= C; j++) {
            if (j >= p) {
                dp[i][j] = dp[i-1][j];
                if (dp[i-1][j-p] + v > dp[i][j]) dp[i][j] = dp[i-1][j-p] + v;
                else dp[i][j] = dp[i-1][j];
        }
    }
    printf("%d\n", dp[N][C]);
    return 0;
}