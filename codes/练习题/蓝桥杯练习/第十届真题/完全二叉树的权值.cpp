#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("in.txt", "r", stdin);

    int n; //元素个数
    int tree[100005] {0}; //数组储存元素
    
    //输入数据
    cin >> n; 
    for(int i = 0; i < n; i++)
        cin >> tree[i];

    int maxV = -100005, maxK = -1; //maxV为最大和, maxK为maxV对应深度
    int N = 0; //总深度
    while(pow(++N, 2) - 1 < n); //计算总深度

    //solve:遍历二叉树每一层,更新最大和及对应深度坐标
    for(int i = 0; i < N; i++) {
        int sum = 0;
        for(int j = pow(2, i) - 1; j < 2 * pow(2, i) - 1; j++)
            sum += tree[j];
        if(sum > maxV) {
            maxV = sum;
            maxK = i;
        }
    }

    cout << maxK + 1;
    return 0;
}