//插入排序法

#include<iostream>
using namespace std;

int main()
{
    int n, a[1000];
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    //插入排序实现
    for(int i = 1; i < n; i++)
    {
        int t = a[i];
        int j = i - 1;
        while(t < a[j] && j >= 0)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = t;

        for(int k = 0; k < n; k++)
        {
            cout << a[k] << " ";
        }
        cout << endl;
    }

    system("pause");
    return 0;
}