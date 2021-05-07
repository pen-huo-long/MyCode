#include<bits/stdc++.h>
using namespace std;

int main() {
    stack<int> s;
    int t;
    while(cin >> t && t != 0)
        s.push(t);
    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}