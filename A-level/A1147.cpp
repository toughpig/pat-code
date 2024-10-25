#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
vector<int> node;
int n,m,temp,head;
string results[3]={"Max Heap","Min Heap","Not Heap"};
int flag;
vector<int> post;

void pos(int a){
	if(a*2+1<m) pos(a*2+1);
	if(a*2+2<m) pos(a*2+2);
	post.push_back(node[a]);
}

int main(){
	scanf("%d%d",&n,&m);
	node.resize(m);
	for(int i=0;i<n;i++){
		flag=0;
		post.clear();
		node.clear();
		scanf("%d",&head);
		node.push_back(head);
		for(int j=1;j<m;j++){
			scanf("%d",&temp);
			if(temp>head) flag=1;
			node.push_back(temp);
		}
		pos(0);
		if(flag==1)
		for(int k=m-1;k>0;k--){
			if(node[k]<node[(k-1)/2]){
				flag=2;
				break;
			}
		}
		if(flag==0)
		for(int k=m-1;k>0;k--){
			if(node[k]>node[(k-1)/2]){
				flag=2;
				break;
			}
		}
		printf("%s\n",results[flag].c_str());
		for(int k=0;k<post.size();k++){
			if(k==0) printf("%d",post[k]);
			else printf(" %d",post[k]);
		}
		printf("\n");
	}
	
	return 0;
}
