#include "testUtils.h"
#include "hashmap.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
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
	free(map);
}
void test_get_an_element_to_hashmap(){
    void* data;
    int key=1234 , value = 1;
    HashMap* map = createHashMap(hashFun, compareKey);
    ASSERT(put(map, &key , &value));
    data = get(map, &key);
    ASSERT(&value == data);
	free(map);

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
	free(map);

}
void test_remove_element_from_hashmap(){
    void* data;
    int key=1234 , value = 1;
	HashMap* map = createHashMap(hashFun, compareKey);
    ASSERT(put(map, &key , &value));
    ASSERT(removeMap(map, &key));
	free(map);

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
	free(map);

}
void test_for_getting_keys_available_in_hashmap(){
	Iterator result;
    int key=0 , value = 1;
    int key1=10 , value1 = 2;
    int key2=11 , value2 = 3;
    HashMap* map = createHashMap(hashFun, compareKey);
    ASSERT(put(map, &key , &value));
    ASSERT(put(map, &key1 , &value1));
    ASSERT(put(map, &key2 , &value2));

    result = keys(map);
    ASSERT(*(int*)result.hashnext(&result) == 0);
    // ASSERT(*(int*)result.hashnext(&result) == 10);
    // ASSERT(*(int*)result.hashnext(&result) == 11);

}