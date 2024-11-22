#ifndef HEAP_H
#define HEAP_H
#define MAX_HEAP 100
 
struct Heap{
    int arr[MAX_HEAP];
    int num;
};
 
void initialize(struct Heap *heap);
int removeMin(struct Heap *heap);
void add(struct Heap *heap, int i);
int isFull(struct Heap *heap);
int isEmpty(struct Heap *heap);
void swap (int *a, int *b);
#endif
