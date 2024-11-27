#include <stdio.h>
#include <stdbool.h>
#include "tree.h"
void traversal(Node *root, int N, int command[]) {
	Node *cur = root;
	Node *path[1500];
	path[0] = cur;
	int idx = 1;
	for(int i = 0; i < N; i++) {
		bool valid = 1;
		switch(command[i]) {
			case 0:
				valid = 0;
				break;
			case 1:
				printf("%d\n", cur->label);
				break;
			case 2:
				if(idx-2 >= 0) {
					cur = path[idx-2];
					idx--;
				}else valid = 0;
				break;
			case 3:
				if(cur->left != NULL) {
					cur = cur->left;
					path[idx++] = cur;
				}else valid = 0;
				break;
			case 4:
				if(cur->right != NULL) {
					cur = cur->right;
					path[idx++] = cur;
				}else valid = 0;
				break;
			case 5:
				if(idx-2 >= 0) {
					if(path[idx-2]->left != cur && path[idx-2]->left != NULL) {
						path[idx-1] = path[idx-2]->left;
						cur = path[idx-1];
					}else if(path[idx-2]->right != cur && path[idx-2]->right != NULL) {
						path[idx-1] = path[idx-2]->right;
						cur = path[idx-1];
					}else valid = 0;
				}else valid = 0;
				break;
			default:
				break;
		}
		if(!valid) {
			printf("%d\n", cur->label);
			break;
		}
	}
}
