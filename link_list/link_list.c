#include "link_list.h"
#include <stdlib.h>

List* create(){
        List *list = malloc(sizeof(List));
        list->length = 0;
        list->head = NULL;
        return list;
}
Node* createNode(void* previous,void* next){
        Node* node = malloc(sizeof(Node));
        node->previous = previous;
        node->next = next;
        return node;
}

int add(List* list,int index,void * element){
        int i;
        Node *prevAdr;
        Node *nextAdr;
        Node *nodeToAdd;
        if(index > list->length) 
            return 0;
        list->length++;
        nodeToAdd = createNode(NULL,NULL);
        nodeToAdd->data = element;
        prevAdr = list->head;
        if(list->head == NULL){
                nextAdr = NULL;
                list->head = nodeToAdd;
        }
        else
                nextAdr = prevAdr->next;
        for(i=1;i<index;i++){
                nextAdr = prevAdr->next;
                prevAdr = nextAdr->previous;
        }
        nodeToAdd->previous = prevAdr;
        if(prevAdr != NULL)
            prevAdr->next = nodeToAdd;
        nodeToAdd->next = nextAdr;
        
        return 1;
}
int removeElement(List* list,int index){
        int i;
        Node *head;
        if(index > list->length-1)
                return 0;
        head = list->head;
        for(i=0;i<index;i++){
                head = head->next;
        }
        if(i==0){   
                list->length--;
                return 1;
        }
        if(i==list->length-1){
                head->previous = NULL;
                list->length--;
                return 1;
        }
        head->previous = head->next;
    head->next = head->previous;
    free(head);
    list->length--;
    return 1;
};