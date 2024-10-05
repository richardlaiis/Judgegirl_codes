#include <stdio.h>
signed main() {
	int r,c,mat[12][12]={{0}};
	scanf("%d%d",&r,&c);
	mat[0][0] = 1;
	for(int i = 0; i < r; i++) mat[i][0] = 1;
	for(int i = 0; i < c; i++) mat[0][i] = 1;
	for(int i = 1; i < r; i++) {
		for(int j = 1; j < c; j++) {
			mat[i][j] = mat[i-1][j]+mat[i][j-1];
		}
	}
	printf("%d\n",mat[r-1][c-1]);
}	
