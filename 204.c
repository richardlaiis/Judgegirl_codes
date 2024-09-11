#include <stdio.h>
struct point {
	int x,y;
};
int changedir(int x) {
	if(x==3) return 0;
	else if(x==2) return 1;
	else if(x==1) return 2;
	else return 3;
}
int main() {
	int W,D;
	scanf("%d%d",&W,&D);
	int rooms[D+5][W+5]; 
	struct point start[2*(W+D)];
	int ans[2*(W+D)];
	for(int i = 0; i < 2*(W+D); i++) ans[i] = -1;
	for(int i = 0; i < D+5; i++) {
		for(int j = 0; j < W+5; j++) rooms[i][j]=-1;
	}
	for(int i = 1; i <= D; i++) {
		for(int j = 1; j <= W; j++) {
			scanf("%d",&rooms[i][j]);
			rooms[i][j]-=3;
		}
	}
	//for(int i = 0; i < W; i++) rooms[0][i+1] = i;	
	for(int i = 0; i < W; i++) rooms[D+1][i+1] = i, start[i].x=D+1, start[i].y=i+1;
	for(int i = W+D-1; i >= W; i--) rooms[W+D-i][W+1] = i, start[i].x=W+D-i, start[i].y=W+1;
	for(int i = 2*W+D-1; i >= W+D; i--) rooms[0][2*W+D-i] = i, start[i].x=0, start[i].y=2*W+D-i;
	for(int i = 2*W+D; i < 2*(W+D); i++) rooms[i-(2*W+D)+1][0] = i, start[i].x=i-(2*W+D)+1, start[i].y=0;
#ifdef DEBUG
	for(int i = 0; i < D+5; i++) {
		for(int j = 0; j < W+5; j++) {
			printf("%3d ",rooms[i][j]);
		}
		printf("\n");
	}
	for(int i = 0; i < 2*(W+D); i++) printf("%d,%d ",start[i].x,start[i].y);
	printf("\n");
#endif
	int d[5]={0, 1, 0, -1, 0};
	for(int i = 0; i < 2*(W+D); i++) {
		if(ans[i]!=-1) continue;
		int op;
		if(i>=0 && i<W) op=3;
		else if(i>=W && i<W+D) op=2;
		else if(i>=W+D && i<2*W+D) op=1;
		else op=0;
		int cur_x = start[i].x, cur_y = start[i].y;
		//printf("(%d,%d) ",cur_x,cur_y);
		while(rooms[cur_x][cur_y]==i || rooms[cur_x][cur_y]==-3 || rooms[cur_x][cur_y]==-2 || rooms[cur_x][cur_y]==-1) {
			cur_x+=d[op];
			cur_y+=d[op+1];
			if(rooms[cur_x][cur_y]==-2) op=changedir(op);
#ifdef DEBUG
			printf("(%d,%d) ",cur_x,cur_y);
#endif
		}
		//printf("\n");
		ans[i]=rooms[cur_x][cur_y];
		ans[rooms[cur_x][cur_y]] = i;
	}
	for(int i = 0; i < 2*(W+D); i++) printf("%d\n",ans[i]);
}
