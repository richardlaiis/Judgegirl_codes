#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef struct node {
	int data;
	struct node *next;
} Node;
Node *genNode(int data, Node *next) {
	Node *p = (Node *)malloc(sizeof(Node));
	assert(p != NULL);
	p->data = data;
	p->next = next;
	return p;
}
void printNode(Node *node) {
	for(; node!=NULL; node = node->next) {
		printf("data: %d\n",node->data);
	}
	return ;
}
void freeNode(Node *node) {
	while(node != NULL) {
		Node *next = node->next;
		free(node);
		node = next;
	}
}
Node *insertNode(Node *head, int data) {
	Node *cur = genNode(data, NULL);
	if(head == NULL) {
		return cur;
	}
	Node *ptr = head;
	Node *last = NULL;
	while(ptr != NULL && ptr->data < data) {
		last = ptr;
		ptr = ptr->next;
	}
	if(last == NULL) {
		cur->next = head;
		return cur;
	}else {
		cur->next = last->next;
		last->next = cur;
		return head;
	}
}
int main() {
	int *arr;
	arr = malloc(5*sizeof(int));
	for(int i = 0; i < 5; i++) {
		scanf("%d",&arr[i]);
	}
	Node *head = NULL;
	for(int i = 0; i < 5; i++) {
		//head = genNode(arr[i], prev);
		//prev = head;
		head = insertNode(head, arr[i]);	
	}
	printNode(head);
	freeNode(head);
	free(arr);
	return 0;
}
