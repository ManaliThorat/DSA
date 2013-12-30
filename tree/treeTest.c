#include "testUtils.h"
#include "tree.h"
#include <stdlib.h>
#include <stdio.h>

int compareInt(void *a,void *b){
	return *(int*)a - *(int*)b;
}

void test_insert_first_node(){
	Tree tree = createTree(compareInt);
	int data = 2;
	int result = insertToTree(&tree, NULL, &data);
	ASSERT(1 == result);
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
	ASSERT(0 == search(&tree,&data[7]));
}

void test_delete_node_under_root(){
	Tree tree = createTree(compareInt);
	Iterator result;
	int data[2] = {1,2};
	ASSERT(insertToTree(&tree, NULL, &data));
	ASSERT(insertToTree(&tree, &data, &data[1]));
	ASSERT(deleteFromTree(&tree,&data[1]));
	result = getChildren(&tree, &data);
	ASSERT(0 == result.hasNext(&result));
}

void test_delete_nodes_at_different_level(){
	Tree tree = createTree(compareInt);
	Iterator result;
	int data[7] = {1,2,3,4,5,6,7};
	ASSERT(insertToTree(&tree, NULL, &data[0]));
	ASSERT(insertToTree(&tree, &data[0], &data[1]));
	ASSERT(insertToTree(&tree, &data[1], &data[2]));
	ASSERT(insertToTree(&tree, &data[2], &data[3]));
	ASSERT(insertToTree(&tree, &data[3], &data[4]));
	ASSERT(insertToTree(&tree, &data[4], &data[5]));
	ASSERT(deleteFromTree(&tree, &data[5]));
	result = getChildren(&tree, &data[4]);
	ASSERT(0 == result.hasNext(&result));
}