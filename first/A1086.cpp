#include<cstdio>
#include<stack>
#include<string>
#include<iostream>
#include<vector>
using namespace std;

int n;
string str;
int temp;
stack<int> st;
vector<int> pre,in,post;

void pos(int prel,int inl,int inr){
	if(inl>inr) return;
	int mid=inl;
	for(;mid<=inr;mid++){
		if(in[mid]==pre[prel])
			break;
	}
	int len=mid-inl;
	pos(prel+1,inl,mid-1);
	pos(prel+len+1,mid+1,inr);
	post.push_back(pre[prel]);
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<2*n;i++){
		cin>>str;
		if(str=="Push"){
			scanf("%d",&temp);
			pre.push_back(temp);
			st.push(temp);
		}
		else{
			temp=st.top();
			st.pop();
			in.push_back(temp);
		}
	}
	pos(0,0,n-1);
	for(int i=0;i<post.size();i++){
		if(i==0) printf("%d",post[i]);
		else printf(" %d",post[i]);
	}
	
	return 0;
}
