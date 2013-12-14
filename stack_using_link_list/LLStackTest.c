#include "testUtils.h"
#include "LLStack.h"
#include <stdlib.h>
#include <stdio.h>
void test_create_node(){
        Node expected = {NULL,(void*)5,NULL};
        Node *actual = createNode(NULL,NULL);
        ASSERT(expected.next == actual->next);
        ASSERT(expected.previous == actual->previous);
}
void test_push_data_to_empty_list(){
        List* list = create();
        int num = 5;
        int res = push(list, &num);
        ASSERT(1 == res);
}
void test_push_data_to_list(){
        List* list = create();
        int num = 5;
        int num1 = 6;
        int res,res1;
        res = push(list, &num);
        ASSERT(1 == res);
        res1 = push(list,&num1);
        ASSERT(1 == res1);
}
void test_delete_first_element_in_list(){
     List* list = create();
        void* result;
        int num = 5;
        int res = push(list, &num);
        ASSERT(1 == res);
        result = pop(list);
        ASSERT(5 ==*(int*)result);
}

void test_delete_end_element_in_list_of_2(){
    List* list = create();
        int num = 5;
        int num1 = 6;
        void* result;
        int res,res1;
        res = push(list,&num);
        ASSERT(1 == res);
        res1 = push(list,&num1);
        ASSERT(1 == res1);
        result = pop(list);
        ASSERT(6 == *(int*)result);
}
void test_top_element_in_list(){
   List* list = create();
        void* result;
        int num = 5;
        int res = push(list, &num);
        ASSERT(1 == res);
        result = top(list);
        ASSERT(5 ==*(int*)result);
}
void test_top_end_element_in_list(){
    List* list = create();
        int num = 5;
        int num1 = 6;
        int num2 = 7;
        void* result;
        int res,res1,res2,res3;
        res = push(list,&num);
        ASSERT(1 == res);
        res1 = push(list,&num1);
        ASSERT(1 == res1);
        res2 = push(list,&num2);
        ASSERT(1 == res2);
        result = top(list);
        ASSERT(7 == *(int*)result);
}
void test_top_2_end_element_in_list(){
    List* list = create();
        int num = 5;
        int num1 = 6;
        void* result;
        int res,res1;
        res = push(list,&num);
        ASSERT(1 == res);
        res1 = push(list,&num1);
        ASSERT(1 == res1);
        result = pop(list);
        ASSERT(6 == *(int*)result);
}