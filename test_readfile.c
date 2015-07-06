#include <stdio.h>
int BubSort(int x[ ], int n);
  
int BubSort(int x[ ], int n)
{
    int i, j, temp;

    for (i = 0; i < n - 1; i++) {
        for (j = n - 1; j > i; j--) {
            if (x[j - 1] > x[j]) {  
                temp = x[j];       
                x[j] = x[j - 1];
                x[j - 1]= temp;
            }
	}
    }
    
}

  int main(void){
  FILE *fpr;
  FILE *fpw;
  char*fname_r="test1";
  char*fname_w="result1";
  int value[2];
  int i,size;
  int tmp=0;
  
  fpr=fopen(fname_r,"rb");
  
  if(fpr==NULL){
    printf("cannot open\n");
    return -1;
  }
  size=fread(value,sizeof(int) ,2, fpr);//kakunousaki yomikomudatahitotunobitesuu yomikomudatanokosuu filepointer
  printf("before sorting\n");
  for(i=0;i<size;i++){
    printf("%02X\n" , value[i]);
  }
  printf("after sorting\n");
  BubSort(value,size);
  for(i=0;i<size;i++){
    printf("%02X\n" , value[i]);
  }
  
  
  
  fpw=fopen(fname_w,"wb");
  if(fpw==NULL){
    printf("cannot open result\n", fname_w);
    return -1;
  }
  
  fwrite(value,sizeof(int),size,fpw);
  fclose(fpr);
  fclose(fpw);
  
  return 0;
  }
  
  
  
  
