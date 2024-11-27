#include <stdio.h>
int main() {
	FILE *fp1 = fopen("owo", "w+");
	for(int i = 0; i < 25; i++) {
		fputc('g', fp1);
	}
	fclose(fp1);
	fp1 = fopen("owo", "r");
	char c;
	while((c = fgetc(fp1)) != EOF) {
		//printf("%d\n", c);
		fputc(c, stdout);
	}
	fclose(fp1);
	fp1 = fopen("owo", "r");
	FILE *fp2 = fopen("XD", "a+");
	while((c = fgetc(fp1)) != EOF)
		fputc(c, fp2);
	fclose(fp2);
	fp2 = fopen("XD", "r+");
	for(int i = 0; i < 7; i++) {
		fputc('@', fp2);
	}
	fclose(fp2);
}
