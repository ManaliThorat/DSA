#include "testUtils.h"
#include "bubble_sort.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef char String[256];
int compareInt ( void* a,  void* b){
    return (*(int*)a - *(int*)b);
}
int compareDouble( void* a,  void* b){
    return (*(double*)a - *(double*)b);
}
int compareChar( void* a,  void* b){
    return (*(char*)a - *(char*)b);
}
int compareString(void* a,void* b){
    return (strcmp(*(String*)a,*(String*)b));
}

void test_1_sorting_an_array_of_integers(){
    int expected[] = {1,2,3,4};
    int actual[] = {4,3,1,2};
    int i;
    void* base[4] = {&actual[0],&actual[1],&actual[2],&actual[3]};
    bsort(base, 4,sizeof(int), compareInt);
    for(i=0;i<4;i++)
        ASSERT(expected[i] == *(int*)base[i]);
}
void test_1_sorting_an_array_of_float(){
   float actual[] = {10.5f,1.5f,2.5f,7.5f};
   float expected[] = {1.5f,2.5f,7.5f,10.5f};
    int i;
    void *base[4] = {&actual[0],&actual[1],&actual[2],&actual[3]};
    bsort(base,4,sizeof(float),compareInt);
    for(i=0;i<4;i++)
            ASSERT(expected[i] == *(float*)base[i]);
}
void test_1_sorting_an_array_of_double(){
    double actual[] = {10.5f,1.5f,2.5f,7.5f};
    double expected[] = {1.5f,2.5f,7.5f,10.5f};
    int i;
    void *base[4] = {&actual[0],&actual[1],&actual[2],&actual[3]};
    bsort(base,4,sizeof(double),compareDouble);
    for(i=0;i<4;i++)
            ASSERT(expected[i] == *(double*)base[i]);
}


void test_3_sorting_an_array_of_characters(){
   char actual[] = {'m','a','n','u'};
    char expected[] = {'a','m','n','u'};
    int i;
    void *base[4] = {&actual[0],&actual[1],&actual[2],&actual[3]};
    bsort(base,4,sizeof(char),compareChar);
    for(i=0;i<4;i++)
            ASSERT(expected[i] == *(char*)base[i]);
}
