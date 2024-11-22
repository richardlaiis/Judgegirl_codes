#include "heap.h"
void initialize(struct Heap *heap) {
	heap->num = 0;
}
void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
int removeMin(struct Heap *heap) {
	int min = heap->arr[0];

	heap->arr[0] = heap->arr[heap->num-1];
	heap->num--;
	int idx = 0;
	while(1) {
		int left = idx*2+1;
		int right = idx*2+2;
		int min_idx = idx;
		if(left < heap->num && heap->arr[left] < heap->arr[min_idx]) {
			min_idx = left;
		}
		if(right < heap->num && heap->arr[right] < heap->arr[min_idx]) {
			min_idx = right;
		}
		if(min_idx == idx) break;
		swap(&heap->arr[min_idx], &heap->arr[idx]);
		idx = min_idx;
	}
	return min;
}
void add(struct Heap *heap, int i) {
	int idx = heap->num;
	heap->num++;
	heap->arr[idx] = i;
	while(idx != 0 && heap->arr[(idx-1)/2] > heap->arr[idx]) {
		swap(&heap->arr[(idx-1)/2], &heap->arr[idx]);
		idx = (idx-1)/2;
	}
}
int isFull(struct Heap *heap) {
	return heap->num >= MAX_HEAP;
}
int isEmpty(struct Heap *heap) {
	return heap->num == 0;
}
