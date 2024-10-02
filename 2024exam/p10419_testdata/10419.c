#include <stdio.h>
#include <stdbool.h>
int main() {
	int weight[501][501];
	bool vis[501][501];
	int n;
	scanf("%d",&n);
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			scanf("%d",&weight[i][j]);
		}
	}

}
