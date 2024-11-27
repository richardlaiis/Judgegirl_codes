#include "merge.h"
#include <stdio.h>
Node *merge(Node *list[], int K) {
	Node *cur[K];
	int dir = 0;
	Node *head = NULL;
	for(int i = 0; i < K; i++) {
		cur[i] = list[i];
	}
	while(1) {
		for(int i = 0; i < K; i++) {
			if(head == NULL) {
				head = list[i];
				cur = list[i];
			}else {
				head->next = cur[i];
				head = head->next;
				cur[i] = cur[i]->next;
			}
		}
	}
}
