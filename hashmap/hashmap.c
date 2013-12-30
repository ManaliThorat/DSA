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
	Data *data = malloc(sizeof(Data));
	data->key = key;
	data->value = value;
	return data;
}

int put(HashMap *map, void *key, void *value){
	DoubleList *list;
	Data *data;
	int bucketNumber;
	bucketNumber = (map->hashFunc(key)) % 10;
	data = createHashNode(key, value);
	list = (DoubleList*)ArrayList_get(map->buckets, bucketNumber);
	dList_insert(list, list->length, data);
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

Iterator keys(HashMap *map){
        Iterator it1;
        Iterator it2;
        Iterator result;
        Data *data;
        DoubleList list = dList_create();
        it1 = ArrayList_getIterator(map->buckets);
        while(it1.hasNext(&it1)){
            it2 = dList_getIterator(it1.next(&it1));
            while(it2.hasNext(&it2)){
               data = it2.next(&it2);
                dList_insert(&list, 0, data->key);
            }
        }
        result = dList_getIterator(&list);
        return result;
}
