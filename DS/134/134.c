#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef struct node {
	int data;
	struct node *left, *right;
} Node;
typedef struct point {
	int data;
	int depth;
} Point;
Node *genNode(int data, Node *left, Node *right) {
	Node *newnode = (Node *)malloc(sizeof(Node));
	assert(newnode != NULL);
	newnode->data = data;
	newnode->left = left;
	newnode->right = right;
	return newnode;
}
Node *insert(Node *tree, int data) {
	if(tree == NULL) {
		return genNode(data, NULL, NULL);
	}
	Node *cur = tree;
	if(data > cur->data) {
		cur->right = insert(tree->right, data);
	}else {
		cur->left = insert(tree->left, data);
	}
	return cur;
}
int cmp(const void *a, const void *b) {
	const Point *A = (const Point *)a;
	const Point *B = (const Point *)b;
	if(A->depth != B->depth) return A->depth-B->depth;
	else return A->data-B->data;
}
void traverse(Node *root) {
	if(root != NULL) printf("%d\n", root->data);
	else return;
	if(root->left != NULL) traverse(root->left);
	if(root->right != NULL)traverse(root->right);
}
Node *findLCA(Node *root, int a, int b) {
	if(root == NULL) return NULL;
	if(a < root->data && b < root->data && root->left != NULL) return findLCA(root->left, a, b);
	else if(a > root->data && b > root->data && root->right != NULL) return findLCA(root->right, a, b);
	else return root;
}
int find_distance(Node *root, int x) {
	int dis = 0;
	Node *cur = root;
	while(cur != NULL && cur->data != x) {
		if(x < cur->data) cur = cur->left;
		else cur = cur->right;
		dis++;
	}
	return dis;
}
void freeTree(Node *root) {
	if(root->left != NULL) freeTree(root->left);
	if(root->right != NULL) freeTree(root->right);
	if(root != NULL) free(root);
}
int main() {
	int n;
	scanf("%d", &n);
	Point arr[1<<10];
	for(int i = 0; i < n; i++) {
		scanf("%d%d", &arr[i].data, &arr[i].depth);
	}
	if(n > 0) qsort(arr, n, sizeof(Point), cmp);
	Node *root = NULL;
	for(int i = 0; i < n; i++) {
		root = insert(root, arr[i].data);
	}
	//traverse(root);
	int q;
	scanf("%d", &q);
	for(int i = 0; i < q; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		Node *LCA = findLCA(root, a, b);
		int distance = find_distance(LCA, a)+find_distance(LCA, b);
		printf("%d\n", distance);
	}
	if(n > 0) freeTree(root);
	else free(root);
}
