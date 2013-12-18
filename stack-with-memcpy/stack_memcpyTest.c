#include "testUtils.h"
#include "stack_memcpy.h"

// #include "testUtils.h"
// #include "stack.h"
#include <stdlib.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed



void test_pushing_an_integer_in_the_stack(){
        Stack* stack = create(sizeof(int));
        int element =10;
        push(stack,&element);
        ASSERT(*(int*)((*stack->top).element) == 10);
        ASSERT((*stack->top).previous == NULL);
};

void test_pop_integer_element_from_the_stack(){
        Stack* stack = create(sizeof(int));
        int element = 10;
        Stack_element* stack_element;
        push(stack,&element);
        stack_element = pop(stack);
        ASSERT(*(int*)stack_element->element == element);
};
void test_pop_float_element_from_the_stack(){
        Stack* stack = create(sizeof(float));
        float element = 10;
        Stack_element* stack_element;
        push(stack,&element);
        stack_element = pop(stack);
        ASSERT(*(float*)stack_element->element == element);
};
void test_pop_double_element_from_the_stack(){
        Stack* stack = create(sizeof(double));
        double element = 10;
        Stack_element* stack_element;
        push(stack,&element);
        stack_element = pop(stack);
        ASSERT(*(double*)stack_element->element == element);
};

void test_pop_integer_element_from_the_empty_stack(){
        Stack* stack = create(sizeof(int));
        int element = 10;
        Stack_element* stack_element;
        push(stack,&element);
        stack_element = pop(stack);
        stack_element = pop(stack);
        ASSERT(stack_element == NULL);
};