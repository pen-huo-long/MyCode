#include <bits/stdc++.h>
using namespace std;

int m, n; //m行n列
string fpath;
int maze[32][52];                                 //储存地图
bool vis[32][52];                                 //走过的路径用bool值1代替,
const int dir[4][2] = {1, 0, 0, -1, -1, 0, 0, 1}; //移动方向
const char dc[5] = {'R', 'U', 'L', 'D'};
const string dc1[4] = {"右", "上", "左", "下"}; //方向

//点-第y行第x列,移动到这一位置需要的步骤
class point
{
public:
    int x;
    int y;
    string path;
    point(int x, int y, string path) : x(x), y(y), path(path) {}
};

//bfs
void bfs()
{
    queue<point> p;          //队列储存point
    vis[1][1] = 1;           //起始位置
    p.push(point(1, 1, "")); //起始位置
    //队列不为空时执行循环
    while (!p.empty())
    {
        point cur = p.front(); //临时变量等于队列头端
        p.pop();               //去除
        int xx = cur.x, yy = cur.y;
        string path = cur.path;
        //当改点为终点时输出path并结束
        if (xx == n && yy == m)
        {
            fpath = path;
            //cout << path << endl;
            return;
        }
        //当不为终点时继续搜索
        for (int i = 0; i < 4; ++i)
        {
            int dx = xx + dir[i][0];
            int dy = yy + dir[i][1];
            //判断是否出界以及是否撞墙以及是否走了走过的点
            if (dx > 0 && dx <= n && dy > 0 && dy <= m && (!vis[dy][dx]) && (!maze[dy][dx]))
            {
                vis[dy][dx] = 1;
                p.push(point(dx, dy, path + dc[i]));
            }
        }
    }
    cout << "impossible"; //无法到达时打印impossible
}

void PrintResult() {
    int dx = 1, dy = 1;
    for (int i = 0; i < fpath.length(); i++) {
        switch (fpath[i]) {
        case 'U':
            maze[dy][dx] = 2;
            dy -= 1;
            break;
        case 'D':
            maze[dy][dx] = 3;
            dy += 1;
            break;
        case 'L':
            maze[dy][dx] = 4;
            dx -= 1;
            break;
        case 'R':
            maze[dy][dx] = 5;
            dx += 1;
            break;
        }
    }
    char maze2[32][52];
    for (int i = 1; i <= 30; i++) {
        for (int j = 1; j <= 50; j++) {
            switch (maze[i][j]) {
            case 0:
                maze2[i][j] = ' ';
                break;
            case 1:
                maze2[i][j] = ' ';
                break;
            case 2:
                maze2[i][j] = 'U';
                break;
            case 3:
                maze2[i][j] = 'D';
                break;
            case 4:
                maze2[i][j] = 'L';
                break;
            case 5:
                maze2[i][j] = 'R';
                break;
            }
        }
    }

    for (int i = 1; i <= 30; i++) {
        for (int j = 1; j <= 50; j++) {
            cout << maze2[i][j];
        }
        cout << endl;
    }
}

int main()
{
    freopen("maze.txt", "r", stdin);
    freopen("maze2.txt", "w", stdout);
    
    cin >> m >> n;
    char c;
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin >> c;
            maze[i][j] = c - '0';
        }
    }

    bfs();
    PrintResult();
    return 0;
}