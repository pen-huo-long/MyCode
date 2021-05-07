#include<bits/stdc++.h>
using namespace std;

//字符串倒置函数
void convert(string & a) {
    for(int i = 0; i < a.length() / 2; i++) {
        char temp = a[i];
        a[i] = a[a.length() - 1 - i];
        a[a.length() - 1 - i] = temp;
    }
}

int main() {
    freopen("in.txt", "r", stdin);

    string num1, num2; //num1, num2 = 加数
    cin >> num1 >> num2; //输入数据

    //倒置后对应位数相加, 满十进一
    convert(num1);
    convert(num2);
    int len = max(num1.length(), num2.length());
    num1.resize(len, '0');
    for(int i = 0; i < len; i++) {
        num1[i] += num2[i] - '0';
        if(i == len - 1 && num1[i] - '0' >= 10) {
            num1[i] -= 10;
            num1 += '1';
        }
        else if(num1[i] - '0' >= 10) {
            num1[i] -= 10;
            num1[i + 1]++;
        }
    }

    convert(num1);

    cout << num1;
    return 0;
}