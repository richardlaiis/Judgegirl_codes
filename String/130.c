#include <stdio.h>
#include <string.h>
int main() {
	int n;
	scanf("%d",&n);
	char a[80],b[80];
	while(n--) {
		scanf("%s%s",&a,&b);
		int na = strlen(a);
		int nb = strlen(b);
		if(na == nb) {
			if(strcmp(a, b)==0) printf("yes\n");
			else {
				int diffcnt = 0;
				int diffidx[2];
				int di = 0;
				for(int i = 0; i < na; i++) {
					if(a[i]!=b[i]) {
						diffcnt++;
						if(di<2) diffidx[di++] = i;
					}
				}
				if(diffcnt==2) {
					if(a[diffidx[0]]==b[diffidx[1]] && a[diffidx[1]]==b[diffidx[0]]) {
						printf("yes\n");
					}else {
						printf("no\n");
					}
				}else {
					printf("no\n");
				}
			}
		}else if(na-nb==1 || na-nb==-1) {
			int ida = 0, idb = 0;
			int diffcnt = 0;
			while(ida<na && idb<nb) {
				if(a[ida]!=b[idb]) {
					if(diffcnt==0) {
						if(na>nb) ida++;
						else idb++;
						diffcnt++;
						continue;
					}
					diffcnt++;
				}
				ida++;
				idb++;
			}
			if(diffcnt<=1) printf("yes\n");
			else printf("no\n");
		}else {
			printf("no\n");
		}
	}
}
