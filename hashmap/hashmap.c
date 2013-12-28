#include "hashmap.h"
#include "internalHashMap.h"
#include <stdlib.h>
#include <stdio.h>
#include "arrayList.h"

HashMap* createHashMap(hash hashFunc, compare compareKey){
	HashMap* map = calloc(1, sizeof(HashMap));
	map->bucket = calloc(10, sizeof(DoubleList));
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
    Intern *intern = createHashNode(key,value);
    DoubleList *list = (DoubleList*)(map->bucket+(bucketNumber*sizeof(DoubleList)));
    insert(list, list->length, intern);
    return 1;
}
void* get(HashMap *map, void *key){
    node* node;
    Intern* data;
    int i;
    int bucketNumber = map->hashFunc(key);
    DoubleList *list = (DoubleList*)(map->bucket+(bucketNumber*sizeof(DoubleList)));
    if(0 == list->length) return NULL;
    node = list->head;
    for(i=0;i<list->length;i++){
    	data = node->data;
        if (!map->cmp(key ,data->key)) return data->value;
        node = node->next;
    }
    return NULL;
}
int removeMap(HashMap* map, void* key) { 
    node* node;
    Intern* data;
    int i,index = 1;
    int bucketNumber = map->hashFunc(key);
    DoubleList *list = (DoubleList*)(map->bucket+(bucketNumber*sizeof(DoubleList)));
    if(0 == list->length) return 0;
    node = list->head;
    for(i=0;i<list->length;i++){
    printf("-----%d   %d\n", list->length,index);

    	data = node->data;
        if (map->cmp(key ,data->key)){
         node = node->next;
        index++; 
        	delete(list,index);
        }	
    printf("-----%d   %d\n", list->length,index);

       
    }
    printf("-----%d\n", list->length);
    delete(list,index);
    // printf("%d\n", list->length);

    return 1;

}
