#include <stdio.h>
#include <assert.h>
int main() {
	FILE *fp;
	fp = fopen("uwu", "a+");
	assert(fp != NULL);
	fclose(fp);
}
