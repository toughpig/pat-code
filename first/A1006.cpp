#include<cstdio>
#include<iostream>
using namespace std;
const int maxn=1010;
int N;
struct rec{
  char name[15];
  int h[2],m[2],s[2];
}a[maxn];

int op,lo;

bool isearlier(int i,int j){
  if(a[i].h[0]<a[j].h[0]){
    return true;
  }
  else if(a[i].h[0]==a[j].h[0]){
    if(a[i].m[0]<a[j].m[0]){
    return true;
  }
  else if(a[i].m[0]==a[j].m[0]){
    if(a[i].s[0]<a[j].s[0]){
    return true;
  }
  else if(a[i].s[0]==a[j].s[0]){
    return false;
  }
  else{
    return false;
  }
  }
  else{
    return false;
  }
  }
  else{
    return false;
  }
}

bool islater(int i,int j){
  if(a[i].h[1]>a[j].h[1]){
    return true;
  }
  else if(a[i].h[1]==a[j].h[1]){
    if(a[i].m[1]>a[j].m[1]){
    return true;
  }
  else if(a[i].m[1]==a[j].m[1]){
    if(a[i].s[1]>a[j].s[1]){
    return true;
  }
  else if(a[i].s[1]==a[j].s[1]){
    return false;
  }
  else{
    return false;
  }
  }
  else{
    return false;
  }
  }
  else{
    return false;
  }
}
int findop(rec r[],int n){
  int op=0;
  for(int i=1;i<n;i++){
    if(isearlier(i,op))
      op=i;
  }
  return op;
}

int findlo(rec r[],int n){
  int lo=0;
  for(int i=1;i<n;i++){
    if(islater(i,op))
      lo=i;
  }
  return lo;
}

int main(){
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%s %d:%d:%d %d:%d:%d\n",a[i].name,a[i].h,a[i].m,a[i].s,a[i].h+1,a[i].m+1,a[i].s+1);
  }
  op=findop(a,N);
  lo=findlo(a,N);
  printf("%s %s",a[op].name,a[lo].name);
  return 0;
}

