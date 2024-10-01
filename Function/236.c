#include <stdio.h>
int gcd(int a, int b) {
	int k;
	while(a%b) {
		k = a%b;
		a = b;
		b = k;
	}
	return b;
}
int main() {
	int n, result = 1;
	while(scanf("%d",&n)!=EOF) result = result*n/gcd(result,n);
	printf("%d\n",result);
}
