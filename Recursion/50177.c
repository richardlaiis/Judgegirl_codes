#include <stdio.h>
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};
void solve(int cur, int light[4][4], int sol[], int step, int n, int *ans, int b[]) {
	if(cur >= n*n) {
		int ok = 1;
		for(int i = 0; i < n*n && ok; i++) {
			if(light[i/n][i%n]&1) ok = 0;
		}
		if(ok) {
			if(step < *ans) {
				*ans = step;
				for(int i = 0; i < step; i++) {
					b[i] = sol[i];
				}
				return;
			}			
		}
		return;
	}
	
	int cur_x = cur/n, cur_y = cur%n;
	light[cur_x][cur_y]++;
	for(int i = 0; i < 4; i++) {
		int nx = cur_x + dx[i];
		int ny = cur_y + dy[i];
		if(nx >= 0 && nx < n && ny >= 0 && ny < n) {
			light[nx][ny]++;
		}
	}
	sol[step++] = cur;
	solve(cur+1, light, sol, step, n, ans, b);
	light[cur_x][cur_y]--;
	step--;
	for(int i = 0; i < 4; i++) {
		int nx = cur_x + dx[i];
		int ny = cur_y + dy[i];
		if(nx >= 0 && nx < n && ny >= 0 && ny < n) {
			light[nx][ny]--;
		}
	}
	solve(cur+1, light, sol, step, n, ans, b);
}
int main() {
	int n;
	scanf("%d", &n);
	int a[4][4] = {0};
	int x;
	while(scanf("%d", &x) != EOF) {
		a[x/n][x%n] = 1;
	}
	int sol[16];
	int ans = 16;
	int b[16];
	solve(0, a, sol, 0, n, &ans, b);
	for(int i = 0; i < ans; i++) {
		printf("%d%c", b[i], " \n"[i == ans-1]);
	}
}
