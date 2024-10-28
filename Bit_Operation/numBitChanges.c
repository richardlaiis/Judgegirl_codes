#include <stdint.h>
#define ARRAYSIZE 1000
 
typedef struct giantUnsignedInt {
    uint64_t array[ARRAYSIZE];
    int n;
} GiantUnsignedInt;
 
int numBitChanges(GiantUnsignedInt *giantNum) {
	int n = giantNum->n;
	int bits[64*ARRAYSIZE] = {0};
	int t = 0;
	for(int i = 0; i < n; i++) {
		uint64_t x = giantNum->array[i];
		for(int j = 64*(i+1)-1; j >= 64*i; j--) {
			bits[j] = x&1;
			x >>= 1;
		}
	}
	for(int i = 0; i < 64*n-1; i++) {
		t += (bits[i] != bits[i+1]);
	}
	t += (bits[0] != bits[64*n-1]);
	return t;
}
