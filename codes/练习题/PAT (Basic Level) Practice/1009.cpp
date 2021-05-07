#include <iostream>
#include <string>
using namespace std;

int main()
{
    //定义字符串及临时字符串组
    string sen;
    string temp[80];

    //输入句子
    getline(cin, sen);

    //统计单词数及字符数
    int n = 0, t = 1;
    while (sen[n] != '\0')
        n++;
    for (int i = 0; i < n; i++)
    {
        if (sen[i] == ' ')
            t++;
    }

    int te = t - 1;
    //将单词装入临时字符串组
    int tem = 0;
    for (int i = 0; i < t; i++)
    {
        
        for (int j = 0; sen[tem] != ' '&&sen[tem] != '\0'; j++)
        {
            temp[i] += sen[tem];
            tem++;
        }
        tem++;
    }

    //打印变化后字符串
    for (int i = t - 1; i >= 0; i--)
    {
        cout << temp[i];
        if(te--!=0)
        {
            cout <<" ";
        }
    }
    system("pause");
    return 0;
}