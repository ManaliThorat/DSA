typedef struct {
        void* elements;
        int size;
        int elementsSize;
        int rear;
} Queue;
typedef char String[256];
Queue* create(int elementsSize,int size);
int enqueue(Queue* queue,void* element);
void* dequeue(Queue* queue);
void* start(Queue* queue);
