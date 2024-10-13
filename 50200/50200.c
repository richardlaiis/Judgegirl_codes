#include <stdio.h>
#define maxn 500
void rookit(int row, int col, int a[maxn][maxn], int h, int w) {
	int tmp;
	tmp = row+1;
	while(tmp<h && a[tmp][col]!=0) a[tmp][col] = 0, tmp++;
	tmp = row-1;
	while(tmp>-1 && a[tmp][col]!=0) a[tmp][col] = 0, tmp--;
	tmp = col+1;
	while(tmp<w && a[row][tmp]!=0) a[row][tmp] = 0, tmp++;
	tmp = col-1;
	while(tmp>-1 && a[row][tmp]!=0) a[row][tmp] = 0, tmp--;
}
void bishopit(int row, int col, int a[maxn][maxn], int h, int w) {
	int x[] = {1,1,-1,-1};
	int y[] = {1,-1,1,-1};
	for(int i = 0; i < 4; i++) {
		int tmpx = row+x[i];
		int tmpy = col+y[i];
		while(tmpx>=0 && tmpx<h && tmpy>=0 && tmpy<w && a[tmpx][tmpy]!=0) {
			a[tmpx][tmpy] = 0;
			tmpx += x[i];
			tmpy += y[i];
		}
	}
}
int main() {
	int board[maxn][maxn];
	int height, width;
	scanf("%d%d",&height,&width);
	for(int i = 0; i < height; i++) {
		for(int j = 0; j < width; j++) {
			board[i][j] = -1;
		}
	}
	int type, row, col;
	while(scanf("%d%d%d",&type,&col,&row) != EOF) {
		board[row][col] = 0;
		switch(type) {
			case 0:
				board[row][col] = 0;
				break;
			case 1:
				rookit(row,col,board,height,width);
				bishopit(row,col,board,height,width);
				break;
			case 2:
				bishopit(row,col,board,height,width);
				break;
			case 3:
				rookit(row,col,board,height,width);
				break;
			default:
				break;
		}
		//for(int i = 0; i < height; i++) {
		//	for(int j = 0; j < width; j++) {
		//		printf("%2d%c",board[i][j], (j==width-1)?'\n':' ');
		//	}
		//}
		
//		for(int i = 0; i < height; i++) {
//			for(int j = 0; j < width; j++) {
//				printf("%d%c", (board[i][j]==-1)?0:1, (j==width-1)?'\n':' ');
//			}
//		}
//		printf("--------------------------\n");
	}
	for(int i = 0; i < height; i++) {
		for(int j = 0; j < width; j++) {
			printf("%d%c", (board[i][j]==-1)?0:1, (j==width-1)?'\n':' ');
		}
	}
	return 0;
}
