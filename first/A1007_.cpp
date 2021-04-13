#include<cstdio>
#include<vector>
#include<map>
using namespace std;
const int maxn=10010;
int K;
int a[maxn];
int dp[maxn];
pair<int,int> len[maxn];
int getmax(int a,int b,int j){
	if(b>a)
		len[j]=make_pair(j,j);
	else if(a==b&&a>0){
		len[j]=make_pair(len[j-1].first,j);
	}
	else if(a>b){
		len[j]=make_pair(len[j-1].first,j);
	}
	else
		len[j]=make_pair(j,j);
	return a>b?a:b;
}

int main(){
	scanf("%d",&K);
	for(int i=0;i<K;i++){
		scanf("%d",a+i);
	}
	dp[0]=a[0];
	len[0]=make_pair(0,0);
	for(int j=1;j<K;j++){
		dp[j]=getmax(dp[j-1]+a[j],a[j],j);
	}
	int maxx=0;
	for(int k=0;k<K;k++){
		if(dp[maxx]<dp[k]&&dp[k]>0)
			maxx=k;
	}
	if(maxx==0)
	printf("%d %d %d",0,a[0],a[K-1]);
	else
	printf("%d %d %d",dp[maxx],a[len[maxx].first],a[len[maxx].second]);
	return 0;
}
