#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("in.txt", "r", stdin);

    char c;
    int n, s[62505] {0};

    //输入数据,用数组s保存胜负情况,其中胜场用1表示,负场用0
    for(n = 0; cin >> c && c != 'E'; n++) {
        if(c == 'W')
            s[n] = 1;
        else if(c == 'L')
            s[n] = 2;
    }

    if(n == 0) {
        cout << "0:0\n\n0:0";
        return 0;
    }

    int w = 0, l = 0; //用wl储存胜负场次

    //11分制下的比分统计
    for(int i = 0; i < n; i++) {
        s[i] == 1 ? w++ : l++; //记录小比分
        //比分大于等于11分且分差在2分及以上
        if(abs(w - l) > 1 && (w >= 11 || l >= 11)) {
            cout << w << ":" << l << endl;
            w =0, l = 0; //重置小比分
        }
        //数据读取结束时一局未结束则输出目前比分
        if(i == n - 1)
            cout << w << ":" << l << endl;
    }

    w = 0, l = 0; //重置比分
    cout << endl; //换行

    //21分制下的比分统计
    for(int i = 0; i < n; i++) {
        s[i] == 1 ? w++ : l++; //记录小比分
        //比分大于等于21分且分差在2分及以上
        if(abs(w - l) > 1 && (w >= 21 || l >= 21)) {
            cout << w << ":" << l << endl;
            w =0, l = 0; //重置小比分
        }
        //数据读取结束时一局未结束则输出目前比分
        if(i == n - 1)
            cout << w << ":" << l << endl;
    }
    return 0;
}