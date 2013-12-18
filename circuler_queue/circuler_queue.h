typedef struct{
	void *elements;
	int start;
	int rear;
	int elementsSize;
	int size;
}Queue;
typedef char String[256];
int enqueue(Queue* queue,void* element);
void* dequeue(Queue* queue);
Queue* create(int elementsSize, int size);

