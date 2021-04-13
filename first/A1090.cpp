#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;
int H=0;
static int cnt=0;
double P,R;
const int maxn=100100;
using namespace std;
struct node{
	vector<int> child;
}Node[maxn];
void dfs(int a,int b){
	if(Node[a].child.size()==0){
		if(H==b){
			cnt++;
		}
		else if(H<b){
			cnt=1;
			H=b;
		}
		return;
	}
	else{
		for(int j=0;j<Node[a].child.size();j++){
			dfs(Node[a].child[j],b+1);
		}
	}
	
}
int main(){
	int N;
	int sp;
	int root;
	scanf("%d %lf %lf",&N,&P,&R);
	for(int i=0;i<N;i++){
		scanf("%d",&sp);
		if(sp!=-1)
		Node[sp].child.push_back(i);
		else
		root=i;
	}
	cnt=0;
	dfs(root,0);
	printf("%.2lf %d",P*pow(1+R/100,H),cnt);

	return 0;
}

