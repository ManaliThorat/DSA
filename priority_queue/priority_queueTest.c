#include "testUtils.h"
#include "priority_queue.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int compareInt (void* a, void* b){
    return (*(int*)a - *(int*)b);
}
Queue *q;
void test_for_adding_first_element_integer(){
    int value = 10;
    Node firstNode = {&value,30,NULL};
    q = create();
    ASSERT(1 == insert(q, &firstNode,compareInt));
}
void test_for_adding_element_integer(){
    int value[] = {10,20};
    Queue expected = {NULL,0};
    Node firstNode = {&value,30,NULL};
    Node secondNode = {&value,20,NULL};
    q = create();
    ASSERT(1 == insert(q, &firstNode,compareInt));
    ASSERT(1 == insert(q, &secondNode,compareInt));
}
void test_for_adding_element_float(){
        float value[] = {20.0,10.0};
        Queue expected = {NULL,0};
    Node firstNode = {&value[0],30,NULL};
    Node secondNode = {&value[1],20,NULL};
    q = create();
    ASSERT(1 == insert(q, &firstNode,compareInt));
    ASSERT(1 == insert(q, &secondNode,compareInt));
}

void test_for_adding_element_string(){
        string value[] = {"shital","manali"};
        Queue expected = {NULL,0};
    Node firstNode = {&value[0],30,NULL};
    Node secondNode = {&value[1],20,NULL};
    q = create();
    ASSERT(1 == insert(q, &firstNode,compareInt));
    ASSERT(1 == insert(q, &secondNode,compareInt));
}
void test_remove_element_priority(){
        int value[] = {10,20,30};
    Node *second,*third;
    Node firstNode = {&value[0],40,NULL};
    Node secondNode = {&value[1],30,NULL};
    Node thirdNode = {&value[2],20,NULL};
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
void test_remove_element_priority_float(){
        float value[] = {1.0,2.0,3.0};
    Node *second,*third;
    Node firstNode = {&value[0],40,NULL};
    Node secondNode = {&value[1],30,NULL};
    Node thirdNode = {&value[2],20,NULL};
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
void test_remove_element_priority_double(){
       double value[] = {1.000000,2.000000,3.000000};
    Node *second,*third;
    Node firstNode = {&value[0],40,NULL};
    Node secondNode = {&value[1],30,NULL};
    Node thirdNode = {&value[2],20,NULL};
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

void test_remove_element_priority_char(){
       char value[] = {'m','a','n'};
    Node *second,*third;
    Node firstNode = {&value[0],40,NULL};
    Node secondNode = {&value[1],30,NULL};
    Node thirdNode = {&value[2],20,NULL};
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

