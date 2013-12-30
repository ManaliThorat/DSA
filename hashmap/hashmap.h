#include "iterator.h"

#ifndef _COMPARE_
#define _COMPARE_
typedef int (*compare)(void* firstElement, void* secondElement);
typedef int (*hash)(void *key);
#endif	
typedef struct {
	void *buckets;
	hash hashFunc;
	compare cmp;
} HashMap;

HashMap createHashmap(hash hashFunc, compare compareKey);
int put(HashMap* map, void* key, void* value);
void* get(HashMap* map, void* key);
int removeMap(HashMap* map, void* key);
Iterator keys(HashMap* map);
