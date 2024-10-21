#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
int main() {
	int n;
	char grid[55][55];
	char ans[505];
	int d[] = {0, 1, 0, -1, 0};
	scanf("%d",&n);
	for(int i = 0; i < n; i++) {
		scanf("%s", &grid[i]);
	}
	char curc = '~';
	int cr = -1, cc = -1;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			int cnt = 0;
			if(!isalpha(grid[i][j])) continue;
			for(int k = 0; k < 4; k++) {
				int nx = i+d[k];
				int ny = j+d[k+1];
				if(nx >= 0 && nx < n && ny >= 0 && ny < n && isalpha(grid[nx][ny])) cnt++;
			}
			if(cnt == 1) {
				if(grid[i][j]-curc < 0) {
					curc = grid[i][j];
					cr = i;
					cc = j;
				}else if(grid[i][j]-curc == 0) {
					if(i < cr) {
						cr = i;
						cc = j;
					}else if(i == cr && j < cc) {
						cr = i;
						cc = j;
					}
				}
			}	
		}
	}
	//printf("(%d,%d)",cr,cc);
	bool vis[505][505] = {{0}};
	bool flag = 1;
	int idx = 0;
	while(flag) {
		flag = 0;
		vis[cr][cc] = 1;
		ans[idx++] = grid[cr][cc];
		for(int i = 0; i < 4; i++) {
			int nx = cr+d[i];
			int ny = cc+d[i+1];
			if(nx >= 0 && nx < n && ny >= 0 && ny < n && !vis[nx][ny] && isalpha(grid[nx][ny])) {
				flag = 1;
				cr = nx;
				cc = ny;
				break;
			}
		}
	}
	ans[idx] = '\0';
	printf("%s\n", ans);
}
