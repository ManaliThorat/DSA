#include "testUtils.h"
#include "stack.h"
#include <stdlib.h>
#include <stdio.h>
void test_create_node(){
        Node expected = {NULL,(void*)5,NULL};
        Node *actual = createNode(NULL,NULL);
        ASSERT(expected.next == actual->next);
        ASSERT(expected.previous == actual->previous);
}
void test_add_data_to_empty_list(){
        List* list = create();
        int num = 5;
        int res = add(list, 0, &num);
        ASSERT(1 == res);
}
void test_add_data_to_list(){
        List* list = create();
        int num = 5;
        int num1 = 6;
        int res,res1;
        res = add(list, 0, &num);
        ASSERT(1 == res);
        res1 = add(list, 1, &num1);
        ASSERT(1 == res);
}
void test_add_records_at_middle_of_list(){
        List* list = create();
        int num = 5;
        int num1 = 6;
        int num2 = 5;
        int num3 = 6;
        int res,res1,res2,res3;
        res = add(list, 0, &num);
        ASSERT(1 == res);
        res1 = add(list, 1, &num1);
        ASSERT(1 == res1);
        res2 = add(list, 1, &num2);
        ASSERT(1 == res2);
        res3 = add(list, 2, &num3);
        ASSERT(1 == res3);
}
void test_delete_first_element_in_list(){
     List* list = create();
        void* result;
        int num = 5;
        int res = add(list, 0, &num);
        ASSERT(1 == res);
        result = removeElement(list,0);
        printf("%d\n",*(int*)result );
        ASSERT(5 == *(int*)result);
}
// void test_delete_middle_element_in_list(){
//     List* list = create();
//         int num = 5;
//         int num1 = 6;
//         int num2 = 5;
//         void* result;
//         int res,res1,res2,res3;
//         res = add(list, 0, &num);
//         ASSERT(1 == res);
//         res1 = add(list, 1, &num1);
//         ASSERT(1 == res1);
//         res2 = add(list, 1, &num2);
//         ASSERT(1 == res2);
//         result = removeElement(list,1);
//         printf("%d\n",*(int*)result );
//         ASSERT(6 == *(int*)result);
// }
void test_delete_3_end_element_in_list(){
    List* list = create();
        int num = 5;
        int num1 = 6;
        int num2 = 7;
        void* result;
        int res,res1,res2,res3;
        res = add(list,0,&num);
        ASSERT(1 == res);
        res1 = add(list,1,&num1);
        ASSERT(1 == res1);
        res2 = add(list,2,&num2);
        ASSERT(1 == res2);
        result = removeElement(list,2);
        ASSERT(7 == *(int*)result);
}
