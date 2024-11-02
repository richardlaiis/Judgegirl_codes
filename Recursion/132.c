#include <stdio.h>
#include <stdbool.h>
bool legal(int edge[][20], int ans[], int n) {
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if(edge[i][j] && ans[i] != 0 && ans[i] == ans[j])
				return 0;
	return 1;
}
int sol(int idx, int n, int c, int edge[][20], int ans[]) {
	if(idx == n)
		return 1;
	int flag = 0;
	for(int i = 1; i <= c && flag==0; i++) {
		ans[idx] = i;
		if(legal(edge, ans, n))
			flag = sol(idx+1, n, c, edge, ans);
		if(flag)
			break;
		else 
			ans[idx] = 0;

	}
	return flag;
}
int main() {
	int n, c, k;
	scanf("%d%d%d",&n, &c, &k);
	int ans[20] = {0}, edge[20][20] = {0};
	for(int i = 0; i < k; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		edge[a][b] = 1;
		edge[b][a] = 1;
	}
	if(sol(0, n, c, edge, ans)) {
		for(int i = 0; i < n; i++)
			printf("%d\n", ans[i]);
	}else
		printf("no solution.\n");
}
