#include <stdio.h>
#include <stdlib.h>
void solve(int cur, int nums[], int part[], int n, int k, int *ans) {
	if(cur >= n) {
		int maxi = 0;
		for(int i = 0; i < k; i++) {
			if(part[i] == 0) return;
			maxi = (part[i] > maxi)?part[i]:maxi;
		}
		*ans = (maxi < *ans)?maxi:*ans;
		if(*ans == 3) exit(0);
		return;
	}
	for(int i = 0; i < k; i++) {
		if(part[i] > *ans) return;
	}
	int x = nums[cur];
	for(int i = 0; i < k; i++) {
		part[i] += x;
		solve(cur+1, nums, part, n, k, ans);
		part[i] -= x;
	}
}
int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	int a[12];
	for(int i = 0; i < n; i++) 
		scanf("%d", a+i);
	int part[4];
	int ans = 120000000;
	solve(0, a, part, n, k, &ans);
	printf("%d\n", ans);
}
