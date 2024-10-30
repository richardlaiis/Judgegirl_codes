#include <stdio.h>
#include <string.h>
#define S_MAX 81
#define MAXN 50
typedef struct data {
	char lastname[S_MAX], firstname[S_MAX], id[S_MAX];
	int salary, age;
} Data;
int convertInt(char s[]) {
	int num = 0;
	int len = strlen(s);
	for(int i = 0; i < len; i++)
		num = num*10 + (s[i]-'0');
	return num;
}
void print(Data a, char field[8][10], int n) {
	for(int i = 0; i < n; i++) {
		if(field[i][0] == 'l') printf("%s%c",a.lastname," \n"[i == n-1]);
		else if(field[i][0] == 'f') printf("%s%c",a.firstname," \n"[i == n-1]);
		else if(field[i][0] == 'I') printf("%s%c",a.id," \n"[i == n-1]);
		else if(field[i][0] == 's') printf("%d%c",a.salary," \n"[i == n-1]);
		else printf("%d%c", a.age, " \n"[i == n-1]);
	}
}
void processNum(char f[10], char op[3], int x, Data database[], char fs[9][10], int m, int n) {
	if(f[0] == 's') {
		if(op[0] == '=') {
			for(int i = 0; i < n; i++) {
				if(database[i].salary == x) print(database[i], fs, m);
			}
		}else if(op[0] == '<') {
			for(int i = 0; i < n; i++) {
				if(database[i].salary < x) print(database[i], fs, m);
			}
		}else {
			for(int i = 0; i < n; i++) {
				if(database[i].salary > x) print(database[i], fs, m);
			}
		}
	}else {
		if(op[0] == '=') {
			for(int i = 0; i < n; i++) {
				if(database[i].age == x) print(database[i], fs, m);
			}
		}else if(op[0] == '<') {
			for(int i = 0; i < n; i++) {
				if(database[i].age < x) print(database[i], fs, m);
			}
		}else {
			for(int i = 0; i < n; i++) {
				if(database[i].age > x) print(database[i], fs, m);
			}
		}
	}
}
void processStr(char f[10], char op[3], char cons[], Data database[], char fs[9][10], int m, int n) {
	if(f[0] == 'f') {
		if(op[0] == '=') {
			for(int i = 0; i < n; i++) {
				if(strcmp(cons, database[i].firstname) == 0)
					print(database[i], fs, m);
			}
		}else {
			for(int i = 0; i < n; i++) {
				if(strcmp(cons, database[i].firstname) != 0)
					print(database[i], fs, m);
			}
		}
	}else if(f[0] == 'l') {

		if(op[0] == '=') {
			for(int i = 0; i < n; i++) {
				if(strcmp(cons, database[i].lastname) == 0)
					print(database[i], fs, m);
			}
		}else {
			for(int i = 0; i < n; i++) {
				if(strcmp(cons, database[i].lastname) != 0)
					print(database[i], fs, m);
			}
		}
	}else if(f[0] == 'I') {

		if(op[0] == '=') {
			for(int i = 0; i < n; i++) {
				if(strcmp(cons, database[i].id) == 0)
					print(database[i], fs, m);
			}
		}else {
			for(int i = 0; i < n; i++) {
				if(strcmp(cons, database[i].id) != 0)
					print(database[i], fs, m);
			}
		}
	}
}
int main() {
	Data database[MAXN];
	int n, q;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%s%s%s%d%d", database[i].lastname, database[i].firstname, database[i].id, &database[i].salary, &database[i].age);
	scanf("%d", &q);
	for(int i = 0; i < q; i++) {
		char tmp[7];
		scanf("%s", tmp);
		char field[9][10];
		int idx = 0;
		while(scanf("%s", field[idx]) && field[idx][0] != 'w')
			idx++;
		
		char f[10], op[3], con[S_MAX];
		scanf("%s%s%s", f, op, con);
		
		if(f[0] == 's' || f[0] == 'a') {
			int x = convertInt(con);
			processNum(f, op, x, database, field, idx, n);
		}else {
			processStr(f, op, con, database, field, idx, n);
		}

	}
}
