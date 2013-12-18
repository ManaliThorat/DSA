#include "testUtils.h"
#include "priority_queue.h"
#include "customType.h"
#include <string.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int compareInt(void* a,void* b){
    return (*(int*)a - *(int*)b );
}


void test_1_enqueues_an_integer_element_in_empty_queue_and_gives_back_that_element_when_dequeued(){
    void* queue = createQueue();
    int value = 10;
    ASSERT(1 == enqueue(queue, &value,30,compareInt));
    ASSERT(value == *(int*)dequeue(queue));
};

void test_2_enqueues_the_integer_elements_in_queue_and_dequeue_the_top_element(){
    void* queue = createQueue();
    int value[] = {10,15};
    ASSERT(1 == enqueue(queue, &value[0],30,compareInt));
    ASSERT(1 == enqueue(queue, &value[1],20,compareInt));
    ASSERT(value[1] == *(int*)dequeue(queue));
};


void test_4_enqueues_an_float_element_in_empty_queue_and_gives_back_that_element_when_dequeued(){
    void* queue = createQueue();
    float value[] = {10.0,15.0};
    ASSERT(1 == enqueue(queue, &value[0],30,compareInt));
    ASSERT(1 == enqueue(queue, &value[1],40,compareInt));
    ASSERT(value[1] == *(float*)dequeue(queue));
};


void test_6_enqueues_an_double_element_in_empty_queue_and_gives_back_that_element_when_dequeued(){
   void* queue = createQueue();
    double value[] = {10.0,15.0};
    ASSERT(1 == enqueue(queue, &value[0],30,compareInt));
    ASSERT(1 == enqueue(queue, &value[1],40,compareInt));
    ASSERT(value[1] == *(double*)dequeue(queue));
};

void test_7_enqueues_the_double_elements_in_queue_and_dequeue_the_top_element(){
    void* queue = createQueue();
    double value[] = {10.0,15.0};
    ASSERT(1 == enqueue(queue, &value[0],30,compareInt));
    ASSERT(1 == enqueue(queue, &value[1],40,compareInt));
    ASSERT(value[1] == *(double*)dequeue(queue));
};

void test_8_enqueues_an_character_element_in_empty_queue_and_gives_back_that_element_when_dequeued(){
    void* queue = createQueue();
    char value = 'k';
    ASSERT(1 == enqueue(queue, &value,30,compareInt));
    ASSERT(value == *(char*)dequeue(queue));
};

void test_9_enqueues_the_characters_elements_in_queue_and_dequeue_the_top_element(){
    void* queue = createQueue();
    char value[] = {'m','t'};
    ASSERT(1 == enqueue(queue, &value[0],30,compareInt));
    ASSERT(1 == enqueue(queue, &value[1],40,compareInt));
    ASSERT(value[1] == *(char*)dequeue(queue));
};

void test_10_enqueues_an_String_element_in_empty_queue_and_gives_back_that_element_when_dequeued(){
   void* queue = createQueue();
    String value = "manali";
    ASSERT(1 == enqueue(queue, &value,30,compareInt));
    ASSERT(value == *(String*)dequeue(queue));
};

void test_11_enqueues_the_String_elements_in_queue_and_dequeue_the_top_element(){
     void* queue = createQueue();
    String value[] = {"manali","kajal"};
    ASSERT(1 == enqueue(queue, &value[0],30,compareInt));
    ASSERT(1 == enqueue(queue, &value[1],40,compareInt));
    ASSERT(value[1] == *(String*)dequeue(queue));
};