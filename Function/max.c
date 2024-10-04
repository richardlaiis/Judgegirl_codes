int max(int array[5][5]) {
	int res = -1000000000;
	for(int i = 0; i < 5; i++) {
		for(int j = 0; j < 5; j++) {
			if(array[i][j]>res) res=array[i][j];
		}
	}
	return res;
}
