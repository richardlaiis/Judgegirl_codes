#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef struct treenode {
    int data;
    struct treenode *left;
    struct treenode *right;
} TreeNode;
TreeNode *genNode(int data, TreeNode *left, TreeNode *right) {
    TreeNode *node = malloc(sizeof(TreeNode));
    assert(node != NULL);
    node->data = data;
    node->left = left;
    node->right = right;
    return node;
}
TreeNode *insertNode(TreeNode *root, int data) {
    if(root == NULL) return genNode(data, NULL, NULL);
    if(data < root->data) root->left = insertNode(root->left, data);
    else root->right = insertNode(root->right, data);
    return root;
}
void preOrder(TreeNode *root) {
    if(root == NULL) return;
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}
void inOrder(TreeNode *root) {
    if(root == NULL) return;
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}
void postOrder(TreeNode *root) {
    if(root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}
void freeTree(TreeNode *root) {
    if(root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}
TreeNode *rebuildTree(int n, int pre[], int in[]) {
    if(n == 0) return NULL;
    int leftn, rightn;
    for(int i = 0; i < n; i++) {
        if(in[i] == pre[0]) {
            leftn = i;
            rightn = n-leftn-1;
            break;
        } 
    }
    return genNode(pre[0], rebuildTree(leftn, pre+1, in), rebuildTree(rightn, pre+leftn+1, in+leftn+1));
}
TreeNode *treeAND(TreeNode *root1, TreeNode *root2) {
    if(root1 != NULL && root2 != NULL) {
        return genNode(root1->data*root2->data, treeAND(root1->left, root2->left), treeAND(root1->right, root2->right));
    }
    return NULL;
}
TreeNode *treeOR(TreeNode *root1, TreeNode *root2) {
    if(root1 != NULL && root2 != NULL) {
        return genNode(root1->data+root2->data, treeOR(root1->left, root2->left), treeOR(root1->right, root2->right));
    }
    if(root1 != NULL) return root1;
    if(root2 != NULL) return root2;
    return NULL;
}
int main() {
    // int pre[] = {4, 2, 1, 3, 5};
    // int in[] = {1, 2, 3, 4, 5};
    // TreeNode *root = rebuildTree(5, pre, in);

    TreeNode *tree[2] = {NULL, NULL}; 
    for(int i = 0; i < 2; i++) {
        int n;
        scanf("%d", &n);
        for(int j = 0; j < n; j++) {
            int x;
            scanf("%d", &x);
            tree[i] = insertNode(tree[i], x);
        }
    }

    // int x;
    // scanf("%d", &x);
    // TreeNode *root = genNode(x, NULL, NULL);
    // while(scanf("%d",&x) != EOF) {
    //     root = insertNode(root, x);
    // }
    TreeNode *root = treeAND(tree[0], tree[1]);
    preOrder(root);
    printf("\n");
    inOrder(root);
    printf("\n");
    postOrder(root);
    printf("\n");
    freeTree(root);
    root = treeOR(tree[0], tree[1]);
    preOrder(root);
    printf("\n");
    inOrder(root);
    printf("\n");
    postOrder(root);
    printf("\n");
    freeTree(root);
}