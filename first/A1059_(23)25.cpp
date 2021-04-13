#include<cstdio>
#include<cmath>
const int maxn=100000;
int p[maxn]={0};
static int cnt=0;
int prime[maxn];

void MakePrime(){
  for(int i=2;i<maxn;i++){
    if(p[i]==0){
      prime[cnt++]=i;
      for(int j=i+i;j<maxn;j+=i)
        p[j]=1;
    }
  }
}

struct factor{
  int f;
  int num;
}fa[10];

int main(){
  MakePrime();
  int Cnt=0;
  long int n;
  scanf("%ld",&n);
  long int N=n;
  for(int i=0;prime[i]<=sqrt(1.0*N);i++){
    if(N%prime[i]==0){
      fa[Cnt].f=prime[i];
      fa[Cnt].num=0;
      while(N%prime[i]==0){
        fa[Cnt].num++;
        N/=prime[i];
      }
      Cnt++;
    }
  }
  if(N!=1){
    fa[Cnt].f=N;
    fa[Cnt].num=1;
    Cnt++;
  }
  printf("%d=",n);
  for(int i=0;i<Cnt;i++){
    printf("%d",fa[i].f);
    if(fa[i].num>1)
      printf("^%d",fa[i].num);
    if(i<Cnt-1)
      printf("*");
    
  }
  
  return 0;
}
