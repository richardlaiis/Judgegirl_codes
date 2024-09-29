#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main() {
	char input[500000];
	fread(input, sizeof(char), 500000, stdin);
	int sentence_count = 0;
	int n = strlen(input);
	for(int i = 0; i < n; ++i) {
		if(input[i] == '.') {
			if((input[i+1] == ' ' && input[i+2] == ' ') || (input[i+1] == '\n') || (input[i+1] == '\0')) ++sentence_count;
		}
	}
	printf("%d\n", sentence_count);
}
