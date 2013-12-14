#include "LLstack.h"
#include <stdlib.h>

int push(List* list,void* element){
		int result;
        int index = list->length-1;
 		result = add(list,index,element);
 		return result;       
}
void* pop(List* list){
		void* result;
        int index = list->length-1;
        result = removeElement(list,index);
        return result;
};
void* top(List* list){
	Node *head;
	int i,index;
        void* data;
        if(index > list->length-1)
                return 0;
        head = list->head;
        for(i=0;i<index;i++){
                head = head->next;
        }
        data = head->data;
        return data;
}

