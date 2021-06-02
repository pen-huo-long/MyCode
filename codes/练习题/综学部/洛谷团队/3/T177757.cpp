//https://www.luogu.com.cn/problem/T177757

#include<bits/stdc++.h>
using namespace std;

int fibo(int n) {
    if (n == 0) return 1;
    if (n <= 2)
        return n;
    return fibo(n - 1) + fibo(n - 2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    cout << fibo(15 - n);
    return 0;
}