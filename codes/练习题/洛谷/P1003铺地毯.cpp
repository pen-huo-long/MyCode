#include<bits/stdc++.h>
using namespace std;

int n;
int a, b, g, k, x, y;
int num = 1;

class carpet {
public:
    int num;
    carpet(int a, int b, int g, int k, int num): a(a), b(b), g(g), k(k), num(num) {}
    bool isThis(int x, int y) {
        if(x >= a && x <= a + g && y >= b && y <= b + k) {
            return true;
        }
        return false;
    }
private:
    int a;//横坐标
    int b;//纵坐标
    int g;//横长度
    int k;//纵长度
    
};

void solve() {
    stack<carpet> s;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a >> b >> g >> k;
        s.push(carpet(a, b, g, k, num++));
    }
    cin >> x >> y;
    while(!s.empty()) {
        if(s.top().isThis(x, y)) {
            cout << s.top().num;
            return;
        }
        s.pop();
    } 
    cout << "-1";
}

int main() {
    freopen("in.txt", "r", stdin);
    solve();
    return 0;
}