//#include<cstdio>
//#include<vector>
//#include<algorithm>
//using namespace std;
//const int inf=1<<30;
//const int maxn=550;
//int st,en;
//struct node{
//	int v;
//	int d;
//	int t;
//	node(int _v,int _d,int _t):v{_v},d(_d),t(_t){};
//};
//vector<node> road[maxn];
//bool vis[maxn];
//vector<int> path[maxn];
//vector<int> pathh[maxn];
//vector<int> pre[maxn];
//int dist[maxn];
//int cost[maxn];
//int pass[maxn];
//int n,m;
//
//void dij(int u,int e){
//	fill(dist,dist+maxn,inf);
//	fill(cost,cost+maxn,inf);
//	fill(vis,vis+maxn,false);
//	dist[u]=0;
//	cost[u]=0;
//	path[u].push_back(u);
//	for(int i=0;i<n;i++){
//		int k=-1,minn=inf;
//		for(int j=0;j<n;j++){
//			if(vis[j]==false&&dist[j]<minn){
//				k=j;
//				minn=dist[j];
//			}
//		}
//		if(k==-1) break;
//		vis[k]=true;
//		if(vis[e]==true) return;
//		for(int j=0;j<road[k].size();j++){
//			int vv=road[k][j].v;
//			int dd=road[k][j].d;
//			int tt=road[k][j].t;
//			if(vis[vv]==false&&dist[k]+dd<dist[vv]){
//				dist[vv]=dist[k]+dd;
//				path[vv].clear();
//				path[vv].push_back(k);
//				cost[vv]=cost[k]+tt; 
//			}
//			else if(vis[vv]==false&&dist[k]+dd==dist[vv]&&cost[k]+tt<cost[vv]){
//				path[vv].clear();
//				path[vv].push_back(k);
//				cost[vv]=cost[k]+tt;
//			}
//		}
//	}
//}
//
//void dijs(int u,int e){
//	fill(dist,dist+maxn,inf);
//	fill(cost,cost+maxn,inf);
//	fill(vis,vis+maxn,false);
//	dist[u]=0;
//	cost[u]=0;
//	fill(pass,pass+maxn,inf);
//	pass[u]=1;
//	path[u].push_back(u);
//	for(int i=0;i<n;i++){
//		int k=-1,minn=inf;
//		for(int j=0;j<n;j++){
//			if(vis[j]==false&&cost[j]<minn){
//				k=j;
//				minn=cost[j];
//			}
//		}
//		if(k==-1) break;
//		vis[k]=true;
//		if(vis[e]==true) return;
//		for(int j=0;j<road[k].size();j++){
//			int vv=road[k][j].v;
//			int dd=road[k][j].d;
//			int tt=road[k][j].t;
//			if(vis[vv]==false&&cost[k]+tt<cost[vv]){
//				cost[vv]=cost[k]+tt;
//				path[vv].clear();
//				path[vv].push_back(k);
//				pass[vv]=pass[k]+1;
//			}
//			else if(vis[vv]==false&&cost[k]+tt==cost[vv]&&pass[k]+1<pass[vv]){
//				path[vv].clear();
//				path[vv].push_back(k);
//				pass[vv]=pass[k]+1;
//			}
//		}
//	}
//}
//
//void print(int st,int en){
//	if(st==en){
//		printf("%d",st);
//		return;
//	}
//	else if(path[en][0]==st){
//		printf("%d -> %d",st,en);
//		return;
//	}
//	print(st,path[en][0]);
//	printf(" -> %d",en);
//}
//
//int main(){
//	scanf("%d%d",&n,&m);
//	int v1,v2,one,len,tim;
//	for(int i=0;i<m;i++){
//		scanf("%d%d%d%d%d",&v1,&v2,&one,&len,&tim);
//		road[v1].push_back(node(v2,len,tim));
//		if(one==0)
//		road[v2].push_back(node(v1,len,tim));
//	}
//	scanf("%d%d",&st,&en);
//	dij(st,en);
//	printf("Distance = %d: ",dist[en]);
//	print(st,en);
//	printf("\n");
//	dijs(st,en);
//	printf("Time = %d: ",cost[en]);
//	print(st,en);
//	
//	return 0;
//}


