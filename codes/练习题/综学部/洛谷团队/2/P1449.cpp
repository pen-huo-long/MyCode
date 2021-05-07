#include<bits/stdc++.h>
using namespace std;

int main() {
    stack<int> s;
    char c;
    int temp = 0;
    while((c = getchar()) != '@') {
        int a, b;
        if(c >='0' && c <= '9') {
            temp = temp * 10 + c - '0';
        }
        else if(c == '.') {
            s.push(temp);
            temp = 0;
        }
        else {
            b = s.top();
            s.pop();
            a = s.top();
            s.pop();
            if (c == '+') s.push(a + b);
            else if (c == '-') s.push(a - b);
            else if (c == '*') s.push(a * b);
            else if (c == '/') s.push(a / b);
        }
    }
    cout << s.top();
    return 0;
}