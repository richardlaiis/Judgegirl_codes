#include <stdio.h>
int main() {
	int X,Y,x1,y1,x2,y2,dx1,dy1,dx2,dy2,t;
	scanf("%d%d%d%d%d%d%d%d%d%d%d",&X,&Y,&x1,&y1,&x2,&y2,&dx1,&dy1,&dx2,&dy2,&t);
	while(t--) {
		x1+=dx1,y1+=dy1,x2+=dx2,y2+=dy2;
		if((x1==X && y1==Y) || (x1==1 && y1==Y) || (x1==X && y1==1) || (x1==1 && y1==1)) dx1=-dx1,dy1=-dy1;
		else if(x1==X || x1==1) dx1=-dx1;
		else if(y1==Y || y1==1) dy1=-dy1;

		if((x2==X && y2==Y) || (x2==1 && y2==Y) || (x2==X && y2==1) || (x2==1 && y2==1)) dx2=-dx2,dy2=-dy2;
		else if(x2==X || x2==1) dx2=-dx2;
		else if(y2==Y || y2==1) dy2=-dy2;

		if(x1==x2 && y1==y2) {
			dx1^=dx2,dx2^=dx1,dx1^=dx2;
			dy1^=dy2,dy2^=dy1,dy1^=dy2;
		}
	}
	printf("%d\n%d\n%d\n%d\n",x1,y1,x2,y2);
}
