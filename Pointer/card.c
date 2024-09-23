#include "card.h"
#include <stdio.h>

void shuffle(int *deck[]) {
	int n = 0;
	while(deck[n]!=NULL) ++n;
	if(n == 0) return;
	int tmp[n];
	if(n&1) {
		int idx = 0;
		for(int i = 0; i < n/2; i++) {
			tmp[idx] = *deck[i];
			tmp[idx+1] = *deck[i+n/2+1];
			idx += 2;
		}
		tmp[n-1] = *deck[n/2];
	}else {
		int idx = 0;
		for(int i = 0; i < n/2; i++) {
			tmp[idx] = *deck[i];
			tmp[idx+1] = *deck[i+n/2];
			idx+=2;
		}
	}
	for(int i = 0; i < n; i++) *deck[i] = tmp[i];
}

void print(int *deck[]) {
	int n = 0;
	while(deck[n]!=NULL) ++n;
	if(n == 0) return;
	for(int i = 0; i < n; i++) {
		printf("%d ", *deck[i]);
	}
	printf("\n");
}
