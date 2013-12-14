typedef struct Node{
		struct Node *previous;
        void *data;
        struct Node *next;
}Node;
typedef struct{
        Node* head;
        int length;
} List;

List* create();
List* createList();
Node* createNode(void* prevAddress,void* nextAddress);
int add(List* list,int index,void *element);
void* removeElement(List* list,int index);
