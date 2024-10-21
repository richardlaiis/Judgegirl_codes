#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define maxn 100005
int compare(const void *ptr1, const void *ptr2) {
	return strcmp(((char *)ptr1), ((char *)ptr2));
}
int main() {
	char tmp[maxn];
	char input[maxn] = "";
	while(fgets(tmp, maxn, stdin)) {
		strcat(input, tmp);
	}
	char de[] = " .,!?;:\n";
	char token[2000][70];
	int idx = 0;
	char* start = input;
	start = strtok(start, de);
	
	while(start != NULL) {
		strcpy(token[idx++], start);
		start = strtok(NULL, de);
	}
	//for(int i = 0; i < idx; i++) {
	//	printf("%s\n", token[i]);
	//}
	char suffix[20][5] = {"ed","tion","ness","ful","ing","ly","able","ous","ish","ive","less","ism","ist","ize","ment","ship","ary","ical","ence","hood"};
	qsort(suffix, 20, sizeof(char)*5, compare);
	//for(int i = 0; i < 20; i++) printf("%s\n", suffix[i]);
	//printf("%s\n", input);
	int frequency[20] = {0};
	int suffixlen[20], tokenlen[idx];
	for(int i = 0; i < 20; i++) suffixlen[i] = strlen(suffix[i]);
	for(int i = 0; i < idx; i++) tokenlen[i] = strlen(token[i]);
	for(int i = 0; i < idx; i++) {
		int n = tokenlen[i];
		for(int j = 0; j < 20; j++) {
			int m = suffixlen[j];
			bool flag = 1;
			//printf("%d %d\n",n,m);
			for(int k = 0; k < m; k++) {
				if(suffix[j][k] != token[i][n-m+k]) flag = 0;
			}
			//printf("\n");
			if(flag) {
				frequency[j]++;
				break;
			}
		}
	}
	for(int i = 0; i < 20; i++) {
		if(frequency[i] > 0) {
			printf("%s:\n",suffix[i]);
			printf("Frequency: %d\n",frequency[i]);
		}
	}
}
