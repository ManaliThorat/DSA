#include "testUtils.h"
#include "hashmap.h"
#include <string.h>
#include <stdio.h>
int compareKey(void* key1 , void* key2 ){
    return *(int*)key1 - *(int*)key2;
}
int hashFun(void *key){
    return *(int*)key%10;
};
typedef char String[256];

void test_add_an_element_to_hashmap(){
	void* data;
	int key1 = 1234, data1 = 1;
	int key2 = 1235, data2 = 2;
	int key3 = 1245, data3 = 3;

	HashMap* map = createHashMap(hashFun, compareKey);
    ASSERT(put(map,&key1 , &data1));
    ASSERT(put(map, &key2 , &data2));
    ASSERT(put(map, &key3 , &data3));
    ASSERT(put(map, &key3 , &data3));
    data = get(map, &key1);
	    ASSERT(data == &data1);
}
void test_get_an_element_to_hashmap(){
    void* data;
    int key=1234 , value = 1;
    HashMap* map = createHashMap(hashFun, compareKey);
    ASSERT(put(map, &key , &value));
    data = get(map, &key);
    ASSERT(&value == data);
}
void test_get_an_second_element_to_hashmap(){
    void* data;
    int key=1234 , value = 1;
    int key1=1233 , value1 = 90;
	HashMap* map = createHashMap(hashFun, compareKey);
    ASSERT(put(map, &key , &value));
    ASSERT(put(map, &key1 , &value1));
	data = get(map, &key);
    ASSERT(&value == data);
    data = get(map, &key1);
    ASSERT(&value1 == data);
}
void test_remove_element_from_hashmap(){
    void* data;
    int key=1234 , value = 1;
	HashMap* map = createHashMap(hashFun, compareKey);
    ASSERT(put(map, &key , &value));
    ASSERT(removeMap(map, &key));
}
void test_for_remove_elements_from_hashmap(){
    void* data;
    int key=1234 , value = 1;
    int key1=1235 , value1 = 1;
    int key2=1244 , value2 = 1;
    HashMap* map = createHashMap(hashFun, compareKey);
    ASSERT(put(map, &key , &value));
    ASSERT(put(map, &key1 , &value1));
   	ASSERT(removeMap(map, &key1));
	ASSERT(put(map, &key2 , &value2));
    ASSERT(removeMap(map, &key2));
	data = get(map, &key2);
    ASSERT(data == NULL);
}