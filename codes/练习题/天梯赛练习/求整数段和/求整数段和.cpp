#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("in.txt", "r", stdin);

    int n1, n2, sum = 0;
    cin >> n1 >> n2;

    for(int i = n1, j = 0; i <= n2; i++, j++){
        if(j % 5 == 0 && j != 0)
            cout << endl;
        printf("%5d",i);
        sum += i;
    }
    cout << endl << "Sum = " << sum;
    return 0;
}