#include "merge_sort.h"
#include <string.h>


void part(void* base,int min,int max){
	int mid;
 if(min<max)
 {
   mid=(min+max)/2;
   part(base,min,mid);
   part(base,mid+1,max);
   merge(base,min,mid,max);
 }
}

void merge(void* base,int min,int mid,int max){
  
  
}
