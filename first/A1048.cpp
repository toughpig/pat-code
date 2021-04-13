#include<cstdio>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
const int maxn=100010;
vector<pair<int,int> > ans;
int N,M;
int coin[maxn];
int find(int a,int l,int r){
	if(l>r) return -1;
	int k=coin[(l+r)/2];
	if(a==k) return (l+r)/2;
	else if(k<a){
		return find(a,(l+r)/2+1,r);
	}
	else
		return find(a,l,(l+r)/2-1);
}
int main(){
	scanf("%d%d",&N,&M);
	for(int i=1;i<=N&&coin[i]<=M/2+1;i++){
		scanf("%d",&coin[i]);
	}
	sort(coin+1,coin+N+1);
	for(int i=1;i<=N;i++){
		int temp=find(M-coin[i],i+1,N);
		if(temp!=-1)
			ans.push_back(make_pair(coin[i],coin[temp]));
	}
	if(ans.empty())
		printf("No Solution");
	else
		for(int i=0;i<ans.size();i++){
			printf("%d %d\n",ans[i].first,ans[i].second);
			return 0;
		}
	return 0;
}
