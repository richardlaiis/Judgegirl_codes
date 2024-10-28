#include <stdio.h>
int main() {
	int x1,y1,x2,y2,x3,y3;
	int n;
	scanf("%d",&n);
	while(n--) {
		scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3);
		int a_2 = (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
		int b_2 = (x1-x3)*(x1-x3)+(y1-y3)*(y1-y3);
		int c_2 = (x3-x2)*(x3-x2)+(y3-y2)*(y3-y2);
		if((a_2-b_2)*(a_2-c_2)*(b_2-c_2)) {
			if(a_2>b_2) b_2^=a_2^=b_2^=a_2;
			if(b_2>c_2) b_2^=c_2^=b_2^=c_2;
			if(a_2>c_2) c_2^=a_2^=c_2^=a_2;
			if(a_2+b_2==c_2) printf("%s\n","right");
			else if(a_2+b_2>c_2) printf("%s\n","acute");
			else printf("%s\n","obtuse");
		}else {
			printf("%s\n", "isosceles");
		}
	}
}
