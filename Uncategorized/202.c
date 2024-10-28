#include <stdio.h>
int abs(int x) {
	if(x>0) return x;
	else return -x;
}
int gcd(int a, int b) {
	int k;
	int aa=abs(a), bb=abs(b);
	if(aa==0) return bb;
	if(bb==0) return aa;
	while(aa%bb) {
		k=aa%bb;
		aa=bb;
		bb=k;
	}
	return bb;
}
int main() {
	int a,b,c,d,e,f,g;
	scanf("%d%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f,&g);
	int x,y,z,w;
	if(a>0) {
		x=a*c+b;
		y=c;
		int p=gcd(x,y);
		x/=p;
		y/=p;
	}else {	
		x=a*c-b;
		y=c;
		int p=gcd(x,y);
		x/=p;
		y/=p;
	}
	
	if(e>0) {
		z=e*g+f;
		w=g;
		int p=gcd(z,w);
		z/=p;
		w/=p;
	}else {	
		z=e*g-f;
		w=g;
		int p=gcd(z,w);
		z/=p;
		w/=p;
	}
	int k,l,m,i,j;
	if(d==0) {
		if(y==w) {
			i=x+z,j=y;
			int r=gcd(i,j);
			i/=r;
			j/=r;
		}else {
			i=x*w+z*y, j=y*w;
			int r=gcd(i,j);
			i/=r;
			j/=r;
		}

		if(i>0 )printf("%d\n%d\n%d\n", i/j, i%j, j);
		else printf("%d\n%d\n%d\n", -abs(i)/j, abs(i)%j, j);
	}else if(d==1) {	
		if(y==w) {
			i=x-z,j=y;
			int r=gcd(i,j);
			i/=r;
			j/=r;
		}else {
			i=x*w-z*y, j=y*w;
			int r=gcd(i,j);
			i/=r;
			j/=r;
		}
		if(i>0 )printf("%d\n%d\n%d\n", i/j, i%j, j);
		else printf("%d\n%d\n%d\n", -abs(i)/j, abs(i)%j, j);
	}else if(d==2) {
		int i=x*z, j=y*w;
		if(i>0 && j<0) i=-i, j=-j;
		int r=gcd(i,j);
		i/=r;
		j/=r;
		if(i>0 )printf("%d\n%d\n%d\n", i/j, i%j, j);
		else printf("%d\n%d\n%d\n", -abs(i)/j, abs(i)%j, j);
	}else {
		int i=x*w, j=y*z;
		int r=gcd(i,j);
		i/=r;
		j/=r;
		if((i>0 && j<0) || (i<0 && j<0)) i=-i, j=-j;
		if(i>0 )printf("%d\n%d\n%d\n", i/j, i%j, j);
		else printf("%d\n%d\n%d\n", -abs(i)/j, abs(i)%j, j);
	}
}
