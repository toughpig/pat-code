#include<cstdio>
#include<vector>
#include<map>
#include<cmath>
#include<algorithm>
using namespace std;

vector<int> mp[33];
vector<int> in,post;
int n,temp,cnt;

map<int,long long> pm;

void solve(int inl,int inr,int pol,int por,int level){
	if(inl>inr) return;
	int mid;
	for(mid=inl;mid<=inr;mid++){
		if(in[mid]==post[por]){
			break;
		}
	}
	int len=mid-inl;
	solve(inl,mid-1,pol,pol+len-1,level+1);
	solve(mid+1,inr,pol+len,por-1,level+1);
	mp[level].push_back(post[por]);
}

 
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&temp);
		in.push_back(temp);
	}
	for(int i=0;i<n;i++){
		scanf("%d",&temp);
		post.push_back(temp);
	}
	cnt=0;
	solve(0,n-1,0,n-1,1);
	for(int i=1;i<=31;i++){
		if(cnt==n) break;
		if(i%2==1){
			for(int j=mp[i].size()-1;j>=0;j--){
				printf("%d",mp[i][j]);
				cnt++;
				if(cnt<n) printf(" ");
			}
		}
		else{
			for(int j=0;j<mp[i].size();j++){
				printf("%d",mp[i][j]);
				cnt++;
				if(cnt<n) printf(" ");
			}
		}
	}
	return 0;
}
