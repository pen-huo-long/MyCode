#include<bits/stdc++.h>
using namespace std;

int main() {
    char c;
    int a = 0;
    while((c = cin.get()) != '@') {
        if(c == ')') 
            a--;
        else if(c == '(')
            a++;
        if(a < 0) {
            cout << "NO";
            return 0;
        }
    }
    if(a == 0) 
        cout << "YES";
    else
    {
        cout << "NO";
    }
    
    return 0;
}