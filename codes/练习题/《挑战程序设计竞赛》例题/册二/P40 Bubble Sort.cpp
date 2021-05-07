#include<iostream>
using namespace std;

void bubbleSort(int a[], int N)
{
    for(int i = 0; i < N - 1; i++)
    {
        for(int j = N - 1; j > i; j--)
        {
            if(a[j] < a[j - 1])
            {
                int temp = a[j - 1];
                a[j - 1] = a[j];
                a[j] = temp;
            }
        }

        for(int j = 0; j < N; j++)
        {
            cout << a[j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int N, a[10000];
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> a[i];
    }

    bubbleSort(a,N);

    system("pause");
    return 0;
}