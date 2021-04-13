#include<cstdio>
void print(int a){
  if(a<=13)
    printf("S%d",a);
  else if(a<=26)
    printf("H%d",a-13);
    else if(a<=39)
      printf("C%d",a-26);
      else if(a<=52)
        printf("D%d",a-39);
        else
          printf("J%d",a-52);
}
int main(){
  void print(int a);
  int a[55];
  int b[55];
  int re;
  scanf("%d",&re);
  int tem[55];
  for(int i=1;i<=54;i++){
    scanf("%d",b+i);
  }
  if(re>0){
  for(int j=1;j<55;j++){
    a[b[j]]=j;
  }
  for(int k=1;k<55;k++){
    tem[k]=a[k];
  }
  for(int p=re-1;p>0;p--){
    for(int i=1;i<55;i++){
      a[b[i]]=tem[i];
    }
    for(int i=1;i<55;i++)
      tem[i]=a[i];
  }
  }else{
    for(int i=1;i<55;i++){
      a[i]=i;
    }
  }
  for(int i=1;i<55;i++){
    print(a[i]);
    printf(" ");
  }
  
  return 0;
}

