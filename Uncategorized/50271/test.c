#include <stdio.h>
#include <string.h>
int main() {
	char s[100];
	while(fgets(s, 100, stdin) != NULL) {
		printf("%s\n",s);
	}
	printf("EOF");
}
