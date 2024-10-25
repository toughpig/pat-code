#include<cstdio>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn=100000;

struct node{
	int pos;
	int v;
	int next;
//	node(int a,int b,int c):pos(a),v(b),next(c){};
}Node[maxn];


map<int,int> mp;

int root,n,k;
int ad,da,ne;

vector<node> ve; 

bool cmp(node a,node b){
	if(a.v<k&&b.v>=k||a.v<0&&b.v>=0||a.v<=k&&b.v>k) return true;
	else if(a.v<0&&b.v<0||a.v<k&&b.v<k||a.v>k&&b.v>k||a.v==b.v==k){
		return a.pos<b.pos;
	}
	else return false;
}

int main(){
	scanf("%d%d%d",&root,&n,&k);
	for(int i=0;i<n;i++){
		scanf("%d%d%d",&ad,&da,&ne);
		mp[da]=ad;
		Node[ad].v=da;
		Node[ad].next=ne;
	}
	int r=root;
	int cnt=0;
	while(r!=-1){
		Node[r].pos=cnt++;
		ve.push_back(Node[r]);
		r=Node[r].next;
	}
	cnt=0;
	for(int i=0;i<n;i++){
		if(ve[i].v<0){
			if(cnt==0) printf("%05d %d",mp[ve[i].v],ve[i].v);
			else printf(" %05d\n%05d %d",mp[ve[i].v],mp[ve[i].v],ve[i].v);
			cnt++;
		}
	}
	for(int i=0;i<n;i++){
		if(ve[i].v>=0&&ve[i].v<k){
			if(cnt==0) printf("%05d %d",mp[ve[i].v],ve[i].v);
			else printf(" %05d\n%05d %d",mp[ve[i].v],mp[ve[i].v],ve[i].v);
			cnt++;
		}
	}
	for(int i=0;i<n;i++){
		if(ve[i].v==k){
			if(cnt==0) printf("%05d %d",mp[ve[i].v],ve[i].v);
			else printf(" %05d\n%05d %d",mp[ve[i].v],mp[ve[i].v],ve[i].v);
			cnt++;
		}
	}
	for(int i=0;i<n;i++){
		if(ve[i].v>k){
			if(cnt==0) printf("%05d %d",mp[ve[i].v],ve[i].v);
			else printf(" %05d\n%05d %d",mp[ve[i].v],mp[ve[i].v],ve[i].v);
			cnt++;
		}
	}
	printf(" -1");
	return 0;
}
