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
  FILE *fpr;
  FILE *fpw;
  FILE *fp1;
  FILE *fp2;
  FILE *fp3;
  FILE *fp4;
  FILE *fp5;
  FILE *fp6;
  FILE *fp7;
  FILE *fp8;
  FILE *fpm1;
  FILE *fpm2;
  FILE *fpm3;
  FILE *fpm4;
  FILE *fpp1;
  FILE *fpp2;
  
# define N 335545 //0.1GB/4/8    (10GB/8=1.25GB) 
  
  char*fname_r="test100";
  char*fname_w="result100";
  char*fname_1="temp1";
  char*fname_2="temp2";
  char*fname_3="temp3";
  char*fname_4-"temp4";
  char*fname_5="temp5";
  char*fname_6="temp6";
  char*fname_7="temp7";
  char*fname_8="temp8";
  char*fname_m1="merge12";
  char*fname_m2="merge34";
  char*fname_m3="merge56";
  char*fname_m4="merge78";
  char*fname_p1="merge1234";
  char*fname_p2="merge5678";
  
  int value[N];
  int i,size;
  int tmp=0;
  int *pointer;
  
  fpr=fopen(fname_r,"rb");
  
  if(fpr==NULL){
    printf("cannot open\n");
    return -1;
  }
  /*read 0 ~N-1 and write them on temp1*/
  size=fread(value,sizeof(int) ,N, fpr);//kakunousaki yomikomudatahitotunobitesuu yomikomudatanokosuu filepointer
  merge_sort(value,N);
  pointer=value[N+1];

  fp1=fopen(fname_1,"wb");
    if(fp1==NULL){
     printf("cannot open temp\n", fname_1);
     return -1;
    }
  fwrite(value,sizeof(int),size,fp1);
  fclose(fp1);
  /*read N~2N*/
  size=fread(value,sizeof(int) ,N, fpr);//kakunousaki yomikomudatahitotunobitesuu yomikomudatanokosuu filepointer
  merge_sort(value,N);
  fp1=fopen(fname_1,"wb");
    if(fp1==NULL){
     printf("cannot open temp\n", fname_1);
     return -1;
    }
  fwrite(value,sizeof(int),size,fp1);
  fclose(fp1);
  
  
  
  
  
  
  
  
  fclose(fpr);
  
  return 0;
  }
  
  
  
  
