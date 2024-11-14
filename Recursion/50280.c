#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#define max(a, b) (((a)>(b))?(a):(b))
const int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
void place(int cur, int board[16][16], int n, int m, int cnt, int *ans) {
	if(cur >= n*m) {
		*ans = max(*ans, cnt);
		return;
	}
	if(n*m-cur <= *ans-cnt) return;
	int curx = cur/m;
	int cury = cur%m;
	if(board[curx][cury] == -1) {
		place(cur+1, board, n, m, cnt, ans);
	}else {
		bool ok = 1;
		for(int i = 0; i < 8 && ok; i++) {
			int nx = curx + dx[i];
			int ny = cury + dy[i];
			if(nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if(board[nx][ny] == 1) ok = 0;
			}
		}
		if(ok) {
			board[curx][cury] = 1;
			place(cur+1, board, n, m, cnt+1, ans);
			board[curx][cury] = 0;
			place(cur+1, board, n, m, cnt, ans);
		}else {
			place(cur+1, board, n, m, cnt, ans);
		}
	}

}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	int board[16][16] = {0};
	int x, y;
	while(scanf("%d%d", &x, &y) != EOF) board[x][y] = -1;
	int ans = 0;
	place(0, board, n, m, 0, &ans);
	printf("%d\n", ans);

}
