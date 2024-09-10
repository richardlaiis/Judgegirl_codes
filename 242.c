#include <stdio.h>
#define int long long
int dist(int a,int b,int c,int d) {
	return (c-a)*(c-a)+(d-b)*(d-b);
}
signed main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		int x[3],y[3],r[3];
		for(int i = 0; i < 3; i++) {
			scanf("%lld%lld%lld",&x[i],&y[i],&r[i]);
		}
		int p1=0,p3=0;
		for(int i = 0; i < 3; i++) {
			for(int j = x[i]-r[i]; j <= x[i]+r[i]; j++) {
				for(int k = y[i]-r[i]; k <= y[i]+r[i]; k++) {
					p1 += (dist(j,k,x[i],y[i])<=r[i]*r[i] && dist(j,k,x[(i+1)%3],y[(i+1)%3])>r[(i+1)%3]*r[(i+1)%3] && dist(j,k,x[(i+2)%3],y[(i+2)%3])>r[(i+2)%3]*r[(i+2)%3]  
);
					p3 += (dist(j,k,x[i],y[i])<=r[i]*r[i] && dist(j,k,x[(i+1)%3],y[(i+1)%3])<=r[(i+1)%3]*r[(i+1)%3] && dist(j,k,x[(i+2)%3],y[(i+2)%3])<=r[(i+2)%3]*r[(i+2)%3]);  
				}
			}
		}
		printf("%d\n",p1+p3/3);
	}
}
