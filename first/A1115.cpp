#include<cstdio>
#include<vector>
#include<queue>
#include<cstdlib>
using namespace std;

struct node{
	int v;
	int h;
	node *l;
	node *r;
	node(int _v,int _h,node* _l,node* _r):v(_v),h(_h),l(_l),r(_r){};
};

int n,temp;
int maxx=0;
queue<node> q;

void insert(node* &root,int h,int v){
	if(root==NULL){
		root=new node(v,h,NULL,NULL);
		if(maxx<h) maxx=h;
	}
	else{
		if(root->v>=v) insert(root->l,h+1,v);
		else insert(root->r,h+1,v);
	}
}

int main(){
	int n1=0;
	int n2=0;
	scanf("%d",&n);
	node* root=(node*)malloc(sizeof(node));
	root=NULL;
	for(int i=0;i<n;i++){
		scanf("%d",&temp);
		insert(root,1,temp);
	}
	q.push(*root);
	while(!q.empty()){
		node Node=q.front();
		q.pop();
		if(Node.h==maxx-1) n2++;
		else if(Node.h==maxx) n1++;
		if(Node.l) q.push(*(Node.l));
		if(Node.r) q.push(*(Node.r));
	}
	printf("%d + %d = %d",n1,n2,n1+n2);
	return 0;
}
