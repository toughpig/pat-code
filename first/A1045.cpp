#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=10010;
int a[maxn];
int aa[maxn];
int b[maxn];
int dp[maxn];
int maxx=0;
int N,M,L;
int getmax(int a,int b){
	return a>b?a:b;
}
int main(){
	scanf("%d",&N);
	scanf("%d",&M);
	fill(a,a+M+1,-1);
	fill(dp,dp+L+1,-1);
	int cnt=1;
	for(int i=0;i<M;i++){
		int index;
		scanf("%d",&index);
		a[index]=cnt++;
	} 
	scanf("%d",&L);
	for(int i=1;i<=L;i++){
		scanf("%d",b+i);
	}
	int first;
	for(first=1;first<=L;first++){
		if(a[b[first]]!=-1){
			dp[first]=1;
			break;
		}  
	}
	for(int k=first+1;k<=L;k++){
		int temp=b[k];
		if(a[temp]==-1) continue;
		for(int i=1;i<k;i++){
			int temp2=b[i];
			if(a[temp2]!=-1&&a[temp2]<=a[temp]){
				dp[k]=getmax(dp[k],dp[i]+1);
			}
		}
		if(dp[k]==-1)
			dp[k]=1; 
	}
	for(int j=1;j<=L;j++){
		if(maxx<dp[j])
			maxx=dp[j];
	}
	printf("%d",maxx);
	return 0;
}
