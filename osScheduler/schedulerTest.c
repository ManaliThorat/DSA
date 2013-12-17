#include "testUtils.h"
#include "scheduler.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int compareInt(void* a , void* b){
    return (*(int*)a - *(int*)b);
}
void test_for_create_a_new_process(){
	scheduler *q;
        scheduler expected = {NULL,0};
    q = create();
    ASSERT(q->front == expected.front);
    ASSERT(q->length == expected.length);
}
void test_for_adding_front_process(){
       scheduler *q;
        scheduler expected = {NULL,0};
    condition status = {0,1,0};
    Process firstProcess = {"firstProcess",3000,status,7,NULL};
    q = create();
    ASSERT(1 == insert(q, &firstProcess,compareInt));
    ASSERT(q->front == &firstProcess);
    ASSERT(q->front->next == NULL);
}
void test_for_adding_high_priority_process(){
	scheduler *q;
        scheduler expected = {NULL,0};
    condition status = {0,1,0};
    Process firstProcess = {"firstProcess",3000,status,7,NULL};
    Process secondProcess = {"secondProcess",900,status,1,NULL};
    q = create();
    ASSERT(1 == insert(q, &firstProcess,compareInt));
    ASSERT(2 == insert(q, &secondProcess,compareInt));
    ASSERT(q->front == &secondProcess);
    ASSERT(q->front->next == &firstProcess);
}
void test_add_process_in_middle(){
	scheduler *q;
        scheduler expected = {NULL,0};
    condition status = {0,1,0};
    Process *second,*third;
    Process firstProcess = {"p1",3000,status,7,NULL};
    Process secondProcess = {"p2",900,status,1,NULL};
    Process thirdProcess = {"p3",400,status,2,NULL};
    q = create();
    ASSERT(1 == insert(q, &firstProcess,compareInt));
    ASSERT(2 == insert(q, &secondProcess,compareInt));
    ASSERT(3 == insert(q, &thirdProcess,compareInt));
    ASSERT(q->front == &secondProcess);
    second = q->front->next;
    third = second->next;
    ASSERT(second == &thirdProcess);
    ASSERT(third == &firstProcess);
    ASSERT(third->next == NULL);
}
void test_remove_first(){
	scheduler *q;
    condition statusp1 = {0,1,0};
    Process p1 = {"p1",0,statusp1,5,NULL};
    q = create();
    insert(q, &p1,compareInt);
    ASSERT(0 == removeProcess(q));
    ASSERT(NULL == q->front);
}

void test_remove_last_process(){
	scheduler *q;
    condition statusp1 = {0,1,0};
    Process p1 = {"p1",1000,statusp1,1,NULL};
    Process p2 = {"p2",10,statusp1,5,NULL};
    Process p3 = {"p3",0,statusp1,7,NULL};
    q = create();
    insert(q, &p1,compareInt);
    insert(q, &p2,compareInt);
    insert(q, &p3,compareInt);
    ASSERT(2 == removeProcess(q));
    ASSERT(q->front->next->next == NULL);
}
void test_remove_processes_in_middle(){
	scheduler *q;
    condition statusp1 = {0,1,0};
    Process p1 = {"p1",1000,statusp1,1,NULL};
    Process p2 = {"p2",0,statusp1,5,NULL};
    Process p3 = {"p3",1000,statusp1,7,NULL};
    q = create();
    insert(q, &p1,compareInt);
    insert(q, &p2,compareInt);
    insert(q, &p3,compareInt);
    ASSERT(2 == removeProcess(q));
    ASSERT(q->front->next == &p3);
}
