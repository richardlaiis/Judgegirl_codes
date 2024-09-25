#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char* substr(int start, int end, char string[]) {
	int cnt = end-start+1;
	char* dest = (char*)malloc((cnt+1)*sizeof(char));
	strncpy(dest, string+start, cnt);
	dest[cnt] = '\0';
	return dest;
}
int min(int x, int y) {
	return (x<y)?x:y;
}
int main() {
	//char hello[] = "Hello, world!";
	//char *result = substr(3, 8, hello);
	//printf("%s\n", result);
	//free(result);
	
	char *ans = "";
	char input[128];
	int n = strlen(ans);
	while(scanf("%s",&input)!=EOF) {
		int len = strlen(input);
		if(n==0) {
			ans = input;
			n = strlen(ans);
		}else {
			int cnt = 0;
			for(int i = 0; i < min(n, len); i++) {
				char *result1 = substr(0,i,input);
				char *result2 = substr(n,n-i,ans);
				if(result1==result2) cnt++;
				else break;
			}
			if(cnt==0) strcat(ans, input);
			else strncat(ans, input+len-cnt, cnt);
			n = strlen(ans);
		}
	}
	printf("%s\n", ans);
}
