#include<cstdio>
#include<vector>
#include<algorithm>
//#include<map>
#include<queue>
using namespace std;
const int maxn=1010;
vector<int> user[maxn];
bool inq[maxn]={false};
int N,L,M,temp;
int ans=0;
//int lev[maxn]={0};
//queue<int> q;

//当构成环时，dfs不能全面访问 

void dfs(int u,int level){
	if(level>L) return;
	int tem;
	for(int i=0;i<user[u].size();i++){
		tem=user[u][i];
		if(inq[tem]==false){
			inq[tem]=true;
			ans++;
			dfs(tem,level+1);
		}
	}
}

int main(){
	scanf("%d%d",&N,&L);
	int num;
	for(int i=1;i<=N;i++){
		scanf("%d",&num);
		for(int j=0;j<num;j++){
			scanf("%d",&temp);
			user[temp].push_back(i);
		}
	}
	scanf("%d",&num);
	for(int i=0;i<num;i++){
		scanf("%d",&temp);
		fill(inq,inq+maxn,false);
//		fill(lev,lev+maxn,0);
		ans=0;
		inq[temp]=true;
		dfs(temp,1);
		printf("%d\n",ans);
	}
	
	return 0;
}
