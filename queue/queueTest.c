#include "testUtils.h"
#include "queue.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
int areEqual(Queue* actual,Queue* expected){
        return (actual->elementsSize == expected->elementsSize) && 
        (actual->size == expected->size) &&
        (actual->rear == expected->rear) && 
        (0 == memcmp(expected->elements,actual->elements,expected->size*expected->elementsSize));
}

void test_create_queue(){
		Queue* queue;
        int arr[] = {0,0};
        Queue expected = {arr,2,sizeof(int),-1};
        queue = create(sizeof(int),2);
        ASSERT(areEqual(queue,&expected));
        free(queue);
}

void test_enqueue_integer(){
		Queue *queue;
        int arr[] = {1,0};
        int result;
        int element = 1;
        Queue expected = {arr,2,sizeof(int),0};
        queue = create(sizeof(int),2);
        result = enqueue(queue,&element);
        ASSERT(result==1);
        free(queue);
}
void test_enqueue_float(){
		Queue *queue;
        float arr[] = {1.0,2.0};
        int result;
        float element = 1.1;
        Queue expected = {arr,2,sizeof(float),0};
        queue = create(sizeof(float),2);
        result = enqueue(queue,&element);
        ASSERT(result==1);
        free(queue);
}
void test_enqueue_character(){
		Queue *queue;
        char arr[] = {'a',' '};
        int result;
        char element = 'a';
        Queue expected = {arr,2,sizeof(char),0};
        queue = create(sizeof(char),2);
        result = enqueue(queue,&element);
        ASSERT(result==1);
        free(queue);
}
void test_enqueue_string(){
		Queue *queue;
        String arr[] = {"manali","kajal"};
        int result;
        String element = "manali";
        Queue expected = {arr,2,sizeof(String),0};
        queue = create(sizeof(String),2);
        result = enqueue(queue,&element);
        ASSERT(result==1);
        free(queue);
}
void test_dequeue_interger_queue(){
		Queue *queue;
        int result;
        int arr[] = {1,2};
        int _1 = 1;
        int _2 = 2;
        int removedElement;
        Queue expected = {arr,2,sizeof(int),1};
        queue = create(sizeof(int),2);
        result = enqueue(queue,&_1);
        result = enqueue(queue,&_1);
        removedElement = *(int*)dequeue(queue);
        result = enqueue(queue,&_2);
        ASSERT(areEqual(queue,&expected));
        free(queue);
}
void test_dequeue_float_queue(){
		Queue *queue;
        int result;
        float element = 1.1;
        float element1 = 1.2;
        float removedElement;
        queue = create(sizeof(float),2);
        result = enqueue(queue,&element);
        result = enqueue(queue,&element1);
        removedElement = *(float*)dequeue(queue);
        ASSERT(removedElement == 1.2f);
        free(queue);
}
void test_dequeue_character_queue(){
		Queue *queue;
        int result;
        char element = 'a';
         char element1 = 'b';
        char res;
        queue = create(sizeof(char),2);
        result = enqueue(queue,&element);
        result = enqueue(queue,&element1);
        res = *(char*)dequeue(queue);
        ASSERT(res == 'b');
        free(queue);
}
void test_dequeue_String_queue(){
		Queue *queue;
        int result;
        String element = "manali";
        queue = create(sizeof(String),2);
        result = enqueue(queue,&element);
        result = enqueue(queue,&element);
        ASSERT(strcmp(dequeue(queue),"manali")==0);
        free(queue);
}