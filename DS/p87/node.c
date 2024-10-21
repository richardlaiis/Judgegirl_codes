#include <stdio.h>
struct node {
    int value;
    struct node * next;
};
 
struct node *merge(struct node *list1, struct node *list2) {
	//if(list1->next == NULL) return list1;
	//if(list2->next == NULL) return list2;
	if(list1 == NULL && list2 != NULL) {
		return list2;
	}else if(list1 != NULL && list2 == NULL) {
		return list1;
	}else if(list1 == NULL && list2 == NULL) {
		return NULL;
	}
	if(list1->value < list2->value) {
		list1->next = merge(list1->next, list2);
		return list1;
	}else {
		list2->next = merge(list1, list2->next);
		return list2;
	}
}
