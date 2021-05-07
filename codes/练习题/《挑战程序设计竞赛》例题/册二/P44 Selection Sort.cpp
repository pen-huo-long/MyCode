#include<iostream>
using namespace std;

void selectionSort(int a[], int N)
{
    for(int i = 0; i < N - 1; i++)
    {
        int minV = i;
        for(int j = i + 1; j < N; j++)
            if(a[j] < a[minV])
                minV = j;
        
        int temp = a[i];
        a[i] = a[minV];
        a[minV] = temp; 

        for(int j = 0; j < N; j++)
            cout << a[j] << " ";
        cout << endl;
    }
}

int main()
{
    int N, a[100000];
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> a[i];

    selectionSort(a,N);

    system("pause");
    return 0;
}