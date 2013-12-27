#include "testUtils.h"
#include "tree.h"
#include <stdlib.h>
#include <stdio.h>
const int SUCCESSFUL = 1;
int compareInt(void *a,void *b){
	return *(int*)a - *(int*)b;
}
void test_insert_first_node(){
	Tree tree = createTree(compareInt);
	int data = 2;
	int result = insertToTree(&tree, NULL, &data);
	ASSERT(SUCCESSFUL == result);
}
void test_insert_second_node(){
	Tree tree = createTree(compareInt);
	int data[] = {2,3,5};
	Iterator result;
	insertToTree(&tree, NULL, &data[0]);
	insertToTree(&tree, &data[0], &data[1]);
	insertToTree(&tree, &data[0], &data[2]);
	result = getChildren(&tree, &data);
	ASSERT(5 == *(int*)result.next(&result));
	ASSERT(3 == *(int*)result.next(&result));
}
void test_insert_to_second_node(){
	Tree tree = createTree(compareInt);
	int data[] = {2,3,5};
	Iterator result;
	insertToTree(&tree, NULL, &data[0]);
	insertToTree(&tree, &data[0], &data[1]);
	insertToTree(&tree, &data[1], &data[2]);
	result = getChildren(&tree, &data[1]);
	ASSERT(5 == *(int*)result.next(&result));
}
void test_insert_to_second_child(){
	Tree tree = createTree(compareInt);
	int data0 = 2;
	int data1[] = {3,5};
	int data2 = 9;
	Iterator result;
	insertToTree(&tree, NULL, &data0);
	insertToTree(&tree, &data0, &data1[0]);
	insertToTree(&tree, &data0, &data1[1]);
	insertToTree(&tree, &data1[1], &data2);
	result = getChildren(&tree, &data1[1]);
	ASSERT(9 == *(int*)result.next(&result));
}
void test_insert_nodes_at_different_level(){
	Tree tree = createTree(compareInt);
	Iterator it;
	int data[7] = {1,2,3};
	ASSERT(insertToTree(&tree, NULL, &data[0]));
	ASSERT(insertToTree(&tree, &data[0], &data[1]));
	ASSERT(insertToTree(&tree, &data[1], &data[2]));
	
}

void test_search_element(){
	Tree tree = createTree(compareInt);
	Iterator result;
	int data[7] = {1,2,3,4,5,6,7};
	ASSERT(insertToTree(&tree, NULL, &data[0]));
	ASSERT(insertToTree(&tree, &data[0], &data[1]));
	ASSERT(insertToTree(&tree, &data[1], &data[2]));
	ASSERT(search(&tree,&data[2]));
	ASSERT(search(&tree,&data[1]));
	ASSERT(search(&tree,&data[0]));
}
void test_search_element_which_is_not_present(){
	Tree tree = createTree(compareInt);
	Iterator result;
	int data[7] = {1,2,3,4,5,6,7};
	ASSERT(insertToTree(&tree, NULL, &data[0]));
	ASSERT(insertToTree(&tree, &data[0], &data[1]));
	ASSERT(insertToTree(&tree, &data[1], &data[2]));
	ASSERT(search(&tree,&data[2]));
	ASSERT(0 == search(&tree,&data[7]));
}