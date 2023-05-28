#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cout << "请输入资源种类数和进程数：";
    cin >> n >> m;

    // 输入资源总数
    vector<int> available(n, 0);
    cout << "请输入每种资源的总数：";
    for(int i = 0; i < n; i++) {
        cin >> available[i];
    }

    // 输入分配矩阵
    vector<vector<int>> allocation(m, vector<int>(n, 0));
    cout << "请输入分配矩阵：\n";
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> allocation[i][j];
        }
    }

    // 输入需求矩阵
    vector<vector<int>> need(m, vector<int>(n, 0));
    cout << "请输入需求矩阵：\n";
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> need[i][j];
        }
    }

    // 检查每个进程是否可以执行
    vector<bool> finish(m, false);
    vector<int> work(available);
    int count = 0;
    while(count < m) {
        bool found = false;
        for(int i = 0; i < m; i++) {
            if(!finish[i]) {
                bool enough = true;
                for(int j = 0; j < n; j++) {
                    if(need[i][j] > work[j]) {
                        enough = false;
                        break;
                    }
                }
                if(enough) {
                    finish[i] = true;
                    found = true;
                    count++;
                    for(int j = 0; j < n; j++) {
                        work[j] += allocation[i][j];
                    }
                }
            }
        }
        if(!found) {
            cout << "不能执行\n";
            return 0;
        }
    }
    cout << "可以执行\n";
    return 0;
}