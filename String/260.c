#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char* substr(int start, int end, char string[]) {
	int cnt = end-start+1;
	char* dest = (char*)malloc((cnt+1)*sizeof(char));
	strncpy(dest, string+start, cnt);
	dest[cnt] = '\0';
	return dest;
}
int main() {
	char hello[] = "Hello, world!";
	char *result = substr(3, 8, hello);
	printf("%s\n", result);
	free(result);
}
