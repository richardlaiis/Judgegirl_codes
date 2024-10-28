#include <stdint.h>
void BubbleSort(uint64_t input, uint64_t output[63]) {
	uint64_t k = 1;
	for(int i = 0; i < 63; i++) {
		for(int j = 64; j >= 2; j--) {
			int a = (input>>(j-1))&k;
			int b = (input>>(j-2))&k;
			if(a == 1 && b == 0) {
				input = input & ~(k<<(j-1));
				input = input | k<<(j-2);
			}
		}
		output[i] = input;
	}
}
