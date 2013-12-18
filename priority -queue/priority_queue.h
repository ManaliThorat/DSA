#include <stdlib.h>
void* createQueue();
typedef int compare(void*,void*);
int enqueue(void* queue,void* data, size_t priority,compare* comp);
void* dequeue(void* queue);