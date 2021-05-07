#include<iostream>
using namespace std;

// class Decode
// {
// public:
//     string GetDay(string & fs,string & ss);//获取周几
//     int GetHour(string & fs,string & ss);//获取小时
//     int GetMinute(string & ts,string & fs);//获取分钟
// public:
//     string day;
//     int minute,hour;
// };

string GetDay(string & fs,string & ss,int & i)
{
    string day[7] = {"MON","TUE","WEN","THU","FRI","SAT","SUN"};
    for(i = 0; ; i++)
    {
        if(fs[i] >= 65 && fs[i] <= 71 && fs[i] == ss[i])
        {
            return day[int(fs[i] - 65)];
        }
    }
}

int GetHour(string & fs,string & ss,int & i)
{
    i++;
    while(1)
    {
        if((fs[i] >= 48 && fs[i] <=57 || fs[i] >= 65 && fs[i] <= 90) && fs[i] == ss[i])
        {
            return (fs[i] >= 48 && fs[i] <= 57) ? (fs[i] - 48) : (fs[i] - 55);
        }
        i++;
    }
}

int GetMinute(string & ts,string & fs)
{
    for(int j = 0;;j++)
    {
        if((ts[j] >= 65 && ts[j] <= 90 || ts[j] >= 97 && ts[j] <= 122) && ts[j] == fs[j])
        {
            return j;
        }
    }
}

int main()
{
    //第1234个字符串
    string firstStr,secondStr,thirdStr,forthStr;
    int i;
    //输入字符串
    cin >> firstStr >> secondStr >> thirdStr >> forthStr;
    //输出解密后结果
    cout << GetDay(firstStr,secondStr,i) << " "; 
    int hour = GetHour(firstStr,secondStr,i);
    if(hour < 10)
        cout << "0";
    cout << hour << ":";
    if(GetMinute(thirdStr,forthStr) < 10)
        cout << "0";
    cout << GetMinute(thirdStr,forthStr);
    system("pause");
    return 0;
}