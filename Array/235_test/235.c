#include <stdio.h>
#define int long long
typedef struct Frac {
	int nu;
	int de;
} frac;
typedef struct Pins {
	int l;
	int r;
} pins;
int abs(int x) {
	return (x>0)?x:(-x);
}
int gcd(int a, int b) {
	a = abs(a);
	b = abs(b);
	while(a%b != 0) {
		int k = a%b;
		a = b;
		b = k;
	}
	return b;
}
frac add(frac a, frac b) {
	int new_nu = a.nu*b.de+b.nu*a.de;
	int new_de = a.de*b.de;
	int gcdn = gcd(new_nu, new_de);
	new_nu /= gcdn;
	new_de /= gcdn;
	frac res = {abs(new_nu), abs(new_de)};
	return res;
}
frac mul(frac a, frac b) {
	int new_nu = a.nu*b.nu;
	int new_de = a.de*b.de;
	int gcdn = gcd(new_nu, new_de);
	new_nu /= gcdn;
	new_de /= gcdn;
	frac res = {new_nu, new_de};
	return res;

}
void print(frac x) {
	printf("%lld/%lld\n",x.nu,x.de);
	return ;
}
signed main() {
	/*
	frac a = {6,17};
	frac b = {9,85};
	frac result = add(a, b);
	printf("%d/%d\n",result.nu,result.de);
	*/
	int n; 
	scanf("%lld",&n);
	pins pin[n+1][n+1];
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= i; j++) {
			scanf("%lld%lld",&pin[i][j].l,&pin[i][j].r);
		}
	}
	frac chance[n+2][n+2];
	for(int i = 1; i <= n+1; i++) {
		for(int j = 1; j <= n+1; j++) {
			chance[i][j].nu = 0;
			chance[i][j].de = 1;
		}
	}
	frac init = {1,1};
	chance[1][1] = init;
	for(int i = 2; i <= n+1; i++) {
		for(int j = 1; j <= i; j++) {
			if(j == 1) {
				frac c = {pin[i-1][j].l, pin[i-1][j].l+pin[i-1][j].r};
				frac tmp = mul(chance[i-1][j], c);
				chance[i][j] = tmp;
			}else if(j == i) {
				frac c = {pin[i-1][j-1].r, pin[i-1][j-1].l+pin[i-1][j-1].r};
				frac tmp = mul(chance[i-1][j-1], c);
				chance[i][j] = tmp;
			}else {
				frac tmp1 = {pin[i-1][j-1].r, pin[i-1][j-1].l+pin[i-1][j-1].r};
				frac tmp2 = {pin[i-1][j].l, pin[i-1][j].l+pin[i-1][j].r};
				frac left = mul(chance[i-1][j-1], tmp1);
				frac right = mul(chance[i-1][j], tmp2);
				chance[i][j] = add(left, right);
			}
		}
	}
	for(int i = 1; i <= n+1; i++) print(chance[n+1][i]);

}
