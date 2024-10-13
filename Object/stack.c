#include "stack.h"
#include <stdio.h>
#include <stdbool.h>
void initStack(Stack *s) {
    s->top = 0;
}
bool stackEmpty(Stack *s) {
    return s->top <= 0;
}
void pushStack(Stack *s, int x) {
    if(stackFull(s)) {
        printf("Stack is full\n");
        return;
    }
    s->data[s->top++] = x;
}
bool stackFull(Stack *s) {
    return s->top >= maxn;
}
int popStack(Stack *s) {
    if(stackEmpty(s)) {
        printf("Stack is empty\n");
        return (-1);
    }
    return s->data[--s->top];
}