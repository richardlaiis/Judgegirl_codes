#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
typedef struct listnode {
    int data;
    struct listnode *next;
    struct listnode *prev;
} ListNode;
 
typedef struct linkedlist{
    struct listnode *head;
    struct listnode *tail;
} LinkedList;
 
void insert(LinkedList *list, int data) {
	ListNode *node = (ListNode *)malloc(sizeof(ListNode));
	assert(node != NULL);
	node->data = data;
	node->next = NULL;
	node->prev = NULL;
	
	if(list->head == NULL && list->tail == NULL) {
		list->head = node;
		list->tail = node;
	}else if(data <= list->head->data) {
		node->next = list->head;
		list->head->prev = node;
		list->head = node;
	}else if(data >= list->tail->data) {
		node->prev = list->tail;
		list->tail->next = node;
		list->tail = node;
	}else {
		ListNode *cur = list->head;
		while(cur != NULL && data > cur->data) {
			cur = cur->next;
		}
		node->next = cur;
		node->prev = cur->prev;
		cur->prev->next = node;
		cur->prev = node;
	}
}
void delete_head(LinkedList *list) {
	if(list->head == NULL) return;
	ListNode *tmp = list->head;
	list->head = list->head->next;
	if(list->head != NULL) list->head->prev = NULL;
	else list->tail = NULL;
	free(tmp);
}
void delete_tail(LinkedList *list) {
	if(list->tail == NULL) return;
	ListNode *tmp = list->tail;
	list->tail = list->tail->prev;
	if(list->tail != NULL) list->tail->next = NULL;
	else list->head = NULL;
	free(tmp);
}
