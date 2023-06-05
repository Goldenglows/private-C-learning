#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
using namespace std;

const int maxn = 100000;
const int range = 200001;

void CountSort(vector<int>& nums) {
    int n = nums.size();
    vector<int> count(range, 0), sornum(n);

    for (int i = 0; i < n; i++) {
        count[nums[i] + maxn]++;
    }

    for (int i = 1; i < range; i++) {
        count[i] += count[i - 1];
    }

    for (int j = n - 1; j >= 0; j--) {
        sornum[count[nums[j] + maxn] - 1] = nums[j];
        count[nums[j] + maxn]--;
    }

    nums = sornum;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    CountSort(nums);

    vector<int> count(range, 0);
    for (int i = 0; i < n; i++) {
        count[nums[i] + maxn]++;
    }
    cout << count[0];
    for (int i = 1; i < range; i++) {
        if (count[i] == 0) {
            continue;
        }
        cout << " " << count[i];
    }
    cout << endl;

    for (int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}