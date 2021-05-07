#include<iostream>
using namespace std;

#define MAX_N 200000

int main()
{
    int n, R[MAX_N];
    for(int i = 0; i < n; i++)
    {
        cin >> R[i];
    }

    int maxV = -20000000000;
    int minV = R[0];
    for(int i = 1; i < n; i++)
    {
        maxV = max(maxV, R[i] - minV);
        minV = min(minV, R[i]);
    }

    cout << maxV << endl;
    system("pause");
    return 0;
}