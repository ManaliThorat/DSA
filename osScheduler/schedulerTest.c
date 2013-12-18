#include "testUtils.h"
#include "scheduler.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int compareInt(void* a , void* b){
    return (*(int*)a - *(int*)b);
}
void test_for_add_front_process(){
       scheduler *q;
        scheduler expected = {NULL,0};
    Process firstProcess = {"p1",3000,7,NULL};
    q = create();
    ASSERT(1 == scheduleProcess(q, &firstProcess,compareInt));
}
void test_for_adding_high_priority_process(){
	scheduler *q;
        scheduler expected = {NULL,0};
    Process firstProcess = {"p1",3000,7,NULL};
    Process secondProcess = {"p2",900,1,NULL};
    q = create();
    ASSERT(1 == scheduleProcess(q, &firstProcess,compareInt));
    ASSERT(2 == scheduleProcess(q, &secondProcess,compareInt));
}
void test_add_process_in_middle(){
	scheduler *q;
        scheduler expected = {NULL,0};
    Process *second,*third;
    Process firstProcess = {"p1",3000,7,NULL};
    Process secondProcess = {"p2",900,1,NULL};
    Process thirdProcess = {"p3",400,2,NULL};
    q = create();
    ASSERT(1 == scheduleProcess(q, &firstProcess,compareInt));
    ASSERT(2 == scheduleProcess(q, &secondProcess,compareInt));
    ASSERT(3 == scheduleProcess(q, &thirdProcess,compareInt));
    ASSERT(q->front == &secondProcess);
}
void test_remove_first(){
	scheduler *q;
   
    Process p1 = {"p1",0,5,NULL};
    q = create();
    scheduleProcess(q, &p1,compareInt);
    ASSERT(0 == removeProcess(q));
}

void test_remove_last_process(){
	scheduler *q;
    Process p1 = {"p1",1000,1,NULL};
    Process p2 = {"p2",10,5,NULL};
    Process p3 = {"p3",0,7,NULL};
    q = create();
    scheduleProcess(q, &p1,compareInt);
    scheduleProcess(q, &p2,compareInt);
    scheduleProcess(q, &p3,compareInt);
    ASSERT(2 == removeProcess(q));
}
void test_remove_processes_in_middle(){
	scheduler *q;
   
    Process p1 = {"p1",1000,1,NULL};
    Process p2 = {"p2",0,5,NULL};
    Process p3 = {"p3",1000,7,NULL};
    q = create();
    scheduleProcess(q, &p1,compareInt);
    scheduleProcess(q, &p2,compareInt);
    scheduleProcess(q, &p3,compareInt);
    ASSERT(2 == removeProcess(q));
}
