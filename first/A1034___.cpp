#include<cstdio>
#include<map>
#include<vector>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=2010;
int node[maxn][maxn];
bool vis[maxn];
map<string,int> mp;
map<int,string> pm;
vector<pair<string,int> > ans;
int tot[maxn];
int N,W;
int head,mem,sum;
int cnt=0;

void dfs(int &h,int u,int &mem,int &sum){
	vis[u]=true;
	sum+=tot[u];
	if(tot[h]<tot[u])
		h=u;
	mem++;
	for(int i=0;i<cnt;i++){
		if(node[u][i]!=0&&vis[i]==false)
			dfs(h,i,mem,sum);
	}
}

bool cmp(pair<string,int> a,pair<string,int> b){
	return strcmp(a.first.c_str(),b.first.c_str())<0;
}

int main(){
	fill(node[0],node[0]+maxn*maxn,0);
	fill(vis,vis+maxn,false);
	scanf("%d%d",&N,&W);
	string a,b;
	int time;
	int aid,bid;
	for(int i=0;i<N;i++){
		cin>>a>>b>>time;
		if(mp.find(a)!=mp.end()){
			aid=mp.find(a)->second;
		}
		else{
			mp[a]=cnt;
			pm[cnt]=a;
			aid=cnt;
			cnt++;
		}
		if(mp.find(b)!=mp.end()){
			bid=mp.find(b)->second;
		}
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
		if(vis[i]==false){
			head=i;
			mem=0;
			sum=0;
			dfs(head,i,mem,sum);
			if(sum>W*2&&mem>2)
				ans.push_back(make_pair(pm[head],mem));
		}
	}
	sort(ans.begin(),ans.end(),cmp);
	if(ans.size()==0)
	printf("0");
	else{
		printf("%d\n",ans.size());
		for(int i=0;i<ans.size();i++){
			printf("%s %d\n",ans[i].first.c_str(),ans[i].second);
		}
	}
	return 0;
}
