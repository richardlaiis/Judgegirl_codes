#include <stdio.h>
#include <stdbool.h>
//#include <stdlib.h>
//bool find = 0;
bool solve(int cur, int set[], bool vis[], bool p[100][100], int n, int m) {
	if(cur >= m) {
		/*
		for(int i = 0; i < m; i++) {
			printf("%d%c", set[i], " \n"[i == m-1]);
		}
		*/
		return 1;
	}
	if(cur == 0) {
		for(int i = 0; i < n; i++) {
			set[cur] = i;
			vis[i] = 1;
			if(solve(cur+1, set, vis, p, n, m)) {
				for(int i = 0; i < m; i++) {
					printf("%d%c", set[i], " \n"[i == m-1]);
				}
				return 1;
			}
			vis[i] = 0;
		}
	}else {
		for(int i = 0; i < n; i++) {
			bool ok = 1;
			for(int j = 0; j < cur && ok; j++) {
				if(p[i][j]) ok = 0;
			}
			if(ok && !vis[i]) {
				vis[i] = 1;
				set[cur] = i;
				if(solve(cur+1, set, vis, p, n, m)) {
					vis[i] = 0;
					return 1;
				}else {
					vis[i] = 0;
					return 0;
				}
			}
		}
	}

}
int main() {
	int n, m;
	bool p[100][100];
	bool vis[100] = {0};
	int set[100];
	while(scanf("%d%d", &n, &m) != EOF) {
		
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				scanf("%d", &p[i][j]);
		if(!solve(0, set, vis, p, n, m)) {
			printf("no solution\n");
		}
		
	}
}
