#include <stdio.h>
#include <string.h>
int main() {
	int n, m;
	char ing[101][13][65];
	int cnt[101];
	scanf("%d",&n);
	for(int i = 0; i < n; i++) {
		scanf("%s",&ing[i][12]);
		int j;
		scanf("%d",&j);
		cnt[i] = j;
		for(int k = 0; k < j; k++) {
			scanf("%s",&ing[i][k]);
		}
	}
	scanf("%d",&m);
	char a[65],b[65];
	for(int i = 0; i < m; i++) {
		scanf("%s%s",&a,&b);
		int ida=-1, idb=-1;
		for(int j = 0; j < n; j++) {
			if(strcmp(a, ing[j][12])==0) ida=j;
			if(strcmp(b, ing[j][12])==0) idb=j;
			if(ida!=-1 && idb!=-1) {
				break;
			}
		}
		char *ans[11], tot=0;
		for(int j = 0; j < cnt[ida]; j++) {
			for(int k = 0; k < cnt[idb]; k++) {
				if(strcmp(ing[ida][j], ing[idb][k])==0) {
					ans[tot++] = ing[ida][j];
				}
			}
		}
		//printf("%d\n",tot);
		if(tot==0) {
			printf("nothing\n");
			continue;
		}
		char fans[tot][65];
		for(int j = 0; j < tot; j++) {
			strcpy(fans[j], ans[j]);
		}
		
		for(int j = tot-2; j >= 0; j--) {
			for(int k = 0; k <= j; k++) {
				if(strcmp(fans[k], fans[k+1])>0) {
					char tmp[65];
					strcpy(tmp, fans[k]);
					strcpy(fans[k], fans[k+1]);
					strcpy(fans[k+1], tmp);
				}
			}
		}
		
		for(int j = 0; j < tot; j++) {
			printf("%s%c",fans[j],(j==tot-1)?'\n':' ');
		}
	}
}
