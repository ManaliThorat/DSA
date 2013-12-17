#include "priority_queue.h"
#include <stdlib.h>

Queue* create(){
    Queue *queue = calloc(sizeof(Queue),1);
    return queue;
}
int addAtStart(Node *node,Queue *queue){
    if(queue->front == NULL)
        node->next = NULL;
    else node->next = queue->front;
    queue->front = node;
    queue->length++;
    return 1;        
}
int insert(Queue *queue,Node *q,compFunc* compare){
    Node *previous,*next,*temp;
    int result;
    temp = queue->front;
    if(queue->length == 0)                
        return addAtStart(q,queue);
           if(compare(&q->priority,&temp->priority) < 0) 
        return addAtStart(q,queue);
    while(temp != NULL){
        previous = temp;
        next = temp->next;
        temp = temp->next;
        if(q->priority < next->priority){
                previous->next = q;
                    q->next = next;
                    return ++queue->length;
        }
    };
    return 0;
}
int removeElement(Queue *queue){
        if(queue->length == 0) return 0;
        queue->front = queue->front->next;
        queue->length--;
    return 1;
}