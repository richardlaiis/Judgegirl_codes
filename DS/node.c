#include "node.h"
#include <stdio.h>
struct node *getNode(struct node *head, unsigned int i) {
    struct node *tmp = head;
    int n = 0;
    while(tmp != NULL) {
        n++;
        tmp = tmp->next;

    }
    struct node *tmp2 = head;
    int idx = n-1;
    
    if(i >= n) {
        return NULL;
    }


    while(idx != i) {
        tmp2 = tmp2->next;
        idx--;
    }
    return tmp2;
}