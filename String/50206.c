#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define maxn 100001

int main() {
	char s[maxn];
	char token[4000][40];
	int idx = 0;
	fgets(s, maxn, stdin);
	char *p = strtok(s, " ");
	while(p != NULL) {
		strcpy(token[idx++], p);
		p = strtok(NULL, " ");
	}
	//for(int i = 0; i < idx; i++) printf("%s\n",token[i]);
	char pattern[50000][4];
	int cnt[50000] = {0};
	int n = 0;
	for(int i = 0; i < idx; i++) {
		int m = strlen(token[i]);
		if(m < 3) continue;
		for(int j = 0; j < m-2; j++) {
			char tmp[4];
			for(int k = 0; k < 3; k++) tmp[k] = token[i][j+k];

		}
	}
}
