#include<bits/stdc++.h>
using namespace std;

int a[1000001], b[100001], re, m, n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> m >> n;
    for (int i = 0;i < m;++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    for (int i = 0; i < n; ++i) {
        re = lower_bound(a, a + m, b[i]) - a;
        if (a[re] == b[i]) cout << re + 1 << " ";
        else cout << "-1 ";
    }
    return 0;
}