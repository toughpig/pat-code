#include<cstdio>
#include<vector>
#include<map>
#include<iostream>
using namespace std;

vector<pair<int,int> > mp;

int main(){
  int n,r;
  int flag=1;
  while(cin>>n>>r){
    if(flag==0)
        printf(" ");
    flag=0;
    if(r!=0&&n!=0){
      mp.push_back(make_pair(n,r));
      printf("%d %d",n*r,r-1);
    }
    else if(r==0)
      printf("0 0");
  }
  
  return 0;
}
