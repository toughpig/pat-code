#include<cstdio>
#include<algorithm>
using namespace std;

int N,M,L;
int a[210];
int dp[210][10010];
int list[10010];
//int maxx=0;

int main(){
	scanf("%d%d",&N,&M);
	for(int i=1;i<=M;i++){
		dp[i][0]=0;
		scanf("%d",a+i);
	}
	scanf("%d",&L);
	for(int i=1;i<=L;i++){
		dp[0][i]=0;
		scanf("%d",list+i);
	}
	dp[0][1]=dp[1][0]=0;
	for(int i=1;i<=M;i++){
		for(int j=1;j<=L;j++){
			if(list[j]!=a[i]){
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
			else
				dp[i][j]=max(dp[i][j-1],dp[i-1][j])+1;
//			maxx=max(dp[i][j],maxx);
		}
	}
	printf("%d",dp[M][L]);
	return 0;
}
