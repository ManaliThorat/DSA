#ifndef _ITERATOR_
#define _ITERATOR_

typedef struct iterator{
	int position;
	void* list;
	void* (*hashnext)(struct iterator *it);
	int (*hasNext)(struct iterator *it);
} Iterator;

#endif
