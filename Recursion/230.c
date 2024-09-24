#include <stdio.h>
int n,W;
int w[25], v[25];
int ans = -1;
int max(int a, int b) {
	return (a>b)?a:b;
}
void knapsack(int idx, int cur_weight, int cur_value) {
	if(idx == n) {
		if(cur_weight<=W) {
			ans = max(ans, cur_value);
		}
		return ;
	}
	knapsack(idx+1, cur_weight+w[idx], cur_value+v[idx]);
	knapsack(idx+1, cur_weight, cur_value);
}
int main() {
	scanf("%d%d",&n,&W);
	for(int i = 0; i < n; i++) scanf("%d%d",&w[i],&v[i]);
	knapsack(0, 0, 0);
	printf("%d\n", ans);
}
