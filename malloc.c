#include <stdio.h>
#include <stdlib.h>
int main() {
	int *arr;
	int n, m;
	scanf("%d",&n);
	arr = malloc(n * sizeof(int));
	for(int i = 0; i < n; i++) {
		scanf("%d",&arr[i]);
	}
	scanf("%d",&m);
	arr = realloc(arr, sizeof(int)*(n+m));
	for(int i = n; i<n+m; i++) scanf("%d",&arr[i]);
	n+=m;
	for(int i = 0; i < n; i++) {
		printf("%d%c",arr[i],(i==n-1)?'\n':' ');
	}
	free(arr);
	return 0;
}
