#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
#include<stack>
using namespace std;
const int maxn=110;
int ss[maxn];
struct node{
	int w;
	vector<int> child;
}Node[maxn];
static int temp=0;
bool cmp(int a,int b){
	return Node[a].w>Node[b].w;
}
using namespace std;
queue<int> q;

int N,M,S;

//vector<vector<int> > ans;
//void generate(){
////	stack<int> temp;
//	ans.push_back(ss);
//	while(temp--){
//			ss.pop_back();
//		}
//	
//}
void dfs(int index,int len,int s){
	if(s==S&&Node[index].child.size()==0){
//		generate();
		for(int p=0;p<=len;p++){
			printf("%d",ss[p]);
			if(p!=len)
				printf(" ");
			else
				printf("\n");
		}
		return;
	}
	else if(s>S){
		return;
	}
	else if(s<S&&Node[index].child.size()!=0){
//		temp++;
		for(int k=0;k<Node[index].child.size();k++){
			ss[len+1]=Node[Node[index].child[k]].w;
			dfs(Node[index].child[k],len+1,s+Node[Node[index].child[k]].w);
		}
		
	}
	else{
		return;
	}
}
int main(){
	int wei;
	int fa,so,num;
	scanf("%d%d%d",&N,&M,&S);
	for(int i=0;i<N;i++){
		scanf("%d",&wei);
		Node[i].w=wei;
	}
	for(int i=0;i<M;i++){
		scanf("%d %d",&fa,&num);
		for(int j=0;j<num;j++){
			scanf("%d",&so);
			Node[fa].child.push_back(so);
		}
		sort(Node[fa].child.begin(),Node[fa].child.end(),cmp);
	}	
//	int sum=0;
//	s.push(0);
	ss[0]=Node[0].w;
	dfs(0,0,Node[0].w);
//	for(int i=0;i<ans.size();i++){
//		for(int j=0;j<ans[i].size();j++){
//			printf("%d",Node[ans[i][j]].w);
//			if(j!=ans[i].size()-1)
//				printf(" ");
//			else
//				printf("\n");
//		}
//	}
	return 0;
}
 
