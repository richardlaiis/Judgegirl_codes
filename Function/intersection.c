/*
#include <assert.h>
void intersection(int map[100][100], int result[4]) {
	int d[5] = {0, 1, 0, -1, 0};
	for(int i = 0; i < 4; i++) result[i] = 0;
	for(int i = 0; i < 100; i++) {
		for(int j = 0; j < 100; j++) {
			if(map[i][j]==0) continue;
			int cnt = 0;
			for(int k = 0; k < 4; k++) {
				int newx = i+d[k];
				int newy = j+d[k+1];
				if(newx>=0 && newx<100 && newy>=0 && newy<100) {
					if(map[newx][newy]==1) cnt++;
				}
			}
			assert(cnt>=0 && cnt<=4);
			if(cnt==0) continue;
			else if(cnt == 2) {	
				int x[2], y[2];
				int idx = 0;	
				for(int k = 0; k < 4; k++) {
					int newx = i+d[k];
					int newy = j+d[k+1];
					if(newx>=0 && newx<100 && newy>=0 && newy<100) {
						if(map[newx][newy]) x[idx++]=newx,y[idx++]=newy;
					}
				}
				if(x[0]!=x[1] && y[0]!=y[1]) result[2]++;
			}else {
				result[4-cnt]++;
			}
		}
	}
}
*/
#include"intersection.h"
void intersection(int map[100][100], int result[4]){
    int i; int j;
    int sum;
    int n;
    result [0]=0;
    result [1]=0;
    result [2]=0;
    result [3]=0;
       for (i=0;i<100;i++){
        for (j=0;j<100;j++){
            sum =0;
            if (i+1<100 && map[i+1][j] ==1) sum++;
            if (i-1>=0 && map[i-1][j]==1) sum++;
            if (j+1<100 && map[i][j+1] ==1) sum++;
            if (j-1>=0 && map[i][j-1] ==1) sum++;

            if (sum==4){
                if (map[i][j]==1)
                   result[0]++;
            }
            if (sum==3){
                if (map[i][j]==1){
                       result[1]++;
                    }
            }
            if (sum==2){
                if (map[i][j]==1){
                    if (map[i-1][j]==1 && i-1>=0 && map[i+1][j]!=1){
                        result[2]++;
                    }
                    else if (map[i+1][j]==1 && i+1<100 && map[i-1][j]!=1){
                       result[2]++;
                    }
                    else if (map[i][j+1]==1 && j+1<100 && map[i][j-1]!=1){
                        result[2]++;
                    }
                    else if (map[i][j-1]==1 && j-1>=0 && map[i][j+1]!=1){
                        result[2]++;
                    }
                }
            }
            if (sum==1){
                if (map[i][j]==1){
                    result[3]++;
                    }
                }
            }
        }
        return;
}
