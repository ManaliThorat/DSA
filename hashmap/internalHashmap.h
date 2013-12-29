#include "dList.h"
#include "arrayList.h"

typedef struct hashNode {
        void* key;
        void* value;
        DoubleList elements;
}HashNode;