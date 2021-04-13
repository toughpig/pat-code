#include<cstdio>
#include<vector>
#include<queue>
using namespace std;


struct Node{
	int v,w,cos;
	Node(int _v,int _w,int _cos):v(_v),w(_w),cos(_cos){}
};
const int inf=0x3fffffff;
const int maxn=1010;
queue<int> q;
bool inq[maxn]={false};
int num[maxn]={0};
vector<Node> city[maxn];
int dist[maxn];
int mincost[maxn];
int path[maxn];
int N,M,S,D;
int a,b,c,d;
bool flag;
bool SPFA(int u){
	fill(dist,dist+maxn,inf);
	fill(mincost,mincost+maxn,inf);
	dist[u]=0;
	mincost[u]=0;
	q.push(u);
	num[u]++;
	inq[u]=true;
	while(!q.empty()){
		int temp=q.front();
		q.pop();
		inq[u]=false;
		for(int i=0;i<city[temp].size();i++){
			int c2=city[temp][i].v;
			int c2w=city[temp][i].w;
			int c2c=city[temp][i].cos;
			if(dist[temp]+c2w<dist[c2]){
				dist[c2]=c2w+dist[temp];
				path[c2]=temp;
				mincost[c2]=mincost[temp]+c2c;
				if(inq[c2]==false){
					q.push(c2);
					num[c2]++;
					if(num[c2]>=N)
						return false;
				}
			}
			else if(dist[temp]+c2w==dist[c2]&&mincost[temp]+c2c<mincost[c2]){
				path[c2]=temp;
				mincost[c2]=mincost[temp]+c2c;
				if(inq[c2]==false){
					q.push(c2);
					num[c2]++;
					if(num[c2]>=N)
						return false;
				}
			}
		}
	}
	return true;
}
void print(int s,int d){
	if(path[d]==s){
		printf("%d %d ",s,d);
		return ;
	}
		print(s,path[d]);
		printf("%d ",d);
	
}


int main(){
	scanf("%d%d%d%d",&N,&M,&S,&D);
	for(int i=0;i<M;i++){
		scanf("%d%d%d%d",&a,&b,&d,&c);
		city[a].push_back(Node(b,d,c));
		city[b].push_back(Node(a,d,c));
	}
	flag=SPFA(S);
	if(flag){
		print(S,D);
		printf("%d %d",dist[D],mincost[D]);
	}
	return 0;
}
