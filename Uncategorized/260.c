#include <stdio.h>
#include <string.h>
int main() {
	char input[128];
	char ans[130] = "";
	int curlength = 0;
	while(scanf("%s",&input)!=EOF) {
		int n = strlen(input);
		int samecnt = 0;
		for(int i = n; i >= 1; i--) {
			int flag = 1;
			if(i > curlength) continue;
			for(int j = 0; j < i; j++) {
				if(input[j]!=ans[curlength-(i-j)]) flag=0;
			}
			if(flag) {
				samecnt = i;
				break;
			}
		}
		if(samecnt==0) strcat(ans, input);
		else {
			for(int i = samecnt; i < n; i++) {
				ans[curlength++] = input[i];
			}
		}
		curlength = strlen(ans);
	}
	printf("%s\n",ans);
}
