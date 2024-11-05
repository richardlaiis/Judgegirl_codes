#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>

void set_alpha(bool alpha[], char s[]) {
	int n = strlen(s);
	for(int i = 0; i < n; i++) {
		if(!isdigit(s[i])) alpha[s[i]-'A'] = 1;
	}
}

int convertInt(char s[]) {
	int n = strlen(s);
	int m = 0;
	for(int i = 0; i < n; i++) {
		m = 10*m + (s[i]-'0');
	}
	return m;
}

void solve_eq(bool alpha[], int cur[], int idx, char s1[], char s2[], char s3[]) {
	if(idx == 26) {
		char tmp1[10], tmp2[10], tmp3[10];
		strcpy(tmp1, s1);
		strcpy(tmp2, s2);
		strcpy(tmp3, s3);
		int l1 = strlen(tmp1), l2 = strlen(tmp2), l3 = strlen(tmp3);
		for(int i = 0; i < l1; i++) {
			if(!isdigit(tmp1[i])) tmp1[i] = '0'+cur[tmp1[i]-'A'];
		}
		for(int i = 0; i < l2; i++) {
			if(!isdigit(tmp2[i])) tmp2[i] = '0'+cur[tmp2[i]-'A'];
		}
		for(int i = 0; i < l3; i++) {
			if(!isdigit(tmp3[i])) tmp3[i] = '0'+cur[tmp3[i]-'A'];
		}
		if(convertInt(tmp1) * convertInt(tmp2) == convertInt(tmp3)) {
			printf("%s x %s = %s\n", tmp1, tmp2, tmp3);
			exit(0);
		}else {
			return;
		}
	}
	if(!alpha[idx]) {
		solve_eq(alpha, cur, idx+1, s1, s2, s3);
	}else {
		for(int i = 0; i <= 9; i++) {
			cur[idx] = i;
			solve_eq(alpha, cur, idx+1, s1, s2, s3);
		}
	}
}

int main() {
	char s1[10], s2[10], s3[10];
	scanf("%s%s%s", s1, s2, s3);
	bool alpha[26] = {0};
	set_alpha(alpha, s1);
	set_alpha(alpha, s2);
	set_alpha(alpha, s3);
	int cur[26] = {0};
	solve_eq(alpha, cur, 0, s1, s2, s3);
	
}