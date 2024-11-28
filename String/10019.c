#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main() {
	char str[101];
	while(fgets(str, 101, stdin) != NULL) {
		int idx1 = 0;
		while(isspace(str[idx1++]));
		idx1--;
		int n = strlen(str);
		int idx2 = n-1;
		while(isspace(str[idx2--]));
		idx2++;
		for(int i = idx1; i <= idx2; i++) {
			fputc(str[i], stdout);
		}
		fputc('\n', stdout);
	}
}
