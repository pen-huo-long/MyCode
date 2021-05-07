#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);

    map<int, int>mp;
    string s;
    cin >> s;

    for(int i = 0; i < s.length(); i++) //统计位数
        mp[s[i] - '0']++;

    for(map<int, int>::iterator it = mp.begin(); it != mp.end(); it++)
        cout << it->first << ":" << it->second << endl;
    return 0;
}