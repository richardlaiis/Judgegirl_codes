#include <stdio.h>
#include <stdbool.h>
#include "sub.h"
int length(Node* text) {
	Node *cur = text;
	int ret = 0;
	while(cur != NULL) {
		ret++;
		cur = cur->next;
	}
	return ret;
}
void substring(Node* text, Node* pattern) {
	//printf("%d\n", length(text));
	//printf("%d\n", length(pattern));
	//int txtlen = length(text);
	//int patlen = length(pattern);
	Node *cur1 = text, *cur2 = pattern;
	int i = 0;
	int ans = 0;
	while(cur1 != NULL && cur2 != NULL) {
		bool ok = 1;
		if(cur1->c == cur2->c) {
			int len = 0;
			Node *tmp1 = cur1, *tmp2 = cur2;
			while(tmp1 != NULL && tmp2 != NULL) {
				len++;
				if(tmp1->c != tmp2->c) {
					ok = 0;
					break;
				}
				tmp1 = tmp1->next;
				tmp2 = tmp2->next;
			}	
			if(ok) {
				ans = (2*i+len-1)*len/2;
				printf("%d\n", ans);
				break;
			}
		}
		cur1 = cur1->next;
		i++;
	}
}
void subsequence(Node* text, Node* pattern) {
	//printf("%d\n", length(text));
	//printf("%d\n", length(pattern));
	//int txtlen = length(text);
	//int patlen = length(pattern);
	int ans = 0;
	int i = 0;
	Node *cur1 = text, *cur2 = pattern;
	while(cur1 != NULL && cur2 != NULL) {
		if(cur1->c == cur2->c) {
			ans += i;
			cur2 = cur2->next;
		}
		cur1 = cur1->next;
		i++;
	}
	printf("%d\n", ans);
}
