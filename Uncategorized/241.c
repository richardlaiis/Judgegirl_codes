#include <stdio.h>
int main() {
	int a,b,c,d,e,f,g,h;
	scanf("%d%d%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f,&g,&h);
	int cr1=a*d-b*c;
	int cr2=c*f-d*e;
	int cr3=e*h-f*g;
	int cr4=b*g-a*h;
	int ans = ((cr1>0 && cr2>0 && cr3>0 && cr4>0) || (cr1<0 && cr2<0 && cr3<0 && cr4<0));
	printf("%d\n",ans);
}
