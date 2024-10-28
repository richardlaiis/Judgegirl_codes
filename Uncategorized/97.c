#include <stdio.h>
struct bike {
	int x,y,m;
};
int abs(int x) {
	return (x>0)?x:(-x);
}
int dis(int x1,int y1,int x2,int y2) {
	return abs(x1-x2)+abs(y1-y2);
}
int main() {
	int n,m;
	scanf("%d",&n);
	int cnt[n];
	for(int i = 0; i < n; i++) cnt[i]=0;
	struct bike a[n];
	for(int i = 0; i < n; i++) {
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].m);
	}
	scanf("%d",&m);
	for(int l = 0; l<m; l++) {
		int i,j;
		scanf("%d%d",&i,&j);
		int cur_dis=1000000000, cur_x, cur_y, cur_idx;
		for(int k=0;k<n;k++) {
			if(cnt[k]<a[k].m) {
				if(dis(i,j,a[k].x,a[k].y)<cur_dis) {
					cur_dis=dis(i,j,a[k].x,a[k].y);
					cur_x = a[k].x;
					cur_y = a[k].y;
					cur_idx = k;
				}else if(dis(i,j,a[k].x,a[k].y)==cur_dis) {
					if(a[k].x!=cur_x) {
						if(a[k].x<cur_x) {
							cur_x = a[k].x;
							cur_y = a[k].y;
							cur_idx = k;
						}
					}else {
						if(a[k].y<cur_y) {
							cur_x = a[k].x;
							cur_y = a[k].y;
							cur_idx = k;
						}
					}
				}
			}
		}
		cnt[cur_idx]++;
	}
	for(int i = 0; i < n; i++) printf("%d\n", cnt[i]);
}
