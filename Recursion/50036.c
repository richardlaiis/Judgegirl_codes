#include <stdio.h>
void Sol(int k,int n,int m,int a[],int idx, int sum, int cnt, int *ans) {
	if(sum > m) return;	
	if(idx == n) {
		if(sum <= m && cnt >= k)
			*ans = *ans + 1;
		return;
	}
	Sol(k, n, m, a, idx+1, sum, cnt, ans);
	Sol(k, n, m, a, idx+1, sum+a[idx], cnt+1, ans);
}
int main() {
	int k,n,m,a[20];
	scanf("%d%d%d",&k,&n,&m);
	for(int i = 0; i < n; i++) scanf("%d",a+i);
	int ans = 0;
	Sol(k, n, m, a, 0, 0, 0, &ans);
	printf("%d\n",ans);
}
