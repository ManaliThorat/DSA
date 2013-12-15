#include "testUtils.h"
#include "priority_queue.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


int compareInt (void* a, void* b){
    return (*(int*)a - *(int*)b);
}
list *q;
void test_for_create_a_new_process(){
        list expected = {NULL,0};
    q = create();
    ASSERT(q->front == expected.front);
    ASSERT(q->length == expected.length);
}
void test_for_adding_first_element_integer(){
        int value = 10;
           Queue firstNode = {&value,30,NULL};
        q = create();
        ASSERT(1 == insert(q, &firstNode,compareInt));
}
void test_for_adding_element_integer(){
        int value[] = {10,20};
        list expected = {NULL,0};
    Queue firstNode = {&value,30,NULL};
    Queue secondNode = {&value,20,NULL};
    q = create();
    ASSERT(1 == insert(q, &firstNode,compareInt));
    ASSERT(1 == insert(q, &secondNode,compareInt));
}
void test_for_adding_element_float(){
        float value[] = {20.0,10.0};
        list expected = {NULL,0};
    Queue firstNode = {&value[0],30,NULL};
    Queue secondNode = {&value[1],20,NULL};
    q = create();
    ASSERT(1 == insert(q, &firstNode,compareInt));
    ASSERT(1 == insert(q, &secondNode,compareInt));
}

void test_for_adding_element_string(){
        string value[] = {"shital","manali"};
        list expected = {NULL,0};
    Queue firstNode = {&value[0],30,NULL};
    Queue secondNode = {&value[1],20,NULL};
    q = create();
    ASSERT(1 == insert(q, &firstNode,compareInt));
    ASSERT(1 == insert(q, &secondNode,compareInt));
}
void test_remove_element_priority(){
        int value[] = {10,20,30};
    Queue *second,*third;
    Queue firstNode = {&value[0],40,NULL};
    Queue secondNode = {&value[1],30,NULL};
    Queue thirdNode = {&value[2],20,NULL};
    q = create();
    ASSERT(1 == insert(q, &firstNode,compareInt));
    ASSERT(1 == insert(q, &secondNode,compareInt));
    ASSERT(1 == insert(q, &thirdNode,compareInt));
    second = q->front->next;
    third = second->next;
    ASSERT(1 == removeElement(q));
    ASSERT(1 == removeElement(q));
    ASSERT(1 == removeElement(q));
}

