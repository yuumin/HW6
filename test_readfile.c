#include <stdio.h>

//void read_file(char*fname){
  int main(void){
  FILE *fp;
  char*fname="test1";
  unsigned char value[100000];
  int i,size;
  
  fp=fopen(fname,"rb");
  
  if(fp==NULL){
    printf("cannot open\n");
    return -1;
  }
  size=fread(value,sizeof(int) ,10000, fp);//kakunousaki yomikomudatahitotunobitesuu yomikomudatanokosuu filepointer
 
  for(i=0;i<size;i++){
    if(i%16==0)printf("\n");
    printf("%02X" , value[i]);
  }
  
  fclose(fp);
  return 0;
  }
  
  
  
  
