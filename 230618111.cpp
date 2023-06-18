#include <iostream>

using namespace std;

// 计算组合数
long long combination(int n, int k) {
    int i;

    if (k > n) return 0;
    long long res = 1;
    for (i = 1; i <= k; i++) {
        res *= n - i + 1;
        res /= i;
    }
    return res;
}

int main() {
    int m, n;
    cin >> m >> n;
    cout << combination(m + n - 2, m - 1) << endl;
    return 0;
}