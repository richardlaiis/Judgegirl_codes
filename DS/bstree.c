#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
struct treenode {
	int data;
	struct treenode *left;
	struct treenode *right;
};
typedef struct treenode TreeNode;
TreeNode* genTreeNode(int data, TreeNode* left, TreeNode* right) {
	TreeNode* node = malloc(sizeof(TreeNode));
	assert(node != NULL);
	node -> data = data;
	node -> left = left;
	node -> right = right;
	return node;
}
TreeNode* insertBsTree(TreeNode* root, int data) {
	if(root == NULL) {
		return genTreeNode(data, NULL, NULL);
	}else {
		if(data < root->data) {
			root -> left = insertBsTree(root -> left, data);
		}else {
			root -> right = insertBsTree(root -> right, data);
		}
	}
	return root;
}
void printTreeNode(TreeNode* root) {
	if(root == NULL) {
		return;
	}
	printTreeNode(root -> left);
	printf("%d\n",root -> data);
	printTreeNode(root -> right);
}
void freeTreeNode(TreeNode* root) {
	if(root == NULL) {
		return;
	}
	freeTreeNode(root -> left);
	freeTreeNode(root -> right);
	free(root);
}
int main() {
	int n;
	scanf("%d",&n);
	TreeNode* root = NULL;
	for(int i = 0; i < n; i++) {
		int x;
		scanf("%d",&x);
		root = insertBsTree(root, x);
	}
	printTreeNode(root);
	freeTreeNode(root);
	return 0;
}
