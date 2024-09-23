#include <stdio.h>
int arr[15];
int subsum_cnt(int start, int end, int cur, int target) {
	if(cur == target || cur+arr[start]==target) return 1;
	else if(start==end) return 0;
	return subsum_cnt(start+1, end, cur+arr[start], target)+subsum_cnt(start+1, end, cur, target);
}
int main() {
	int n,k;
	scanf("%d",&n);
	for(int i = 0 ; i < n; i++) {
		scanf("%d",&arr[i]);
	}
	while(scanf("%d",&k)!=EOF) {
		printf("%d\n",subsum_cnt(0, n-1, 0, k));
	}
}
