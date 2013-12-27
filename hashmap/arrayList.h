#include "Iterator.h"
typedef struct {
	void** base;
	int capacity;
	int length;
} ArrayList;

ArrayList create_arrayList(int capacity);

int arrayList_insert(ArrayList *list, int index, void* data);

int arrayList_remove(ArrayList *list, int index);

int arrayList_search(ArrayList *list, void* data);

int arrayList_add(ArrayList *, void* data);

void* arrayList_get(ArrayList *list, int index);

void arrayList_dispose(ArrayList *list);

// Iterator getIterator(ArrayList* list);