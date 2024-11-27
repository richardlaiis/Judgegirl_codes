#include <stdio.h>
int main(void) {
	FILE *fp = fopen("file_eof", "w");
	char input[20];
	while(scanf("%s", input) != EOF) {
		fputs(input, fp);
		fputc('\n', fp);
	}
	fclose(fp);
	fp = fopen("file_eof", "r");
	char cur[20];
	while(!feof(fp)) {
		fputs(cur, stdout);
		fgets(cur, 20, fp);
		//fputc('\n', stdout);
	}
	fclose(fp);
}	
