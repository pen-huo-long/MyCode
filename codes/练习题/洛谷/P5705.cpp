#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s, s2 = "12345";
    cin >> s;
    s2[0] = s[4];
    s2[1] = '.';
    s2[2] = s[2];
    s2[3] = s[1];
    s2[4] = s[0];
    cout << s2;
    return 0;
}