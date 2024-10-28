#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main() {
	char word[127];
	while(scanf("%s",&word) != EOF) {
		int len = strlen(word);
		if(strcmp(word,"the.")==0 || strcmp(word,"of.")==0 || strcmp(word,"at.")==0 || strcmp(word,"and.")==0) {
			printf("\n");
			continue;
		}
		if(strcmp(word,"the")!=0 && strcmp(word,"of")!=0 && strcmp(word,"and")!=0 && strcmp(word,"at")!=0) {
			if(word[len-1]=='.') printf("%c\n",toupper(word[0]),word);
			else printf("%c",toupper(word[0]),word);
		}
	}
}
