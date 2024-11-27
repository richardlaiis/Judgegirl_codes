#include "operations.h"
#include <stdio.h>
#include <stdlib.h>
Node *FlipTree(Node *root) {
	if(root == NULL)
		return NULL;
	if(root->left == NULL && root->right == NULL)
		return root;
	Node *ans = (Node *)malloc(sizeof(Node));
	ans->n = root->n;
	Node *left = root->left;
	Node *right = root->right;
	ans->left = FlipTree(right);
	ans->right = FlipTree(left);
	return ans;
}
int isIdentical(Node *tree1, Node *tree2) {
	if(tree1 == NULL && tree2 == NULL) return 1;
	if(tree1 == NULL || tree2 == NULL) return 0;
	if(tree1->n == tree2->n) {
		return (isIdentical(tree1->left, tree2->left) && isIdentical(tree1->right, tree2->right));
	}else {
		return 0;
	}
}
void traverse(Node *root, int *count, int *length, int curlen) {
	if(root == NULL) return;
	if(root->left == NULL && root->right == NULL) {
		*count += 1;
		*length += curlen;
		return;
	}
	traverse(root->left, count, length, curlen+1);
	traverse(root->right, count, length, curlen+1);
}
void depthAvg(Node *root) {
	int count = 0;
	int length = 0;
	traverse(root, &count, &length, 0);
	printf("%d/%d\n", length, count);
}