#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int inf=1<<30;
const int maxn=550;
int st,en;
struct node{
	int v;
	int d;
	int t;
	node(int _v,int _d,int _t):v{_v},d(_d),t(_t){};
};
vector<node> road[maxn];
bool vis[maxn];
int path[maxn];
int pathh[maxn];
vector<int> pre[maxn];
int dist[maxn];
int cost[maxn];
int pass[maxn];
int n,m;

void dij(int u,int e){
	fill(dist,dist+maxn,inf);
	fill(cost,cost+maxn,inf);
	fill(vis,vis+maxn,false);
	dist[u]=0;
	cost[u]=0;
	path[u]=u;
	for(int i=0;i<n;i++){
		int k=-1,minn=inf;
		for(int j=0;j<n;j++){
			if(vis[j]==false&&dist[j]<minn){
				k=j;
				minn=dist[j];
			}
		}
		if(k==-1) break;
		vis[k]=true;
		if(vis[e]==true) return;
		for(int j=0;j<road[k].size();j++){
			int vv=road[k][j].v;
			int dd=road[k][j].d;
			int tt=road[k][j].t;
			if(vis[vv]==false&&dist[k]+dd<dist[vv]){
				dist[vv]=dist[k]+dd;
				path[vv]=k;
				cost[vv]=cost[k]+tt; 
			}
			else if(vis[vv]==false&&dist[k]+dd==dist[vv]&&cost[k]+tt<cost[vv]){
				path[vv]=k;
				cost[vv]=cost[k]+tt;
			}
		}
	}
}

void dijs(int u,int e){
	fill(cost,cost+maxn,inf);
	fill(vis,vis+maxn,false);
	dist[u]=0;
	cost[u]=0;
	fill(pass,pass+maxn,inf);
	pass[u]=1;
	pathh[u]=u;
	for(int i=0;i<n;i++){
		int k=-1,minn=inf;
		for(int j=0;j<n;j++){
			if(vis[j]==false&&cost[j]<minn){
				k=j;
				minn=cost[j];
			}
		}
		if(k==-1) break;
		vis[k]=true;
		if(vis[e]==true) return;
		for(int j=0;j<road[k].size();j++){
			int vv=road[k][j].v;
			int dd=road[k][j].d;
			int tt=road[k][j].t;
			if(vis[vv]==false&&cost[k]+tt<cost[vv]){
				cost[vv]=cost[k]+tt;
				pathh[vv]=k;
				pass[vv]=pass[k]+1;
			}
			else if(vis[vv]==false&&cost[k]+tt==cost[vv]&&pass[k]+1<pass[vv]){
				pathh[vv]=k;
				pass[vv]=pass[k]+1;
			}
		}
	}
}

void print(int st,int en){
	if(st==en){
		printf("%d",st);
		return;
	}
	else if(path[en]==st){
		printf("%d -> %d",st,en);
		return;
	}
	print(st,path[en]);
	printf(" -> %d",en);
}

void printt(int st,int en){
	if(st==en){
		printf("%d",st);
		return;
	}
	else if(pathh[en]==st){
		printf("%d -> %d",st,en);
		return;
	}
	print(st,pathh[en]);
	printf(" -> %d",en);
}

bool judge(int st,int en){
	int h=en;
	int hh=en;
	while(path[h]!=st&&pathh[hh]!=st){
		if(h!=hh){
			return false;
		}
		h=path[h];
		hh=pathh[hh];
	}
	if(h!=hh||path[h]!=pathh[hh]) return false;
	else return true;
}

int main(){
	scanf("%d%d",&n,&m);
	int v1,v2,one,len,tim;
	for(int i=0;i<m;i++){
		scanf("%d%d%d%d%d",&v1,&v2,&one,&len,&tim);
		road[v1].push_back(node(v2,len,tim));
		if(one==0)
		road[v2].push_back(node(v1,len,tim));
	}
	scanf("%d%d",&st,&en);
	dij(st,en);
	dijs(st,en);
	bool flag=judge(st,en);
	if(flag==false){
		printf("Distance = %d: ",dist[en]);
		print(st,en);
		printf("\n");
		printf("Time = %d: ",cost[en]);
		printt(st,en);
	}
	else{
		printf("Distance = %d; Time = %d: ",dist[en],cost[en]);
		printt(st,en);
	}
	return 0;
}
