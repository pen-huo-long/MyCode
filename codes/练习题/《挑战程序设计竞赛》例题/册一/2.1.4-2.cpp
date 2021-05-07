#include<bits/stdc++.h>
using namespace std;

#define MAX_N 100
#define MAX_M 100

int M, N;
char field[MAX_M][MAX_N];

void dfs(int x, int y) {
    field[x][y] = '.';
    for(int i = -1; i <= 1; i++) {
        for(int j = -1; j <=1; j++) {
            int nx = x + i, ny = y + j;
            if(field[nx][ny] == 'W' && nx >= 0 && nx < N && ny >= 0 && ny < M) {
                dfs(nx, ny);
            }
        }
    }
}

int main() {
    cin >> M >> N;
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            cin >> field[i][j];
        }
    }

    int res = 0;

    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            if(field[i][j] == 'W') dfs(i,j);
            res++;
        }
    }

    cout << res;
    return 0;
}