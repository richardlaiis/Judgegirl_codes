#include <stdio.h>
#include <stdbool.h>
long long ans = 0;
int mat[12][12], r, c;
void walk(int x,int y) {
	if(x==r-1 && y==c-1) {
		++ans;
		return;
	}
	if(x+1<r && mat[x+1][y]==1) walk(x+1,y);
	if(y+1<c && mat[x][y+1]==1) walk(x,y+1);
}
int main() {
	int x;
	scanf("%d%d",&r,&c);
	for(int i = r-1; i >= 0; i--) {
		for(int j = 0; j < c; j++) {
			scanf("%d",&mat[i][j]);
		}
	}
	walk(0,0);
	printf("%d\n",ans);
}
