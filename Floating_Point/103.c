#include <stdio.h>
int main() {
	int n;
	double A[16][16], x[16], y[16];
	scanf("%d",&n);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			scanf("%lf",&A[i][j]);
		}
	}
	for(int i = 0; i < n; i++) scanf("%lf", &y[i]);
	x[n-1] = y[n-1]/A[n-1][n-1];
	for(int i = n-2; i >= 0; i--) {
		double cur_y = y[i];
		for(int j = n-1; j > i; j--) {
			cur_y -= x[j]*A[i][j];
		}
		x[i] = cur_y/A[i][i];
	}
	for(int i = 0; i < n; i++) {
		printf("%lf\n", x[i]);
	}
}
