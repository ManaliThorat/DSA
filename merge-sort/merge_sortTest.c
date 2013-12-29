#include "testUtils.h"
#include "merge_sort.h"

int compareInt(void* prev, void* next){
        return *(int*)prev < *(int*)next;
}

int compareFloat (void* prev, void* next){
        return *(float*)prev < *(float*)next;
}

int compareChar (void* prev, void* next){
        return *(char*)prev < *(char*)next;
}

void test_1_sorting_an_array_of_integers(){
    int expected[] = {1,2,3,4};
    int actual[] = {4,3,1,2};
    int i;
    void* base[4] = {&actual[0],&actual[1],&actual[2],&actual[3]};
    mergeSort(base, 4,sizeof(int), compareInt);
    for(i=0;i<4;i++)
        ASSERT(expected[i] == *(int*)base[i]);
}

