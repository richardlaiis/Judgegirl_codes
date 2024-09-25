#include <stdio.h>
int max(int x, int y) {
	return (x>y)?x:y;
}
int main() {
	int n,a,b;
	scanf("%d%d%d",&n,&a,&b);
	int t = n*(2*a-b);
	int cur1=-1, cur2=-1;
	int firstCnt=1, secondCnt=1;
	int maxFirst=1, maxSecond=1;
	int x;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < b; ++j) {
			scanf("%d",&x);
			if(x!=cur2) {
				cur2 = x;
				maxSecond = max(maxSecond, secondCnt);
				secondCnt = 1;
			}else {
				++secondCnt;
			}
		}
		int m = (a-b)*2;
		for(int j = 0; j < m; j++) {
			scanf("%d",&x);
			if(j%4==1 || j%4==2) {
				if(x!=cur1) {
					cur1 = x;
					maxFirst = max(maxFirst, firstCnt);
					firstCnt = 1;
				}else {
					++firstCnt;
				}
			}else {
				if(x!=cur2) {
					cur2 = x;
					maxSecond = max(maxSecond, secondCnt);
					secondCnt = 1;
				}else {
					++secondCnt;
				}
			}
		}
		maxFirst = max(maxFirst, firstCnt);
		firstCnt = 1;
		cur1 = -1;
		maxSecond = max(maxSecond, secondCnt);
	}
	printf("%d\n",max(maxFirst, maxSecond));
}
