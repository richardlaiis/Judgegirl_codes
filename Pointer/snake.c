void snake(const int *ptr_array[100][100], int m) {
	int idx = 0;
	const int *sortarr[m*m];
	for(int i = 0; i < m; ++i) {
		for(int j = 0; j < m; ++j) {
			sortarr[idx++] = ptr_array[i][j];
		}
	}
	for(int i = m*m-1; i >= 0; --i) {
		for(int j = 0; j < i; ++j) {
			if(*(sortarr[j]) > *(sortarr[j+1])) {
				const int *tmp = sortarr[j];
				sortarr[j] = sortarr[j+1];
				sortarr[j+1] = tmp;
			}
		}
	}
	idx = 0;
	for(int i = 0; i < m; ++i) {
		if(i&1) {
			for(int j = m-1; j >= 0; --j) ptr_array[i][j] = sortarr[idx++];
		}else {
			for(int j = 0; j < m; ++j) ptr_array[i][j] = sortarr[idx++];
		}
	}
}
