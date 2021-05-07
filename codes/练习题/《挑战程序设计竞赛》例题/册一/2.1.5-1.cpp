#include<bits/stdc++.h>
using namespace std;

const int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
char maze[12][12];
bool vis[12][12] = {0};
int sa, sb;
int ea, eb;

class point {
public:
    int a;
    int b;
    int steps;
    point(int a, int b, int steps): a(a), b(b), steps(steps) {}
};

void bfs() {
    queue<point> p;
    vis[1][1] = 1;
    p.push(point(sa, sb, 0));
    while(!p.empty()) {
        point cur = p.front();
        p.pop();
        int aa = cur.a, bb = cur.b;
        if(aa == ea && bb == eb) {
            cout << cur.steps;
            return;
        } 
        for(int i = 0; i < 4; i++) {
            int da = aa + dir[i][0];
            int db = bb + dir[i][1];
            if(da > 0 && da <= 10 && db > 0 && db <= 10 && !vis[da][db] && (maze[da][db] == '.' || maze[da][db] == 'G')) {
                p.push(point(da, db, cur.steps + 1));
                vis[da][db] = 1;
            }
        }
    }
    cout << "impossible";
}

int main() {
    freopen("maze.txt", "r", stdin);
    cin >> sa >> sb >> ea >> eb;
    for(int i = 1; i <= 10; i++) {
        for(int j = 1; j <= 10; j++) {
            cin >> maze[i][j];
        }
    }
    bfs();
    return 0;
}