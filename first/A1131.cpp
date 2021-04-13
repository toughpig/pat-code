#include<cstdio>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

const int maxn=10005;

struct node{
	int line;
	int v;
	node(int a,int b):line(a),v(b){};
};

bool vis[maxn];

map<int,int> mp;

vector<node> Node[maxn];
vector<int> ans,temp;
int trans;
int pass;

int n,m,k,st,en;

void getans(){
	ans.clear();
	for(int i=0;i<temp.size();i++){
		ans.push_back(temp[i]);
	}
}

void dfs(int s,int e,int h,int line,int pa){
	if(s==e){
		if(pa<pass){
			temp.push_back(s);
			getans();
			temp.pop_back();
			pass=pa;
			trans=h;
			return;
		}
		else if(pa==pass&&h<trans){
			temp.push_back(s);
			getans();
			temp.pop_back();
			trans=h;
			return;
		}
		else
		return;
	}
	temp.push_back(s);
	vis[s]=true;
	for(int i=0;i<Node[s].size();i++){
		int vv=Node[s][i].v;
		int ll=Node[s][i].line;
		int hh=h;
		if(line!=ll&&line!=0){ 
			hh++;
		}
		if(vis[vv]==false){
			dfs(vv,e,hh,ll,pa+1);
		}
	}
	temp.pop_back();
	vis[s]=false;
}

void print(int ss,int ee){
	if(ss==ee-1) return;
	if(ss==0)
	printf("%d\n",pass);
	int s=ss;
	int next=ss+1;
	int lin=mp[ans[s]*10000+ans[next]];
	while(next<ee-1&&mp[ans[next]*10000+ans[next+1]]==lin){
		next++;
	}
	printf("Take Line#%d from %04d to %04d.\n",lin,ans[s],ans[next]);
	print(next,ee);
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&m,&st);
		for(int j=0;j<m-1;j++){
			scanf("%d",&en);
			if(st!=en){
				Node[st].push_back(node(i,en));
				Node[en].push_back(node(i,st));
				mp[st*10000+en]=mp[en*10000+st]=i;
				st=en;
			}
		}
	}
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		scanf("%d%d",&st,&en);
		ans.clear();
		temp.clear();
		fill(vis,vis+maxn,false);
		trans=maxn;
		pass=maxn;
		dfs(st,en,0,0,0);
		print(0,ans.size());
	}
	
	return 0;
}
