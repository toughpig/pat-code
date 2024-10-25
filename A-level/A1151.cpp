#include<cstdio>
#include<map>
#include<set>
#include<vector>
using namespace std;



vector<int> pre,in;
map<int,int> mp;
set<int> st;

int m,n,temp;
int a,b;

void search(int st,int en,int inl,int inr,int a,int b,bool flag){
	int i=st;
	if(st>en) return;
	if(mp[pre[i]]>mp[a]&&mp[pre[i]]<mp[b]){
		if(!flag)
		printf("LCA of %d and %d is %d.\n",a,b,pre[i]);
		else
		printf("LCA of %d and %d is %d.\n",b,a,pre[i]);
		return;
	}
	else if(mp[pre[i]]==mp[a]){
		printf("%d is an ancestor of %d.\n",a,b);
		return;
	}
	else if(mp[pre[i]]==mp[b]){
		printf("%d is an ancestor of %d.\n",b,a);
		return;
	}
	else{
		int mid;
		for(mid=inl;mid<=inr;mid++){
			if(in[mid]==pre[st])
				break;
		}
		int len=mid-inl;
		if(mp[pre[i]]>mp[b])
			search(st+1,st+len,inl,mid-1,a,b,flag);
		else if(mp[pre[i]]<mp[a])
			search(st+len+1,en,mid+1,inr,a,b,flag);
	}
	
	
}

int main(){
	scanf("%d%d",&m,&n);
	for(int i=0;i<n;i++){
		scanf("%d",&temp);
		in.push_back(temp);
		st.insert(temp);
		mp[temp]=i;
		
	}
	for(int i=0;i<n;i++){
		
		scanf("%d",&temp);
		pre.push_back(temp);
	}
	for(int i=0;i<m;i++){
		scanf("%d%d",&a,&b);
		bool aa=false;
		bool bb=false;
		if(st.count(a)==0) aa=true;
		if(st.count(b)==0) bb=true;
		if(aa&&bb) printf("ERROR: %d and %d are not found.\n",a,b);
		else if(aa) printf("ERROR: %d is not found.\n",a);
		else if(bb) printf("ERROR: %d is not found.\n",b);
		else{
			int c=a;
			int d=b;
			bool flag=false;
			if(mp[a]>mp[b]){
				a+=b;
				b=a-b;
				a=a-b;
				flag=true;
			}
			search(0,n-1,0,n-1,a,b,flag);
		}
	}
	return 0;
}

