#include "testUtils.h"
#include "merge_sort.h"

int compareInt(void* prev, void* next){
        return *(int*)prev < *(int*)next;
}

int compareFloat (void* prev, void* next){
        return *(float*)prev < *(float*)next;
}
int compareDouble (void* prev, void* next){
        return *(double*)prev < *(double*)next;
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
void test_2_sorting_an_array_of_float(){
    float expected[] = {1,2,3,4};
    float actual[] = {4,3,1,2};
    int i;
    void* base[4] = {&actual[0],&actual[1],&actual[2],&actual[3]};
    mergeSort(base, 4,sizeof(float), compareFloat);
    for(i=0;i<4;i++)
        ASSERT(expected[i] == *(float*)base[i]);
}

void test_3_sorting_an_array_of_double(){
    double actual[] = {10.5f,1.5f,2.5f,7.5f};
    double expected[] = {1.5f,2.5f,7.5f,10.5f};
    int i;
    void *base[4] = {&actual[0],&actual[1],&actual[2],&actual[3]};
    mergeSort(base,4,sizeof(double),compareDouble);
    for(i=0;i<4;i++)
            ASSERT(expected[i] == *(double*)base[i]);
}

void test_4_sorting_an_array_of_characters(){
   char actual[] = {'m','a','n','u'};
    char expected[] = {'a','m','n','u'};
    int i;
    void *base[4] = {&actual[0],&actual[1],&actual[2],&actual[3]};
    mergeSort(base,4,sizeof(char),compareChar);
    for(i=0;i<4;i++)
            ASSERT(expected[i] == *(char*)base[i]);
}

