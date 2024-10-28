#include <stdio.h>
int cross(int x1,int y1,int x2,int y2) {
	return x1*y2-x2*y1;
}

int main() {
	int n;
	scanf("%d",&n);
	while(n--) {
		int a,b,c,d,e,f,g,h;
		scanf("%d%d%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f,&g,&h);
		int k=cross(c-a,d-b,e-a,f-b), l=cross(c-a,d-b,g-a,h-b), m=cross(e-a,f-b,g-a,h-b);
		if((k>0 && l<0 && m<0) || (k<0 && l>0 && m>0)) {
			c^=e,e^=c,c^=e;
			d^=f,f^=d,d^=f;		
		}else if((k<0 && l<0 && m>0) || (k>0 && l>0 && m<0)) {
			e^=g,g^=e,e^=g;
			f^=h,h^=f,f^=h;
		}
		int l12,l13,l14,l23,l24,l34;
		l12=(a-c)*(a-c)+(b-d)*(b-d);
		l13=(a-e)*(a-e)+(b-f)*(b-f);
		l14=(a-g)*(a-g)+(b-h)*(b-h);
		l23=(c-e)*(c-e)+(d-f)*(d-f);
		l24=(c-g)*(c-g)+(d-h)*(d-h);
		l34=(e-g)*(e-g)+(f-h)*(f-h);
		if(l12==l23 && l23==l34 && l34==l14) {
			if(l13==l12+l23) printf("square\n");
			else printf("diamond\n");
		}else {
			if(l13==l12+l23 && l24==l12+l14 && l13==l14+l34 && l24==l23+l34) printf("rectangle\n");
			else printf("other\n");
		}
	}
}
