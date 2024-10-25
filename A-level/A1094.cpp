#include<cstdio>
#include<vector>
using namespace std;
const int maxn=110;
vector<int> node[maxn];
int level[maxn]={0};
int depth_=1;
void dfs(int root,int depth){
	level[depth]++;
	if(level[depth]>depth_){
		depth_=depth;
	}
	if(node[root].size()==0)
		return;
	else{
		for(int k=0;k<node[root].size();k++)
			dfs(node[root][k],depth+1);
	}
}
int main(){
	int N,M;
	int fa,so,num;
	scanf("%d %d",&N,&M);
	for(int i=0;i<M;i++){
		scanf("%d%d",&fa,&num);
		for(int j=0;j<num;j++){
			scanf("%d",&so);
			node[fa].push_back(so);
		}
	}
	dfs(1,1);
	printf("%d %d",level[depth_],depth_);
	return 0;
}
 
