#include<cstdio>
#include<set>
using namespace std;
int main(){
  
  int N;
  scanf("%d",&N);
  set<int> s[N];
  for(int i=0;i<N;i++){
    int tot;
    scanf("%d",&tot);
    for(int j=0;j<tot;j++){
      int tem;
      scanf("%d",&tem);
      s[i].insert(tem);
    }
  }
  int m;
  scanf("%d",&m);
  for(int i=0;i<m;i++){
    int a,b;
    scanf("%d%d",&a,&b);
    int B=0;
    int J=s[b-1].size();
    for(set<int>::iterator j=s[a-1].begin();j!=s[a-1].end();j++){
        if(s[b-1].end()!=s[b-1].find(*j))
			B++;
		else
			J++;
    }
    printf("%.1f%\n",100.0*B/J);
  }
  
  return 0;
}

