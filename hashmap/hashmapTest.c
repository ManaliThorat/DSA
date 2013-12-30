#include "testUtils.h"
#include "hashmap.h"
#include <string.h>
#include <stdio.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int compareKey(void* key1 , void* key2 ){
	return *(int*)key1 - *(int*)key2;
}
int hashFun(void *key){
	return *(int*)key;
};

void test_add_an_element_to_hashmap(){
    void* data;
    int key1 = 1234, data1 = 1;
    HashMap map = createHashmap(hashFun, compareKey);
    ASSERT(put(&map,&key1 , &data1));
    data = get(&map, &key1);
    ASSERT(data == &data1);
}
void test_add_multiple_elements_to_hashmap(){
    void* data;
    int key1 = 1234, data1 = 1;
    int key2 = 1235, data2 = 2;
    int key3 = 1245, data3 = 3;
    HashMap map = createHashmap(hashFun, compareKey);
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
    HashMap map = createHashmap(hashFun, compareKey);
    ASSERT(put(&map,&key1 , &data1));
    data = get(&map, &key1);
    ASSERT(put(&map,&key2 , &data2));
    data = get(&map, &key2);
    ASSERT(put(&map,&key3 , &data3));
    data = get(&map, &key3);
    ASSERT(data == &data3);
      ASSERT(removeMap(&map, &key1));
  }
void test_get_element_from_hashmap_after_removing(){
    void* data;
    int key1 = 1234, data1 = 1;
    int key2 = 1235, data2 = 2;
    int key3 = 1245, data3 = 3;
    HashMap map = createHashmap(hashFun, compareKey);
    ASSERT(put(&map,&key1 , &data1));
    data = get(&map, &key1);
    ASSERT(put(&map,&key2 , &data2));
    data = get(&map, &key2);
    ASSERT(put(&map,&key3 , &data3));
    data = get(&map, &key3);
    ASSERT(data == &data3);
      ASSERT(removeMap(&map, &key3));
      data = get(&map, &key3);
    ASSERT(data == NULL);
  }

void test_keys_of_hashmap_gives_all_keys_in_map(){
    void* data;
    int key1 = 1234, data1 = 1;
    int key2 = 1235, data2 = 2;
    int key3 = 1245, data3 = 3;
    Iterator it;
    HashMap map = createHashmap(hashFun, compareKey);
    ASSERT(put(&map,&key1 , &data1));
    data = get(&map, &key1);
    ASSERT(put(&map,&key2 , &data2));
    data = get(&map, &key2);
    ASSERT(put(&map,&key3 , &data3));
    data = get(&map, &key3);
    ASSERT(data == &data3);
    keys(&map);
    ASSERT(15388 == *(int*)it.next(&it));
}