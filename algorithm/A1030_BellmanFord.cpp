#include<cstdio>
#include<vector>
using namespace std;

struct Node{
	int v;
	int w;
	int cos;
	Node(int _v,int _w,int _cos):v(_v),w(_w),cos(_cos){}
};
const int inf=0x3fffffff;
const int maxn=1010;
int N,M,S,D;
int a,b,c,d;
vector<Node> city[maxn];
int dist[maxn];
int mincost[maxn];
int path[maxn];

bool bellman(int u){
	dist[u]=0;
	mincost[u]=0;
	for(int i=0;i<N-1;i++){
		for(int j=0;j<N;j++){
//			if(dist[j]!=inf)
			for(int k=0;k<city[j].size();k++){
				int c2=city[j][k].v;
				int c2w=city[j][k].w;
				int c2c=city[j][k].cos;
				if(dist[j]+c2w<dist[c2]){
					dist[c2]=dist[j]+c2w;
					path[c2]=j;
					mincost[c2]=mincost[j]+c2c;
				}
				else if(dist[j]+c2w==dist[c2]&&mincost[j]+c2c<mincost[c2]){
					mincost[c2]=mincost[j]+c2c;
					path[c2]=j;
				}
			}
		}
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<city[i].size();j++){
			if(dist[i]+city[i][j].w<dist[city[i][j].v]){
				return false;
			}
		}
	}
	return true;
}

void print(int s,int d){
	if(path[d]==s){
		printf("%d %d ",s,d);
		return;
	}
	print(s,path[d]);
	printf("%d ",d);
}

int main(){
	scanf("%d%d%d%d",&N,&M,&S,&D);
	fill(dist,dist+maxn,inf);
	fill(mincost,mincost+maxn,inf);
	for(int i=0;i<M;i++){
		scanf("%d%d%d%d",&a,&b,&d,&c);
		city[a].push_back(Node(b,d,c));
		city[b].push_back(Node(a,d,c));
	}
	for(int j=0;j<N;j++){
		path[j]=j;
	}
	bool flag=bellman(S);
	if(flag){
		print(S,D);
		printf("%d %d",dist[D],mincost[D]);
	}
	return 0;
}
