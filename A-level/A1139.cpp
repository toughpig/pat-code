#include<cstdio>
#include<vector>
#include<map>
#include<queue>
#include<algorithm>
using namespace std;

int n,m,a,b;

vector<int> cup[20000];
vector<pair<int,int> > ans;
vector<int>temp;

bool vis[20000]={false};

void getans(){
	ans.push_back(make_pair(temp[0],temp[1]));
}

void dfs(int a,int b,int d){
	if(d==0){
		vis[a]=true;
		if(a<10000)
		for(int i=0;i<cup[a].size();i++){
			if(vis[cup[a][i]]==false&&cup[a][i]!=b&&cup[a][i]<10000){
				temp.push_back(cup[a][i]);
				vis[cup[a][i]]=true;
				dfs(cup[a][i],b,1);
				temp.pop_back();
				vis[cup[a][i]]=false;
			}
		}
		if(a>=10000)
		for(int i=0;i<cup[a].size();i++){
			if(vis[cup[a][i]]==false&&cup[a][i]!=b&&cup[a][i]>=10000){
				temp.push_back(cup[a][i]);
				vis[cup[a][i]]=true;
				dfs(cup[a][i],b,1);
				temp.pop_back();
				vis[cup[a][i]]=false;
			}
		}
	}
	if(d==1){
		if(b<10000)
		for(int i=0;i<cup[a].size();i++){
			if(vis[cup[a][i]]==false&&cup[a][i]<10000){
				temp.push_back(cup[a][i]);
				vis[cup[a][i]]=true;
				dfs(cup[a][i],b,2);
				temp.pop_back();
				vis[cup[a][i]]=false;
			}
		}
		if(b>=10000)
		for(int i=0;i<cup[a].size();i++){
			if(vis[cup[a][i]]==false&&cup[a][i]>=10000){
				temp.push_back(cup[a][i]);
				vis[cup[a][i]]=true;
				dfs(cup[a][i],b,2);
				temp.pop_back();
				vis[cup[a][i]]=false;
			}
		}
	}
	if(d==2){
		for(int i=0;i<cup[a].size();i++){
			if(vis[cup[a][i]]==false&&cup[a][i]==b){
				getans();
				return;
			}
		}
	}
}

bool cmp(pair<int,int> a,pair<int,int> b){
	if(a.first!=b.first) return a.first<b.first;
	else return a.second<b.second;
}

int main(){
	scanf("%d%d",&n,&m);
	char aa[6],bb[6];
	for(int i=0;i<m;i++){
		scanf("%s%s",aa,bb);
		if(aa[0]!='-') sscanf(aa,"%d",&a);
		else{
			sscanf(aa+1,"%d",&a);
			a+=10000;
		}
		if(bb[0]!='-') sscanf(bb,"%d",&b);
		else{
			sscanf(bb+1,"%d",&b);
			b+=10000;
		}
		cup[a].push_back(b);
		cup[b].push_back(a); 
	}
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		scanf("%s%s",aa,bb);
		if(aa[0]!='-') sscanf(aa,"%d",&a);
		else{
			sscanf(aa+1,"%d",&a);
			a+=10000;
		}
		if(bb[0]!='-') sscanf(bb,"%d",&b);
		else{
			sscanf(bb+1,"%d",&b);
			b+=10000;
		}
		fill(vis,vis+20000,false);
		temp.clear();
		ans.clear();
		dfs(a,b,0);
		sort(ans.begin(),ans.end(),cmp);
		printf("%d\n",ans.size());
		for(int i=0;i<ans.size();i++){
			printf("%04d %04d\n",ans[i].first%10000,ans[i].second%10000);
		}
	}
	return 0;
}
