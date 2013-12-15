typedef struct{
	void *elements;
	int start;
	int rear;
	int elementsSize;
	int size;
}Queue;
typedef char String[256];
int isFull(Queue *queue);
int isEmpty(Queue *queue);
int enqueue(Queue* queue,void* element);
void* dequeue(Queue* queue);
Queue* create(int,int);
void* front(Queue* queue);
void* rear(Queue* queue);
