#include <stdio.h>
#include <string.h>
struct bingo {
	int row, col;
};
int main() {
	int n, m;
	scanf("%d%d",&n,&m);
	char names[n][64];
	struct bingo nums[n][m*m+1];
	int rows[n][m], cols[n][m], slope[n][2];
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			rows[i][j] = 0;
			cols[i][j] = 0;
		}
		for(int j = 0; j < 2; j++) slope[i][j] = 0;
	}
	for(int i = 0; i < n; i++) {
		scanf("%s",names[i]);
		for(int j = 0; j < m; j++) {
			for(int k = 0; k < m; k++) {
				int x;
				scanf("%d",&x);
				nums[i][x].row = j;
				nums[i][x].col = k;
			}
		}
	}
	int cnt = 0, ans;
	char people[1000] = " ";
	for(int i = 0; i < m*m; i++) {
		int x;
		scanf("%d",&x);
		for(int j = 0; j < n; j++) {
			int r = nums[j][x].row, c = nums[j][x].col;
			rows[j][r]++;
			cols[j][c]++;
			if(r==c) slope[j][0]++;
			if(r+c==m-1) slope[j][1]++;
			
			if(rows[j][r]==m || cols[j][c]==m || slope[j][0]==m || slope[j][1]==m) {
				cnt++;
				ans = x;
				if(cnt>1) strcat(people, " ");
				strcat(people, names[j]);
			}
		}
		if(cnt) {
			printf("%d%s\n",ans,people);
			break;
		}
	}
}
