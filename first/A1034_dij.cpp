#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
#include<cstring>
#include<map>
#include<map>
using namespace std;

const int inf=1<<30;
const int maxn=1010;

map<string,int> mp;
map<int,string> pm;

int arc[maxn][maxn];
bool vis[maxn];
int tot[maxn];
vector<pair<string,int> > ans;

string n1,n2;
int n,k,cnt,num;
int head;
int mem,totw;

void dfs(int u){
	mem++;
	totw+=tot[u];
	vis[u]=true;
	if(tot[u]>tot[head]){
		head=u;
	}
	for(int i=0;i<cnt;i++){
		if(vis[i]==false&&arc[u][i]!=inf){
			dfs(i);
		}
	}
}

void dfst(){
	for(int i=0;i<cnt;i++){
		if(vis[i]==false){
			head=i;
			mem=0;
			totw=0;
			dfs(i);
			if(mem>2&&totw>2*k)
				ans.push_back(make_pair(pm[head],mem));
		}
	}
}

bool cmp(pair<string,int> a,pair<string,int> b){
	return a.first<b.first;
}

int main(){
	scanf("%d%d",&n,&k);
	cnt=0;
	fill(tot,tot+maxn,0);
	fill(vis,vis+maxn,false);
	fill(arc[0],arc[0]+maxn*maxn,inf);
	for(int i=0;i<n;i++){
		cin>>n1>>n2>>num;
		int in1,in2;
		if(mp.find(n1)==mp.end()){
			in1=cnt;
			pm[cnt]=n1;
			mp[n1]=cnt++;
		}
		else{
			in1=mp.find(n1)->second;
		}
		if(mp.find(n2)==mp.end()){
			in2=cnt;
			pm[cnt]=n2;
			mp[n2]=cnt++;
		}
		else{
			in2=mp.find(n2)->second;
		}
		arc[in1][in2]=arc[in2][in1]=num;
		tot[in1]+=num;
		tot[in2]+=num;
	}
	dfst();
	sort(ans.begin(),ans.end(),cmp);
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++){
		printf("%s %d\n",ans[i].first.c_str(),ans[i].second);
	}
	return 0;
}
