#include <stdio.h>
int area(int ldx,int ldy,int rtx,int rty) {
	return (rtx-ldx)*(rty-ldy);
}
int main() {
	int x1,y1,x2,y2;
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	int x3,y3,x4,y4;
	scanf("%d%d%d%d",&x3,&y3,&x4,&y4);
	
	int x5,y5,x6,y6;


	if(x3>x1 && x3<x2) {
		if(y3>y1 && y3<y2) {
			x5 = x3;
			y5 = y3;
			x6 = x2;
			y6 = y2;	
		}else if(y1>y3 && y1<y4) {
			x5 = x3;
			y5 = y3;
			x6 = x2;
			y6 = y2;	
			
		}
	}else if(x1>x3 && x1<x4) {
		if(y3>y1 && y3<y2) {
			x5 = x3;
			y5 = y3;
			x6 = x2;
			y6 = y2;	
		}else if(y1>y3 && y1<y4) {
			x5 = x3;
			y5 = y3;
			x6 = x2;
			y6 = y2;	
			
		}
	}

	int a1,a2,a3,a4;
	int b1,b2,b3,b4;
	int ab1,ab2,ab3,ab4;
	
	a1 = (x2>0 && y2>0)?x2*y2:0;
	b1 = (x4>0 && y4>0)?x4*y4:0;

}
