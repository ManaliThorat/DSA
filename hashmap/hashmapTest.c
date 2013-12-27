#include "testUtils.h"
#include "hashmap.h"
#include <string.h>

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
Intern shital = {15386,"shital"};
Intern manali = {15388,"manali"};
Intern samiksha = {15432,"samiksha"};
void test_add_an_element_to_hashmap(){
        HashMap map = createMap(hashFun, areKeyEqual);
        ASSERT(put(&map, &manali.key, &manali.value));
}