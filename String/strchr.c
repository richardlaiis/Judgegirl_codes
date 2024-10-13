#include <stdio.h>
#include <string.h>
#define maxn 50
int main() {
	char pathname[maxn];
	scanf("%s",&pathname);
	char file[maxn][maxn];
	int cnt = 0;
	char *start = pathname;
	if(*start == '/') start++;
	while(start != NULL) {
		char *slash  = strchr(start, '/');
		if(slash == NULL) {
			strcpy(file[cnt], start);
			cnt++;
			start = NULL;
		}else {
			strncpy(file[cnt], start, slash-start);
			file[cnt][slash-start] = '\0';
			cnt++;
			start = slash+1;
		}
	}
	for(int i = 0; i<cnt; i++) {
		printf("%s\n",file[i]);
	}
}
