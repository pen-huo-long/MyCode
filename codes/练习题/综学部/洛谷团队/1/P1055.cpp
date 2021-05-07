#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int j = 1, sum = 0;
    for(int i = 0; i < 11; ++i) {
        if(i != 1 && i != 5) {
            sum += (s[i] - '0') * j++;
        }
    }
    sum %= 11;
    if(sum == s[12] - '0' || sum == 10 && s[12] == 'X')
        cout << "Right";
    else {
        sum == 10 ? s[12] = 'X' : s[12] = sum + '0';
        cout << s;
    }
    return 0;
}