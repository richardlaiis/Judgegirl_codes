#include <stdio.h>
#include <stdbool.h>
#include "stack.h"
int main() {
    Stack s;
    initStack(&s);
    pushStack(&s, 1);
    pushStack(&s, 2);
    pushStack(&s, 3);
    printf("%d\n", popStack(&s));
}