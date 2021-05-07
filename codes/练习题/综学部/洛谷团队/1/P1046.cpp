#include<bits/stdc++.h>
using namespace std;

int main() {
    int a[10];
    int b, ans = 0;
    for(int i = 0; i < 10; ++i) {
        cin >> a[i];
    }
    cin >> b;
    for(auto x: a) {
        if(x <= b + 30) ans++;
    }
    cout << ans;
    return 0;
}