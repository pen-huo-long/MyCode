#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("in.txt", " r", stdin);

    map<int, string>mp;
    string s1, s2, infor;
    int key, n1, n2, rec;

    //输入数据
    cin >> n1;
    for(int i = 0; i < n1; i++)
    {
        cin >> s1 >> key >> s2;
        infor = s1 + " " + s2;
        mp[key] = infor;
    }

    cin >> n2;
    for(int i = 0; i < n2; i++)
    {
        cin >> rec;
        cout << mp[rec];
    }
    return 0;
}