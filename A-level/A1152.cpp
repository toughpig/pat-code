#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;

int L,N;
char num[1001];

int getnum(int first,char ch[],int len){
    int res=0;
    for(int i=first;i<first+len;i++){
        res*=10;
        res+=ch[i]-'0';
    }
    return res;
}

int isprime(int a,int first,char ch[],int len){
    for(int i=2;i<=sqrt(a);i++){
        if(a%i==0){
            return 404;
        }
    }
    for(int i=first;i<len+first;i++) putchar(ch[i]);
            return a;
}

int main(){
  scanf("%d%d",&L,&N);
  scanf("%s",num);
  int flag=404;
  for(int i=0;i<=L-N;i++){
      int a=getnum(i,num,N);
        flag=isprime(a,i,num,N);
        if(flag!=404) break;
  }
  if(flag==404) printf("404");

  return 0;
}
