#include <stdio.h>
#define int long long
int gcd(int a, int b) {
	while(a%b!=0) {
		int k = a%b;
		a=b;
		b=k;
	}
	return b;
}
struct pin {
	int a,b;
};
signed main() {
	int N;
	scanf("%lld",&N);
	struct pin pins[N+1][N+1];
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= i; j++) {
			scanf("%lld%lld",&pins[i][j].a, &pins[i][j].b);
		}
	}
	struct pin chance[N+5][N+5];
	for(int i = 1; i <= N+5; i++) {
		for(int j = 1; j<= N+5; j++) {
			chance[i][j].a = 0;
			chance[i][j].b = 1;
		}
	}
	chance[1][1].a = 1;
	chance[1][1].b = 1;
	int tmp;
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= i; j++) {
			int m, n;
			m = chance[i][j].a;
			n = chance[i][j].b;
			int k, l;
			k = pins[i][j].a;
			l = pins[i][j].b;
			int x, y, z, w;
			x = chance[i+1][j].a;
			y = chance[i+1][j].b;
			z = chance[i+1][j+1].a;
			w = chance[i+1][j+1].b;
			int u = m*k, v = n*(k+l);
			tmp = gcd(u,v);
			u/=tmp, v/=tmp;
			int e = x*v+u*y, f = v*y;
			tmp = gcd(e,f);
			e/=tmp, f/=tmp;
			chance[i+1][j].a=e, chance[i+1][j].b=f;
			
			u = m*l, v = n*(k+l);
			tmp = gcd(u,v);
			u/=tmp, v/=tmp;
			e = z*v+w*u, f = w*v;
			tmp = gcd(e,f);
			e/=tmp, f/=tmp;
			chance[i+1][j+1].a=e, chance[i+1][j+1].b=f;
			//int x = chance[i][j].a*pins[i][j].a, y = chance[i][j].a*pins[i][j].b, z = chance[i][j].b*(pins[i][j].a+pins[i][j].b);
			//int k = chance[i+1][j].a, l = chance[i+1][j].b, m = chance[i+1][j+1].a, n = chance[i+1][j+1].b;
			//chance[i+1][j].a = k*z+x*l, chance[i+1][j].b = z*l;
			//int tmp = gcd(chance[i+1][j].a, chance[i+1][j].b);
			//chance[i+1][j].a/=tmp, chance[i+1][j].b/=tmp;	
			//printf("%d %d %d %d %d %d %d\n",x,y,z,k,l,m,n);
			//chance[i+1][j+1].a = y*n+m*z, chance[i+1][j+1].b = z*n;
			//tmp = gcd(chance[i+1][j+1].a, chance[i+1][j+1].b);
			//chance[i+1][j+1].a/=tmp, chance[i+1][j+1].b/=tmp;	
		}
	}
	//for(int i = 1; i <= N+1; i++) {
	//	for(int j = 1; j<= N+1; j++) {
	//		printf("%lld/%lld ", chance[i][j].a, chance[i][j].b);
	//	}
	//	printf("\n");
	//}
	//for(int i = 1; i <= N; i++) {
	//	printf("%d/%d ", chance[N][i].a, chance[N][i].b);
	//}
	for(int i = 1; i <= N+1; i++) {
		printf("%lld/%lld\n",chance[N+1][i].a,chance[N+1][i].b);
	}
	
}

