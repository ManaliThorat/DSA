#include "hashmap.h"
#include "dList.h"
#include "ArrayList.h"
#include "internalHashMap.h"
#include <stdlib.h>
#include <stdio.h>
void createListForEachBucket(void *bucket){
	DoubleList list;
	list  = dList_create();
	*(DoubleList*)bucket = list;
}
HashMap createHashmap(hash hashFunc, compare compareKey){
	HashMap map;
	int i;
	ArrayList buckets = ArrayList_create(10);
	map.buckets = malloc(sizeof(ArrayList));
	*(ArrayList*)map.buckets = buckets;
	map.cmp = compareKey;
	map.hashFunc = hashFunc;
	for(i = 0;i < 10;i++)
		ArrayList_add(map.buckets, malloc(sizeof(DoubleList)));
	ArrayList_iterate(*(ArrayList*)map.buckets, createListForEachBucket);
	return map;
}
Data* createHashNode(void *key, void *value){
	Data *hash_node = malloc(sizeof(Data));
	hash_node->key = key;
	hash_node->value = value;
	return hash_node;
}

int put(HashMap *map, void *key, void *value){
	DoubleList *list;
	Data *hash_node;
	int bucketNumber;
	bucketNumber = (map->hashFunc(key)) % 10;
	hash_node = createHashNode(key, value);
	list = (DoubleList*)ArrayList_get(map->buckets, bucketNumber);
	dList_insert(list, list->length, hash_node);
	return 1;
}

void* get(HashMap *map, void *key){
    node* Node;
    Data* data;
    int i;
    DoubleList* list;
    int bucketNumber = map->hashFunc(key) % 10;
    list = (DoubleList*)ArrayList_get(map->buckets, bucketNumber);
    if(0 == list->length) return NULL;
    Node = (node*)list->head;
    for(i=0;i<list->length;i++){
            data = (Data*)Node->data;
        if (!map->cmp(key ,data->key)) return data->value;
        Node = Node->next;
    }
    return NULL;
}

int removeMap(HashMap* map, void* key) { 
    node* Node;
    Data* data;
    int i,index = 0;
    int bucketNumber = map->hashFunc(key) % 10;
    DoubleList *list = (DoubleList*)ArrayList_get(map->buckets, bucketNumber);
    if(0 == list->length) return 0;
    Node = (node*)list->head;
    for(i = 0; i< list->length ; i++){
            data = (Data*)Node->data;
        if (!map->cmp(key ,data->key)){
            dList_delete(list,index);
            break;
        }
        else{
            Node = Node->next;
            index++;
        }
    }
    return 1;
}
