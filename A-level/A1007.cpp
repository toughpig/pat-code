//最大连续子列和，并且要记录首尾 
//两种算法 online 与 dp
#include<cstdio>
#include<vector>
#include<map>
using namespace std;
int K,temp;
int ans,left,right,sum,templeft;
//算法一：online-----------------
int main(){
	scanf("%d%d",&K,&templeft);
	right=ans=sum=left=templeft;
	for(int i=1;i<K;i++){
		scanf("%d",&temp);
		if(sum<0){
			templeft=sum=temp;
		}
		else{
			sum+=temp;
		}
		if(sum>ans){
			left=templeft;
			ans=sum;
			right=temp;
		}
	}
	if(ans<0){
		ans=0;
		right=temp;
	}
	printf("%d %d %d",ans,left,right);
	return 0;
}
//算法二：dp------------------ 
//vector<pair<int,int> > record(10);  //与单纯 dp 不同的是本题要存储的 
//vector<int> data(10),dp(10);       //不仅是子列和，还要存首尾元素 
//
//int main(){
//	scanf("%d%d",&K,&temp);
//	record.resize(K);
//	data.resize(K);
//	dp.resize(K);
//	data[0]=dp[0]=temp;
//	record[0]=make_pair(temp,temp);
//	int maxn=temp,index=0;
//	for(int i=1;i<K;i++){
//		scanf("%d",&temp);
//		data[i]=temp;
//		if(dp[i-1]>=0){
//			dp[i]=dp[i-1]+temp;
//			record[i]=make_pair(record[i-1].first,temp);
//		}
//		else{
//			dp[i]=temp;
//			record[i]=make_pair(temp,temp);
//		}
//		if(maxn<dp[i]){
//			maxn=dp[i];
//			index=i;
//		}
//	}
//	if(maxn<0){
//		maxn=0;
//		index=0;
//		record[index]=make_pair(data[0],data[K-1]);
//	}
//	printf("%d %d %d",maxn,record[index].first,record[index].second);
//	return 0;
//}
