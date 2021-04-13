#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;
const int maxn=1020;
const int inf=0x3fffffff;
struct Node{
	int v,w;
	Node(int _v,int _w):v(_v),w(_w){}
};
int N,M,K,D,aa,bb,cc;
string a,b;
vector<Node> node[maxn];
bool vis[maxn]={false};
int dist[maxn];
struct cand{
	double sh,av;
	int index;
//	cand(double _sh,double _av,int _index):sh(_sh),av(_av),index(_index){}
};
struct cand ans[maxn];

void dijkstra(int u){
	dist[u]=0;
	double sum=0;
	double sho=inf*1.0;
	for(int k=0;k<N+M;k++){
		int n=-1,minn=inf;
		for(int i=1;i<=N+M;i++){
			if(vis[i]==false&&dist[i]<minn){
				n=i;
				minn=dist[i];
			}
		}
		if(n==-1)
			return;
		vis[n]=true;
		if(n<=N&&minn>D){
			cand* temp=(cand *)malloc(sizeof(cand));
			temp->sh=-1;
			temp->index=u-N;
			temp->av=inf*1.0;
			ans[u-N]=*temp;
			free(temp);
			return;
		}
		if(n<=N){
			sum+=minn;
			if(minn<sho){
				sho=minn*1.0;
			}
		}
		for(int j=0;j<node[n].size();j++){
			int vv=node[n][j].v;
			int ww=node[n][j].w;
			if(vis[vv]==false&&dist[n]+ww<dist[vv]){
				dist[vv]=ww+dist[n];
			}
		}
	}
	cand* temp=(cand *)malloc(sizeof(cand));
			temp->sh=sho;
			temp->index=u-N;
			temp->av=1.0*sum/(1.0*N);
			ans[u-N]=*temp;
			free(temp);
}

bool cmp(cand a,cand b){
	if(a.sh>b.sh){
		return true;
	}
	else if(a.sh<b.sh){
		return false;
	}
	else{
		if(a.av<b.av)
			return true;
		else if(a.av>b.av)
			return false;
		else
			return a.index<b.index;
	}
}

int main(){
	scanf("%d%d%d%d",&N,&M,&K,&D);
//	getchar();
	for(int i=0;i<K;i++){
		cin>>a>>b;
		if(a[0]=='G'){
			a.erase(a.begin());
			sscanf(a.c_str(),"%d",&aa);
			aa+=N;
		}
		else
			sscanf(a.c_str(),"%d",&aa);
		if(b[0]=='G'){
			b.erase(b.begin());
			sscanf(b.c_str(),"%d",&bb);
			bb+=N;
		}
		else
			sscanf(b.c_str(),"%d",&bb);
		scanf("%d",&cc);
		node[aa].push_back(Node(bb,cc));
		node[bb].push_back(Node(aa,cc));
	}
	for(int p=0;p<M;p++){
		fill(dist,dist+maxn,inf);
		fill(vis,vis+maxn,false);
		dijkstra(N+p+1);
	}
	sort(ans+1,ans+M+1,cmp);
	if(ans[1].sh==-1)
		printf("No Solution");
	else
		printf("G%d\n%.1lf %.1lf",ans[1].index,ans[1].sh,ans[1].av);
	return 0;
}
