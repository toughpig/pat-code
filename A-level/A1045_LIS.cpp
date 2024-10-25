#include<cstdio>
#include<algorithm>
using namespace std;
int N,M,L;
int a[210];
int dp[10010];
int list[10010];
int temp;
int ans=0;
int num=0;
int main(){
	fill(a,a+210,-1);
	scanf("%d%d",&N,&M);
	for(int i=1;i<=M;i++){
		scanf("%d",&temp);
		a[temp]=i;
	}
	scanf("%d",&L);
	for(int i=1;i<=L;i++){
		scanf("%d",&temp);
		if(a[temp]!=-1)
			list[num++]=temp;
	}
	for(int i=0;i<num;i++){
		int temp1=list[i];
		dp[i]=1;
		for(int j=0;j<i;j++){
			int temp2=list[j];
			if(a[temp2]<=a[temp1]&&dp[j]+1>dp[i])
				dp[i]=dp[j]+1;
		}
	}
	for(int i=0;i<num;i++){
		ans=max(ans,dp[i]);
	}
	printf("%d",ans);
	return 0;
}
