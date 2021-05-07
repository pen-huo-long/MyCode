#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    int group[52];
    //赋值
    //cin >> n >> m;
    n = 5, m = 3;
    for(int i = 1; i <= n; ++i) {
        group[i] = i;
    }

    //
    int times = 1, p = 1, k = 0;
    while(times < n) {
        for(int j = 1; j <= n; ++j) {
            if(group[j]) k++;
            if(k == m) {
                cout << "No" << p++ << ":" << j << endl;
                group[j] = 0;
                k = 0;
                ++times;
            }
        }
    }
    //找到最后一个不为0的数
    for(int i = 1; i <= n; i++) {
        if(group[i])
            cout << "Last No is:" << i << endl;
    }

    return 0;
}