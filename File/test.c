#include <stdio.h>
int main() {
	FILE *fp, *fp1;
	fp = fopen("testfile", "a+");
	for(int i = 0; i < 5; i++) {
		fputc('g', fp);
	}
	fclose(fp);
	fp = fopen("testfile", "r");
	fp1 = fopen("newfile", "w");
	int c;
	while((c = fgetc(fp)) != EOF) fputc(c, fp1);
	
	fclose(fp);
	fclose(fp1);

	fp1 = fopen("newfile", "r");
	while((c = fgetc(fp1)) != EOF) fputc(c, stdout);
}
