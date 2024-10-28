#include <stdio.h>
#include <stdbool.h>
int main() {
	int n;
	scanf("%d",&n);
	int w[501][501];
	bool vis[501];
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			scanf("%d",&w[i][j]);
		}
	}
	int minlen = 600000000, minidx = 0;
	for(int i = 1; i <= n; i++) {
		int cnt = 1, curlen = 0, curidx = i;
		for(int j = 1; j <= n; j++) {
			vis[j] = 0;
		}
		vis[i] = 1;

		while(cnt != n) {
			int minw = 1000000;
			int nxtminidx = 0;
			for(int j = 1; j <= n; j++) {
				if(j == i) continue;
				if(w[curidx][j]<=minw && !vis[j]) {
					minw = w[curidx][j];
					nxtminidx = j;
				}	
			}
			curidx = nxtminidx;
			vis[curidx] = 1;
			cnt++;
			curlen += minw;
		}
		curlen += w[curidx][i];
		
		if(curlen <= minlen) {
			minlen = curlen;
			minidx = i;
		}
	}
	printf("%d %d\n",minidx, minlen);
}
