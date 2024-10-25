#include<cstdio>
#include<cstring>
const int maxn=101;

struct bign{
  int num[maxn];
  int len;
  bign(){
    memset(num,0,maxn);
    len=0;
  }
};

bool ispali(bign p){
  int h=p.len/2;
  for(int i=0;i<h;i++){
    if(p.num[i]!=p.num[p.len-i-1])
      return false;
  }
  return true;
}
//bign change(bign cha){
//  bign t;
//  int l=cha.len;
//  for(int i=0;i<l;i++){
//    t.num[i]=cha.num[l-i-1];
//  }
//  t.len=cha.len;
//  return t;
//}
bign op(bign nopo){
  bign temp;
  int cnt=0;
  int le=nopo.len;
  int c=0;
  int kk;
  int sum=0;
  for(int j=0;j<nopo.len;j++){
    sum=c+nopo.num[j]+nopo.num[le-j-1];
    kk=sum%10;
    c=sum/10;
    temp.len++;
    temp.num[cnt++]=kk;
  }
  if(c!=0){
    temp.len++;
    temp.num[cnt++]=c;
  }
  return temp;
}


void print(bign p){
  for(int i=p.len;i>0;i--){
    printf("%d",p.num[i-1]);
  }
  printf("\n");
}

int main(){
  
  char ch[maxn];
  scanf("%s",ch);
  bign a;
  int lo=strlen(ch);
  a.len=lo;
  for(int i=0;i<lo;i++){
    a.num[i]=ch[lo-i-1]-'0';
  }
  int k;
  scanf("%d",&k);
  int cnt=0;
  while(k){   //while(k--)µ¼ÖÂÑ­»·Íêk=-1******************** 
    if(ispali(a)){
      print(a);
      printf("%d",cnt);
      break;
    }
    else{
      bign tt=op(a);
      a=tt;
      cnt++;
    }
    k--;
  }
  if(k==0){
    print(a);
    printf("%d",cnt);
  }
  
  return 0;
}
