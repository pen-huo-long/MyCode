#include<bits/stdc++.h>
using namespace std;

int main() {
    string star, group;
    int a = 1, b = 1;
    cin >> star >> group;
    for(int i = 0; i < star.length(); ++i) {
        a *= star[i] - 'A' + 1;
    }
    for(int i = 0; i < group.length(); ++i) {
        b *= group[i] - 'A' + 1;
    }
    if(a % 47 == b % 47)
        cout << "GO";
    else 
        cout<< "STAY";
    return 0;
}