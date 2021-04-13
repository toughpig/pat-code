#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
struct node{
	int v,dis;
	node(int _v,int _dis):v(_v),dis(_dis){};
};
const int inf=1<<30;
const int maxn=510;
int dist[maxn];
bool vis[maxn]={false};
int N,M,st,en,a,b,len;
vector<node> arc[maxn];
int wei[maxn];
int num[maxn]={0};
int maxx[maxn]={0};

void dij(int sta,int end){
	fill(dist,dist+maxn,inf);
	dist[sta]=0;
	num[sta]=1;
	maxx[sta]=wei[sta];
	for(int k=0;k<maxn;k++){
		int minn=inf,n=-1;
		for(int i=0;i<N;i++){
			if(vis[i]==false&&dist[i]<minn){
				minn=dist[i];
				n=i;
			}
		}
		if(n==-1) return;
		vis[n]=true;
		if(n==en) break;
		for(int i=0;i<arc[n].size();i++){
			node next=arc[n][i];
			if(vis[next.v]==false&&next.dis+dist[n]<dist[next.v]){
				num[next.v]=num[n];
				dist[next.v]=dist[n]+next.dis;
				maxx[next.v]=wei[next.v]+maxx[n];
			}
			else if(vis[next.v]==false&&next.dis+dist[n]==dist[next.v]){
				num[next.v]+=num[n];
				if(maxx[next.v]<maxx[n]+wei[next.v])
					maxx[next.v]=maxx[n]+wei[next.v];
			}
		}
	}
}

int main(){
	scanf("%d%d%d%d",&N,&M,&st,&en);
	for(int i=0;i<N;i++){
		scanf("%d",wei+i);
	}
	for(int i=0;i<M;i++){
		scanf("%d%d%d",&a,&b,&len);
		arc[a].push_back(node(b,len));
		arc[b].push_back(node(a,len));
	}
	dij(st,en);
	printf("%d %d",num[en],maxx[en]);
	
	return 0;
}
