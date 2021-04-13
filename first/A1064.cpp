#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;
const int maxn=1010;
struct gg{
//	int index;
	int h;
	int ll;
//	int lr;
//	int rl;
	int rr;
//	int num;
}g;
queue<struct gg> q;
using namespace std;
vector<int> ans;
int node[maxn]={0};

//void dfs(int l,int r,int h){
//	
//}

int main(){
	int N;
	scanf("%d",&N);
	for(int i=1;i<=N;i++){
		scanf("%d",&node[i]);
	}
	sort(node+1,node+N+1);
	int H;
	for(H=0;;H++){
		if((int)pow(2,H)-1>=N)
			break;
	}
	
//	int root;
//	int n=N-l+1;
//	int num=n-((int)pow(2,H-1)-1);
//	if(num<=(int)pow(2,h-2)){
//		root=(int)pow(2,h-2)+num+l-1;
//	}
//	else{
//		root=(int)pow(2,h-1)+l-1;
//	}
//	g.index=root;
	g.h=H;
	g.ll=1;
//	g.lr=root-1;
//	g.rl=root+1;
	g.rr=N;
//	g.num=N;
	q.push(g);
	
	while(!q.empty()){
		
//		if(l>r||h<=0){
//		return;
//	}
	gg ng=q.front();
	q.pop();
	if(ng.ll>ng.rr||ng.h<=0){
		break;
	}
//	newroot=ng.index;
	int newroot;
	int h=ng.h;
	int l=ng.ll;
	int r=ng.rr;
	int n=r-l+1;
	int num=n-((int)pow(2,h-1)-1);
	if(num<=(int)pow(2,h-2)){
		newroot=(int)pow(2,h-2)+num+l-1;
		ans.push_back(node[newroot]);
		gg nng;
		nng.ll=ng.ll;
//		nng.lr=newroot-1;
//		nng.rl=newroot+1;
		nng.rr=newroot-1;
		nng.h=h-1;
		q.push(nng);
		nng.ll=newroot+1;
		nng.rr=r;
		nng.h=h-2;
		q.push(nng);
	}
	else{
		newroot=(int)pow(2,h-1)+l-1;
		ans.push_back(node[newroot]);
		gg nng;
		nng.ll=ng.ll;
//		nng.lr=newroot-1;
//		nng.rl=newroot+1;
		nng.rr=newroot-1;
		nng.h=h-1;
		q.push(nng);
		nng.ll=newroot+1;
		nng.rr=r;
		nng.h=h-1;
		q.push(nng);
		
	}

	}

	
	

	for(int j=0;j<ans.size();j++){
		printf("%d",ans[j]);
		if(j<ans.size()-1)
			printf(" ");
	}

	return 0;
}
