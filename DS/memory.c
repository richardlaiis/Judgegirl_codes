#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
typedef struct freeBlock {
	int start;
	int length;
	struct freeBlock *next;
} FreeBlock;
FreeBlock *getFreeBlock(int start, int length, FreeBlock *next) {
	FreeBlock *block = (FreeBlock *)malloc(sizeof(FreeBlock));
	block->start = start;
	block->length = length;
	block->next = next;
	return block;
}
void initMemory(FreeBlock **head, int length) {
	assert(length > 0);
	*head = getFreeBlock(0, length, NULL);
}
void allocateMemory(FreeBlock **head, int start, int length) {
	FreeBlock *current = *head;
	FreeBlock *before = NULL;
	while(!((start >= current->start) && (start < current->start+current->length))) {
		before = current;
		current = current->next;
		assert(current != NULL);
	}
	bool beginSame = (start == current->start);
	bool endSame = (start + length == current->start + current->length);
	if(beginSame && endSame) {
		if(before == NULL) {
			assert(current == *head);
			*head = current->next;
		}else {
			before->next = current->next;
			free(current);
		}
	}else if(beginSame) {
		current->start += length;
		current->length -= length;
	}else if(endSame) {
		current->length -= length;
	}else {
		FreeBlock *after = getFreeBlock(start+length, (current->start+current->length)-(start+length), current->next);
		current->next = after;
		current->length = start - current->start;
	}
}
void freeMemory(FreeBlock **head, int start, int length) {
	FreeBlock *current = *head;
	FreeBlock *before = NULL;
	while((current != NULL) && start > current->start) {
		before = current;
		current = current->next;
	}
	bool adjBefore = (before != NULL) && (start == before->start + before->length);
	bool adjCurrent = (current != NULL) && (start + length == current->start);

	if(adjBefore && adjCurrent) {
		before->length += (length + current->length);
		before->next = current->next;
		free(current);
	}else if(adjBefore) {
		before->length += length;
	}else if(adjCurrent) {
		current->start -= length;
		current->length += length;
	}else {
		FreeBlock *between = getFreeBlock(start, length, current);
		if(before == NULL) {
			*head = between;
		}else {
			before->next = between;
		}
	}
}
void printMemory(FreeBlock *head) {
	FreeBlock *ptr = head;
	printf("==========\n");
	while(ptr != NULL) {
		printf("start %d, length %d\n", ptr->start, ptr->length);
		ptr = ptr->next;
	}
}
int main() {
	FreeBlock *head = NULL;
	int size;
	scanf("%d", &size);
	initMemory(&head, size);
	printMemory(head);
	for(int i = 0; i < 3; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		allocateMemory(&head, x, y);
		printMemory(head);
	}
	int a, b;
	scanf("%d%d", &a, &b);
	freeMemory(&head, a, b);
	printMemory(head);
}
