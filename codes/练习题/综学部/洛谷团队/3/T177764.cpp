//https://www.luogu.com.cn/problem/T177764

#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    int m = 1;
    cin >> n;
    while (n--)
        m *= 2;
    cout << m;
    return 0;
}