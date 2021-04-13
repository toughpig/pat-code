#include<cstdio>
//#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn=510;
const int inf=0x3fffffff;
queue<int> q;
//vector<int> city[maxn];
int dist[maxn];
bool inq[maxn];
int path[maxn];
int cost[maxn][maxn];
int dis[maxn][maxn];
int mincost[maxn];
int N,M,S,D;

void dijkstra(int s){
	dist[s]=0;
	mincost[s]=0;
	for(int k=0;k<N;k++){
		int n=-1,min=inf;
		for(int i=0;i<N;i++){
			if(inq[i]==false&&dist[i]<min){
				n=i;
				min=dist[i];
			}
		}
		if(n==-1)
			return;
		inq[n]=true;
		for(int j=0;j<N;j++){
			if(inq[j]==false&&dis[n][j]!=inf){
				if(dist[n]+dis[n][j]<dist[j]){
					dist[j]=dist[n]+dis[n][j];
					path[j]=n;
					mincost[j]=mincost[n]+cost[n][j];
				}
				else if(inq[j]==false&&dist[n]+dis[n][j]==dist[j]&&mincost[n]+cost[n][j]<mincost[j]){
					path[j]=n;
					mincost[j]=mincost[n]+cost[n][j];
				}
			}
		}
	}
}
void print(int a,int b){
	if(path[b]==a){
		printf("%d %d ",a,b);
		return;
	}
	print(a,path[b]);
	printf("%d ",b);
}

int main(){
	scanf("%d%d%d%d",&N,&M,&S,&D);
	fill(dist,dist+N,inf);
	fill(cost[0],cost[0]+maxn*maxn,inf);
	fill(inq,inq+N,false);
	fill(mincost,mincost+maxn,inf);
	fill(dis[0],dis[0]+maxn*maxn,inf);
	int a,b,d,c;
	for(int i=0;i<M;i++){
		scanf("%d%d%d%d",&a,&b,&d,&c);
//		city[a].push_back(b);
		dis[a][b]=d;
		dis[b][a]=d;
		cost[a][b]=c;
		cost[b][a]=c;
	}
	dijkstra(S);
	print(S,D);
	printf("%d %d",dist[D],mincost[D]);
		
	

	
	return 0;
}
