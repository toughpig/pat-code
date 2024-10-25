#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn=550;
const int inf=1<<30;

int path[maxn];
bool vis[maxn]={false};
int dist[maxn];
int minn[maxn];
int arc[maxn][maxn];
int co[maxn][maxn];

int n,m,s,d,c1,c2,cost,dis;

void dij(int u,int e){
	dist[u]=0;
	path[u]=u;
	minn[u]=0;
	for(int j=0;j<n;j++){
		int k=-1,mn=inf;
		for(int i=0;i<n;i++){
			if(vis[i]==false&&mn>dist[i]){
				mn=dist[i];
				k=i;
			}
		}
		if(k==-1) return;
		vis[k]=true;
		if(k==e) return;
		for(int i=0;i<n;i++){
			if(vis[i]==false&&arc[k][i]!=inf&&dist[i]>dist[k]+arc[k][i]){
				dist[i]=dist[k]+arc[k][i];
				minn[i]=minn[k]+co[k][i];
				path[i]=k;
			}
			else if(vis[i]==false&&arc[k][i]!=inf&&dist[i]==dist[k]+arc[k][i]&&minn[i]>minn[k]+co[k][i]){
				path[i]=k;
				minn[i]=minn[k]+co[k][i];
			}
		}
		
	}
}
void print(int u,int e){
	if(path[e]==u){
		printf("%d %d",u,e);
		return;
	}
	print(u,path[e]);
	printf(" %d",e);
}


int main(){
	fill(co[0],co[0]+maxn*maxn,inf);
	fill(dist,dist+maxn,inf);
	fill(arc[0],arc[0]+maxn*maxn,inf);
	fill(minn,minn+maxn,inf);
	scanf("%d%d%d%d",&n,&m,&s,&d);
	for(int i=0;i<m;i++){
		scanf("%d%d%d%d",&c1,&c2,&dis,&cost);
		arc[c1][c2]=arc[c2][c1]=dis;
		co[c1][c2]=co[c2][c1]=cost;
	}
	dij(s,d);
	print(s,d);
	printf(" %d %d",dist[d],minn[d]);
	return 0;
}
