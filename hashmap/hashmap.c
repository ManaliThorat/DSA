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
void* get(HashMap* map,void* key){
    node* node;
    Intern* data;
    int bucketNumber = map->hashFunc(key) % 10;
    DoubleList* list = (DoubleList*)(map->bucket+(sizeof(DoubleList)*bucketNumber));
	if(0 == list->length) return NULL;
    return data;
}