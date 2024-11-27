#ifndef _NODE_H
#define _NODE_H
 
typedef struct node {
    struct node *left;
    struct node *right;
    int data;
} Node;

void record_paths(Node *root, int path[], int len); 
void print_all_paths(Node *root);
 
#endif
