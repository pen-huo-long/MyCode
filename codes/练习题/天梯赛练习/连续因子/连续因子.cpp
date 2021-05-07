#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("in.txt", "r", stdin);

    int N;
    cin >> N;

    int len = 0, n = sqrt(N);
    for(len = 12; len >= 1; len--){ //最多12位连续数字, 从12位开始递减枚举
        
        for(int start = 2; start < n - len; start++){
            long long ins = 1;

            for(int i = start; i - start <= len - 1; i++){ //执行从start开始对应因子数垒乘
                ins *= i;
            }

            if(N % ins == 0){ //当当前位数连续因子能被整除时打印并结束
                cout << len <<endl << start;
                for(int i = start + 1; i - start <= len - 1; i++){
                    cout << "*" << i;
                }
                return 0;
            }
        }
    }
    printf("1\n%d",N);
    return 0;
}