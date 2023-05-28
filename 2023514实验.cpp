#include <iostream>
#include <unordered_map>
using namespace std;

int n, pre[200], in[200];
unordered_map <int, int> fun;


void visit_post(int al, int ar, int bl, int br) 
{
    int root = pre[bl];
    int k = fun[root];

    if (al < k)
    {
        fun(al, k - 1, bl + 1, k - al + bl);
    }
    if (ar > k)
    {
        fun(k + 1, ar, k - al + bl + 1, br);
    }
    cout << root << " ";
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> pre[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> in[i];
        fun[in[i]] = i;
    }

    visit_post(0, n - 1, 0, n - 1);


    return 0;
}

