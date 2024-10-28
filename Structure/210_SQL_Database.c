#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define maxn 500
typedef struct Data {
	char lastname[85],firstname[85],id[85];
	int salary, age;
} data;
int stoi(char *s) {
	int num = 0;
	int len = strlen(s);
	for(int i = 0; i < len; i++) {
		num = num*10+(s[i]-'0');
	}
	return num;
}	
int main() {
	int n;
	scanf("%d", &n);
	data db[n];
	for(int i = 0; i < n; i++) {
		scanf("%s%s%s%d%d", &(db[i].lastname), &(db[i].firstname), &(db[i].id), &(db[i].salary), &(db[i].age));
	}
	int k;
	scanf("%d", &k);
	char query[maxn];
	while(fgets(query, maxn, stdin)) {
		char token[20][85];
		char *start = strtok(query, " ");
		int idx = 0;
		while(start != NULL) {
			strcpy(token[idx++], start);
			start = strtok(NULL, " ");
		}
		if(strcmp("salary", token[idx-3]) == 0) {
			int wage = stoi(token[idx-1]);
			if(strcmp("==", token[idx-2]) == 0) {
				
			}
		}
	}
}
