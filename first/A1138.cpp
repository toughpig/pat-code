#include<cstdio>
#include<vector>
using namespace std;

int n,temp;
vector<int> pre,in;
int ans,cnt;

void solve(int prel,int prer,int inl,int inr){
	if(cnt>0||prel>prer) return;
	int mid;
	for(mid=inl;mid<=inr;mid++){
		if(in[mid]==pre[prel])
			break;
	}
	int len=mid-inl;
	solve(prel+1,prel+len,inl,mid-1);
	solve(prel+len+1,prer,mid+1,inr);
	if(cnt==0){
		ans=pre[prel];
		cnt++;
	}
}

int main(){
	cnt=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&temp);
		pre.push_back(temp);
	}
	for(int i=0;i<n;i++){
		scanf("%d",&temp);
		in.push_back(temp);
	}
	solve(0,n-1,0,n-1);
	printf("%d",ans);
	return 0;
}
