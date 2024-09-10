#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main() {
	int a,b,c,d,e,f;
	scanf("%d%d%d",&a,&b,&c);
	if(b==0 && c==0) {
		if(a>0) {
			printf("%d %d %d\n",0,0,a);
		}else if(a==0) {
			printf("%d %d %d\n",0,0,0);
		}else {
			printf("%d %d %d\n",a,0,0);
		}
		return 0;
	}else if(a!=0 && b!=0 && c==0) {
		for(int i = -abs(b); i <= abs(b); i++) {
			if(b%i==0 && i+b/i==a) {
				d=0,e=i,f=b/i;
						if(d>e) d^=e,e^=d,d^=e;
						if(e>f) e^=f,f^=e,e^=f;
						if(d>f) d^=f,f^=d,d^=f;
				printf("%d %d %d\n",d,e,f);
				return 0;
			}
		}
	}
	for(int i = -abs(c); i <= abs(c); i++) {
		if(i==0) continue;
		if(c%i==0) {
			int d = i, k=c/i;
			for(int j = -abs(k); j<=abs(k); j++) {
				if(j==0) continue;
				if(k%j==0) {
					e=j;
					f=c/e/d;
					if(d+e+f==a && d*e+e*f+d*f==b) {
						if(d>e) d^=e,e^=d,d^=e;
						if(e>f) e^=f,f^=e,e^=f;
						if(d>f) d^=f,f^=d,d^=f;
						printf("%d %d %d\n",d,e,f);
						return 0;
					}
				}
			}
		}
	}
}
