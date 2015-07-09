#include<stdio.h>
#include <stdlib.h>
# define N 335545 //0.1GB/4/8 4byte=int  1.25GB for 10GB

void merge_file(char*file1, char*file2){ /*merge 2 files and output sorted array*/
 
  
  FILE *fp1;
  FILE *fp2;
  int a[N/4]; // from file1
  int b[N/4]; // from file2
  int c[N/2];// sorted array for out put
 //a+b+c=N
 /*read file1 and generate array size of N/4*/
 fp1=fopen(file1,"rb");
  if(fp1==NULL){
    printf("cannot open\n");
    return -1;
  }
  size=fread(a,sizeof(int) ,N/4, fp1);
  
  /*read file2 and generate array size of N/4*/
  fp2=fopen(file2,"rb");
  if(fp2==NULL){
    printf("cannot open\n");
    return -1;
  }
  size=fread(b,sizeof(int) ,N/4, fp2);

int work1=0;
int work2=0;
 work1=a[0];
 work2=b[0];
 int i=0;
 int j=0;
 int k=0;
 int asize=N/4;
 int bsize=N/4;
 
  while(asize==N/4 || bsize==N/4){   
    while(k!=asize && j!=bsize){// while a or b is not full
      if(work1>=work2){
      c[i]=work2;
      j++;
      i++;
      work2=b[j];
      }
      else{
      c[i]=work1;
      k++;
      i++;
      work1=a[k];
      }
    }//if a o b is full,read more
    if(k==N/4){ //read another N/4
      seek(*fp1,0,1);//continue fron last end
      asize=fread(a,sizeof(int) ,N/4, fp1);
    }
     else if(j==N/4){
     seek(*fp2,0,1);//continue from last end
     bsize=fread(b,sizeof(int) ,N/4, fp2);
     }
  }// if read end of the file
    if(k==asize){
    for(i;i<asize+bsize;i++){
    c[i]=b[j];
    j++;
    }
  }
  else if(j==bsize){
    for(i;i<asize+bsize;i++){
    c[i]=a[k];
    k++;
    }
  }
}

  int main (void){
  char*fname_1="temp1";
  char*fname_2="temp2";
  char*fname_w="result1";
  FILE*fpw;
  merge_file(fname_1, fname_2);
  fpw=fopen(fname_w,"wb");
  if(fpw==NULL){
    printf("cannot open result\n", fname_w);
    return -1;
  }
  
  fwrite(c,sizeof(int),size,fpw);
  fclose(fpr);
  fclose(fpw);
  
  return 0;
  }
 
