#include <stdio.h>
#include <string.h>
#define maxn 100010
int main() {
	char s1[maxn], s2[maxn];
	char tok1[1<<10][1<<7], tok2[1<<10][1<<7];
	fgets(s1, maxn, stdin);
	fgets(s2, maxn, stdin);
	char de[] = ".,!?;:[](){} ";
	s1[strlen(s1)-1] = '\0';
	s2[strlen(s2)-1] = '\0';
	//printf("%s\n",s1);
	//printf("%s\n",s2);
	char *start1 = s1;
	start1 = strtok(start1, de);
	int cnt1 = 0;
	while(start1 != NULL) {
		strcpy(tok1[cnt1++], start1);
		start1 = strtok(NULL, de);
	}
	//for(int i = 0; i < cnt1; i++) {
	//	printf("%s\n",tok1[i]);
	//}
	char *start2 = s2;
	start2 = strtok(start2, de);
	int cnt2 = 0;
	while(start2 != NULL) {
		strcpy(tok2[cnt2++], start2);
		start2 = strtok(NULL, de);
	}
	//for(int i = 0; i < cnt2; i++) {
	//	printf("%s\n",tok2[i]);
	//}
	int idx1 = 0;
	int idx2 = 0;
	char ans[2*maxn+10];
	while(idx1 < cnt1 && idx2 < cnt2) {
		if(strcmp(tok1[idx1], tok2[idx2])<0) {
			strcat(ans, tok1[idx1++]);
		}else {
			strcat(ans, tok2[idx2++]);
		}
	}
	while(idx1<cnt1) {
		strcat(ans, tok1[idx1++]);
	}
	while(idx2<cnt2) {
		strcat(ans, tok2[idx2++]);
	}
	printf("%s\n", ans);
}
