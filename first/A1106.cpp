#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;
int dep=100010;
int N;
int cnt=0;
double P,R;
const int maxn=100010;
vector<int> node[maxn];
void dfs(int root,int depth){
	if(depth>dep)
		return;
	else if(depth==dep&&node[root].size()==0){
		cnt++;
	}
	else if(node[root].size()==0&&depth<dep){
		dep=depth;
		cnt=1;
	}
	else{
		for(int k=0;k<node[root].size();k++)
			dfs(node[root][k],depth+1);
	}
}
int main(){
	scanf("%d%lf%lf",&N,&P,&R);
	R/=100;
	R+=1;
	int num,sub;
	for(int i=0;i<N;i++){
		scanf("%d",&num);
		if(num!=0)
		for(int j=0;j<num;j++){
			scanf("%d",&sub);
			node[i].push_back(sub);
		}
	}
	dfs(0,0);
	printf("%.4lf %d",P*pow(R,dep),cnt);
	
	return 0;
}
