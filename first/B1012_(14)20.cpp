#include<stdio.h>
using namespace std;
int main(){
  int N;
  scanf("%d",&N);
  int num[N];
  for(int i=0;i<N;i++)
    scanf("%d",num+i);
  int j=0;
  int max=0;
  int cnt=0;
  int A1=0;
  int A2=0;
  int A5=0;
  int A3=0;
  long long A4=0;
  static int a1=0;
  static int a2=0;
  static int a3=0;
  static int a4=0;
  static int a5=0;
  static int f=1;
  int k,i=0;
  while(i<N){
    switch(k=num[i]%5){
      case 0:{
        a1=1;
        if(num[i]%2==0)
          A1+=num[i];
        break;
      }
      case 1:{
        a2=1;
        A2+=num[i]*f;
        f*=(-1);
        break;
      }
      case 2:{
        a3=1;
        A3++;
        break;
      }
      case 3:{
        a4=1;
        cnt++;
        A4+=num[i];
        break;
      }
      case 4:{
        a5=1;
        if(max<num[i])
          max=num[i];
        break;
      }
    }
    i++;
  }
  if(a1==1)
    printf("%d ",A1);
  else
    printf("N ");
  if(a2==1)
    printf("%d ",A2);
  else
    printf("N ");
  if(a3==1)
    printf("%d ",A3);
  else
    printf("N ");
  if(a4==1)
    printf("%.1f ",(float)(1.0*A4)/(1.0*cnt));
  else
    printf("N ");
  if(a5==1)
    printf("%d",max);
  else
    printf("N");
  return 0;
}

