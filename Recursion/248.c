#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#define W 9
#define TOT W*W
const int dx[8] = {0, 0, -1, 1, -1, -1, 1, 1};
const int dy[8] = {-1, 1, 0, 0, -1, 1, -1, 1};
bool find = 0;
void construct(int cur, int field[W][W], int sol[W][W]) {
	if(cur >= TOT) {
		bool ok = 1;
		for(int i = 0; i < W; i++) {
			for(int j = 0; j < W; j++) {
				if(field[i][j] != 0) {
					ok = 0;
				}
			}
		}
		if(ok) {
			find = 1;
			for(int i = 0; i < W; i++) {
				for(int j = 0; j < W; j++) {
					printf("%d%c", sol[i][j], " \n"[j==W-1]);
				}
			}
			exit(0);
		}
		return;
		/*
		find = 1;
		for(int i = 0; i < W; i++) {
			for(int j = 0; j < W; j++) {
				printf("%d%c", sol[i][j], " \n"[j == W-1]);
			}
		}
		exit(0);
		*/
	}
	int curx = cur/W;
	int cury = cur%W;
	bool ok = 1;
	for(int i = 0; i < 8 && ok; i++) {
		int nx = curx + dx[i];
		int ny = cury + dy[i];
		if(nx >= 0 && nx < W && ny >= 0 && ny < W) {
			if(field[nx][ny] < 1) ok = 0;
		}
	}
	if(curx-1 >= 0 && cury-1 >= 0) {
		if(field[curx-1][cury-1] > 1)
			return;
	}
	if(curx-1 >= 0)
		if(field[curx-1][cury] > 2)
			return;
	if(curx-1 >= 0 && cury+1 < W)
		if(field[curx-1][cury+1] > 3)
			return;
	if(ok) {
		construct(cur+1, field, sol);
		sol[curx][cury] = 1;
		field[curx][cury] -= 1;
		for(int i = 0; i < 8; i++) {
			int nx = curx + dx[i];
			int ny = cury + dy[i];
			if(nx >= 0 && nx < W && ny >= 0 && ny < W) {
				field[nx][ny]-=1;
			}
		}
		construct(cur+1, field, sol);
		sol[curx][cury] = 0;
		field[curx][cury] += 1;
		for(int i = 0; i < 8; i++) {
			int nx = curx + dx[i];
			int ny = cury + dy[i];
			if(nx >= 0 && nx < W && ny >= 0 && ny < W) {
				field[nx][ny]+=1;
			}
		}
	}else {
		construct(cur+1, field, sol);
	}

}
int main() {
	int field[W][W];
	for(int i = 0; i < W; i++) {
		for(int j = 0; j < W; j++) {
			scanf("%d", &field[i][j]);
		}
	}
	int sol[W][W] = {0};
	construct(0, field, sol);
	if(!find) printf("no solution\n");
}
