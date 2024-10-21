#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
	int n = 0;
	char s[1001], first[1001], prev[1001];
	int tot_length = 0;
	while(scanf("%s",&s) != EOF) {
		if(n == 0) {
			tot_length += strlen(s);
			strcpy(first, s);
			strcpy(prev, s);
			n = 1;
			continue;
		}
		int m = strlen(s);
		tot_length += m;
		int k = strlen(prev);
		for(int i = 0; i < m; i++) {
			bool find = 0;
			for(int j = k-1; j >= 0; j--) {
				if(s[i] == prev[j]) {
					find = 1;
					tot_length -= i;
					tot_length -= (k-1-j);
					break;
				}
			}
			if(find) {
				break;
			}
		}
		tot_length--;
		strcpy(prev, s);
	}
	int m = strlen(first);
	int k = strlen(prev);
	bool find = 0;
	for(int i = 0; i < m; i++) {
		for(int j = k-1; j >= 0; j--) {
			if(first[i] == prev[j]) {
				find = 1;
				tot_length -= i;
				tot_length -= (k-1-j);
				break;
			}
		}
		if(find) {
			break;
		}
	}
	tot_length--;
	printf("%d\n", tot_length);
}
