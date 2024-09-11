#include <stdio.h>
int main() {
	int year, month, firstDay, daycnt;
	scanf("%d%d%d",&year,&month,&firstDay);
	if(firstDay>6 || firstDay<0) {
		printf("invalid\n");
		return 0;
	}
	switch(month) {
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			daycnt = 31;
			break;
		case 4: case 6: case 9: case 11:
			daycnt = 30;
			break;
		case 2:
			if(year%400==0 || (year%4==0 && year%100!=0)) daycnt=29;
			else daycnt=28;
			break;
		default:
			printf("invalid\n");
			return 0;
			break;
	}
	printf(" Su Mo Tu We Th Fr Sa\n");
	printf("=====================\n");
	for(int i = 0; i < firstDay; i++) printf("   ");
	int curDay = 1;
	for(int i = 0; i < 7-firstDay; i++) {
		printf("%3d", curDay);
		curDay++;
	}
	printf("\n");
	int midWeek = (daycnt-curDay)/7;
	int lastDays = (daycnt-curDay)%7;
	for(int i = 0; i < midWeek; i++) {
		for(int j = 0; j < 7; j++) {
			printf("%3d", curDay);
			curDay++;
		}
		printf("\n");
	}
	for(int i = 0; i <= lastDays; i++) {
		printf("%3d", curDay);
		curDay++;
	}
	printf("\n");
	printf("=====================\n");
}
