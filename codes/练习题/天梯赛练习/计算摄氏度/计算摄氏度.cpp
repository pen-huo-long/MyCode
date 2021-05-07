/*
    C=5×(F−32)/9
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    int F, C;
    cin >> F;
    C = (F - 32) * 5 / 9 + 0.5;
    cout << "Celsius = " << C;
    return 0;
}