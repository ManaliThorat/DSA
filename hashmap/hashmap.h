#include "iterator.h"

#ifndef _COMPARE_
#define _COMPARE_
typedef int (*compare)(void* firstElement, void* secondElement);
typedef int (*hash)(void *key);
#endif        
typedef struct {
        void *bucket;
        hash hashFunc;
        compare cmp;
} HashMap;

typedef struct{
        void* key;
        void* value;
} Intern;
HashMap* createHashMap(hash hashFunc, compare compareKey);
Intern* createHashNode(void *key, void *value);
int put(HashMap* map,void* key,void* value);
void* get(HashMap* map,void* key);
int removeMap(HashMap* map, void* kay);
Iterator keys(HashMap* map);