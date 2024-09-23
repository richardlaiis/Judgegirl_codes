#include <stdio.h>
int arr[15], ans[20000] = {0};
int n,k;
void subcnt(int cur, int sum) {
	if(cur == n) {
		ans[sum]++;
		return;
	}
	subcnt(cur+1, sum+arr[cur]);
	subcnt(cur+1, sum);
}
int main() {
	scanf("%d",&n);
	for(int i = 0 ; i < n; i++) {
		scanf("%d",&arr[i]);
	}
	subcnt(0, 0);
	while(scanf("%d",&k)!=EOF) {
		printf("%d\n", ans[k]);
	}
}
