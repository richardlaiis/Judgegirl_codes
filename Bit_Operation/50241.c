#include <stdio.h>
typedef unsigned long long ull;
int main() {
	int n;
	scanf("%d",&n);
	for(int i = 0; i < n; i++) {
		ull x;
		scanf("%llu",&x);
		char s[12];
		for(int j = 0; j < 12; j++) {
			s[j] = 'a'+ (x >> (5*j))%32;
		}
		printf("%s",s);
	}
	printf("\n");
}
