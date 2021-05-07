#include<bits/stdc++.h>
using namespace std;

bool jud(int n) {
    while(n != 0) {
        if(n % 10 == 2 || n % 10 == 4)
            return false;
        n /= 10;
    }
    return true;
}

int main() {
    int t = 0;

    for(int i = 1; i < 2019; i++) {
        for(int j = i + 1; j < 2019; j++) {
            for(int k = j + 1; k < 2019; k++) {
                if(jud(i) && jud(j) && jud(k) && i + j + k == 2019)
                    t++;
            }
        }
    }
    cout << t;
    system("pause");
    return 0;
}