#include "arrayList.h"
#include <stdlib.h>

ArrayList create_arrayList(int capacity) {
	ArrayList list;
	list.base = (void*)malloc(sizeof(void*) * capacity);
	list.capacity = capacity;
	list.length = 0;
	return list;
}

void shiftElementsIfNeeded(ArrayList *list, int index){
	int i;
	if (index < list->length) {
		for (i = list->length - 1; i >= index; i--){
			list->base[i+1] = list->base[i];
		}
	}	
}
void shiftElementsLeft(ArrayList *list, int index){
	int i;
	if (index < list->length){
		for (i = 0; i <= list->length; i++){
			list->base[i] = list->base[i+1];
		}
	}	
}

int isFull(ArrayList *list){
	return list->length == list->capacity;
}

void increaseCapacity(ArrayList *list){
	int targetCapacity;
	if (isFull(list)){
		targetCapacity = list->capacity * 2;
		list->base = realloc(list->base, targetCapacity * sizeof(void*));
		list->capacity = targetCapacity;
	}	
}

int arrayList_insert(ArrayList *list, int index, void* data){
	if (list == NULL) return 0;
	if (index < 0 || index > list->length) return 0;

	increaseCapacity(list);
	shiftElementsIfNeeded(list, index);

	list->base[index] = data;
	list->length++;
	return 1;
}

int arrayList_remove(ArrayList *list, int index){
	if (list == NULL) return 0;
	if (index < 0 || index > list->length) return 0;
	shiftElementsLeft(list, index);
	return 1;
}

int arrayList_search(ArrayList *list, void* data){
	int i;
		for (i = 0; i <= list->length; i++){
			if(list->base[i]== data) return 1;
		}
		return 0;
	}	

void* arrayList_get(ArrayList *list, int index){
	if (index < 0 || index >= list->length) return NULL;
	return list->base[index];
}
int arrayList_add(ArrayList *list, void* data){
	int index = list->length;
	if (list == NULL) return 0;
	increaseCapacity(list);
	shiftElementsIfNeeded(list, index);

	list->base[index] = data;
	list->length++;
	return 1;

}
// int hasNext(Iterator* it){
//     ArrayList *list = it->list;
//     if(list->length <= it->position) return 0;
//     return 1;
// }
// void* next(Iterator* it){
//         ArrayList* list = it->list;
//     if(!hasNext(it)) return NULL;
//     return list->base[it->position++];
// }

// Iterator getIterator(ArrayList* list){
//     Iterator it;
//     it.list = list;
//     it.position = 0;
//     it.hasNext = &hasNext;
//     it.next = &next;
//     return it;
// }
void arrayList_dispose(ArrayList *list){
	free(list->base);
}
