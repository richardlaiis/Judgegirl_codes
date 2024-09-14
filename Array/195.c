#include <stdio.h>
int main() {
	int N;
	scanf("%d",&N);
	int cnt = 0;
	int plate[3][3];
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) plate[i][j] = -1;
	}
	int cur = 1;
	int black=0, white=0;
	while(N--) {
		int x,y;
		scanf("%d%d",&x,&y);
		if(cnt>=9) continue;
		if((plate[0][0]==1&&plate[0][1]==1&&plate[0][2]==1) || (plate[1][0]==1&&plate[1][1]==1&&plate[1][2]==1) || (plate[2][0]==1&&plate[2][1]==1&&plate[2][2]==1) || (plate[0][0]==1&&plate[1][0]==1&&plate[2][0]==1) || (plate[0][1]==1&&plate[1][1]==1&&plate[2][1]==1) || (plate[0][2]==1&&plate[1][2]==1&&plate[2][2]==1) || (plate[0][0]==1&&plate[1][1]==1&&plate[2][2]==1) || (plate[0][2]==1&&plate[1][1]==1&&plate[2][0]==1)) black=1;
		if((plate[0][0]==0&&plate[0][1]==0&&plate[0][2]==0) || (plate[1][0]==0&&plate[1][1]==0&&plate[1][2]==0) || (plate[2][0]==0&&plate[2][1]==0&&plate[2][2]==0) || (plate[0][0]==0&&plate[1][0]==0&&plate[2][0]==0) || (plate[0][1]==0&&plate[1][1]==0&&plate[2][1]==0) || (plate[0][2]==0&&plate[1][2]==0&&plate[2][2]==0) || (plate[0][0]==0&&plate[1][1]==0&&plate[2][2]==0) || (plate[0][2]==0&&plate[1][1]==0&&plate[2][0]==0)) white=1;
		if(black || white) continue;
		if(x>=0 && x<=2 && y>=0 && y<=2) {
			if(plate[2-y][x]==-1) {
				plate[2-y][x] = cur;
				cur = !cur;
				++cnt;
			}
		}
	}
//	for(int i = 0; i < 3; i++) {
//		for(int j = 0; j < 3; j++) {
//			printf("%d ",plate[i][j]);
//		}
//		printf("\n");
//	}

		if((plate[0][0]==1&&plate[0][1]==1&&plate[0][2]==1) || (plate[1][0]==1&&plate[1][1]==1&&plate[1][2]==1) || (plate[2][0]==1&&plate[2][1]==1&&plate[2][2]==1) || (plate[0][0]==1&&plate[1][0]==1&&plate[2][0]==1) || (plate[0][1]==1&&plate[1][1]==1&&plate[2][1]==1) || (plate[0][2]==1&&plate[1][2]==1&&plate[2][2]==1) || (plate[0][0]==1&&plate[1][1]==1&&plate[2][2]==1) || (plate[0][2]==1&&plate[1][1]==1&&plate[2][0]==1)) black=1;
		if((plate[0][0]==0&&plate[0][1]==0&&plate[0][2]==0) || (plate[1][0]==0&&plate[1][1]==0&&plate[1][2]==0) || (plate[2][0]==0&&plate[2][1]==0&&plate[2][2]==0) || (plate[0][0]==0&&plate[1][0]==0&&plate[2][0]==0) || (plate[0][1]==0&&plate[1][1]==0&&plate[2][1]==0) || (plate[0][2]==0&&plate[1][2]==0&&plate[2][2]==0) || (plate[0][0]==0&&plate[1][1]==0&&plate[2][2]==0) || (plate[0][2]==0&&plate[1][1]==0&&plate[2][0]==0)) white=1;
		if(black) printf("Black wins.\n");
	else if(white) printf("White wins.\n");
	else printf("There is a draw.\n");
}
