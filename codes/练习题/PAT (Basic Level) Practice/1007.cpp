#include <iostream>
using namespace std;

int main()
{
    int pri[10000];
    pri[0] = 2;
    int n = 1,N = 0;
    cin >> N;

    //记录N以内素数
    for(int i = 2; i < N; i++)
    {
        int tem = i;
        int jud = 0;
        if(i > 2)
        {
        for(int j = 2; j < i; j++)
        {
            if(i % j != 0)
            jud++;
        }
        if(jud == i - 2)
        pri[n++] = tem;
        }
    }

    //计算素数对个数
    int count = 0;
    for(int i = 0; i < n; i++)
    {
        if(pri[i + 1] - pri[i] == 2)
        count++;
    }

    //输出素数对个数
    cout << count;
    
    system("pause");
    return 0;

}

