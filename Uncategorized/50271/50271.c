#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
bool valid(char *var) {
	bool flag = 1;
	char reserved[12][7] = {"if", "else", "while", "for", "switch", "case", "break", "return", "void", "int", "float", "char"};
	for(int i = 0; i < 12; i++) {
		if(strcmp(var, reserved[i]) == 0) {
			flag = 0;
			break;
		}
	}
	if(strspn(var, "0123456789.") == strlen(var)) flag = 0;
	if(strspn(var, " ") == strlen(var)) flag = 0;
	if(isdigit(var[0])) flag = 0;
	if(strcmp("", var) == 0) flag = 0;
	return flag;
}
int main() {
	char line[1024];
	char vars[32][32];
	int cnt[32] = {0};
	int idx = 0;
	while(fgets(line, 1024, stdin) != NULL) {
		char de[] = "?,+-*/;[](){}<>:&|^%!~= \n";
		char *token = strtok(line, de);
		while(token != NULL) {
			int n = strlen(token);
			token[n] = '\0';
			/*
			if(valid(token)) {
				printf("%s ",token);
			}
			*/
			if(!valid(token)) {
				token = strtok(NULL, de);
				continue;
			}
			bool found = 0;
			
			for(int i = 0; i < idx; i++) {
				if(strncmp(vars[i], token, 24) == 0) {
					found = 1;
					cnt[i]++;
					break;
				}
			}
			if(!found) {
				if(n >= 24) {
					strncpy(vars[idx++], token, 25);
					vars[idx-1][24] = '\0';
				}else strcpy(vars[idx++], token);
				cnt[idx-1] = 1;
			}
			//printf("%s ",token);
			token = strtok(NULL, de);
		}
		//printf("\n");
		//printf("%d\n",idx);
	}
	//printf("%d",idx);
	for(int i = 0; i < idx; i++) {
		printf("%s %d\n", vars[i], cnt[i]);
	}
}
