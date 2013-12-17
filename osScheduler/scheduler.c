#include "scheduler.h"
#include <stdlib.h>

scheduler* create(){
    scheduler *queue = calloc(sizeof(scheduler),1);
    return queue;
}
int frontAdd(scheduler *queue, Process *process){
    if(queue->front == NULL)
        process->next = NULL;
    else process->next = queue->front;
    queue->front = process;
    queue->length++;
    return queue->length;        
}
int insert(scheduler *queue, Process *process,compFunc* compare){
    Process *previous,*next,*temp;
    int i;
    temp = queue->front;
    if(queue->length == 0 || (compare(&process->priority,&temp->priority) < 0))                
        return frontAdd(queue, process);
    for(i=0;temp->next != NULL;temp = temp->next){
        previous = temp;
        next = temp->next;
        if(process->priority < next->priority){
            previous->next = process;
            process->next = next;
            return ++queue->length;
        }
    };
    temp->next = process;
    process->next = NULL;
    return ++queue->length;
}
int removeProcess(scheduler *queue){
    Process *temp,*previous,*next;
    int i;
    temp = queue->front;
    if(queue->length == 1){
        if(temp->processTime == 0)
            queue->front = NULL;
        return --queue->length;
    }
    if(temp->processTime == 0)
        queue->front = temp->next;
    for(i=0;temp->next != NULL;temp = temp->next){
        previous = temp;
        next = temp->next;
        if(next->processTime == 0){
            previous->next = next->next;
            return --queue->length;
        }
    }
    if(temp->next == NULL){
        previous->next = NULL;
        return --queue->length;
    };
    return 0;
}