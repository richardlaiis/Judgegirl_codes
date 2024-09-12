#include <stdio.h>
int main() {
	int m,n,x1,y1,e1,n1,f1,x2,y2,e2,n2,f2;
	scanf("%d%d%d%d%d%d%d%d%d%d%d%d",&m,&n,&x1,&y1,&e1,&n1,&f1,&x2,&y2,&e2,&n2,&f2);
	int t = 0;
	int dir1=0, dir2=1;
	int tmp1=n1, tmp2=e2; 
	while(1) {
		if(f1==0 && f2==0) {
			break;
		}
		t++;
		if(f1>0) {
			f1--;
			if(dir1==0) {
				tmp1--;
				y1+=1;
				if(tmp1==0) {
					tmp1 = e1;
					dir1 = 1;
				}
				if(y1==n) y1=0;
			}else {
				tmp1--;
				x1+=1;
				if(tmp1==0) {
					tmp1 = n1;
					dir1 = 0;
				}
				if(x1==m) x1=0;
			}
		}
		if(f2>0) {	
			f2--;
			if(dir2==0) {
				tmp2--;
				y2+=1;
				if(tmp2==0) {
					tmp2 = e2;
					dir2 = 1;
				}
				if(y2==n) y2=0;
			}else {
				tmp2--;
				x2+=1;
				if(tmp2==0) {
					tmp2 = n2;
					dir2 = 0;
				}
				if(x2==m) x2=0;
			}
		}
		if(x1==x2 && y1==y2) {
			printf("robots explode at time %d\n",t);
			return 0;
		}
	}
	printf("robots will not explode\n");
}
