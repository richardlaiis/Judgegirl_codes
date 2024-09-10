#include <stdio.h>
int main() {
	long long x;
	scanf("%ld",&x);
	int ans=0;
	if(x<=0) ans=-100;
	else {
		if(x%3==0) ans+=3;
		if(x%5==0) ans+=5;
		if(x>=100 && x<=200) ans+=50;
		else ans-=50;
	}
	printf("%d\n",ans);
}
