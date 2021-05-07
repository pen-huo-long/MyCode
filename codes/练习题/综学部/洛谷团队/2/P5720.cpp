#include<bits/stdc++.h>
using namespace std;

int main() {
    int a, t = 1;
    cin >> a;
    while(a != 1) {
        a /= 2;
        t++;
    }
    cout << t;
    return 0;
}