#include<cstdio>
#include<vector>
using namespace std;
const int maxn=10010;
vector<int> node[maxn];
int indegree[maxn]={0};
int n,m,k,a,b;
int in[maxn]={0};
vector<int> candi;
vector<int> ans;
bool flag;

void getin(){
	for(int i=0;i<maxn;i++)
		in[i]=indegree[i];
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d%d",&a,&b);
		node[a].push_back(b);
		indegree[b]++;
		in[b]++;
	}
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		candi.clear();
		getin();
		flag=true;
		for(int j=0;j<n;j++){
			scanf("%d",&a);
			if(in[a]!=0)
				flag=false;
			for(int p=0;p<node[a].size();p++){
				in[node[a][p]]--;
			}
		}
		if(flag==false)
			ans.push_back(i);
	}
	for(int i=0;i<ans.size();i++){
		if(i==0)
		printf("%d",ans[i]);
		else
		printf(" %d",ans[i]);
	}
	return 0;
}
