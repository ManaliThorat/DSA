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

void merge(void* base,int min,int mid,int max)
{
  void* tmp;
  int i,j,k,m; 
  j=min;
  m=mid+1;
  for(i=min; j<=mid && m<=max ; i++)
  {
     if(base+j*4<=base+m*4)
     {
        memcpy(tmp+i*4,base+j*4,4);
         j++;
     }
     else
     {
     	memcpy(tmp+i*4,base+m*4,4);
         m++;
     }
  }
  if(j>mid)
  {
     for(k=m; k<=max; k++)
     {
     	memcpy(tmp+i*4,base+k*4,4);
         i++;
     }
  }
  else
  {
     for(k=j; k<=mid; k++)
     {
     	memcpy(tmp+i*4,base+k*4,4);
        // tmp[i]=arr[k];
        i++;
     }
  }
  for(k=min; k<=max; k++)
  	memcpy(base+k*4,tmp+k*4,4);
     // arr[k]=tmp[k];
}
