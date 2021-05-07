#include<iostream>
using namespace std;

//结构体包括两个加数和一个比较数
struct Sum
{
    long n1,n2,comp;
};

int main()
{
    Sum a[10];
    
    //输入和组个数
    int n;
    cin >> n;
    
    //输入每个元素
    for(int i = 0; i < n; i++)
    {
        cin >> a[i].n1 >> a[i].n2 >> a[i].comp;
    }

    //作比较
    for(int i = 0; i < n; i++)
    {
        if(a[i].n1 + a[i].n2 > a[i].comp)
        {
            cout << "Case #" << i + 1 << ": true\n";
        }
        else
        {
            cout << "Case #" << i + 1 << ": false\n";
        }
        
    }

    system("pause");
    return 0;
}