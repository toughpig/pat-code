#include<cstdio>
#include<vector>
#include<map>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=250;
const int inf=0x3fffffff;
struct Node{
	int v,w;
	Node(int _v,int _w):v(_v),w(_w){}
};
vector<Node> city[maxn];
int dist[maxn];
bool vis[maxn];
vector<int> path[maxn];
vector<int> ans;
vector<int> temp;
map<string,int> id;
int cnt=1,N,K;
string cty;
int hap[maxn];
int maxhap;
int happ;
int avehapp;
int avehap;

void dijkstra(){
	fill(dist,dist+maxn,inf);
	fill(vis,vis+maxn,false);
	dist[0]=0;
	for(int i=0;i<N;i++){
		int n=-1,minn=inf;
		for(int j=0;j<N;j++){
			if(dist[j]<minn&&vis[j]==false){
				n=j;
				minn=dist[j];
			}
		}
		if(n==-1)
			return;
		vis[n]=true;
		string str="ROM";
		if(id.find(str)->second==n){
			return;
		}
		for(int k=0;k<city[n].size();k++){
			int vv=city[n][k].v;
			int ww=city[n][k].w;
			if(vis[vv]==false&&dist[n]+ww<dist[vv]){
				path[vv].clear();
				path[vv].push_back(n);
				dist[vv]=ww+dist[n];
			}
			else if(vis[vv]==false&&dist[vv]==dist[n]+ww){
				path[vv].push_back(n);
			}
		}
	}
}

void change(vector<int> &a,vector<int> &b){
	a.clear();
	for(int i=0;i<b.size();i++)
		a.push_back(b[i]);
}

void dfs(int u){
	if(u==0){
		temp.push_back(u);
		happ+=hap[u];
		if(happ>maxhap){
			change(ans,temp);
			maxhap=happ;
		}
		else if(happ==maxhap&&temp.size()<ans.size()){
			change(ans,temp);
		}
		happ-=hap[u];
		temp.pop_back();
		return;
	}
	temp.push_back(u);
	happ+=hap[u];
	cnt+=(path[u].size()-1);
	for(int i=0;i<path[u].size();i++){
		dfs(path[u][i]);
	}
	temp.pop_back();
	happ-=hap[u];
}



void print(){
	for(int i=ans.size()-1;i>=0;i--){
		int tem=ans[i];
		string str;
		for(map<string,int>::iterator it=id.begin();it!=id.end();it++){
			if(it->second==tem)
				str=it->first;
		}
		printf("%s",str.c_str());
		if(i>0)
			printf("->");
	}
}
int main(){
	scanf("%d%d",&N,&K);
	cin>>cty;
	int k=0;
	id[cty]=k++;
	hap[0]=0;
	int cost;
	for(int i=0;i<N-1;i++){
		cin>>cty;
		scanf("%d",&cost);
		hap[k]=cost;
		id[cty]=k;
		k++;
	}
	for(int j=0;j<K;j++){
		string a,b;
		cin>>a>>b>>cost;
		city[id.find(a)->second].push_back(Node(id.find(b)->second,cost));
		city[id.find(b)->second].push_back(Node(id.find(a)->second,cost));
	}
	dijkstra();
	int u=id.find("ROM")->second;
	maxhap=0;
	avehap=0;
	avehapp=0;
//	path[0].push_back(0);
	happ=0;
	dfs(u);
	avehap=maxhap/(ans.size()-1);
	printf("%d %d %d %d\n",cnt,dist[id.find("ROM")->second],maxhap,avehap);
	print();
	
	
	return 0;
}
