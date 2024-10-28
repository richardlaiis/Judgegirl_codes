#include <stdio.h>
int sp[3], fp[3];
int check(int x) {
	for(int i = 0; i < 3; i++) {
		if(x == sp[i]) return 2000000;
	}
	for(int i = 0; i < 3; i++) {
		if(x == fp[i]) return 200000;
		else if(x%10000000 == fp[i]%10000000) return 40000;
		else if(x%1000000 == fp[i]%1000000) return 10000;
		else if(x%100000 == fp[i]%100000) return 4000;
		else if(x%10000 == fp[i]%10000) return 1000;
		else if(x%1000 == fp[i]%1000) return 200;
	}
	return 0;
}
int main() {
	for(int i = 0; i < 3; i++) scanf("%d", &sp[i]);
	for(int i = 0; i < 3; i++) scanf("%d", &fp[i]);
	long long int n, ans = 0;
	while(scanf("%d",&n) != EOF) ans += check(n);
	printf("%d\n", ans);
}
