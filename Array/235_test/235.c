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
	
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= i; j++) {
			int x = chance[i][j].a*pins[i][j].a, y = chance[i][j].a*pins[i][j].b, z = chance[i][j].b*(pins[i][j].a+pins[i][j].b);
			int k = chance[i+1][j].a, l = chance[i+1][j].b, m = chance[i+1][j+1].a, n = chance[i+1][j+1].b;
			chance[i+1][j].a = k*z+x*l, chance[i+1][j].b = z*l;
			int tmp = gcd(chance[i+1][j].a, chance[i+1][j].b);
			chance[i+1][j].a/=tmp, chance[i+1][j].b/=tmp;	

			chance[i+1][j+1].a = y*n+m*z, chance[i+1][j+1].b = z*n;
			tmp = gcd(chance[i+1][j+1].a, chance[i+1][j+1].b);
			chance[i+1][j+1].a/=tmp, chance[i+1][j+1].b/=tmp;	
		}
	}
	for(int i = 1; i <= N+1; i++) {
		for(int j = 1; j<= N+1; j++) {
			printf("%lld/%lld ", chance[i][j].a, chance[i][j].b);
		}
		printf("\n");
	}
	//for(int i = 1; i <= N; i++) {
	//	printf("%d/%d ", chance[N][i].a, chance[N][i].b);
	//}
	for(int i = 1; i <= N+1; i++) {
		printf("%lld/%lld\n",chance[N+1][i].a,chance[N+1][i].b);
	}
	
}

