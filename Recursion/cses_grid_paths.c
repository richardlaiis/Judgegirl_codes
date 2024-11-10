#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {1, -1, 0, 0};

int findWays(int idx, int x, int y, bool vis[9][9], int p[49]) {
    
    if(vis[x][y+1] && vis[x][y-1] && !vis[x+1][y] && !vis[x-1][y]) return 0;
    if(vis[x-1][y] && vis[x+1][y] && !vis[x][y-1] && !vis[x][y+1]) return 0;

    if(x == 7 && y == 1) {
        if(idx == 48) return 1;
        else return 0;
    }

    if(idx == 48) return 0;

    int ret = 0;
    vis[x][y] = 1;

    if(p[idx] != 4) {
        int nx = x+dx[p[idx]];
        int ny = y+dy[p[idx]];
        if(!vis[nx][ny]) ret += findWays(idx+1, nx, ny, vis, p);
    }else {
        for(int i = 0; i < 4; i++) {
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(vis[nx][ny]) continue;
            ret += findWays(idx+1, nx, ny, vis, p);
        }
    }
    vis[x][y] = 0;
    return ret;
}
 
int main() {
    char path[49];
    scanf("%s", path);
    int p[49];
    for(int i = 0; i < 48; i++) {
        switch (path[i])
        {
        case 'R':
            p[i] = 0;
            break;
        case 'L':
            p[i] = 1;
            break;
        case 'U':
            p[i] = 2;
            break;
        case 'D':
            p[i] = 3;
            break;
        default:
            p[i] = 4;
            break;
        }
    }
    bool vis[9][9];
    for(int i = 0; i < 9; i++) {
        vis[i][0] = 1;
        vis[0][i] = 1;
        vis[i][8] = 1;
        vis[8][i] = 1;
    }
    for(int i = 1; i <= 7; i++) {
        for(int j = 1; j <= 7; j++) {
            vis[i][j] = 0;
        }
    }
    int ans = findWays(0, 1, 1, vis, p);
    printf("%d\n", ans);

}