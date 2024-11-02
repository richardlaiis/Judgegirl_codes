#include <stdio.h>
#include <string.h>
#include <ctype.h>
int convertInt(char s[20]) {
	int num = 0;
	int len = strlen(s);
	for(int i = 0; i < len; i++)
		num = num*10 + (s[i]-'0');
	return num;
}
void solve(char s1[], char s2[], char result[], int idx1, int idx2) {
}
int main() {
	char s1[9], s2[9], result[12];
	scanf("%s%s%s", s1, s2, result);
	solve(s1, s2, result, 0, 0);
}
