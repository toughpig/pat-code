#include<cstdio>
#include<queue>
#include<vector>
using namespace std;

priority_queue<int,vector<int>,greater<int> > q;
int n,temp;
vector<int> node;

int main(){
  scanf("%d",&n);
  for(int i=0;i<n;i++){
  	scanf("%d",&temp);
  	q.push(temp);
  }
  while(!q.empty()){
    temp=q.top();
    q.pop();
    if(q.empty()) break;
    else{
      temp+=q.top();
      q.pop();
      q.push(temp/2);
    }
  }
  printf("%d",temp);
  return 0;
}
