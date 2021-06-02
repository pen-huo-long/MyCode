//https://www.luogu.com.cn/problem/T177769

#include<bits/stdc++.h>
using namespace std;



struct Point
{
    int x;
    int y;
    int steps;
    Point(int x, int y, int steps) : x(x), y(y), steps(steps) {}
};

void dfs() {
    char maze[100][100];
    bool vis[100][100];
    int n, fx, fy;
    queue<Point> q;

    //输入数据
    int dir[4][2] = { 1, 0, -1, 0, 0, 1, 0, -1 };
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> maze[i][j];
        }
    }
    cin >> fx >> fy;
    if (maze[fy][fx] == 'x') {
        cout << "IMPOSSIBLE";
        return;
    }
    vis[fy][fx] = 1;
    q.push(Point(fx, fy, 0));

    while (!q.empty()) {
        Point cur = q.front();
        q.pop();
        int xx = cur.x, yy = cur.y, sts = cur.steps;
        if (xx == 0 || yy == 0 || xx == n - 1 || yy == n - 1) {
            cout << sts;
            return;
        }
        for (int i = 0; i < 4; ++i) {
            int dx = xx + dir[i][0];
            int dy = yy + dir[i][1];
            if (dx >= 0 && dx < n && dy >= 0 && dy < n && maze[dy][dx] != 'x' && !vis[dy][dx]) {
                vis[dy][dx] = 1;
                q.push(Point(dx, dy, sts + 1));
            }
        }
    }
    cout << "IMPOSSIBLE";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("1.in", "r", stdin);
    dfs();
    return 0;
}