#include <stdio.h>
int Sol(int D, int a, int b, int c, int A, int B, int C) {
	if(D == 0)
		return 1;
	if(D < 0)
		return 0;
	int flag = 0;
	if(a-1 >= 0) {
		flag = Sol(D-A, a-1, b, c, A, B, C);
		if(flag) return 1;
	}	
	if(b-1 >= 0) {
		flag = Sol(D-B, a, b-1, c, A, B, C);
		if(flag) return 1;
	}
	if(c-1 >= 0) {
		flag = Sol(D-C, a, b, c-1, A, B, C);
		if(flag) return 1;
	}
	return 0;
	
}
int main() {
	int N;
	scanf("%d", &N);
	while(N--) {
		int D, a, b, c, A, B, C;
		scanf("%d%d%d%d%d%d%d", &D, &a, &b, &c, &A, &B, &C);
		int found = Sol(D, a, b, c, A, B, C);
		if(found)
			printf("yes\n");
		else
			printf("no\n");
	}
}
