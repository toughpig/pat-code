#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

struct Node{
	int v,w;
	Node(int _v,int _w):v(_v),w(_w){}
};
const int maxn=510;
int dist[maxn];
bool vis[maxn];
int tot[maxn];
int tott[maxn];
int C,N,S,M;
int a,b,c;
int held[maxn];
vector<Node> st[maxn];
int path[maxn];
int pathh[maxn];
const int inf=0x3fffffff;
int temp;

void dijkstra(int s,int u){
	path[s]=s;
	fill(dist,dist+maxn,inf);
	fill(tot,tot+maxn,inf);
	fill(tott,tott+maxn,inf);
	fill(vis,vis+maxn,false);
//	vis[s]=true;
	dist[s]=0;
	tot[s]=0;
	tott[s]=0;
	for(int j=0;j<=N;j++){
		int n=-1,minn=inf;
		for(int i=0;i<=N;i++){
			if(vis[i]==false&&dist[i]<minn){
				n=i;
				minn=dist[i];
			}
		}
		if(n==-1)
			return;
		vis[n]=true;
		if(vis[u]==true)
			return;
		for(int i=0;i<st[n].size();i++){
			int w=st[n][i].w;
			int v=st[n][i].v;
			if(dist[n]+w<dist[v]){
				path[v]=n;
//				pathh[v]=n;
				dist[v]=dist[n]+w;
				if(temp-held[v]<=0){
					tot[v]=tot[n];
					tott[v]=tott[n]+held[v]-temp;
				}
				else{
					tott[v]=tott[n]-temp+held[v];
					tot[v]=tot[n];
					if(tott[v]<0){
						tot[v]=tot[n]-tott[v];
						tott[v]=0;
					}
				}
//				tott[v]=tott[n]+held[v]-temp;
			}
			else if(dist[n]+w==dist[v]){
				int aa=tot[v];
				int bb=tott[v];
				if(temp-held[v]<=0){
					tot[v]=tot[n];
					tott[v]=tott[n]+held[v]-temp;
				}
				else{
					tott[v]=tott[n]-temp+held[v];
					tot[v]=tot[n];
					if(tott[v]<0){
						tot[v]=tot[n]-tott[v];
						tott[v]=0;
					}
				}
				if(aa<tot[v]){
					tot[v]=aa;
				}
				else if(aa==tot[v]&&bb<tott[v]){
					tott[v]=bb;
				}
				else
					path[v]=n;
			}
		}
	}
}

void print(int s,int d){
	if(path[d]==s){
		printf("%d->%d",s,d);
		return;
	}
	print(s,path[d]);
	printf("->%d",d);
}

int main(){
	scanf("%d%d%d%d",&C,&N,&S,&M);
	for(int i=1;i<=N;i++){
		scanf("%d",&held[i]);
	} 
	for(int j=0;j<M;j++){
		scanf("%d%d%d",&a,&b,&c);
		st[a].push_back(Node(b,c));
		st[b].push_back(Node(a,c));
	}
	temp=C/2;
	dijkstra(0,S);
	printf("%d ",tot[S]);
	print(0,S);
	printf(" %d",tott[S]);
	return 0;
} 
