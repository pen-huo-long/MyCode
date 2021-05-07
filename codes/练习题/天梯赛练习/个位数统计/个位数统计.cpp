#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);

    int num;
    cin >> num;
    map<int, int>mp;

    //对每个数字单独检索
    for(int i = 0; i < 10; i++)
    {
        int temp = num; //临时数据
        int times = 0; //数字出现次数
        while(temp > 0)
        {
            if(temp % 10 == i)
                times++;
            temp /= 10;
        }
        if(times != 0) //出现过的数字及其次数计入map
            mp[i] = times;
    }

    //遍历map输出数据
    for(auto i: mp)
    {
        cout << i.first << ":" << i.second << endl;
    }
    return 0;
}