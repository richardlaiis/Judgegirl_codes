// The usage of sscanf and sprintf
#include <stdio.h>
//#include <string.h>
int main(void) {
	int grade;
	char name[20];
	scanf("%d%s", &grade, name);
	
	char result[30];
	sprintf(result, "%s got a score of %d", name, grade);

	printf("%s\n", result);
	
	char invname[20];
	int invgrade;
	sscanf(result, "%s got a score of %d", invname, &invgrade);
	printf("%s %d", invname, ++invgrade);
}
