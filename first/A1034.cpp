#include<cstdio>
#include<vector>
#include<map>
#include<string>
#include<iostream>
#include<cstring>
using namespace std;


int N,K;
vector<int> adj[2010];
map<string,int> name; 
int sum,mem;
map<string,int> an;
bool vis[2010]={false};
int tot[2010]={0};
int head;

int findh(int maxn,int a,int b){
	if(tot[maxn]<tot[a]||tot[maxn]<tot[b]){
		return tot[a]>tot[b]?a:b;
	}
	return maxn;
}

void dfs(int v){
	vis[v]=true;
	int maxn=v;
	for(int i=0;i<adj[v].size();i++){
		if(vis[adj[v][i]]==false){
			sum+=tot[adj[v][i]];
			mem++;
//			tot[v]+=temp.w;
//			tot[i]+=temp.w;
			head=findh(maxn,i,v);
			dfs(adj[v][i]);
		}
	}
}

int main(){
	string a,b;
	int cnt=0;
	int time;
	scanf("%d %d",&N,&K);
//	getchar();
//	adj.resize(N);
	for(int i=0;i<N;i++){
		cin>>a>>b>>time;
//		scanf("%s %s %d",a,b,&time);
		if(name.find(a)!=name.end())
			name[a]=cnt++;
		if(name.find(b)!=name.end())
			name[b]=cnt++;
		tot[name[a]]+=time;
		adj[name[a]].push_back(name[b]);
		tot[name[b]]+=time;
		adj[name[b]].push_back(name[a]);
	}
	for(int i=0;i<cnt;i++){
		if(vis[i]==false){
			sum=tot[i];
			mem=1;
			head=i;
			string str;
			dfs(i);
			if(mem>2&&sum>K){
				for(map<string,int>::iterator j=name.begin();j!=name.end();j++){
					if(j->second==head)
						str=j->first;		
				}
				an[str]=mem;
			}
		}
	}
	printf("%d\n",an.size());
	for(map<string,int>::iterator it=an.begin();it!=an.end();it++){
		printf("%s %d\n",it->first.c_str(),it->second);
	}
	return 0;
}
