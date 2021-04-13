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
//int tot[maxn];
//int tott[maxn];
int C,N,S,M;
int a,b,c;
int held[maxn];
vector<Node> st[maxn];
vector<int> path[maxn];
vector<int> pathh[maxn];
const int inf=0x3fffffff;
vector<int> temp;
int mid;
vector<int> ans;
int ba,se,minba,minse;

void dijkstra(int s,int u){
	fill(dist,dist+maxn,inf);
//	fill(tot,tot+maxn,inf);
//	fill(tott,tott+maxn,inf);
	fill(vis,vis+maxn,false);
//	vis[s]=true;
	dist[s]=0;
//	tot[s]=0;
//	tott[s]=0;
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
		for(int i=0;i<st[n].size();i++){
			int w=st[n][i].w;
			int v=st[n][i].v;
			if(dist[n]+w<dist[v]){
				path[v].clear();
				path[v].push_back(n);
				dist[v]=dist[n]+w;
			}
			else if(dist[n]+w==dist[v]){
				path[v].push_back(n);
			}
		}
		for(int k=0;k<path[n].size();k++)
				pathh[path[n][k]].push_back(n);
		if(vis[u]==true){
			return;
		}
	}
}
void change(){
	ans.clear();
	for(int i=0;i<temp.size();i++){
		ans.push_back(temp[i]);
	}
}

void dfs(int s){
	if(s==S){
		temp.push_back(s);
		se=ba=minse=minba=0;
		for(int o=1;o<=temp.size();o++){
			int q=temp[o];
			int k=mid-held[q];
			if(k>0){
				ba-=k;
				if(ba<0){
				se+=(-1)*ba;
				ba=0;
				}
			}
			else{
				ba+=held[q]-mid;
			}
		}
		if(se<minse){
			minse=se;
			minba=ba;
			change();
		}
		else if(se==minse&&ba<minba){
			minba=ba;
			change();
		}
		temp.pop_back();
		return;
	}
	else{
		temp.push_back(s);
		for(int p=0;p<pathh[s].size();p++){
			dfs(pathh[s][p]);
		}
		temp.pop_back();
	}
	
}


void print(){
	for(int i=0;i<ans.size();i++){
		printf("%d",ans[i]);
		if(i<ans.size()-1)
			printf("->");
	}
}

int main(){
	scanf("%d%d%d%d",&C,&N,&S,&M);
	held[0]=C;
	for(int i=1;i<=N;i++){
		scanf("%d",&held[i]);
	} 
	for(int j=0;j<M;j++){
		scanf("%d%d%d",&a,&b,&c);
		st[a].push_back(Node(b,c));
		st[b].push_back(Node(a,c));
	}
	mid=C/2;
	dijkstra(0,S);
	ba=se=minba=minse=0;
	dfs(0);
	printf("%d ",minse);
	print();
	printf(" %d",minba);
	return 0;
} 
