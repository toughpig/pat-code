#include<cstdio>
#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
char id[40010][5];
vector<int> stu[2510];
// int _hash(char ch[]){
//   int id=0;
//   for(int i=0;i<3;i++)
//     id=id*26+ch[i]-'A';
//   id=id*10+ch[3]-'0';
// }
bool cmp(int a,int b){
  return strcmp(id[a],id[b])<=0;
}

int main(){
  int N,K;
  scanf("%d%d",&N,&K);
  int k=1;
  while(N--){
    scanf("%s",id[k]);
    // int id=_hash(name);
    int x;
    int index;
    scanf("%d",&x);
    while(x--){
      scanf("%d",&index);
      stu[index].push_back(k);
    }
    k++;
  }
  for(int i=1;i<=K;i++){
    printf("%d %d",i,stu[i].size());
    if(stu[i].size()!=0){
      printf("\n");
      sort(stu[i].begin(),stu[i].end(),cmp);
      int len=stu[i].size();
      for(int j=0;j<len;j++)
        printf("%s\n",id[stu[i][j]]);
    }
  }
  
  
  return 0;
}

