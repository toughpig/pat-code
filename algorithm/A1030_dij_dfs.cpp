#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn=550;
const int inf=1<<30;
vector<int> path[maxn];
int dist[maxn];
bool vis[maxn]={false};
int arc[maxn][maxn];
int cost[maxn][maxn];
vector<int> ans,temp;
int minn[maxn];
int N,M,st,en,a,b,c,d;

void dij(int s,int e){
	fill(dist,dist+maxn,inf);
	dist[s]=0;
	path[s].push_back(s);
	fill(minn,minn+maxn,inf);
	minn[s]=0;
	for(int j=0;j<N;j++){
		int MIN=inf,n=-1;
		for(int i=0;i<N;i++){
			if(vis[i]==false&&dist[i]<MIN){
				n=i;
				MIN=dist[i];
			}
		}
		if(n==-1) return;
		vis[n]=true;
//		if(n==e) break;
		for(int i=0;i<N;i++){
			if(arc[n][i]!=inf&&vis[i]==false&&dist[n]+arc[n][i]<dist[i]){
				dist[i]=dist[n]+arc[n][i];
				minn[i]=minn[n]+cost[n][i];
				path[i].clear();
				path[i].push_back(n);
			}
			else if(arc[n][i]!=inf&&vis[i]==false&&dist[n]+arc[n][i]==dist[i]){
				if(minn[n]+cost[n][i]<minn[i]){
					path[i].clear();
					path[i].push_back(n);
					minn[i]=minn[n]+cost[n][i];
				}
			}
		}
	}
	
}

void print(int a){
	if(a==st){
		printf("%d",st);
		return;
	}
	print(path[a][0]);
	printf(" %d",a);
}

int main(){
	scanf("%d%d%d%d",&N,&M,&st,&en);
	fill(arc[0],arc[0]+maxn*maxn,inf);
	fill(cost[0],cost[0]+maxn*maxn,inf);
	for(int i=0;i<M;i++){
		scanf("%d%d%d%d",&a,&b,&d,&c);
		arc[a][b]=arc[b][a]=d;
		cost[a][b]=cost[b][a]=c;
	}
	dij(st,en);
	int i=st;
	print(en);
	printf(" %d %d",dist[en],minn[en]);
	return 0;
}
