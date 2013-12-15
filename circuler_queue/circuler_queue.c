#include "circuler_queue.h"
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
Queue* create(int elementsSize, int size){
        Queue* queue = (Queue*)calloc(1,sizeof(Queue));
        queue->start=-1;
        queue->rear=-1;
        queue->elements= calloc(size,elementsSize);
        queue->size=size;
        queue->elementsSize=elementsSize;
        return queue;
}
int isFull(Queue* queue){
        if((queue->rear == queue->size-1 && queue->start==-1) || queue->start-queue->rear==1)
                return 1;
        return 0;
}
int enqueue(Queue* queue,void* element){
        if(isFull(queue)) return false;
        if(queue->rear==queue->size-1) queue->rear=-1;
        queue->rear++;
        if(memcpy((queue->elements+(queue->elementsSize*queue->rear)) , element,queue->elementsSize))
                return true;
        return false;
}
int isEmpty(Queue* queue){
        if(queue->rear == queue->start)
                return 1;
        return 0;
}
void* dequeue(Queue* queue){
        void* element=malloc(queue->elementsSize);
        if(isEmpty(queue)) return 0;
        queue->start++;
        memcpy( element,(queue->elements+(queue->elementsSize*queue->start)) ,queue->elementsSize);
        return element;
}