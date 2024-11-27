#include <stdio.h>
void dump(char *filename, char *mode) {
	FILE *fp = fopen(filename, mode);
	int c;
	int count = 0;
	while((c = fgetc(fp)) != EOF) {
		printf("%02x ", c);
		count++;
		if(count % 8 == 0) fputc('\n', stdout);
	}
	fclose(fp);
	printf("%d bytes in file %s", count, filename);
}
int main() {
	FILE *fp = fopen("binary", "wt");
	fputs("12345\n", fp);
	fclose(fp);
	dump("binary", "r");
}
