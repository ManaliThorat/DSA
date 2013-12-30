#include "merge_sort.h"
#include <memory.h>
#include <stdlib.h>
int merge(void** base, void** left, void** right, size_t leftLength, size_t rightLength,size_t elementSize, comparator cmp){
        int  i=0,j=0,k=0;
        while(i < leftLength && j < rightLength){
                if(cmp(left[i], right[j])){
                        base[k] = left[i];
                        i++;
                }
                else{
                        base[k] = right[j];
                        j++;
                }
                        k++;
        }
        while( j < rightLength){
                base[k] = right[j];
                j++;
                k++;
        }
        while(i < leftLength){
                base[k] = left[i];
                i++;
                k++;
        }
        return 1;
}

void mergeSort(void** base, int numberOfElements, int elementSize, comparator comp){
        int mid = numberOfElements/2,i,j,leftLength,rightLength;
        void** left = calloc(mid,elementSize);
        void** right = calloc(mid+1,elementSize);
        if(numberOfElements < 2) return;
        leftLength = mid;
        rightLength = numberOfElements-mid;
        for(i=0;i<mid;i++)
                left[i] = base[i];
        for(i=mid;i<numberOfElements;i++)
                right[i-mid] = base[i];
        mergeSort(left,leftLength,elementSize,comp);
        mergeSort(right,rightLength,elementSize,comp);
        merge(base, left, right, leftLength, rightLength, elementSize, comp);
        free(left);
        free(right);
}