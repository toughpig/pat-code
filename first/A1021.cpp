#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
const int maxn=10100;
vector<int> node[maxn];
int num=0;
int k=-1;
bool vis[maxn];
int N,a,b;
int maxnn;
int cnt;
vector<int> an;
int oldmax;
void dfsp(int i){
	vis[i]=true;
	for(int j=0;j<node[i].size();j++){
		if(vis[node[i][j]]==false)
			dfsp(node[i][j]);
	} 
}

int dfss(){
	fill(vis,vis+maxn,false);
	int p=0;
	for(int i=1;i<=N;i++){
		if(vis[i]==false){
			p++;
			dfsp(i);
		}
	}
	return p;
}

void dfs(int v,int depth){
	vis[v]=true;
	if(depth>maxnn)
		maxnn=depth;
	for(int j=0;j<node[v].size();j++){
		if(vis[node[v][j]]==false){
			dfs(node[v][j],depth+1);
		}
	}
	
}

int main(){
	scanf("%d",&N);
	for(int i=1;i<N;i++){
		scanf("%d%d",&a,&b);
		node[a].push_back(b);
		node[b].push_back(a);
	}	
	oldmax=1;
	int te=dfss();
	if(te==1){
	
	for(int i=1;i<=N;i++){
		maxnn=1;
		cnt=0;
		fill(vis,vis+maxn,false);
		dfs(i,1);
	if(maxnn>oldmax){
		an.clear();
		an.push_back(i);
		oldmax=maxnn;
	}
	else if(maxnn==oldmax){
		an.push_back(i);
	}
	}
	for(int i=0;i<an.size();i++)
		printf("%d\n",an[i]);
	}
	else
		printf("Error: %d components",te);
	return 0;
}
