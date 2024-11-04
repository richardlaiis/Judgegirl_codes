#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#define maxn 9
int convertInt(char s[]) {
	int n = strlen(s);
	int num = 0;
	for(int i = 0; i < n; i++) {
		num = num*10 + (s[i]-'0');
	}
	return num;
}

int main() {
	char s1[maxn], s2[maxn], s3[maxn];
	assert(scanf("%s%s%s", s1, s2, s3) == 3);
	bool alpha[26] = {0};
	int l1 = strlen(s1);
	for(int i = 0 ;i < l1; i++) {
		if(!isdigit(s1[i])) {
			alpha[s1[i]-'A'] = 1;
		}
	}
	int l2 = strlen(s2);
	for(int i = 0 ;i < l2; i++) {
		if(!isdigit(s2[i])) {
			alpha[s2[i]-'A'] = 1;
		}
	}
	int l3 = strlen(s3);
	for(int i = 0 ;i < l3; i++) {
		if(!isdigit(s3[i])) {
			alpha[s3[i]-'A'] = 1;
		}
	}
	int a[26];
}