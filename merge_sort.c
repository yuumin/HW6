
#include <stdio.h>
void insert_sort(int *buff, int low, int high)
{
  int i;
  int j;
  for (i = low+1 ; i <= high; i++) {
    double temp = buff[i];
    for (j = i - 1; j >= low && temp < buff[j]; j--) {
      buff[j + 1] = buff[j];
    }
    buff[j + 1] = temp;
  }
}

// ??????
#define LIMIT 32//?kukann nohabaga LIMIT ika nara insert sort

void merge_sort_sub(int *buff, int low, int high)
{
  
  if (high - low <= LIMIT) {
    insert_sort(buff, low, high);
  } else {
    int mid = low + (high - low) / 2;
    merge_sort_sub(buff, low, mid);
    merge_sort_sub(buff, mid + 1, high);
    int p = 0;
    int i = low;
    int work[mid-i];
    while (i <= mid) work[p++] = buff[i++];
    i = mid + 1;
    int j = 0;
    int k = low;
    while (i <= high && j < p) {
      if (work[j] <= buff[i]) {
        buff[k++] = work[j++];
      } else {
        buff[k++] = buff[i++];
      }
    }
    while (j < p) buff[k++] = work[j++];
  }
}

void merge_sort(int *buff, int size)
{
  merge_sort_sub(buff, 0, size - 1);
}

int main(void){
  int i;
  int a[10]={1,3,2,6,8,3,6,1,9,5};
  merge_sort(a , 10);
  for(i=0;i<10;i++){
    printf("%d \n", a[i]);
  }
}

  
  
  
  
  
  
