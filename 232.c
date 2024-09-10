#include <stdio.h>
int main() {
	int year, day;
	scanf("%d%d",&year,&day);
	int month[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
	if((year%400==0) || (year%4==0 && year%100!=0)) month[2]=29;
	int presum[13];
	for(int i = 0; i < 13; i++) presum[i]=0;
	for(int i = 1; i < 13; i++) presum[i]=month[i]+presum[i-1];
	int n;
	scanf("%d",&n);
	while(n--) {
		int m, d, past;
		scanf("%d%d", &m, &d);
		if(m==1) {
			if(d<=31 && d>=1) {
				past = d-1;
			}else {
				printf("%d\n",-2);
				continue;
			}
		}else if(m>=2 && m<=12) {
			if(d<=month[m] && d>=1) {
				past = presum[m-1]+d-1;
			}else {
				printf("%d\n", -2);
				continue;
			}
		}else {
			printf("%d\n",-1);
			continue;
		}
		int ans;
		ans = (day+past%7)%7;
		printf("%d\n",ans);
	}
}
