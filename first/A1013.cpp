#include<cstdio>
#include<vector>
using namespace std;
const int maxn=1010;
vector<int> city[maxn];
int N,M,C;
int a,b;
bool vis[maxn]={false};

void dfs(int u){
		vis[u]=true;
		for(int i=0;i<city[u].size();i++){
			if(vis[city[u][i]]==false){
				dfs(city[u][i]);
			}
		}
}

int dfstranv(int s){
	int cnt=0;
	vis[s]=true;
	for(int i=1;i<=N;i++){
		if(i==s)
			continue;
		if(vis[i]==false){
			cnt++;
			dfs(i);
		}
	}
	return cnt-1;
}

int main(){
	scanf("%d%d%d",&N,&M,&C);
	for(int i=0;i<M;i++){
		scanf("%d%d",&a,&b);
		city[a].push_back(b);
		city[b].push_back(a);
	}
	for(int i=0;i<C;i++){
		fill(vis,vis+maxn,false);
		int temp;
		scanf("%d",&temp);
		vis[temp]=true;
		int ans=dfstranv(temp);
		printf("%d\n",ans);
	}
	return 0;
}
