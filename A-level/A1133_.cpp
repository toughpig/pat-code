#include<cstdio>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

const int maxn=100010;

struct node{
	int add;
	int data;
	int next;
}Node[maxn];

//map<int,int> mp;    //≤ª∂‘”¶ 
vector<int> ve;

int n,ad,da,ne;
int root,k;

int main(){
	scanf("%d%d%d",&root,&n,&k);
	for(int i=0;i<n;i++){
		scanf("%d%d%d",&ad,&da,&ne);
		Node[ad].add=ad;
		Node[ad].data=da;
		Node[ad].next=ne;
	}
	while(root!=-1){
		ve.push_back(Node[root].add);
		root=Node[root].next;
	}
	int cnt=0;
	for(int i=0;i<ve.size();i++){
		int aad=ve[i];
		if(Node[aad].data<0){
			if(cnt==0) printf("%05d %d",aad,Node[aad].data);
			else printf(" %05d\n%05d %d",aad,aad,Node[aad].data);
			cnt++;
		}
	}
	for(int i=0;i<ve.size();i++){
		int aad=ve[i];
		if(Node[aad].data>=0&&Node[aad].data<=k){
			if(cnt==0) printf("%05d %d",aad,Node[aad].data);
			else printf(" %05d\n%05d %d",aad,aad,Node[aad].data);
			cnt++;
		}
	}
//	for(int i=0;i<n;i++){
//		if(ve[i]==k){
//			if(cnt==0) printf("%05d %d",mp[ve[i]],ve[i]);
//			else printf(" %05d\n%05d %d",mp[ve[i]],mp[ve[i]],ve[i]);
//			cnt++;
//			if(cnt==n) break;
//		}
//	}
	for(int i=0;i<ve.size();i++){
		int aad=ve[i];
		if(Node[aad].data>k){
			if(cnt==0) printf("%05d %d",aad,Node[aad].data);
			else printf(" %05d\n%05d %d",aad,aad,Node[aad].data);
			cnt++;
		}
	}
	printf(" -1\n");
	return 0;
}
