#include<cstdio>
#include<vector>
#include<stdlib.h>
using namespace std;
int main(){
  float c[1010]={0.0};
  int N,a,cnt=0;
  double b;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d %lf",&a,&b);
    c[a]+=b;
  }
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d %lf",&a,&b);
    c[a]+=b;
  }
  for(int j=0;j<1010;j++){
    if(c[j]!=0.0)
      cnt++;
  }
  printf("%d",cnt);
  for(int j=1009;j>=0;j--){
    if(c[j]!=0.0)
    printf(" %d %.1lf",j,c[j]);
  }
  
  return 0;
}

