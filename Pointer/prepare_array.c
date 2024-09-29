#include "prepare_array.h"

void prepare_array(int buffer[], int *array[], int row, int column[]) {
	int idx = 0;
	for(int i = 0; i < row; ++i) {
		array[i] = &buffer[idx];
		idx += column[i];
	}
}
