//online，double判断为零eps比较
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

const int maxn=1000001;
const double eps=1e-8;

vector<int> k1;
double pol[1001];
double ans[maxn];

int k,n;
double temp;

int main(){
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		scanf("%d%lf",&n,&temp);
		k1.push_back(n);
		pol[n]=temp;
	}
	scanf("%d",&k);
	fill(ans,ans+maxn,0);
	for(int i=0;i<k;i++){
		scanf("%d%lf",&n,&temp);
		for(int j=0;j<k1.size();j++){
			ans[k1[j]+n]+=temp*pol[k1[j]];
		}
	}
	int cnt=0;
	for(int i=maxn-1;i>=0;i--){
		if(fabs(ans[i])>eps)
			cnt++;
	}
	printf("%d",cnt);
	for(int i=maxn-1;i>=0;i--){
		if(fabs(ans[i])>eps)
			printf(" %d %.1lf",i,ans[i]);
	}
	return 0;
}
