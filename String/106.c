#include <stdio.h>
#include <string.h>
int abs(int x) {
	return (x>0)?x:(-x);
}
int atoi(char a) {
	return a-'0';
}
int main() {
	char num[1005];
	scanf("%s", &num);
	while(num[0]!='-') {
		int len = strlen(num);
		if(atoi(num[len-1])%2==0) printf("yes ");
		else printf("no ");

		int sum = 0;
		for(int i = 0; i < len; i++) sum+=atoi(num[i]);
		if(sum%3==0) printf("yes ");
		else printf("no ");

		if(atoi(num[len-1])%5==0) printf("yes ");
		else printf("no ");
	
		int evensum = 0, oddsum = 0;

		for(int i = 0; i < len; i++) {
			if(i&1) oddsum+=atoi(num[i]);
			else evensum+=atoi(num[i]);
		}
		if(abs(oddsum-evensum)%11==0) printf("yes\n");
		else printf("no\n");
		scanf("%s",&num);
	}
}
