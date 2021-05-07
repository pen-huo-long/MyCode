#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("in.txt", "r", stdin);
    int a[10000], b1[10000], b2[10000], n = 0;
    int len = 1;
    while(cin >> a[++n]);
    n--;
    b1[1] = a[1];
    for(int i = 2; i <= n;i++) {
        if(a[i] <= b1[len]) {
            b1[++len] = a[i];
        }
        else {
            b1[upper_bound(b1 + 1, b1 + 1 + len, a[i], greater<int>()) - b1] = a[i];
        }
    }
    cout << len;
    return 0;
}