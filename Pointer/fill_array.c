void fill_array(int *ptr[], int n) {
	for(int i = 0; i < n; ++i) {
		*ptr[i] = i;
	}
	for(int i = n-1; i >= 0; --i) {
		for(int j = 0; j < i; ++j) {
			if(ptr[j]>ptr[j+1]) {
				int *tmp = ptr[j];
				ptr[j] = ptr[j+1];
				ptr[j+1] = tmp;
			}
		}
	}
	for(int i = 1; i < n; ++i) {
		for(int j = 1; j < ptr[i]-ptr[i-1]; ++j) {
			*(ptr[i-1]+j) = (*ptr[i-1])+(*ptr[i]);
		}
	}
}
