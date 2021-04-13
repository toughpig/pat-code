#include<cstdio>
#include<vector>
using namespace std;

int n,temp;
vector<int> pre;
vector<int> post;
vector<int> in;

bool judge(int prel,int prer,int postl,int postr){
	if(prer-prel<1){
		return true;
	}
	else if(prer-prel==1){
		in.push_back(pre[prel]);
		return true;
	}
	else if(prer-prel==2){
		judge(prel,prer-1,postl+1,postr);
		judge(prel+1,prer,postl,postr-1);
		return false;
	}
	else{
		int mid=postl;
		for(;mid<postr;mid++){
			if(post[mid]==pre[prel+1])
				break;
		}
		int len=mid-postl+1;
		bool f1=judge(prel+1,prel+len+1,postl,mid+1);
		in.push_back(pre[prel]);
		bool f2=judge(prel+len+1,prer,mid+1,postr-1);
		return f1&&f2;
	}
	
}


int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&temp);
		pre.push_back(temp);
	}
	for(int i=0;i<n;i++){
		scanf("%d",&temp);
		post.push_back(temp);
	}
	bool flag=judge(0,n,0,n);
	if(flag) printf("Yes\n");
	else printf("No\n");
	for(int i=0;i<in.size();i++){
		if(i==0) printf("%d",in[i]);
		else printf(" %d",in[i]);
	}
	return 0;
}
