#include "testUtils.h"
#include "circuler_queue.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void test_create__int_elements(){
        int i;
        Queue* queue;
        int test_arr[] = {0,0,0,0,0};
        queue = create(sizeof(int),5);
        i=memcmp(test_arr,queue->elements,5);
        ASSERT(!i);
        ASSERT(queue->elementsSize == 4);
        ASSERT(queue->start == -1);
        ASSERT(queue->rear == -1);
        ASSERT(queue->size == 5);
}
void test_create_float_elements(){
        int i;
        Queue* queue;
        int test_arr[] = {0,0,0,0,0};
        queue = create(sizeof(float),5);
        i=memcmp(test_arr,queue->elements,5);
        ASSERT(!i);
        ASSERT(queue->elementsSize == sizeof(float));
        ASSERT(queue->rear == -1);
        ASSERT(queue->start == -1);
        ASSERT(queue->size == 5);
}
void test_create_char_Strings(){
        int i;
        Queue* queue;
        String test_arr[] = {0,0,0};
        queue = create(sizeof(String),3);
        i=memcmp(test_arr,queue->elements,3);
        ASSERT(!i);
        ASSERT(queue->elementsSize == sizeof(String));
        ASSERT(queue->start == -1);
        ASSERT(queue->rear==-1);
        ASSERT(queue->size == 3);
}
void test_create_characters(){
        int i;
        Queue* queue;
        char test_arr[] = {0,0,0};
        queue = create(sizeof(char),3);
        i=memcmp(test_arr,queue->elements,3);
        ASSERT(!i);
        ASSERT(queue->elementsSize == sizeof(char));
        ASSERT(queue->start == -1);
        ASSERT(queue->rear==-1);
        ASSERT(queue->size == 3);
}
void test_enqueue_char_element(){
        Queue* queue;
        char c='A';
        queue = create(sizeof(char),5);
        ASSERT(enqueue(queue,&c));
        ASSERT(*(char*)(queue->elements)=='A');
        ASSERT(queue->rear==0);
        free(queue);
}

void test_enqueue_char_element_queue_is_full(){
        Queue* queue;
        char c='Q';
        queue = create(sizeof(char),6);
        queue->rear = 5;
        queue->start = -1;
        ASSERT(!enqueue(queue,&c));
        ASSERT(queue->rear == 5);
        free(queue);
}
void test_enqueue_int_element(){
        Queue* queue;
        int c=5;
        queue = create(sizeof(int),5);
        ASSERT(enqueue(queue,&c));
        ASSERT(*(int*)(queue->elements)==5);
        ASSERT(queue->rear==0);
        free(queue);
}
void test_enqueue_float_element(){
        Queue* queue;
        float c=1.5;
        queue = create(sizeof(float),5);
        queue->rear = 1;
        ASSERT(enqueue(queue,&c));
        ASSERT(queue->rear == 2);
        ASSERT(*(float*)(queue->elements+queue->rear*queue->elementsSize)==1.5);
        free(queue);
}
void test_enqueue_String_element(){
        Queue* queue;
        String c = "hi";
        queue = create(sizeof(String),5);
        ASSERT(enqueue(queue,&c));
        ASSERT(!strcmp("hi", *(String*)queue->elements));
        ASSERT(queue->rear == 0);
        free(queue);
}
void test_enqueue_int_element_at_middle(){
        Queue* queue;
        int c=10;
        queue = create(sizeof(int),6);
        queue->rear = 3;
        queue->start = 5;
        ASSERT(enqueue(queue,&c));
        ASSERT(*(int*)(queue->elements+queue->rear*queue->elementsSize) == 10);
        ASSERT(queue->rear == 4);
        free(queue);
}
void test_enqueue_int_element_when_queue_is_full(){
        Queue* queue;
        int c=10;
        queue = create(sizeof(int),6);
        queue->rear = 5;
        queue->start = -1;
        ASSERT(!enqueue(queue,&c));
        ASSERT(queue->rear == 5);
        free(queue);
}
void test_enqueue_float_element_at_middle(){
        Queue* queue;
        float c=5.90f;
        queue = create(sizeof(float),6);
        queue->rear = 3;
        ASSERT(enqueue(queue,&c));
        ASSERT(*(float*)(queue->elements+queue->rear*queue->elementsSize) == 5.90f);
        ASSERT(queue->rear == 4);
        free(queue);
}

void test_enqueue_float_element_when_queue_is_full(){
        Queue* queue;
        float c=10.50;
        queue = create(sizeof(float),6);
        queue->rear = 5;
        queue->start = -1;
        ASSERT(!enqueue(queue,&c));
        ASSERT(queue->rear == 5);
        free(queue);
}

void test_enqueue_String_element_at_middle(){
        Queue* queue;
        String c="manali";
        queue = create(sizeof(String),6);
        queue->rear = 3;
        ASSERT(enqueue(queue,&c));
        ASSERT(!strcmp(*(String*)(queue->elements+queue->rear*queue->elementsSize) , "manali"));
        ASSERT(queue->rear == 4);
        free(queue);
}
void test_enqueue_String_element_when_queue_is_full(){
        Queue* queue;
        String c="me";
        queue = create(sizeof(float),6);
        queue->rear = 5;
        queue->start = -1;
        ASSERT(!enqueue(queue,&c));
        ASSERT(queue->rear == 5);
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
        ASSERT(queue->rear == 2);
        ASSERT(queue->start == 0);
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
        ASSERT(queue->rear == 2);
        ASSERT(queue->start == 0);
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
        ASSERT(queue->rear == 2);
        ASSERT(queue->start == 0);
}