#include <stdio.h>
#define int long long
int fac(int x) {
	int res = 1;
	for(int i = 1; i <= x; i++) res*=i;
	return res;
}
int c(int a, int b) {
	return fac(a)/(fac(b)*fac(a-b));
}
signed main() {
	int n,m;
	scanf("%lld%lld",&n,&m);
	int ans = 0;
	for(int i = 0; i <= m; i++) {
		ans += c(n,i);
	}
	printf("%lld\n",ans);
}
