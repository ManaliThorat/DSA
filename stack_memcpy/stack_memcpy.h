typedef struct 
{
        void* element;
        void* previous;
} Stack_element;
typedef struct {
        Stack_element* top;
        int elements;
        int typeSize;
} Stack;

Stack* create(int typeSize);
void push(Stack* stack,void* element);
Stack_element* pop(Stack* stack);