#include<iostream>
#include<cmath>
using namespace std;

int A1(int a[],int n);
double A2(int a[],int n);
int A3(int a[],int n);
double A4(int a[],int n);
int A5(int a[],int n);

int main()
{
    int n,a[1000];
    cin >> n;

    //输入元素
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    //输出
    if(A1(a,n) == 0)
    {
        cout << 'N' << " ";
    } 
    else
    {
        printf("%d ", A1(a,n));
    }
    if(A2(a,n) == 0.1)
    {
        cout << 'N' << " ";
    } 
    else
    {
        printf("%.f ", A2(a,n));
    }
    if(A3(a,n) == 0)
    {
        cout << 'N' << " ";
    } 
    else
    {
        printf("%d ", A3(a,n));
    }
    if(A4(a,n) == 0)
    {
        cout << 'N' << " ";
    } 
    else
    {
        printf("%.1f ", A4(a,n));
    }
    if(A5(a,n) == 0)
    {
        cout << 'N';
    } 
    else
    {
        printf("%d", A5(a,n));
    }
    system("pause");
    return 0;
}

//A1(能被5整除的数字中所有偶数的和)
int A1(int a[],int n)
{
    int b[1000];
    int j = 0,sum = 0;
    for(int i = 0; i < n; i++)
    {
        if(a[i] % 10 == 0)
        {
            b[j++] = a[i];
        }
    }

    if(j == 0)
    {
        return 0;
    }

    for(int i = 0; i < j; i++)
    {
        sum += b[i];
    }

    return sum;
}

//A2(能被5除后余1的整数交错求和)
double A2(int a[], int n)
{
    int b[1000];
    int j = 0;
    double sum = 0;
    for(int i = 0; i < n; i++)
    {
        if(a[i] % 5 == 1)
        {
            b[j++] = a[i];
        }
    }

    if(j == 0)
    {
        return 0.1;
    }

    for(int i = 0; i < j; i++)
    {
        sum += pow(-1,i) * b[i];
    }

    return sum;
}

//A3(被5除后余2的数字的个数)
int A3(int a[],int n)
{
    int num = 0;
    for(int i = 0; i < n; i++)
    {
        if(a[i] % 5 == 2)
        {
            num++;
        }
    }

    return num;
}

//A4(被5除后余3的数字的平均数,精确到小数点后一位)
double A4(int a[], int n)
{
    int b[1000];
    int j = 0;
    double sum =  0, average = 0;
    for(int i = 0; i < n; i++)
    {
        if(a[i] % 5 == 3)
        {
            b[j++] = a[i];
        }
    }

    if(j == 0)
    {
        return 0;
    }

    for(int i = 0; i < j; i++)
    {
        sum += b[i];
    }

    average = sum / j;

    return average;
}

//A5(被5除后余4的数字中的最大数字)
int A5(int a[], int n)
{
    int b[1000];
    int j = 0,max = 0;
    for(int i = 0; i < n; i++)
    {
        if(a[i] % 5 == 4)
        {
            b[j++] = a[i];
        }
    }

if(j == 0)
    {
        return 0;
    }

    for(int i = 0; i < j; i++)
    {
        if(b[i] > max)
        {
            max = b[i];
        }
    }

    return max;
}