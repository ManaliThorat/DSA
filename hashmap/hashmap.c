#include "hashmap.h"
#include "internalHashMap.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct{
    DoubleList* dList;
} Bucket;
HashMap* createHashMap(hash hashFunc, compare compareKey){
	HashMap* map = calloc(1, sizeof(HashMap));
	map->bucket = calloc(10, sizeof(void*));
	map->cmp = compareKey;
	map->hashFunc = hashFunc;
    return map;
}
Intern* createHashNode(void *key, void *value){
	Intern* intern = malloc(sizeof(Intern));
	intern->key = key;
	intern->value = value;
	return intern;
}

int put(HashMap *map, void *key,void *value){
    int bucketNumber = map->hashFunc(key);
    Intern *intern = (Intern*)createHashNode(key,value);
    DoubleList *list = (DoubleList*)map->bucket+bucketNumber*sizeof(void*);
    return insert(list, list->length, intern);
}
void* get(HashMap *map, void *key){
    node* Node;
    Intern* data;
    int i;
    int bucketNumber = map->hashFunc(key);
    DoubleList *list = (DoubleList*)map->bucket+bucketNumber*sizeof(void*);
    if(0 == list->length) return NULL;
    Node = (node*)list->head;
    for(i=0;i<list->length;i++){
    	data = (Intern*)Node->data;
        if (!map->cmp(key ,data->key)) return data->value;
        Node = Node->next;
    }
    return NULL;
}
int removeMap(HashMap* map, void* key) { 
    node* Node;
    Intern* data;
    int i,index = 1;
    int bucketNumber = map->hashFunc(key);
    DoubleList *list = (DoubleList*)map->bucket+bucketNumber*sizeof(void*);
    if(0 == list->length) return 0;
    Node = (node*)list->head;
    for(i = 0; i< list->length ; i++){
    	data = (Intern*)Node->data;
        if (!map->cmp(key ,data->key)){
			delete(list,index-1);
        	break;
        }
        else{
        	Node = Node->next;
        	index++;
    	}
    }
    return 1;
}
void* hashNext(Iterator* it){
	Intern* list;
	Iterator hashIterator = getIterator(it->list);
	hashIterator.position = it->position;
	list = hashIterator.hashnext(&hashIterator);
	it->position++;
	return list->key;
}
Iterator keys(HashMap* map){
	DoubleList* dList;
    Bucket *bucket;
	int i;
	Bucket* temp;
	Iterator it;
	for(i = 0;i <= 9;i++){
        dList = (DoubleList*)map->bucket +(i *sizeof(void*));
        while(!hasNext(it))
        printf("comming\n");
        it = getIterator(bucket->dList);
        it.hashnext = &hashNext;
	}
	return it;
}
