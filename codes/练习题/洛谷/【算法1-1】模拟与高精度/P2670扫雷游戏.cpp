#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("in.txt", "r", stdin);

    char map[101][101] {'0'}; //储存地图
    int n, m, boom; //n = 行数, m = 列数, boom = 当前格子炸弹
    //输入地图
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> map[i][j];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(map[i][j] == '?') {
                boom = 0;
                for(int r = -1; r <= 1; r++) {
                    for(int l = -1; l <= 1; l++) {
                        if(map[i + r][j + l] == '*')
                            boom++;
                    }
                }
                map[i][j] = boom + '0';
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            cout << map[i][j];
        cout << endl;
    }
    return 0;
}