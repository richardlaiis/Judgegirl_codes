#include <stdio.h>
int main() {
	int n;
	scanf("%d",&n);
	int a=0,b=0,c=0;
	while(n--) {
		int x;
		scanf("%d",&x);
		x%=3;
		switch(x) {
			case 0:
				a++;
				break;
			case 1:
				b++;
				break;
			case 2:
				c++;
				break;
			default:
				break;
		}
	}
	printf("%d %d %d\n",a,b,c);
}
