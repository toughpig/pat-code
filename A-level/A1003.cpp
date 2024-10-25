//单源最短路dijkstra,输出最短路径数目，以及第二标尺路径点权之和
#include<cstdio>
#include<algorithm>
using namespace std;

const int inf=1<<30;
const int maxn=500;

int dist[maxn];
int arc[maxn][maxn];
int num[maxn];  //该节点最短路条数
bool vis[maxn];
int gather[maxn];
int team[maxn];

int n,m,st,en,temp,a,b;

void dij(int u,int v){
	fill(dist,dist+maxn,inf);
	fill(vis,vis+maxn,false);
	fill(gather,gather+maxn,0);
	fill(num,num+maxn,0);
	dist[u]=0;
	gather[u]=team[u];
	num[u]=1;
	for(int i=0;i<n;i++){
		int k=-1,minn=inf;
		for(int j=0;j<n;j++){
			if(minn>dist[j]&&vis[j]==false){
				minn=dist[j];
				k=j;
			}
		}
		if(k==-1) return;
		vis[k]=true;
		if(k==v) return;
		for(int p=0;p<n;p++){
			if(vis[p]==false&&dist[p]>dist[k]+arc[k][p]){
				dist[p]=dist[k]+arc[k][p];
				num[p]=num[k];
				gather[p]=gather[k]+team[p];
			}
			else if(vis[p]==false&&dist[p]==dist[k]+arc[k][p]){
				num[p]+=num[k];                                  //此处容易出错 
				if(gather[p]<gather[k]+team[p])
					gather[p]=gather[k]+team[p];
			}
		}
		
	}
}

int main(){
	fill(arc[0],arc[0]+maxn*maxn,inf);
	scanf("%d%d%d%d",&n,&m,&st,&en);
	for(int i=0;i<n;i++)
		scanf("%d",&team[i]);
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&a,&b,&temp);
		arc[a][b]=arc[b][a]=temp;
	}
	dij(st,en);
	printf("%d %d",num[en],gather[en]);
	return 0;
} 
