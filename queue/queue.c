#include "queue.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
bool isFull(Queue *queue){
        if(queue->rear==queue->size-1)
        	return 1;
        return 0;
}
bool isEmpty(Queue *queue){
        if(queue->rear==-1)
        	return 1;
        return 0;
}

Queue* create(int elementSize,int size){
        Queue *queue = calloc(1,sizeof(Queue));
        queue->elements = calloc(size,elementSize);
        queue->size = size;
        queue->elementsSize = elementSize;
        queue->rear = -1;
        return queue;
}
int enqueue(Queue *queue,void* element){
        if(isFull(queue)) return 0;
        queue->rear++;
        memcpy(queue->elements+(queue->rear*queue->elementsSize),element,queue->elementsSize);
        return 1;
}
void* dequeue(Queue *queue){
        void* element;
        if(isEmpty(queue))        return NULL;
        element = queue->elements+queue->elementsSize;
        memmove(queue->elements,queue->elements+queue->elementsSize,queue->elementsSize*queue->rear);
        queue->rear--;
        return element;
}