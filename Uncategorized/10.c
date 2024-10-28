#include <stdio.h>
int main() {
	long long n,i;
	scanf("%lld%lld",&n,&i);
	long long ans=1;
	while(i--) ans*=n;
	printf("%lld\n",ans);
}
