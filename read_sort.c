#include<stdio.h>
#include<stdlib.h>
//# define N 335545 //0.1GB/4/8 4byte=int  1.25GB for 10GB   
# define N 3356 // for 1NB

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

int main (void){

  FILE *fpr;
  FILE *fp1;
  FILE *fp2;
  FILE *fp3;
  FILE *fp4;
  FILE *fp5;
  FILE *fp6;
  FILE *fp7;
  FILE *fp8;
  char*fname_1="temp1";
  char*fname_2="temp2";
  char*fname_3="temp3";
  char*fname_4="temp4";
  char*fname_5="temp5";
  char*fname_6="temp6";
  char*fname_7="temp7";
  char*fname_8="temp8";
  char*fname_r="test100";
  int value[N];
  int size;
  int tmp=0;
  
  fpr=fopen(fname_r,"rb");//open"test1"
  
  if(fpr==NULL){
    printf("cannot open\n");
    return -1;
  }
  
  size=fread(value,sizeof(int) ,N, fpr);//kakunousaki yomikomudatahitotunobitesuu yomikomudatanokosuu filepointer
  merge_sort(value,size); //sorting array of value
  fp1=fopen(fname_1,"wb");
  if(fp1==NULL){
    printf("cannot open result\n", fname_1);
    return -1;
  }
  
  fwrite(value,sizeof(int),size,fp1);//output on temp1
  fclose(fp1);
  
  /*read next N and output on temp2*/
  fseek(fpr,0,1);
  size=fread(value,sizeof(int), N,fpr);
  merge_sort(value,size);
  fp2=fopen(fname_2,"wb");
  if(fp2==NULL){
    printf("cannot open result\n", fname_2);
    return -1;
  }
  fwrite(value,sizeof(int),size,fp2);
  fclose(fp2);
  
  /*read next N and output on temp3*/
   fseek(fpr,0,1);
  size=fread(value,sizeof(int), N,fpr);
  merge_sort(value,size);
  fp3=fopen(fname_3,"wb");
  if(fp3==NULL){
    printf("cannot open result\n", fname_3);
    return -1;
  }
  fwrite(value,sizeof(int),size,fp3);
  fclose(fp3);
  
  /*read next N and output on temp4*/
   fseek(fpr,0,1);
  size=fread(value,sizeof(int), N,fpr);
  merge_sort(value,size);
  fp4=fopen(fname_3,"wb");
  if(fp4==NULL){
    printf("cannot open result\n", fname_4);
    return -1;
  }
  fwrite(value,sizeof(int),size,fp4);
  fclose(fp4);
  
  /*read next N and output on temp5*/
   fseek(fpr,0,1);
  size=fread(value,sizeof(int), N,fpr);
  merge_sort(value,size);
  fp5=fopen(fname_5,"wb");
  if(fp5==NULL){
    printf("cannot open result\n", fname_5);
    return -1;
  }
  fwrite(value,sizeof(int),size,fp5);
  fclose(fp5);
  
  /*read next N and output on temp6*/
   fseek(fpr,0,1);
  size=fread(value,sizeof(int), N,fpr);
  merge_sort(value,size);
  fp6=fopen(fname_3,"wb");
  if(fp6==NULL){
    printf("cannot open result\n", fname_6);
    return -1;
  }
  fwrite(value,sizeof(int),size,fp6);
  fclose(fp6);
  
  /*read next N and output on temp7*/
   fseek(fpr,0,1);
  size=fread(value,sizeof(int), N,fpr);
  merge_sort(value,size);
  fp7=fopen(fname_3,"wb");
  if(fp7==NULL){
    printf("cannot open result\n", fname_7);
    return -1;
  }
  fwrite(value,sizeof(int),size,fp7);
  fclose(fp7);
  
  /*read next N and output on temp8*/
   fseek(fpr,0,1);
  size=fread(value,sizeof(int), N,fpr);
  merge_sort(value,size);
  fp8=fopen(fname_8,"wb");
  if(fp3==NULL){
    printf("cannot open result\n", fname_8);
    return -1;
  }
  fwrite(value,sizeof(int),size,fp8);
  fclose(fp8);
}
