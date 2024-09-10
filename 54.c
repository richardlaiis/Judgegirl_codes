#include <stdio.h>
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	int an[2],am[7];
	for(int i = 0; i < 2; i++) {
		an[i]=n%10;
		//am[i]=m%10;
		n/=10;
	}
	for(int i = 0; i < 7; i++) {
		am[i]=m%10;
		m/=10;
	}
	int ans = 0;
	for(int i = 0; i < 6; i++) {
		ans += (an[0]==am[i] && an[1]==am[i+1]);
	}
	printf("%d\n",ans);
}
