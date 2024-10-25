#include<cstdio>
#include<map>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
map<int,int> ind;  //value->index
map<int,int> val;  //index->value
int n,m,a,b,temp;
set<int> s;
set<int> fa;
vector<int> node;

void getindex(int index,int st,int en){
	if(st>=en) return;
	int head=node[st];
	ind[head]=index;
	val[index]=head;
	s.insert(index);
	for(head=st+1;head<en;head++)
		if(node[head]>=node[st])
			break;
	getindex(index*2,st+1,head);
	getindex(index*2+1,head,en);
}

void solve(int u,int v){
	int flag=1;
	if(ind.find(u)==ind.end()) flag++;
	if(ind.find(v)==ind.end()) flag*=-1;
	if(flag==2){
		printf("ERROR: %d is not found.\n",u);
		return;
	}
	else if(flag==-1){
		printf("ERROR: %d is not found.\n",v);
		return;
	}
	else if(flag==-2){
		printf("ERROR: %d and %d are not found.\n",u,v);
		return;
	}
	int ida=ind[u];
	int idb=ind[v];
	if(ida<idb){
		ida+=idb;
		idb=ida-idb;
		ida-=idb;
		flag=-1;
	}
	fa.clear();
	for(int i=idb;i>=1;i/=2){
		if(s.find(i)!=s.end())
			fa.insert(i);
	}
	int ans=0;
	for(int i=ida;i>=1;i/=2){
		if(fa.find(i)!=fa.end()){
			ans=i;
			break;
		}
	}
	if(ans==idb){
		if(flag==-1){
			printf("%d is an ancestor of %d.\n",u,v);
		}
		else{
			printf("%d is an ancestor of %d.\n",v,u);
		}
	}
	else{
		printf("LCA of %d and %d is %d.\n",u,v,val[ans]);
	}
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d",&temp);
		node.push_back(temp);
	}
	getindex(1,0,m);
	for(int i=0;i<n;i++){
		scanf("%d%d",&a,&b);
		solve(a,b);
	}
	return 0;
}
