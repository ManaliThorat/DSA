#include "stack.h"
#include <string.h>
#include <stdlib.h>
stack* create(int elementsSize,int size){
	stack* Stack;
	Stack = malloc(sizeof(stack)*1);
	Stack->elementsSize =elementsSize;
	Stack->size = size;
	Stack->top = -1;
	Stack->elements = calloc(Stack->size,Stack->elementsSize);
	return Stack;
}
int isFull(stack *s){
	return (s->top+1) >= s->size;
}

int push(stack* Stack,void* elementToPush){
	void* address;
	if(isFull(Stack))
		return 0;
	address = Stack->elements+(++(Stack->top)*Stack->elementsSize);
	*(char*)address = *(char*)elementToPush;
	memcpy(address,elementToPush, Stack->elementsSize);
	return 1;
}
int isEmpty(stack* Stack){
	return Stack->top == -1;
}

void* pop(stack* Stack){
	int* a;
	if(isEmpty(Stack))
		return 0;
	a = Stack->elements + ((Stack->top--)*Stack->elementsSize);
	return a;
}
void* top(stack* Stack){
	void* data = Stack->elements;
	return Stack->elements + ((Stack->top)*Stack->elementsSize);
}

