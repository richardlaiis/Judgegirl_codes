#include <stdio.h>
int main() {
	int r,c;
	scanf("%d%d",&r,&c);
	int arr[r][c];
	for(int i = 0; i < r; i++) 
		for(int j = 0; j < c; j++)
			scanf("%d",&arr[i][j]);
	for(int i = 0; i < r; i++) {
		for(int j = 0; j < c; j++) {
			int flag = 1;
			if(i-1>=0)
				if(arr[i][j]<=arr[i-1][j])
					flag = 0;

			if(i+1<=r-1)
				if(arr[i][j]<=arr[i+1][j])
					flag = 0;
			if(j-1>=0)
				if(arr[i][j]<=arr[i][j-1])
					flag = 0;
			if(j+1<=c-1)
				if(arr[i][j]<=arr[i][j+1])
					flag = 0;
			if(flag) printf("%d\n",arr[i][j]);
		}
	}
}
