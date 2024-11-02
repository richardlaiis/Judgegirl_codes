#include <stdlib.h>
#include <stdio.h>
#include "stack_list.h"
#include <assert.h>
void initStack(Stack *s) {
    s->top = NULL;
}
bool stackEmpty(Stack *s) {
    return s->top == NULL;
}
void pushStack(Stack *s, int x) {
    ListNode *cur = (ListNode *)malloc(sizeof(ListNode));
    assert(cur != NULL);
    cur->data = x;
    cur->next = s->top;
    s->top = cur;
}
void popStack(Stack *s) {
    assert(!stackEmpty(s));
    ListNode *cur = s->top;
    s->top = s->top->next;
    int x = cur->data;
    free(cur);
}