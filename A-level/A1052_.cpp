#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=101;
int N,M,W,num,id,sub;
vector<int> node[maxn];
vector<int> ans[maxn];
vector<int> temp;
int w[maxn];
int cnt=0;
int sum=0;

void getans(int a){
	for(int i=0;i<temp.size();i++){
		ans[a].push_back(temp[i]);
	}
}

void dfs(int u){
	if(sum+w[u]==W&&node[u].empty()){
		temp.push_back(w[u]);
		getans(cnt);
		cnt++;
		temp.pop_back();
		return;
	}
	if(sum+w[u]<W&&!node[u].empty()){
		temp.push_back(w[u]);
		sum+=w[u];
		for(int i=0;i<node[u].size();i++){
			dfs(node[u][i]);
		}
		temp.pop_back();
		sum-=w[u];
		return;
	}
	return;
	
}

bool cmp(int a,int b){
	return w[a]>w[b];
}
void print(vector<int> a){
	for(int i=0;i<a.size();i++){
		printf("%d",a[i]);
		if(i<a.size()-1)
		printf(" ");
		else
		printf("\n");
	}
}
int main(){
	scanf("%d%d%d",&N,&M,&W);
	for(int i=0;i<N;i++)
		scanf("%d",w+i);
	for(int i=0;i<M;i++){
		scanf("%d%d",&id,&num);
		for(int j=0;j<num;j++){
			scanf("%d",&sub);
			node[id].push_back(sub);
		}
	}
	for(int i=0;i<N;i++)
		sort(node[i].begin(),node[i].end(),cmp);
	dfs(0);
	for(int i=0;i<cnt;i++){
		print(ans[i]);
	}
	return 0;
}
