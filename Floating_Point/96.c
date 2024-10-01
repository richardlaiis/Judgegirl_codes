#include <stdio.h>
#define pi 3.1415926
int main() {
	double a,b,c;
	scanf("%lf%lf%lf",&a,&b,&c);
	double area = pi*0.75*c*c;
	area += (c>a)?(pi*0.25*(c-a)*(c-a)):0;	
	area += (c>b)?(pi*0.25*(c-b)*(c-b)):0;
	printf("%lf\n",area);
}
