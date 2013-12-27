#include "hashmap.h"
#include "internalHashMap.h"
#include <stdlib.h>

HashMap createMap(hash hashFunc, compare compareKey){
        HashMap map = {malloc(sizeof(DoubleList) * 10),hashFunc,compareKey};
        return map;
}
int put(HashMap *map, void *key,void *value){
        int bucketNumber = map->hashFunc(key);
        DoubleList *list;
        list = (DoubleList*)map->bucket + bucketNumber*sizeof(void*);
        insert(list, list->length, value);
        return 1;
}