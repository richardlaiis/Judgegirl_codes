#include <stdio.h>
#include <assert.h>
int main() {
	FILE *fptr = fopen("hello", "wb");
	assert(fptr != NULL);
}
