#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a[10], res = 0;
    for(int i=0; i<10; ++i) a[i] = 2021;
    while (true) {
        int temp = ++res;
        while (temp) {
            if (a[temp % 10] > 0) {
                a[temp % 10]--;
                temp /= 10;
            }
            else {
                cout <<  --res;
                return 0;
            }
        }
    }
    return 0;
}
//3181