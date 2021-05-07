#include<iostream>
#include<cmath>
using namespace std;

bool JudgePrimeNumber(int num)
{
    for(int i = 2; i <= sqrt(num); i++)
        if(num % i == 0)
            return 0;
    return 1;
}

int main()
{
    //素数数组,上界M,下界N,循环查找用数字n
    int primeNumber[10000], upperBoundM, lowerBoundN, n = 2;

    //输入下上界
    cin >> lowerBoundN >> upperBoundM;

    //查找并储存第1~10000个素数并储存在数组primeNumber中
    for(int i = 0; i < 10000; i++)
    {
        for(;;n++)
        {
            if(JudgePrimeNumber(n))
            {
                primeNumber[i] = n++;
                break;
            }
        }
    }

    //输出范围内素数(每10个数字占一行,中间空格隔开,但末尾无空格)
    int temp = upperBoundM - lowerBoundN, tn = 1;
    for(int i = lowerBoundN; i <= upperBoundM; i++, tn++)
    {
        cout << primeNumber[i - 1];
        if(tn % 10 != 0 && tn <= temp)
            cout << " ";
        else if(tn % 10 == 0)
            cout << "\n";
    }

    system("pause");
    return 0;
}