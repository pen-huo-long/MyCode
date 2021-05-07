#include<bits/stdc++.h>
using namespace std;

int n, a[100000], k;

bool dfs(int i, int sum) {
    if(i == n) return sum == k;
    if(dfs(i + 1, sum)) return true;
    if(dfs(i + 1, sum + a[i])) return true;
    return false;
}

int main() {
    freopen("in.txt", "r", stdin);

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> k;
    if(dfs(0,0)) cout << "yes" ;
    else cout << "no";
    return 0;
}