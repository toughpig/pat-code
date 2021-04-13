//dfs,容量可变的01背包，一个测试点超时，剪枝未果 
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

struct node{
	int p,l,d;
	node(int a,int b,int c):p(a),l(b),d(c){}
};

vector<node> Node;
int n,maxn=-1;
int pp,ll,dd,potential=0;

void dfs(int index,int dead,int time,int gain,int left){
	if(index==n-1){
		if(maxn<gain){
			maxn=gain;
		}
		return;
	}
	if(gain+left<=maxn) return;
	int dd=Node[index+1].d;
	int tt=Node[index+1].l;
	int gg=Node[index+1].p;
	dfs(index+1,dead,time,gain,left-gg);
	if(dd>dead) dead=dd;
	if(time+tt<=dd) dfs(index+1,dead,time+tt,gain+gg,left-gg);
}

bool cmp(node a,node b){
	return a.d<b.d;
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%d%d",&pp,&ll,&dd);
		potential+=pp;
		Node.push_back(node(pp,ll,dd));
	}
	sort(Node.begin(),Node.end(),cmp);
	dfs(0,Node[0].d,Node[0].l,Node[0].p,potential-Node[0].p);
	dfs(0,0,0,0,potential-Node[0].p);
	printf("%d",maxn);
	return 0;
} 
