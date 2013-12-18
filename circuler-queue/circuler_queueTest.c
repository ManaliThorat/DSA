#include "testUtils.h"
#include "circuler_queue.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


void test_enqueue_int_element(){
        Queue* queue;
        int c=5;
        queue = create(sizeof(int),5);
        ASSERT(enqueue(queue,&c));
        free(queue);
}
void test_enqueue_float_element(){
        Queue* queue;
        float c=1.5;
        queue = create(sizeof(float),5);
        queue->rear = 1;
        ASSERT(enqueue(queue,&c));
        free(queue);
}
void test_enqueue_char_element_queue_is_full(){
        Queue* queue;
        char c='m';
        queue = create(sizeof(char),6);
        queue->rear = 5;
        queue->start = -1;
        ASSERT(!enqueue(queue,&c));
        free(queue);
}
void test_enqueue_String_element(){
        Queue* queue;
        String c = "hi";
        queue = create(sizeof(String),5);
        ASSERT(enqueue(queue,&c));
        free(queue);
}
void test_enqueue_int_element_at_middle(){
        Queue* queue;
        int c=10;
        queue = create(sizeof(int),6);
        queue->rear = 3;
        queue->start = 5;
        ASSERT(enqueue(queue,&c));
        free(queue);
}
void test_enqueue_int_element_when_queue_is_full(){
        Queue* queue;
        int c=10;
        queue = create(sizeof(int),6);
        queue->rear = 5;
        queue->start = -1;
        ASSERT(!enqueue(queue,&c));
        free(queue);
}
void test_enqueue_float_element_at_middle(){
        Queue* queue;
        float c=5.90f;
        queue = create(sizeof(float),6);
        queue->rear = 3;
        ASSERT(enqueue(queue,&c));
        free(queue);
}

void test_enqueue_float_element_when_queue_is_full(){
        Queue* queue;
        float c=10.50;
        queue = create(sizeof(float),6);
        queue->rear = 5;
        queue->start = -1;
        ASSERT(!enqueue(queue,&c));
        free(queue);
}

void test_enqueue_String_element_at_middle(){
        Queue* queue;
        String c="manali";
        queue = create(sizeof(String),6);
        queue->rear = 3;
        ASSERT(enqueue(queue,&c));
        free(queue);
}
void test_enqueue_String_element_when_queue_is_full(){
        Queue* queue;
        String c="me";
        queue = create(sizeof(float),6);
        queue->rear = 5;
        queue->start = -1;
        ASSERT(!enqueue(queue,&c));
        free(queue);
}
void test_dequeue_int_element(){
        void* element;
        Queue* queue;
        int data[]={2,3,4};
        queue = create(sizeof(int),5);
        enqueue(queue,&data[0]);
        enqueue(queue,&data[1]);
        enqueue(queue,&data[2]);
        element = dequeue(queue);
        ASSERT(*(int*)element == 2.0f);
}
void test_dequeue_float_element(){
        void* element;
        Queue* queue;
        float data[]={2.0f,3.0f,4.0f};
        queue = create(sizeof(float),5);
        enqueue(queue,&data[0]);
        enqueue(queue,&data[1]);
        enqueue(queue,&data[2]);
        element = dequeue(queue);
        ASSERT(*(float*)element == 2.0f);
}
void test_dequeue_String_element(){
        void* element;
        Queue* queue;
        String data[]={"manali","kajal","Samiksha"};
        queue = create(sizeof(String),5);
        enqueue(queue,&data[0]);
        enqueue(queue,&data[1]);
        enqueue(queue,&data[2]);
        element = dequeue(queue);
        ASSERT(!strcmp(*(String*)element , "manali"));
}