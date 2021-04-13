#include<cstdio>
#include<vector>
#include<map>
using namespace std;
vector<int> ve;
int dp[100010];
vector<pair<int,int> > ans;
vector<pair<int,int> > mn;
int main(){
	int cantfix=0x3fffffff;;
	int N,M;
	int minn=0;
	int temp;
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++){
		scanf("%d",&temp);
		ve.push_back(temp);
	}
	int cnt=0;
	int first=0;
	for(int i=0;i<N;i++){
		minn+=ve[i];
		if(minn>=M){
			dp[i]=minn;
			cnt=i;
			break;
		}
	}
	for(int i=cnt;i<ve.size();i++){
		if(dp[i]==M){
			ans.push_back(make_pair(first,i));
			mn.clear();
		}
		else if(dp[i]<cantfix){
			mn.clear();
			mn.push_back(make_pair(first,i));
			cantfix=dp[i];
		}
		else if(dp[i]==cantfix){
			mn.push_back(make_pair(first,i));
		}
		if(i==ve.size()-1) break;
		int tot=dp[i]+ve[i+1];
		for(int j=first;;j++){
			if(tot-ve[j]<M){
				first=j;
				break;
			}
			tot-=ve[j];
		}
		dp[i+1]=tot;
		
	}
	if(!ans.empty()){
		for(int i=0;i<ans.size();i++){
			printf("%d-%d\n",ans[i].first+1,ans[i].second+1);
		} 
	}
	else{
		for(int i=0;i<mn.size();i++){
			printf("%d-%d\n",mn[i].first+1,mn[i].second+1);
		}
	}
	
	return 0;
}
