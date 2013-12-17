#include "testUtils.h"
#include "stack.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
int areEqual(stack* src,stack* expected){
    int res = (src->elementsSize == expected->elementsSize)
            && (src->size == expected->size)
            && (src->top == expected->top);
    if(!res)
        return res;
    return 0==memcmp(src->elements, expected->elements, src->size*src->elementsSize);           
}
void test_for_creating_stack(){
    int expectedArr[2]={0,0};
    stack expected = {expectedArr,-1,4,2};
    stack* src = create(sizeof(int),2);
    ASSERT(areEqual(src, &expected));
}

void test_for_pushing_int_element_in_stack(){
    stack* actual = create(sizeof(int),2);
    int value = 1;
    int res = push(actual,&value);
    int* data = (int*)actual->elements;
    ASSERT(data[0]==1);
    free(actual);   
}
void test_for_pushing_float_element_in_stack(){
    stack* actual = create(sizeof(float),2);
    float value = 1.0;
    int res = push(actual,&value);
    float* data = (float*)actual->elements;
    ASSERT(data[0]==1.0);
    free(actual);   
}
void test_for_pushing_char_element_in_stack(){
    stack* actual = create(sizeof(char),2);
    char value = 'm';
    int res = push(actual,&value);
    char* data = (char*)actual->elements;
    ASSERT(data[0]=='m');
    free(actual);   
}

void test_for_pushing_double_element_in_stack(){
    stack* actual = create(sizeof(double),2);
    double value = 2.000000;
    double res = push(actual,&value);
    double* data = (double*)actual->elements;
    ASSERT(data[0]==2.000000);
    free(actual);   
}

void test_for_pushing_String_element_in_stack(){
    stack* actual = create(sizeof(String),2);
    String value = "manali";
    int res = push(actual,&value);
    String* data = (String*)actual->elements;
    ASSERT(0 == strcmp((char*)data,value));
    free(actual);   
}

void test_for_poping_int_element_from_stack(){
    int data[] = {1,2,3,4,5};
    stack* actual = create(sizeof(int),5);
    push(actual,&data[0]);
    push(actual,&data[1]);
    push(actual,&data[2]);
    push(actual,&data[3]);
    push(actual,&data[4]);
    ASSERT(5 ==*(int*)pop(actual));
}
void test_for_poping_float_element_from_stack(){
    float data[] = {1.0,2.0,3.0};
    stack* actual = create(sizeof(float),3);
    push(actual,&data[0]);
    push(actual,&data[1]);
    push(actual,&data[2]);
    ASSERT(3.0 ==*(float*)pop(actual));
}
void test_for_poping_char_element_from_stack(){
    char data[] = {'m','a','n'};
    stack* actual = create(sizeof(char),3);
    push(actual,&data[0]);
    push(actual,&data[1]);
    push(actual,&data[2]);
    ASSERT('n' ==*(char*)pop(actual));
    ASSERT(1==actual->top);
}
void test_for_poping_double_element_from_stack(){
    double data[] = {0.000000,1.000000,2.000000};
    stack* actual = create(sizeof(double),3);
    push(actual,&data[0]);
    push(actual,&data[1]);
    push(actual,&data[2]);
    ASSERT(2.000000 ==*(double*)pop(actual));
    ASSERT(1==actual->top);

}
void test_for_poping_string_element_from_stack(){
    String data[] = {"manali","kajal","samiksha"};
    stack* actual = create(sizeof(String),3);
    push(actual,&data[0]);
    push(actual,&data[1]);
    push(actual,&data[2]);
    ASSERT(0 == strcmp("samiksha",*(String*)pop(actual)));
}
void test_gives_top_int_element_of_stack(){
    int data[] = {1,2,3};
    stack* actual = create(sizeof(int),3);
    push(actual,&data[0]);
    push(actual,&data[1]);
    push(actual,&data[2]);
    ASSERT(3 ==*(int*)top(actual));
}
void test_gives_top_float_element_of_stack(){
    float data[] = {1.0,2.0,3.0};
    stack* actual = create(sizeof(float),3);
    push(actual,&data[0]);
    push(actual,&data[1]);
    push(actual,&data[2]);
    ASSERT(3.0 ==*(float*)top(actual));
}
void test_gives_top_double_element_of_stack(){
    double data[] = {1.000000,2.000000,3.000000};
    stack* actual = create(sizeof(double),3);
    push(actual,&data[0]);
    push(actual,&data[1]);
    push(actual,&data[2]);
    ASSERT(3.000000 ==*(double*)top(actual));

}

void test_gives_top_char_element_of_stack(){
   char data[] = {'m','a','n'};
    stack* actual = create(sizeof(char),3);
    push(actual,&data[0]);
    push(actual,&data[1]);
    push(actual,&data[2]);
    ASSERT('n' ==*(char*)top(actual));
}
void test_gives_top_string_element_of_stack(){
   String data[] = {"manali","samiksha","kajal"};
    stack* actual = create(sizeof(String),3);
    push(actual,&data[0]);
    push(actual,&data[1]);
    push(actual,&data[2]);
    ASSERT(0 == strcmp("kajal",*(String*)top(actual)));
}