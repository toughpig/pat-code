#include<cstdio>
const int maxn=10000;
int p[maxn]={0};
int cnt=0;   //�˴�����cnt��static �������������cnt=3-->cnt=5 ,���ǵ��������е�3��5 
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
