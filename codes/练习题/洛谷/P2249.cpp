#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    map<int, int> map;
    int m, n, a, b;
    cin >> m >> n;
    for (int i = 1; i <= m; ++i) {
        cin >> a;
        if (b != a) {
            map[a] = i;
            b = a;
        }
    }
    for (int i = 0; i < n; ++i) {
        cin >> a;
        auto it = map.find(a);
        if (it != map.end()) {
            cout << it->second << " ";
        }
        else cout << "-1 ";
    }
    return 0;
}