#include<bits/stdc++.h>
using namespace std;


int main() {
    int a = 1, b = 1, c = 1, d;
    
    for(int i = 4; i <= 20190324; i++) {
        d = (a + b + c) % 10000;
        a = b, b = c, c = d;
    }
    cout << c;
    return 0;
}



//20190324