#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn=110;
vector<int> ans;
vector<int> in;

int N;
queue<int> q;
struct node{
	int l;
	int r;
	int data;
}Node[maxn];

void inor(int root){
	if(root==-1)
	return;
	else{
		inor(Node[root].l);
		in.push_back(root);
		inor(Node[root].r);
	}
}


int main(){
	int le,ri,da;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d %d",&le,&ri);
		Node[i].l=le;
		Node[i].r=ri;
	}
	inor(0);
	q.push(0);
	while(!q.empty()){
		int root=q.front();
		q.pop();
		if(root==-1)
			continue;
		ans.push_back(root);
		q.push(Node[root].l);
		q.push(Node[root].r);
	}
	int a[maxn];
	for(int i=0;i<N;i++){
		scanf("%d",a+i);
	}
	sort(a,a+N);
	for(int j=0;j<N;j++){
		Node[in[j]].data=a[j];
	}
	for(int k=0;k<N;k++){
		printf("%d",Node[ans[k]].data);
		if(k<N-1)
		printf(" ");
	}
	return 0;
}

