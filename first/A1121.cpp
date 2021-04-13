#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn=100000;
int guest[maxn];
int come[maxn];
int n,m,p,q;
vector<int> ans;

int main(){
	fill(guest,guest+maxn,-1);
	fill(come,come+maxn,-1);
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%d",&p,&q);
		guest[p]=q;
		guest[q]=p;
	}
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		scanf("%d",&p);
		come[p]=1;
	}
	for(int i=0;i<maxn;i++){
		if(come[i]!=-1&&guest[i]==-1){
			ans.push_back(i);
		}
		else if(come[i]!=-1&&guest[i]!=-1&&come[guest[i]]==-1){
			ans.push_back(i);
		}
	}
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++){
		if(i==0) printf("%05d",ans[i]);
		else printf(" %05d",ans[i]);
	}
	return 0;
}
