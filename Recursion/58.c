#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};
int dfs(int x, int y, int n, int m, bool pic[400][400], bool vis[400][400]) {
	int area = 1;
	for(int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx >= 0 && nx < n && ny >= 0 && ny < m) {
			if(vis[nx][ny] == 0 && pic[nx][ny]) {
				vis[nx][ny] = 1;
				area += dfs(nx, ny, n, m, pic, vis);
			}
		}
	}
	return area;
}
int cmp(const void *a, const void *b) {
	return (*(int *)b - *(int *)a);
}
int main() {
	int n, m;
	bool pic[400][400] = {0}, vis[400][400] = {0};
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			scanf("%d", &pic[i][j]);
		}
	}
	int lakes[80001] = {0}, idx = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(pic[i][j] && vis[i][j] != 1) {
				vis[i][j] = 1;
				lakes[idx++] = dfs(i, j, n, m, pic, vis);
			}
		}
	}
	qsort(lakes, idx, sizeof(int), cmp);
	for(int i = 0; i < idx; i++) {
		printf("%d\n", lakes[i]);
	}
}