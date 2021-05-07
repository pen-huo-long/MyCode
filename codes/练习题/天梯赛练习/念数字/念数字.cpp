#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("in.txt", "r", stdin);

    map<char, string>mp;

    //录入数据
    mp['-'] = "fu", mp['0'] = "ling", mp['1'] = "yi", mp['2'] = "er";
    mp['3'] = "san", mp['4'] = "si", mp['5'] = "wu", mp['6'] = "liu";
    mp['7'] = "qi", mp['8'] = "ba", mp['9'] = "jiu";

    string num;
    cin >> num;

    for(int i = 0; i < num.length(); i++){
        if(i)
            cout << " ";
        cout << mp[num[i]];
    }
    return 0;
}