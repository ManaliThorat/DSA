typedef char string[256];
typedef struct p{
    string processName;
    int processTime;
    int priority;
    struct p *next;
}Process;
typedef struct{
    Process *front;
    int length;
}scheduler;
scheduler* create();
typedef int compFunc(void* a, void* b);
int scheduleProcess(scheduler *queue,Process *process,compFunc* compare);        
int removeProcess(scheduler *queue);