#include <iostream>
#include <vector>

using namespace std;

// 定义进程结构体
struct Process {
    int id;
    vector<int> maxNeed;  // 进程最大需求
    vector<int> allocation;  // 进程已分配资源
    vector<int> need;  // 进程还需要的资源
    bool finish;  // 进程是否完成
};

// 定义银行家类
class Banker {
public:
    Banker(vector<int> available, vector<Process> processes) {
        this->available = available;
        this->processes = processes;
        this->finishCount = 0;
    }

    // 执行银行家算法
    bool execute() {
        // 初始化每个进程的还需要资源
        for (int i = 0; i < processes.size(); i++) {
            Process& p = processes[i];
            p.need.resize(p.maxNeed.size());
            for (int j = 0; j < p.maxNeed.size(); j++) {
                p.need[j] = p.maxNeed[j] - p.allocation[j];
            }
        }

        // 找到一个能够满足需求的进程
        while (finishCount < processes.size()) {
            bool found = false;

            for (int i = 0; i < processes.size(); i++) {
                Process& p = processes[i];

                if (!p.finish && canSatisfy(p)) {
                    found = true;
                    p.finish = true;
                    finishCount++;

                    // 释放该进程占用的资源
                    for (int j = 0; j < available.size(); j++) {
                        available[j] += p.allocation[j];
                    }

                    break;
                }
            }

            if (!found) {
                return false;  // 所有进程都无法满足需求，发生死锁
            }
        }

        return true;
    }

private:
    vector<int> available;  // 可用资源
    vector<Process> processes;  // 所有进程
    int finishCount;  // 已完成的进程数量

    // 判断是否能够满足进程的需求
    bool canSatisfy(Process& p) {
        for (int i = 0; i < available.size(); i++) {
            if (available[i] < p.need[i]) {
                printf("%d ", i);
                return false;
               
            }
          
        }
        return true;
    }
};

int main() {
    vector<int> available = { 3, 3, 2 };  // 可用资源
    vector<Process> processes = {
        {0, {7, 5, 3}, {0, 1, 0}, {}, false},
        {1, {3, 2, 2}, {2, 0, 0}, {}, false},
        {2, {9, 0, 2}, {3, 0, 2}, {}, false},
        {3, {2, 2, 2}, {2, 1, 1}, {}, false},
        {4, {4, 3, 3}, {0, 0, 2}, {}, false}
    };  // 所有进程

    Banker banker(available, processes);
    bool safe = banker.execute();

    if (safe) {
        cout << "安全" << endl;
    }
    else {
        cout << "不安全" << endl;
    }

    return 0;
}