//https://www.luogu.com.cn/problem/T177766

#include<bits/stdc++.h>
using namespace std;

int solve(int n) {
    if (n <= 2)
        return n;
    if (n == 3)
        return 4;
    return solve(n - 1) + solve(n - 2) + solve(n - 3);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int ff[500];
    ff[1] = 1;
    ff[2] = 2;
    ff[3] = 4;
    int  n;
    cin >> n;
    for (int i = 4; i <= n; ++i) {
        ff[i] = ff[i - 1] + ff[i - 2] + ff[i - 3];
    }
    cout << ff[n];
    return 0;
}