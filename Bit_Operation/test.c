#include <stdio.h>
#include <stdint.h>
int main() {
	uint64_t x = 18446744073709551610;
	printf("%ld\n", sizeof(x));
	printf("%llu\n", x);
	
}
