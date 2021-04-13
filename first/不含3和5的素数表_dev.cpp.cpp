#include<cstdio>
const int maxn=10000;
int p[maxn]={0};
int cnt=0;   //此处定义cnt（static 不会出错）出错，在cnt=3-->cnt=5 ,覆盖掉素数表中的3和5 
int prime[maxn];


void makeprime(){
  for(int i=2;i<maxn;i++){
    	if(p[i]==0){
      	prime[cnt++]=i;
      		for(int j=2*i;j<=maxn;j+=i){
        			p[j]=1;
     		 }
   	 }
    }
  for(int u=0;u<100;u++)
  printf("%d  ",prime[u]);
  
}

int main(){
  makeprime();
  return 0;
}
