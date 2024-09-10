#include <stdio.h>
int ad[10], bd[10];
int main() {
	int x,y,a=0,b=0;
	scanf("%d%d",&x,&y);
	for(int i = 0; i < 10; i++) {
		ad[i]=-1;
		bd[i]=-1;
	}
	for(int i = 1; i <= 4; i++) {
		ad[x%10]=i;
		bd[y%10]=i;
		x/=10;
		y/=10;
	}
	for(int i = 0; i <10; i++) {
		if(ad[i]!=-1 && bd[i]!=-1) {
			a+=(ad[i]==bd[i]);
			b+=(ad[i]!=bd[i]);
		}
		//printf("%d %d",ad[i],bd[i]);
		//printf("\n");
	}
	printf("%dA%dB\n", a, b);
}
