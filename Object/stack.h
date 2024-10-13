#ifndef STACK_H
#define STACK_H
#define maxn 1000
#include <stdbool.h>
typedef struct stack {
    int top;
    int data[maxn];
} Stack;

void initStack(Stack *s);
bool stackEmpty(Stack *s);
bool stackFull(Stack *s);
void pushStack(Stack *s, int x);
int popStack(Stack *s);
#endif