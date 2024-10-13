#include <stdio.h>
#include <string.h>
#define maxn 50
int main() {
	char sentence[maxn];
	scanf("%s", &sentence);
	printf("%s\n", sentence);
	const char* d = "/";
	char *token;
	token = strtok(sentence, d);
	while(token != NULL) {
		printf("%s\n", token);
		token = strtok(NULL, d);
	}
}
