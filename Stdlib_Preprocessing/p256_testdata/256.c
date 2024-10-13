#include <stdio.h>
#include <stdlib.h>

int countBit(long long x) {
	int res = 0;
	while(x != 0) {
		if(x&1) ++res;
		x /= 2;
	}
	return res;
}

int compare(const void *a, const void *b) {
	long long aa = *(long long*)a;
	long long bb = *(long long*)b;
	if(countBit(aa) == countBit(bb)) {
		return (aa > bb) - (aa < bb);
	}else {
		return countBit(aa) - countBit(bb);
	}
}

signed main() {
	long long list[1000];
	int idx = 0;
	long long x;
	while(scanf("%lld",&x) != EOF) {
		list[idx++] = x;
	}
	qsort(list, idx, sizeof(long long), compare);
	for(int i=0; i<idx; ++i) {
		printf("%lld\n", list[i]);
	}

	return 0;
}
