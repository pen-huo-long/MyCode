#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    map<int, int>mp;
    int i, num = 0;

    for(i = 1; num <= 1000; i++) //创建map_a储存符合沙漏条件的数
    {
        num = 2 * i * i - 1;
        mp[num] = i;
    }

    //输入数据
    int n;
    char x;
    cin >> n >> x;

    int lines = (--mp.upper_bound(n)) -> second;

    string a(2 * lines - 1,x);
    for(int i = 0; i < lines; i++)//输出上三角
    {
        if(i)
            cout << endl;
        cout << a;
        a[i] = ' ';
        a[2 * lines - 2 - i] = ' ';
    }
    a[lines - 1] = x;
    for(int i = lines - 2; i >= 0; i--)
    {
        a[i] = x;
        a[2 * lines - 2 - i] = x;
        cout << endl << a;
    }
    int sub = n - (--mp.upper_bound(n)) -> first;
    cout << endl << sub;
    return 0;
}
