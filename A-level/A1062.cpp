#include<cstdio>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
struct node{
  int ID;
  int V;
  int T;
};
vector<node> s,n,f,ff;
void print(vector<node> a){
  int len=a.size();
  for(int i=0;i<len;i++){
    printf("%08d %d %d\n",a[i].ID,a[i].V,a[i].T);
  }
}
bool cmp(node a,node b){
  return a.V+a.T>=b.T+b.V;
}
int main(){
  int N,L,H;
  node no;
  scanf("%d%d%d",&N,&L,&H);
  int cnt=0;
  int id,v,t;
  while(N--){
    scanf("%d %d %d",&id,&v,&t);
    no.ID=id;
    no.V=v;
    no.T=t;
    if(v>=L&&t>=L){
      cnt++;
      if(v>=H&&t>=H){
        s.push_back(no);
      }
      if(t<H&&v>=H){
        n.push_back(no);
      }
      if(v>=t&&v<H){
        f.push_back(no);
      }
      if(v<H&&t>v){
        ff.push_back(no);
      }
    }
  }
  sort(s.begin(),s.end(),cmp);
  sort(n.begin(),n.end(),cmp);
  sort(f.begin(),f.end(),cmp);
  sort(ff.begin(),ff.end(),cmp);
  printf("%d\n",cnt);
  print(s);
  print(n);
  print(f);
  print(ff);
  
  return 0;
}

