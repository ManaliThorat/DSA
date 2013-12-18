#include "testUtils.h"
#include "binary_search.h"
#include "testUtils.h"
#include <stdlib.h>
#include <string.h>

int compareInt(void* key,void* element){
        return ( *(int*)key -  *(int*)element );
}

int compareFloat(void* key,void* element){
        return ( *(float*)key -  *(float*)element );
}

int compareDouble(void* key,void* element){
        return ( *(double*)key -  *(double*)element );
}
int compareString(void* key,void* element){
        return strcmp( *(String*)key, *(String*)element );
}

void test_to_search_int_value(){
        int arr[3]={1,2,3};
        int key=3;
        ASSERT(3==*(int*)binarySearch(&key, arr, 3, sizeof(int), compareInt));
}

void test_to_find_value_which_is_not_present(){
        int arr[]={1,2,3,4,5};
        int key=7;
        ASSERT(NULL==(int*)binarySearch(&key, arr, 5, sizeof(int), compareInt));
}

void test_to_search_float_value(){
        float arr[]={1.0,2.0,3.0,4.0,5.0};
        float key=5.0;
        ASSERT(5.0==*(float*)binarySearch(&key, arr, 5, sizeof(float), compareFloat));
}

void test_to_search_double_value(){
        double arr[]={1.000000,2.000000,3.000000,4.000000,5.000000};
        double key=5.000000;
        ASSERT(5.000000==*(double*)binarySearch(&key, arr, 5, sizeof(double), compareDouble));
}

void test_to_search_element_in_double_array_which_is_not_present(){
        double arr[]={1.000000,2.000000,3.000000,4.000000,5.000000};
        double key=6.000000;
        ASSERT(NULL==(double*)binarySearch(&key, arr, 5, sizeof(double), compareDouble));
}

void test_to_search_element_in_char_array_which_is_not_present(){
        String arr[]={"a","b","c"};
        String key="a";
        String res;
        strcpy(res,*(String*)binarySearch(&key, arr, 3, sizeof(String), compareString));
        ASSERT(0 == strcmp("a",res));
}
