#include <stdio.h>
#define maxn 100
int main() {
	int n,m, a[2*maxn], b[2*maxn], c[2*maxn];
	for(int i = 0; i < 2*maxn; i++) {
		a[i] = 0;
		b[i] = 0;
		c[i] = 0;
	}
	scanf("%d",&n);
	for(int i = 0; i < n; i++) {
		scanf("%d",&a[n-1-i]);
	}
	scanf("%d",&m);
	for(int i = 0; i < m; i++) {
		scanf("%d",&b[m-1-i]);
	}
	int k = n+m-2;
	for(int i = k; i >= 1; i--) {
		for(int j = 0; j<=i; j++) {
			c[i] += a[j]*b[i-j];
		}
	}
	c[0] = a[0]*b[0];
	for(int i = k; i >= 0; i--) {
		if(i == 0) printf("%d\n",c[i]);
		else printf("%d ",c[i]);
	}
}
