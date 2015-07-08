#include<stdio.h>

void merge(int *a , int *b ,int *c){

int work1=0;
int work2=0;
 work1=a[0];
 work2=b[0];
 int i=0;
 int j=0;
 int k=0;
 int size_a,size_b;
 size_a=10;
 size_b=10;
 
    if(work1>=work2){
    c[i]=work2;
    j++;
    work2=b[j];
    }
    else{
    c[i]=work1;
     k++;
    work1=a[k];
    }
    i++;
    
  
     
  while(k!=size_a && j!=size_b){
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
  }
  

  if(k==size_a){
    for(i;i<size_a+size_b;i++){
    c[i]=b[j];
    j++;
    }
  }
  else if(j==size_b){
    for(i;i<size_a+size_b;i++){
    c[i]=a[k];
    k++;
    }
  }
 
}

int main (void){
  int i;
  int a[10]={1,1,2,2,2,3,3,3,4,4};
  int b[10]={6,6,6,7,9,12,34,67,89,90};
  int c[20];
  merge(a,b,c);
  for(i=0;i<20;i++){
  printf("%d ",c[i]);
  }
}

