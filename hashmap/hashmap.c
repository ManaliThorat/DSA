#include "hashmap.h"
#include "internalHashMap.h"
#include <stdlib.h>

HashMap createMap(hash hashFunc, compare compareKey){
        // ArrayUtil
        HashMap map = {malloc(sizeof(DoubleList) * 10),hashFunc,compareKey};
        return map;
}
int put(HashMap *map, void *key,void *value){
        int bucketNumber = map->hashFunc(key);
        DoubleList *list = (DoubleList*)map->bucket[bucketNumber];
        insert(list, list->length, value);
        return 1;
}
void* get(HashMap *map,void *key){
        void *data = (char*)"manali";
        return data;
}