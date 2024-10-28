#include <stdio.h>
#include <stdlib.h>
#define maxn 400
int foo = 0;
void dfs(int x, int y, int vis[maxn][maxn], int *area, int n, int m, int a[maxn][maxn]) {
	int d[5] = {0, 1, 0, -1, 0};
	for(int i = 0; i < 4; i++) {
		int newx = x + d[i];
		int newy = y + d[i+1];
		if(newx >=0 && newx < n && newy >= 0 && newy < m && a[newx][newy] && !vis[newx][newy]) {
			*area = *area + 1;
			vis[newx][newy] = 1;
			dfs(newx, newy, vis, area, n, m, a);
		}
	}
	foo++;
}
int cmp(const void *a, const void *b) {
	return *(int*)b - *(int*)a; 
}
int main() {
	int a[maxn][maxn];
	int vis[maxn][maxn] = {{0}};
	int cnt = 0;
	int ans[80005];
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			scanf("%d",&a[i][j]);
		}
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(a[i][j] && !vis[i][j]) {
				vis[i][j] = 1;
				int area = 1;
				dfs(i, j, vis, &area, n, m, a);
				ans[cnt++] = area;		
			}	
		}
	}
	//printf("cnt: %d\n",cnt);
	qsort(ans, cnt, sizeof(int), cmp);
	for(int i = 0; i < cnt; i++) {
		printf("%d\n",ans[i]);
	}
}
