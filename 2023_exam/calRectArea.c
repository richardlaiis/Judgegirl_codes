int calRectArea(int N, int M, int* ptrMat, int* ptrLeft[], int* ptrRight[]) {
	int ret = 0;
	for(int i = 0; i < M; i++) {
		int leftidx = ptrLeft[i] - ptrMat;
		int rightidx = ptrRight[i] - ptrMat;
		int leftx = (leftidx) % N;
		int lefty = (leftidx) / N;
		int rightx = (rightidx) % N;
		int righty = (rightidx) / N;
		ret += (rightx - leftx+1) * (righty - lefty+1);
		if(i != M-1) {
			leftidx = ptrLeft[i+1] - ptrMat;
			leftx = (leftidx) % N;
			lefty = (leftidx) / N;
			ret -= (rightx - leftx+1) * (righty - lefty+1);
		}
	}
	return ret;
}
