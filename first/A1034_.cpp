#include<cstdio>
#include<map>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=2010;
int call[maxn][maxn];
int cnt=0;
int N,W,sum,temp;
vector<int> tempans[maxn];
map<string,int> mp;
map<int,string> pm;
int tot[maxn]={0};
bool vis[maxn]={false};
vector<pair<string,int> > ans;

int strtoint(string a){
	if(mp.find(a)!=mp.end()) return mp.find(a)->second;
	mp[a]=cnt;
	pm[cnt++]=a;
	return cnt-1;
}

string inttostr(int a){
	return pm[a];
}

void dfs(int u,int n){
	tempans[n].push_back(u);
	vis[u]=true;
	for(int i=0;i<cnt;i++){
		if(call[u][i]!=-1){
			sum+=call[u][i];
		}
	}
	for(int i=0;i<cnt;i++){
		if(vis[i]==false&&call[u][i]!=-1){
			dfs(i,n);
		}
	}
			
}
bool cmp(pair<string,int> a,pair<string,int> b){
	return strcmp(a.first.c_str(),b.first.c_str())<0;
}

int main(){
	scanf("%d%d",&N,&W);
	fill(call[0],call[0]+maxn*maxn,-1);
	fill(vis,vis+maxn,false);
	char a[4],b[4];
	for(int i=0;i<N;i++){
		scanf("%s %s %d",a,b,&temp);
		int aid=strtoint(a);
		int bid=strtoint(b);
		call[aid][bid]=call[bid][aid]=temp;
		tot[aid]+=temp;
		tot[bid]+=temp;
	}
	int num=0;
	for(int i=0;i<cnt;i++){
		if(vis[i]==false){
			sum=0;
			dfs(i,num);
			tempans[num].push_back(sum/2);
			num++;
		}
	}
	for(int i=0;i<num;i++){
		if(tempans[i].size()>3&&tempans[i][tempans[i].size()-1]>W){
			int maxx=-1;
			int maxid=tempans[i][0];
			for(int j=0;j<tempans[i].size()-1;j++){
				int id=tempans[i][j];
				if(maxx<tot[id]){
					maxid=id;
					maxx=tot[id];
				}
			}
			string str=inttostr(maxid);
			ans.push_back(make_pair(str,tempans[i].size()-1));
		}
	}
	sort(ans.begin(),ans.end(),cmp);
	if(ans.size()>0){
		printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++){
		printf("%s %d\n",ans[i].first.c_str(),ans[i].second);
	}
}
	else 
	printf("0");
	return 0;
}
