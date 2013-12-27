#include "Iterator.h"
typedef struct {
	void** base;
	int capacity;
	int length;
} ArrayList;

ArrayList create(int capacity);

int insert(ArrayList *list, int index, void* data);

int remove(ArrayList *list, int index);

int search(ArrayList *list, void* data);

int add(ArrayList *, void* data);

void* get(ArrayList *list, int index);

void dispose(ArrayList *list);

Iterator getIterator(ArrayList* list);