#include "testUtils.h"
#include "hashmap.h"
#include <string.h>
#include <stdio.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int areKeyEqual(void* key1 , void* key2 ){
	return *(int*)key1 - *(int*)key2;
}
int hashFun(void *key){
	return *(int*)key;
};
typedef struct{
	int key;
	char value[50];
} Intern;
void test_add_an__element_to_hashmap(){
    void* data;
    int key1 = 1234, data1 = 1;
    HashMap map = createHashmap(hashFun, areKeyEqual);
    ASSERT(put(&map,&key1 , &data1));
    data = get(&map, &key1);
    ASSERT(data == &data1);
}
void test_add_an_element_to_hashmap(){
    void* data;
    int key1 = 1234, data1 = 1;
    int key2 = 1235, data2 = 2;
    int key3 = 1245, data3 = 3;
    HashMap map = createHashmap(hashFun, areKeyEqual);
    ASSERT(put(&map,&key1 , &data1));
    data = get(&map, &key1);
    ASSERT(put(&map,&key2 , &data2));
    data = get(&map, &key2);
    ASSERT(put(&map,&key3 , &data3));
    data = get(&map, &key3);
    ASSERT(data == &data3);
}

void test_remove_element_from_hashmap(){
    void* data;
    int key1 = 1234, data1 = 1;
    int key2 = 1235, data2 = 2;
    int key3 = 1245, data3 = 3;
    HashMap map = createHashmap(hashFun, areKeyEqual);
    ASSERT(put(&map,&key1 , &data1));
    data = get(&map, &key1);
    ASSERT(put(&map,&key2 , &data2));
    data = get(&map, &key2);
    ASSERT(put(&map,&key3 , &data3));
    data = get(&map, &key3);
    ASSERT(data == &data3);
      ASSERT(removeMap(&map, &key1));
  }

