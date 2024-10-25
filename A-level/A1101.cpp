#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn=1000000;
bool pre[maxn],post[maxn];
int num[maxn];
int n;
vector<int> ans;

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&num[i]);
	}
	fill(pre,pre+maxn,false);
	fill(post,post+maxn,false);
	int flag=num[0];
	pre[0]=true;
	for(int i=1;i<n;i++){
		if(num[i]>flag){
			pre[i]=true;
			flag=num[i];
		}
	}
	post[n-1]=true;
	flag=num[n-1];
	for(int i=n-2;i>=0;i--){
		if(num[i]<flag){
			post[i]=true;
			flag=num[i];
		}
	}
	for(int i=0;i<n;i++){
		if(pre[i]&&post[i])
			ans.push_back(num[i]);
	}
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++){
		if(i==0) printf("%d",ans[i]);
		else printf(" %d",ans[i]);
	}
	printf("\n");
	return 0;
}
