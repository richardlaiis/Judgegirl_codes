#include <stdio.h>
#include <string.h>
int min(int a, int b) {
	return (a<b)?a:b;
}
int edit_dis(char *s1, char *s2, int n1, int n2, int mem[105][105]) {
	if(mem[n1][n2] != -1) return mem[n1][n2];
	
	if(strcmp(s1, s2) == 0) mem[n1][n2]=0;
	if(n1 == 0 && n2 != 0) mem[n1][n2]=n2;
	else if(n1 != 0 && n2 == 0) mem[n1][n2]=n1;
	else if(n1 == 0 && n2 == 0) mem[n1][n2]=0;
	else {
		if(s1[0] == s2[0])
			mem[n1][n2]=edit_dis(s1+1, s2+1, n1-1, n2-1, mem);
		else
			mem[n1][n2]=1+min(edit_dis(s1+1, s2, n1-1, n2, mem), edit_dis(s1, s2+1, n1, n2-1, mem));
	}
	return mem[n1][n2];
}
int main() {
	char s[105][105];
	char in[105];
	int idx = 0;
	int len[105];
	while(scanf("%s",&in) != EOF) {
		len[idx] = strlen(in);
		strcpy(s[idx++], in);
	}
	//for(int i=0;i<idx;i++) printf("%s\n",s[i]+1);
	int minvalue = 1000, id1 = 0, id2 = 1;
	//printf("%d\n", edit_dis(s[3], s[4]));
	
	for(int i = 0; i < idx; i++) {
		for(int j = i+1; j < idx; j++) {
			int mem[105][105];
			for(int k = 0; k <= len[i]; k++) {
				for(int l = 0; l <= len[j]; l++) mem[k][l] = -1;
			}
			int tmp = edit_dis(s[i], s[j], len[i], len[j], mem);
			if(tmp < minvalue || (tmp == minvalue && i*1000+j < id1*1000+id2)) {
				minvalue = tmp;
				id1 = i;
				id2 = j;
			}
		}
	}
	id1++;
	id2++;
	printf("%d %d %d\n", minvalue, id1, id2);
}
