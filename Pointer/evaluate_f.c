#include "evaluate_f.h"

int evaluate_f(int *iptr[], int n, int *index) {
	int maxn = *(iptr[0])*4-*(iptr[0]+1)*6;
	*index = 0;
	for(int i = 1; i < n; i++) {
		if(*(iptr[i])*4-*(iptr[i]+1)*6 > maxn) {
			maxn = *(iptr[i])*4-*(iptr[i]+1)*6;
			*index = i;
		}
	}
	return maxn;
}
