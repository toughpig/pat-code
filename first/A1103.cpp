#include<cstdio>
#include<vector>
using namespace std;
vector<int> ans,temp,fac;
//int sum,nowk;
int N,K,P;
int final=-1;
int power(int i){
	int s=1;
	int j=P;
	while(j--)
		s*=i;
	return s;
}
void init(){
	int k=0;
	int tem=0;
	while(tem<N){
		fac.push_back(tem);
		k++;
		tem=power(k);
	}
}

void dfs(int index,int sum,int nowk,int maxn){
	if(sum==N&&K==nowk){
		if(maxn>final){
			ans=temp;
			final=maxn;
		}
		return;
	}
	if(sum>N||nowk>K)  return;
	if(index>0){
		temp.push_back(index);
		dfs(index,sum+fac[index],nowk+1,maxn+index);
		temp.pop_back();
		dfs(index-1,sum,nowk,maxn);
	}
}
int main(){
	scanf("%d%d%d",&N,&K,&P);
	init();
//	for(int i=0;i<fac.size();i++){
//		printf("%d\n",fac[i]);
//	}
	dfs(fac.size()-1,0,0,0);
	if(final==-1)
	printf("Imposible\n");
	else{
		printf("%d=",N);
		for(int i=0;i<K;i++){
			printf(" %d^%d",ans[i],P);
			if(i<K-1)
			printf(" +");
		}
	}
	
	
	return 0;
}
