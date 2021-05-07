#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("in.txt", "r", stdin);

    int n, num[100005] {0}; // n为元素数, num储存元素

    //输入数据
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> num[i];
    }

    sort(num, num + n); //升序排序

    int gcdnum = num[1] - num[0]; //最大公约数

    //找到排序后两两差值的最大公约数gcdnum,即为公差
    for(int i = 0; i < n - 2; i++) {
        gcdnum = __gcd(gcdnum, num[i + 2] - num[i + 1]);
    }

    //公差为0时项数即为元素数
    if(gcdnum == 0) {
        cout << n;
    }
    else {
        int N = (num[n - 1] - num[0]) / gcdnum + 1; //利用首尾项及公差计算项数N
        cout << N;
    }
    return 0;
}