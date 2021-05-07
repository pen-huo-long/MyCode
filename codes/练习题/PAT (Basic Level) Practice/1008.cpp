#include<iostream>
using namespace std;

int main()
{
    int arr[200];
    int n = 0, move = 0;
    cin >> n >> move;
    move %= n;
    int temp = n - 1;
    //赋值
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    //移位
    for(int i = n - 1; i >= 0; i--)
    {
        arr[i + move] = arr[i];
    }
    for(int i = 0; i < move; i++)
    {
        arr[i] = arr[ n + i];
    }

    //打印移位后数组
    for(int i = 0; i < n; i++)
    {

        cout << arr[i];
        if(temp != 0)
        {
        cout << " ";
        temp--;
        }
    }

    system("pause");
    return 0;

}