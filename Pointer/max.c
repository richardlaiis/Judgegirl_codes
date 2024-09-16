#include "max.h"

int max(int *iptr[], int n) {
	int ret = *iptr[0];
	for(int i = 1; i < n; i++) {
		if(*iptr[i]>ret) ret=*iptr[i];
	}
	return ret;
}
