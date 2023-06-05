#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    // 使用一个优先队列来存储胡萝卜堆中的数量
    priority_queue<int> p;  
    `
    int i;
    // 将每一堆的胡萝卜数量插入到优先队列中
    for (i = 0; i < n; i++) {
        int x;
        cin >> x;
        p.push(x);
    }


    // 执行 k 次运输操作
    for (i = 0; i < k; i++) {
        //取出最多剩余数量的胡萝卜
        int maxnum = p.top();  
        p.pop();
        //运输一半的数量
        int half = maxnum / 2; 
        //更新胡萝卜的数量
        p.push(half); 
    }

    int total = 0;
    //计算剩余胡萝卜数量的总和
    while (!p.empty()) {  
        total += p.top();
        p.pop();
    }
    cout << total << endl; 
    return 0;
} 