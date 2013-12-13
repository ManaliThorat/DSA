#include "binary_search.h"
#include <stdlib.h>
#include <math.h>

void* binarySearch(void *key, void *base, int length, int size, int (*compare)(void *, void *)){
        int firstElement = 0;
        int lastElement = length-1;
        int middleElement,result;
        while(firstElement <= lastElement){
                middleElement = floor((firstElement + lastElement) / 2);
                result = compare(key,base+(middleElement*size));
                if(!result)
                        return base+(middleElement*size);
                if(result < 0)
                        lastElement = middleElement -1;
                if(result > 0)
                        firstElement = middleElement + 1;
        }
        return NULL;
}