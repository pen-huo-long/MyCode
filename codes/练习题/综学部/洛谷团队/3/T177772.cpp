//https://www.luogu.com.cn/problem/T177772

#include<bits/stdc++.h>
using namespace std;

int solve(int num) {
    int sum = 1;
    if (num <= 1)
        return num;
    for (int i = 2; i <= num; ++i)
        sum *= i;
    return sum + solve(--num);
}

int main() {
    int n;
    cin >> n;
    cout << solve(n);
    return 0;
}