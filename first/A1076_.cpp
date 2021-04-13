#include<cstdio>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
using namespace std;
const int maxn=1010;
vector<int> user[maxn];
bool inq[maxn]={false};
int N,L,M,temp;
int ans=0;
int lev[maxn]={0};
queue<int> q;


void bfs(int u){
	q.push(u);
	inq[u]=true;
	int sub;
	while(!q.empty()){
		sub=q.front();
		q.pop();
		if(lev[sub]<L){
			for(int i=0;i<user[sub].size();i++){
				if(inq[user[sub][i]]==false){
					lev[user[sub][i]]=lev[sub]+1;
					q.push(user[sub][i]);
					inq[user[sub][i]]=true;
					ans++;
				}
			}
		}
	}
	
}

int main(){
	scanf("%d%d",&N,&L);
	int num;
	for(int i=1;i<=N;i++){
		scanf("%d",&num);
		for(int j=0;j<num;j++){
			scanf("%d",&temp);
			user[temp].push_back(i);
		}
	}
	scanf("%d",&num);
	for(int i=0;i<num;i++){
		scanf("%d",&temp);
		fill(inq,inq+maxn,false);
		fill(lev,lev+maxn,0);
		ans=0;
		while(!q.empty()) q.pop();
		bfs(temp);
		printf("%d\n",ans);
	}
	
	return 0;
}
