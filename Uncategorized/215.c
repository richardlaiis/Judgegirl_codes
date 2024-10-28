#include <stdio.h>
int main() {
    int s,f,t;
    scanf("%d%d%d",&s,&f,&t);
    int chick, rabbit, crab;
    crab = s-t;
	int flag = ((f-8*crab)/2*2 == (f-8*crab));
    rabbit = (f-8*crab)/2-(s-crab);
    chick = s-crab-rabbit;
	if ((crab>=0 && rabbit>=0 && chick>=0) && flag)
    	printf("%d\n%d\n%d\n", chick, rabbit, crab);
	else
		printf("%d\n",0);
}
