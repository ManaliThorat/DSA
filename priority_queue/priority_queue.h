typedef char string[256];
typedef struct Node{
    void* data;
    int priority;
    struct Node *next;
}Node;
typedef struct{
    Node *front;
    int length;
}Queue;
Queue* create();
typedef int compFunc(void* a, void* b);
int insert(Queue *queue,Node *q,compFunc* compare);
int removeElement(Queue* queue);
