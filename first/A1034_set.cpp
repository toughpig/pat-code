#include<cstdio>
#include<vector>
#include<map>
#include<algorithm>
#include<string>
#include<iostream>
#include<cstring>
using namespace std;
const int maxn=2010;
int fa[maxn];
bool vis[maxn];
int node[maxn][maxn];
int N,W;
int cnt=0;
map<string,int> mp;
map<int,string> pm;
vector<pair<string,int> > ans;
int tot[maxn]={0};

int findfa(int a){
	int b=a;
	while(fa[a]!=a) a=fa[a];
	int c=b;
	while(fa[b]!=a){
		fa[c]=a;
		b=fa[b];
		c=b;
	}
	return a;
}

void Union(int a,int b){
	int faa=findfa(a);
	int fab=findfa(b);
	if(tot[faa]>tot[fab])
		fa[fab]=faa;
	else
		fa[faa]=fab;
}

bool cmp(pair<string,int> a,pair<string,int> b){
	return strcmp(a.first.c_str(),b.first.c_str())<0;
}

map<string,int> tempans;

int main(){
	fill(node[0],node[0]+maxn*maxn,0);
	fill(vis,vis+maxn,false);
	string a,b;
	int time;
	scanf("%d%d",&N,&W);
	for(int i=0;i<maxn;i++){
		fa[i]=i;
	}
	for(int i=0;i<N;i++){
		cin>>a>>b>>time;
	int aid,bid;
	if(mp.find(a)!=mp.end()) aid=mp.find(a)->second;
	else{
		mp[a]=cnt;
		pm[cnt]=a;
		aid=cnt;
		cnt++;
	}
	if(mp.find(b)!=mp.end()) bid=mp.find(b)->second;
	else{
		mp[b]=cnt;
		pm[cnt]=b;
		bid=cnt;
		cnt++;
	}
	node[aid][bid]=node[bid][aid]=time;
	tot[aid]+=time;
	tot[bid]+=time;
}
	for(int i=0;i<cnt;i++){
		for(int j=0;j<cnt;j++)
			if(node[i][j]!=0)
				Union(i,j);
	}
	int tott[maxn]={0};
	for(int i=0;i<cnt;i++){
		int fat=findfa(i);
		string s=pm[fat];
		tott[fat]+=tot[i];
		tempans[s]++;
	}
	for(int i=0;i<maxn;i++){
		if(tott[i]>W*2&&tempans[pm[i]]>2)
			ans.push_back(make_pair(pm[i],tempans[pm[i]]));
	}
	sort(ans.begin(),ans.end(),cmp);
	if(ans.size()>0){
		printf("%d\n",ans.size());
		for(int i=0;i<ans.size();i++)
			printf("%s %d\n",ans[i].first.c_str(),ans[i].second);
			
	}
	else
	printf("0");
	return 0;

}
