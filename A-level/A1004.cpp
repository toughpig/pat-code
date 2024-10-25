//dfs
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

const int maxn=100;

queue<int> q;
vector<int> node[maxn];
bool vis[maxn]={false};
int cnt[maxn]={0};

int N,M,root,k,temp;
int depth=0;

void dfs(int root,int level){
	if(depth<level) depth=level;
	if(node[root].size()==0){
		cnt[level]++;
		vis[root]=true;
		return;
	}
	vis[root]=true;
	for(int i=0;i<node[root].size();i++){
		if(vis[node[root][i]]==false)
			dfs(node[root][i],level+1);
	}
}

int main(){
	scanf("%d%d",&N,&M);
	for(int i=0;i<M;i++){
		scanf("%d%d",&root,&k);
		for(int j=0;j<k;j++){
			scanf("%d",&temp);
			node[root].push_back(temp);
		}
	}
	dfs(1,1);
	for(int i=1;i<=depth;i++){
		if(i==1) printf("%d",cnt[i]);
		else printf(" %d",cnt[i]);
	}
	return 0;
}
