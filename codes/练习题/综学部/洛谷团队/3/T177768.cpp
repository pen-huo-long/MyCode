//https://www.luogu.com.cn/problem/T177768

#include<bits/stdc++.h>
using namespace std;

int x;

void solve2() {
    int a[100][100];
    for (int i = 1; i <= x; ++i)
        a[i][1] = a[1][i] = 1;
    for (int i = 2; i <= x; ++i) {
        for (int j = 2; j <= x; ++j) {
            a[i][j] = a[i][j - 1] + a[i - 1][j];
        }
    }
    cout << a[x][x];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> x;
    solve2();
    return 0;
}