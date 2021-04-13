#include<cstdio>
#include<vector>
#include<map>
#include<unordered_set>
#include<algorithm>
using namespace std;
int post[35];
int in[35];
int N;
map<int,int> mp;
vector<int> s;

void creat(int postl,int postr,int inl,int inr,int index){
	if(inl>inr) return;
	s.push_back(index);
	mp[index]=post[postr];
	int j;
	for(j=inl;j<=inr;j++){
		if(in[j]==post[postr])
			break;
	}
	int numl=j-inl;
	creat(postl,postl+numl-1,inl,j-1,index*2+1);
	creat(postl+numl,postr-1,j+1,inr,index*2+2);
}

bool cmp(int a,int b){
	return a<b;
}

int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d",post+i);
	}
	for(int i=0;i<N;i++){
		scanf("%d",in+i);
	}
	creat(0,N-1,0,N-1,0);
	int cnt=0;
	sort(s.begin(),s.end(),cmp);
	for(int it=0;it<s.size();it++){
		printf("%d",mp[s[it]]);
		if(it<s.size()-1)
			printf(" ");
	}
	return 0;
}
