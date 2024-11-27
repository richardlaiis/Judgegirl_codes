#include <stdio.h>
#include "node.h"

void record_paths(Node *root, int path[], int len) {
	if(root == NULL) return;
	path[len++] = root->data;
	if(root->left == NULL && root->right == NULL) {
		for(int i = 0; i < len; i++) {
			printf("%d%c", path[i], " \n"[i == len-1]);
		}
		return;
	}
	record_paths(root->left, path, len);
	record_paths(root->right, path, len);
}
void print_all_paths(Node *root) {
	int path[1024];
	record_paths(root, path, 0);
}
