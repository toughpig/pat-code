#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<stdlib.h>
using namespace std;
vector<int> ans;
int num[1000];
bool has[100000]={false};
void test(int y){
  while(y!=1){
    if(y%2==1){
      y=3*y+1;
      if(has[y]==true)
      return;
      has[y]=true;
    }
    else{
      y/=2;
      if(has[y]==true)
      return;
      if(y!=1)
      has[y]=true;
    }
  }
}
bool cmp(int a,int b){
  return a>b;
}

int main(){
//  for(int i=0;i<1000;i++){
//  	num[i]=0x3f3f3f3f;
//  }
  int N;
  scanf("%d",&N);
  int k=0;
  int n=N;
  while(n--){
    int temp;
    scanf("%d",&temp);
    if(has[temp]==false){
    num[k++]=temp;
    test(temp);
    }
  }
  for(int i=0;i<N;i++){
  	if(has[num[i]]==false){
  		ans.push_back(num[i]);
	  }
  }
  sort(ans.begin(),ans.end(),cmp);
  int i;
//  printf("%d",ans.size());
  for(i=0;i<ans.size()-1;i++){
  	if(ans[i]!=0)
    printf("%d ",ans[i]);
  }
  if(ans[i]!=0)
  printf("%d",ans[i]);
  
  
  
  
  return 0;
}
