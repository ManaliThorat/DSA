#include "testUtils.h"
#include "hashmap.h"
#include <string.h>
#include <stdio.h>

int compareKey(void* key1 , void* key2 ){
	return *(int*)key1 - *(int*)key2;
}
int hashFun(void *key){
	return *(int*)key;
};

void test_add_an_element_to_hashmap(){
    void* data;
    int key1 = 1234, data1 = 1;
    HashMap map = createHashmap(hashFun, compareKey,10);
    ASSERT(put(&map,&key1 , &data1));
    data = get(&map, &key1);
    ASSERT(data == &data1);
    dispose(&map);
}
void test_add_multiple_elements_to_hashmap(){
    void* data;
    int key1 = 1234, data1 = 1;
    int key2 = 1235, data2 = 2;
    int key3 = 1245, data3 = 3;
    HashMap map = createHashmap(hashFun, compareKey,10);
    ASSERT(put(&map,&key1 , &data1));
    data = get(&map, &key1);
    ASSERT(put(&map,&key2 , &data2));
    data = get(&map, &key2);
    ASSERT(put(&map,&key3 , &data3));
    data = get(&map, &key3);
    ASSERT(data == &data3);
    dispose(&map);
}

void test_remove_element_from_hashmap(){
    void* data;
    int key1 = 1234, data1 = 1;
    int key2 = 1235, data2 = 2;
    int key3 = 1245, data3 = 3;
    HashMap map = createHashmap(hashFun, compareKey,10);
    ASSERT(put(&map,&key1 , &data1));
    data = get(&map, &key1);
    ASSERT(put(&map,&key2 , &data2));
    data = get(&map, &key2);
    ASSERT(put(&map,&key3 , &data3));
    data = get(&map, &key3);
    ASSERT(data == &data3);
    ASSERT(removeMap(&map, &key1));
    dispose(&map);
  }
void test_get_element_from_hashmap_after_removing(){
    void* data;
    int key1 = 1234, data1 = 1;
    int key2 = 1235, data2 = 2;
    int key3 = 1245, data3 = 3;
    HashMap map = createHashmap(hashFun, compareKey,10);
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
    dispose(&map);
  }

void test_keys_of_hashmap_gives_all_keys_in_map(){
    void* data;
    int key1 = 1234, data1 = 1;
    int key2 = 1235, data2 = 2;
    int key3 = 1245, data3 = 3;
    Iterator it;
    HashMap map = createHashmap(hashFun, compareKey,10);
    ASSERT(put(&map,&key1 , &data1));
    ASSERT(put(&map,&key2 , &data2));
    ASSERT(put(&map,&key3 , &data3));
    it = keys(&map);
    ASSERT(1234 == *(int*)it.next(&it));
    ASSERT(1235 == *(int*)it.next(&it));
    ASSERT(1245 == *(int*)it.next(&it));
    dispose(&map);
}
void test_rehash_elements_to_hashmap(){
    void* data;
    Iterator it;
    int key1 = 2, data1 = 1;
    int key2 = 3, data2 = 2;
    int key3 = 4, data3 = 3;
    int key4 = 5, data4 = 4;
    int key5 = 14, data5 = 5;
    int key6 = 24, data6 = 6;
    int key7 = 6, data7 = 7;
    HashMap map = createHashmap(hashFun, compareKey,10);
    ASSERT(put(&map,&key1 , &data1));
    ASSERT(put(&map,&key2 , &data2));
    ASSERT(put(&map,&key3 , &data3));
    ASSERT(put(&map,&key4 , &data4));
    ASSERT(put(&map,&key5 , &data5));
    ASSERT(put(&map,&key6 , &data6));
    ASSERT(put(&map,&key7 , &data7));
    it = keys(&map);
    ASSERT(2 == *(int*)it.next(&it));
    ASSERT(3 == *(int*)it.next(&it));
    ASSERT(4 == *(int*)it.next(&it));
    ASSERT(24 == *(int*)it.next(&it));
    ASSERT(5 == *(int*)it.next(&it));
    ASSERT(6 == *(int*)it.next(&it));
    ASSERT(14 == *(int*)it.next(&it));
    dispose(&map);
}