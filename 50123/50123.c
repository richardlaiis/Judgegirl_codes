#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#define maxn 1000
int right(int x, int n) {
	return (x+1)%n;
}
int up(int x, int n) {
	return (x-1+n)%n;
}
int left(int x, int n) {
	return (x-1+n)%n;
}
int down(int x, int n) {
	return (x+1)%n;
}
int main() {
	int N,k,x,y;
	assert(scanf("%d%d%d%d",&N,&k,&x,&y) == 4);
	int mat[maxn][maxn] = {0};
	for(int i = 0; i < k-1; i++) {
		x = down(x, N);
		y = left(y, N);
	}
	for(int i = 1; i <= N*N; i++) {
		mat[x][y] = i;
		//printf("(%d,%d) %d\n",x,y,i);

		int newx = up(x, N);
		int newy = right(y, N);
		//printf("(%d,%d)",newx,newy);
		if(mat[newx][newy]==0) {
			x = newx;
			y = newy;
		}else {
			x = down(x, N);
		}
	}
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			printf("%d%c",mat[i][j],(j==N-1)?'\n':' ');
		}
	}
}
