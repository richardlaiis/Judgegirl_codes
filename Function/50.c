#include <stdio.h>
#include <stdbool.h>
int max(int x, int y) {
	if(x>=y) return x;
	return y;
}
int min(int x, int y) {
	if(x<=y) return x;
	return y;
}
int abs(int x) {
	return (x>0)?x:(-x);
}
bool overlap(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
	if(x1 > x4 || x3 > x2 || y1 > y4 || y3 > y2) return 0;
	return 1;
}
int main() {
	int l1,b1,r1,t1;
	int l2,b2,r2,t2;
	int l3,b3,r3,t3;
	scanf("%d%d%d%d",&l1,&b1,&r1,&t1);
	scanf("%d%d%d%d",&l2,&b2,&r2,&t2);
	scanf("%d%d%d%d",&l3,&b3,&r3,&t3);
	int area1 = abs(l1-r1)*abs(b1-t1);
	int area2 = abs(l2-r2)*abs(b2-t2);
	int area3 = abs(l3-r3)*abs(b3-t3);
	
	int area12 = 0, area23 = 0, area13 = 0, area123 = 0;
	int maxl, maxb, minr, mint;
	if(overlap(l1,b1,r1,t1,l2,b2,r2,t2)==1) {
		maxl = max(l1, l2);
		maxb = max(b1, b2);
		minr = min(r1, r2);
		mint = min(t1, t2);
		area12 = abs(maxl-minr)*abs(maxb-mint);
	}
	if(overlap(l2,b2,r2,t2,l3,b3,r3,t3)) {
		maxl = max(l2, l3);
		maxb = max(b2, b3);
		minr = min(r2, r3);
		mint = min(t2, t3);
		area23 = abs(maxl-minr)*abs(maxb-mint);
	}
	if(overlap(l1,b1,r1,t1,l3,b3,r3,t3)) {
		maxl = max(l1, l3);
		maxb = max(b1, b3);
		minr = min(r1, r3);
		mint = min(t1, t3);
		area13 = abs(maxl-minr)*abs(maxb-mint);
	}
	if(overlap(maxl, maxb, minr, mint, l2, b2, r2, t2)) {
		maxl = max(maxl, l2);
		maxb = max(maxb, b2);
		minr = min(minr, r2);
		mint = min(mint, t2);
		area123 = abs(maxl-minr)*abs(maxb-mint);
	}
	printf("%d\n", area1+area2+area3-area12-area23-area13+area123);

}
