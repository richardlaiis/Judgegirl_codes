#include <stdio.h>
int main() {
	char value = 0;
	char test = 1<<3;
	value |= test;
	int k = value;
	printf("%d\n", k);
	//printf("%d\n", value);
	//value &= (255 ^ test);
	if((value & test) != 0) printf("yes.\n");
}
