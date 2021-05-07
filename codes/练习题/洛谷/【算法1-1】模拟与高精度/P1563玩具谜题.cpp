#include<bits/stdc++.h>
using namespace std;

string map_toy[100005]; //字符串组储存玩具信息-> 朝向 + " " + 名字

int main() {
    freopen("in.txt", "r", stdin);
    //n_toy = 玩具小人数, m_order = 命令数,order = 移动步数, seat = 移动后位置
    int n_toy, m_order, order, seat = 0; 
    char direction; //移动方向
    //输入数据
    cin >> n_toy >> m_order;
    getchar();
    for(int i = 0; i < n_toy; i++)
        getline(cin, map_toy[i]);
    //运行指令
    for(int i = 0; i < m_order; i++) {
        cin >> direction >> order;
        //面内向左/面外向右 -> 顺时针移动
        if(direction == map_toy[seat][0])
            seat = (seat + n_toy - order) % n_toy;
        //面内向右/面外向左 -> 逆时针移动
        else
            seat = (seat + order) % n_toy;
    }
    //输出结果
    cout << map_toy[seat].substr(2);
    return 0;
}