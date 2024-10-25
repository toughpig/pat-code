#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int n,m,k,aa,bb;
int fa[100000];

vector<int> node[100000];
bool inq[100000]={false};
vector<int> temp;


void dfs(int u){
	inq[u]=true;
	for(int i=0;i<node[u].size();i++){
		inq[node[u][i]]=true;
	}
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d%d",&aa,&bb);
		node[aa].push_back(bb);
		node[bb].push_back(aa);
	}
	for(int i=0;i<m;i++){
		scanf("%d%d",&k,&bb);
		fill(inq,inq+100000,false);
		dfs(bb);
		bool flag=true;
		for(int j=1;j<k;j++){
			scanf("%d",&aa);
			if(inq[aa]==true){
				flag=false;
			}
			else{
				dfs(aa);
			}
			
		}
		if(flag==false) printf("No\n");
			else printf("Yes\n");
	}
	
	
	return 0;
} 
