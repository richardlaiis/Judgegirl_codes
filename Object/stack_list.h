#include <stdbool.h>

struct listnode {
    int data;
    struct listnode *next;
};
typedef struct listnode ListNode;
struct stack {
    ListNode *top;
};
typedef struct stack Stack;
void initStack(Stack *s);
bool stackEmpty(Stack *s);
void pushStack(Stack *s, int x);
char popStack(Stack *s);