#include "hashmap.h"
#include "internalHashMap.h"
#include <stdlib.h>
#include <stdio.h>
#include "arrayList.h"

typedef struct{
    DoubleList dList;
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
    	printf("%dkey\n",*(int*)data->key );
        if (!map->cmp(key ,data->key)){
        	// printf("---------%d %d\n",index,list->length);
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
