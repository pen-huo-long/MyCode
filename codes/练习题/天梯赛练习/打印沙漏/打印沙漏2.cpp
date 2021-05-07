#include<bits/stdc++.h>
using namespace std;

void printRow(int row,int i, char x)//打印一行
{
    for(int j = 0; j < i; j++)
        cout << " ";
    for(int j = 0; j < 2 * row - 2 * i - 1; j++)
        cout << x;
    cout << endl;
}

int main()
{
    freopen("in.txt", "r", stdin);

    int N,row = 0;
    char ch;

    cin >> N >> ch;//输入数据

    //计算行数
    while(2 * row * row - 1<= N) row++;
    row--;

    //输出上三角
    for(int i = 0; i < row; i++)
        printRow(row, i, ch);

    //输出下三角
    for(int i = row - 2; i >= 0; i--)
        printRow(row, i, ch);

    //输出差值
    int sub = N - 2 * row * row + 1;
    row == 0 ? cout << "0" : cout << sub;
    return 0;
}