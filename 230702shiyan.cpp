#include <stdio.h>

bool canGiveChange(int n, int coins[]) {
    // 初始化需要找零的金额
    int change = 0;
    // 初始化5元和10元的数量
    int fiveCount = 0;
    int tenCount = 0;

    int i;

    for (i = 0; i < n; i++) {
        if (coins[i] == 5) {
            // 如果顾客支付5元，则不需要找零，直接增加5元的数量
            fiveCount++;
        } else if (coins[i] == 10) {
            // 如果顾客支付10元，则需要找零5元，减少一个5元的数量，并增加一个10元的数量
            if (fiveCount > 0) {
                fiveCount--;
                tenCount++;
            } else {
                // 没有足够的5元来找零
                return false;
            }
        } else if (coins[i] == 20) {
            // 如果顾客支付20元，则优先尝试找零10元和5元的组合，其次是3个5元
            if (tenCount > 0 && fiveCount > 0) {
                tenCount--;
                fiveCount--;
            } else if (fiveCount >= 3) {
                fiveCount -= 3;
            } else {
                // 没有足够的10元和5元组合或者5元数量不足以找零
                return false;
            }
        }
    }

    // 所有顾客都能正确找零
    return true;
}

int main() {
    int n;
    printf("请输入顾客的数量：");
    scanf("%d", &n);
    
    int coins[n];
    int i;
    printf("请输入每位顾客付的币值：");
    for(i = 0; i < n; i++){
        scanf("%d", &coins[i]);
    }

    bool result = canGiveChange(n, coins);
    if (result) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    return 0;
}