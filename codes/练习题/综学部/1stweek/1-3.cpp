#include<bits/stdc++.h>
using namespace std;

double a, eps;

int main() {
    double a, eps;
    cin >> a >> eps;
    double x1 = a / 2, x2 = (x1 + a / x1) / 2;
    while(abs(x1 - x2) >= eps) {
        x1 = x2;
        x2 = (x1 + a / x1) / 2;
    }
    double squareRoot = (x1 + x2) / 2;
    printf("%.4f", squareRoot);
    return 0;
}
