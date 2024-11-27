#include <stdio.h>
#include <assert.h>
int main() {
	FILE *fp1 = fopen("nums", "w");
	assert(fp1 != NULL);
	for(int i = 0; i < 10; i++) {
		fprintf(fp1, "%d\n", i);
	}
	fclose(fp1);
	FILE *fp2 = fopen("sum", "w");
	fp1 = fopen("nums", "r");
	assert(fp1 != NULL);
	assert(fp2 != NULL);
	
	int sum = 0;
	int n;
	while(fscanf(fp1, "%d", &n) != EOF)
		sum += n;
	fclose(fp1);
	fprintf(fp2, "%d\n", sum);
	fclose(fp2);
}
