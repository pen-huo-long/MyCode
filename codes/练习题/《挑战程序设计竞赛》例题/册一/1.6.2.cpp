#include<iostream>
using namespace std;

#define MAX_N 1000000

int L, n;
int x[MAX_N];

void solve()
{
    int minT = 0;
    for(int i = 0; i < n; i++)
    {
        minT = max(minT, min(L - x[i], x[i]));
    }
    int maxT = 0;
    for(int i = 0; i < n; i++)
    {
        maxT = max(maxT, max(L - x[i], x[i]));
    }

    printf("min = %d\nmax = %d", minT, maxT);
}

int main()
{
    cin >> L >> n;
    
    for(int i = 0; i < n; i++)
    {
        cin >> x[i];
    }

    solve();
    
    system("pause");
    return 0;
}