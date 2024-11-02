#include <stdio.h>
#include <string.h>
typedef struct employee {
  int id;
  char first_name[32];
  char last_name[32];
  int boss_id;
} Employee;
void find_relation(char f1[], char l1[], char f2[], char l2[], int n, int boss[], Employee p[]) {
	int idx1, idx2;
	for(int i = 0; i < n; i++) {
		if(strcmp(f1, p[i].first_name) == 0 && strcmp(l1, p[i].last_name) == 0) idx1 = i;
		if(strcmp(f2, p[i].first_name) == 0 && strcmp(l2, p[i].last_name) == 0) idx2 = i;
	}
	int a = idx1, b = idx2;
	while(boss[a] != a) {
		a = boss[a];
		if(a == idx2) {
			printf("subordinate\n");
			return;
		}
	}
	while(boss[b] != b) {
		b = boss[b];
		if(b == idx1) {
			printf("supervisor\n");
			return;
		}
	}
	if(a == b) printf("colleague\n");
	else printf("unrelated\n");
}
int main() {
	int n, m;
	scanf("%d",&n);
	Employee slave[32];
	int boss[32];
	for(int i = 0; i < n; i++)
		scanf("%d%s%s%d",&slave[i].id,slave[i].first_name,slave[i].last_name,&slave[i].boss_id);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			boss[i] = (slave[i].boss_id == slave[j].id)?j:boss[i];
	scanf("%d",&m);
	char f1[32], l1[32], f2[32], l2[32];
	for(int i = 0; i < m; i++) {
		scanf("%s%s%s%s",f1,l1,f2,l2);
		find_relation(f1, l1, f2, l2, n, boss, slave);
	}

}
