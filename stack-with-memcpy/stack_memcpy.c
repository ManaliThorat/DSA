#include "stack_memcpy.h"
#include <string.h>
#include <stdlib.h>
Stack* create(int typeSize){
        Stack* stack = calloc(1,sizeof(Stack));
        stack->top = NULL;
        stack->typeSize = typeSize;
        stack->elements = 0;
        return stack;
};
void push(Stack* stack,void* element){
        Stack_element* stack_element = calloc(1,sizeof(Stack_element));
        int *elementToPush = (int*)calloc(1,stack->typeSize);
        memcpy(elementToPush,element,stack->typeSize);
        stack_element->element = elementToPush;
        if(stack->top == NULL){
                stack_element->previous = NULL;
                stack->top = stack_element;
        }
        else {
                stack_element->previous = stack->top;
                stack->top = stack_element;
        }
        stack->elements++;
};

Stack_element* pop(Stack* stack){
        Stack_element *stack_element;
        Stack_element* elementToPop;
        if(stack->top == NULL)
                return NULL;
        stack_element = calloc(1,sizeof(Stack_element));
        elementToPop = stack->top;
        stack_element->element = calloc(1,stack->typeSize);
        memcpy(stack_element->element, stack->top->element,stack->typeSize);
        stack->top = (*stack->top).previous;
        elementToPop->previous = NULL;
        free(elementToPop->element);
        free(elementToPop);
        return stack_element;
};