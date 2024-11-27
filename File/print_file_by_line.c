#include <stdio.h>
#include <assert.h>
#define maxn 50
int main() {
	FILE *fp;
	char string[maxn];
	fp = fopen("charread.c", "r");
	assert(fp != NULL);
	while(fgets(string, maxn, fp) != NULL) {
		fputs(string, stdout);
	}
	fclose(fp);
	return 0;
}
