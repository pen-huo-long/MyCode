#include<iostream>
using namespace std;

int main()
{
    int arr[1000];
    int a = 0, b = 100,i;

    for(i = 0;; i += 2)
    {

        //输入一个多项式
        cin >> a >> b;

        //求导
        if(b == 0)
            break;
        else
            arr[i] = a * b, arr[i + 1] = b - 1;//储存结果
    }

    //输出结果
    int k = i-1;
    for(int j = 0; j < i; j++)
    {
        cout << arr[j];
        if(k--)
        cout << " ";
    }

    system("pause");
    return 0;
}