#include<cstdio>
#include<vector>
using namespace std;
//const int maxn=200010;
vector<long> a,b;
long n1,n2;
int main(){
	int ans;
	scanf("%ld",&n1);
	long temp;
	for(int i=1;i<=n1;i++){
		scanf("%ld",);
	}
	scanf("%d",&n2);
	for(int i=1;i<=n2;i++){
		scanf("%ld",&b[i]);
	}
	int mid=n1+n2;
	if(mid%2==0)
	mid/=2;
	else
	mid=mid/2+1;
	int cnt=0;
	int i=1,j=1;
	while(cnt!=mid&&i<=n1&&j<=n2){
		if(a[i]<=b[j]){
			cnt++;
			ans=a[i++];
		}
		else{
			cnt++;
			ans=b[j++];
		}
	}
	if(cnt!=mid){
		while(i<=n1&&cnt!=mid){
			ans=a[i++];
			cnt++;
		}
		while(j<=n2&&cnt!=mid){
			ans=b[j];
			cnt++;
		}
	}
	printf("%d",ans);
	return 0;
}
