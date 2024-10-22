#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#define int long long
int main() {
	int n;
	scanf("%lld",&n);
	int cnt = 0;
	char cur[30000];
	char prev[30000] = "";
	int sign = -1;
	while(cnt < n) {
		char input[5005];
		scanf("%s",input);
		if(input[0]!='+' && input[0]!='-' && input[0]!='*' && input[0]!='/') {
			strcpy(cur, input);
			cnt++;
		}else if(input[0]=='*') {
			int x;
			scanf("%lld",&x);
			char tmp[30000] = "";
			//strcpy(tmp, cur);
			int n = strlen(cur);
			int idx = 0;
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < x; j++) {
					tmp[idx++] = cur[i];
				}
			}
			tmp[idx] = '\0';
			strcpy(cur, tmp);
			//for(int i = 0; i < x-1; i++)
			//	strcat(cur, tmp);
			cnt++;
		}else if(input[0]=='/') {
			int x;
			scanf("%lld",&x);
			char tmp[30000];
			int i = 0;
			int n = strlen(cur);
			for(int j = 0; j < n; j+=x) {
				tmp[i++] = cur[j];
			}
			strncpy(cur, tmp, i);
			cur[i] = '\0';
			cnt++;
		}else if(input[0]=='+') {
			if(strlen(prev) == 0) {
				strcpy(prev, cur);
				sign = 1;
				continue;
			}
			if(sign==1) {
				strcat(prev, cur);
			}else if(sign==0){
				int m = strlen(cur);
				int n = strlen(prev);
				if(m>n) {
					sign = 1;
					continue;
				}
				bool flag = (strcmp(cur, prev+n-m) == 0);
				//for(int i = 0; i < m; i++) {
				//	if(cur[i] != prev[n-m+i]) flag = 0;
				//}
				if(flag) {
					//char tmp[6000];
					//strcpy(tmp, prev);
					strncpy(prev, prev, n-m);
					prev[n-m] = '\0';
				}
			}
			sign = 1;
		}else if(input[0]=='-') {
			if(strlen(prev) == 0) {
				strcpy(prev, cur);
				sign = 0;
				continue;
			}
			if(sign == 1) {
				strcat(prev, cur);
			}else if(sign == 0) {
				int m = strlen(cur);
				int n = strlen(prev);
				if(m>n) {
					sign = 0;
					continue;
				}
				bool flag = (strcmp(cur, prev+n-m) == 0);
				//for(int i = 0; i < m; i++) {
				//	if(cur[i] != prev[n-m+i]) flag = 0;
				//}
				if(flag) {
					//char tmp[6000];
					//strcpy(tmp, prev);
					strncpy(prev, prev, n-m);
					prev[n-m] = '\0';
				}
			}
			sign = 0;

		}
		//printf("cnt = %d, prev = %s, cur = %s\n",cnt, prev, cur);
	}
	/*
	printf("%d\n",sign);
	printf("%s\n",cur);
	printf("%s\n",prev);
	*/
	if(sign == -1) {
		strcpy(prev, cur);
	}else if(sign == 1) {
		strcat(prev, cur);
	}else if(sign == 0) {
		int m = strlen(cur);
		int n = strlen(prev);
		//printf("(cur=%d,prev=%d)\n",m,n);
		if(m <= n) {
			bool flag = (strcmp(cur, prev+n-m) == 0);
			//for(int i = 0; i < m; i++) {
			//	if(cur[i] != prev[n-m+i]) flag = 0;
			//}
			//printf("%d\n", flag);
			if(flag) {
				//char tmp[6000];
				//strcpy(tmp, prev);
				//strcpy(prev, "");
				//printf("%s\n",tmp);
				strncpy(prev, prev, n-m);
				prev[n-m] = '\0';
			}

		}	
	}
	//printf("%d\n",sign);
	//printf("%s\n",cur);
	printf("%s\n",prev);
}
