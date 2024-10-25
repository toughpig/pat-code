#include<cstdio>
#include<vector>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;

struct node{
	int v;
	node *l;
	node *r;
};
int n,m,temp;
vector<int> tree;

void insert(node* &root,int val){
	if(root==NULL){
		root=(node*)malloc(sizeof(node));
		root->v=val;
		root->l=root->r=NULL;
	}
	else if(fabs(val)<fabs(root->v))
	insert(root->l,val);
	else
	insert(root->r,val);
}

bool judge1(node *root){
	if(root==NULL) return true;
	if(root->v<0){
		if(root->l!=NULL&&root->l->v<0) return false;
		if(root->r!=NULL&&root->r->v<0) return false;
		return judge1(root->l)&&judge1(root->r);
	}
	else{
		return judge1(root->l)&&judge1(root->r);
	}
}

int cnt(node *root){
	if(root==NULL) return 0;
	else if(root->v<0) return max(cnt(root->l),cnt(root->r));
	else return max(cnt(root->l),cnt(root->r))+1;
}

bool judge2(node *root){
	if(root==NULL) return true;
	int cntl=cnt(root->l);
	int cntr=cnt(root->r);
	if(cntl!=cntr) return false;
	return judge2(root->l)&&judge2(root->r);
}

int main(){
	scanf("%d",&n);
	node *root=(node*)malloc(sizeof(node));
	for(int p=0;p<n;p++){
		scanf("%d",&m);
		root=NULL;
		tree.clear();
		for(int i=0;i<m;i++){
			scanf("%d",&temp);
			insert(root,temp);
		}
		bool flag;
		flag=root->v<0||!judge1(root)||!judge2(root);
		if(flag) printf("No\n");
		else printf("Yes\n");
		
		
		
		
		
	}
	return 0;
}
