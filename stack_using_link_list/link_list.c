#include "link_list.h"
#include <stdlib.h>
Node* createNode(void* previous,void* next){
        Node* node = calloc(1,sizeof(Node));
        node->previous = previous;
        node->next = next;
        return node;
}
List* create(){
        List* list = calloc(1,sizeof(List));
        list->length = 0;
        list->head = NULL;
        return list;
}
int add(List* dList,int index,void* element){
        int i=1;
        Node* nodeToAdd = createNode(NULL,NULL);
        Node *previousNode;
        Node *nextNode = NULL;
        
        if(index > dList->length) return 0;
        nodeToAdd->data = element;
        if(dList->head == NULL){
                dList->head = nodeToAdd;
                dList->length++;
                return 1;
        }
        previousNode = dList->head;
        while(i < index){
                previousNode = previousNode->next;
                if(previousNode!= NULL)
                    nextNode = previousNode->next;
                i++;
        }
        previousNode->next = nodeToAdd;
        if(nextNode != NULL)
            nextNode->previous = nodeToAdd;
        nodeToAdd->previous = previousNode;
        nodeToAdd->next = nextNode;
        dList->length++;
        return 1;
}
void* removeElement(List* list,int index){
        int i;
        Node *head;
        void* data;
        if(index > list->length-1)
                return 0;
        head = list->head;
        for(i=0;i < index ;i++){
            head = head->next;
        }
        data = head->data;
        if(i==0){   
            list->length--;
        }
        if(i==list->length-1){
            head->previous = NULL;
            list->length--;
        }
        head->previous = head->next;
        head->next = head->previous;
    free(head);
    list->length--;
    return data;
};