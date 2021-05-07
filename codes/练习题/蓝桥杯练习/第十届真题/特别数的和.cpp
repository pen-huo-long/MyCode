#include<bits/stdc++.h>
using namespace std;

//判断整型n是否含有数字2/0/1/9
bool jud(int n) {
    while(n > 0) {
        if(n % 10 == 2 || n % 10 == 0 || n % 10 == 1 || n % 10 == 9) {
            return true;
        }
        n /= 10;
    }
    return false;
}

int main() {
    freopen("in.txt", "r", stdin);

    int n, sum = 0;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        if(jud(i))
            sum += i;
    }

    cout << sum;
    return 0;
}