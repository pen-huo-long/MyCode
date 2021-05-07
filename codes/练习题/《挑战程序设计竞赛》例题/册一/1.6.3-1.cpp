#include<iostream>
#include<algorithm>
using namespace std;

#define MAX_N 1000

int k[MAX_N];
int n;
int m;

//二分搜索
bool binary_search(int x)
{
    int l = 0, r = n;
    while(r - l >= 0)
    {
        int i = (r + l) / 2;
        if(k[i] == x)
            return true;
        else if(k[i] < x)
            l = i + l;
        else
            r = i;
    }
    return false;
}

void solve()
{
    sort(k, k + n);

    for(int a = 0; a < n; a++)
    {
        for(int b = 0; b < n; b++)
        {
            for(int c = 0; c < n; c++)
            {
                if(binary_search(m - k[a] - k[b] - k[c]))
                {
                    printf("Yes");
                    return;
                }
            }
        }
    }
    printf("No");
}

int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        cin >> k[i];
    }

    solve();

    system("pause");
    return 0;
}