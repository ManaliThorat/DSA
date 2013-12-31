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
HashMap createHashmap(hash hashFunc, compare compareKey,int capacity){
	HashMap map;
	int i;
	ArrayList buckets = ArrayList_create(10);
	map.buckets = malloc(sizeof(ArrayList));
	*(ArrayList*)map.buckets = buckets;
    map.capacity = capacity;
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
	bucketNumber = (map->hashFunc(key)) % map->capacity;
	data = createHashNode(key, value);
	list = (DoubleList*)ArrayList_get(map->buckets, bucketNumber);
    if(get(map,key))
        removeMap(map,key);
    if(list->length >= 2)
        rehash(map);
	dList_insert(list, list->length, data);
	return 1;
}

void* get(HashMap *map, void *key){
    node* Node;
    Data* data;
    int i;
    DoubleList* list;
    int bucketNumber = map->hashFunc(key) % map->capacity;
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
    int bucketNumber = map->hashFunc(key) % map->capacity;
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
    Iterator it1,it2,result;
    Data *data;
    DoubleList list = dList_create();
    it1 = ArrayList_getIterator(map->buckets);
    while(it1.hasNext(&it1)){
        it2 = dList_getIterator(it1.next(&it1));
        while(it2.hasNext(&it2)){
           data = it2.next(&it2);
           dList_insert(&list, list.length, data->key);
        }
    }
    result = dList_getIterator(&list);
    return result;
}

void rehash(HashMap* map){
    void *key,*value;
    int i,resizeLength = map->capacity * 2;
    Iterator Keys = keys(map);
    for(i = map->capacity;i < resizeLength;i++){
        ArrayList_add(map->buckets, malloc(sizeof(DoubleList)));
        ArrayList_iterate(*(ArrayList*)map->buckets, createListForEachBucket);
    }
    map->capacity = resizeLength;    
    while(Keys.hasNext(&Keys)){
        key = Keys.next(&Keys);
        value = get(map, key);
        removeMap(map , key);
        put(map, key, value);
    }
}

void dispose(HashMap *map){
    int i;
    DoubleList* list;
    Iterator it;
    for(i = 0 ; i < map->capacity ; i++){
        list = (DoubleList*)ArrayList_get(map->buckets,i);
        dList_dispose(*list);
    };
    free(map->buckets);
};
