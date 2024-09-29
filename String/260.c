#include <stdio.h>
#include <string.h>
int main() {
	char inp[130];
	char ans[130] = "";
	int idx = 0;
	while(scanf("%d",&inp)!=EOF) {
		int len = strlen(inp);
		int idt = 0;
		for(int i = len; i > 0; i--) {
			if(i > idx) continue;
			int flag = 1;
			for(int j = 0; j < i; j++) {
				if(ans[idx-(i-j)]!=inp[j]) {
					flag = 0;
				}
			}
			if(flag) {
				idt = i;
				break;
			}
		}
		for(int i = idt; i < len; i++) {
			ans[idx++] = inp[i];
		}
	}
	printf("%s\n", ans);
	return 0;
}
