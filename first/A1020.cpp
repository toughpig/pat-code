#include<cstdio>
#include<queue>
using namespace std;
struct node{
	int data;
	node* lc;
	node* rc;
};
typedef node* dot;

	int po[33];
	int in[33];
node* creat(int inl,int inr,int pol,int por){
	if(inl>inr) return NULL;
	dot root;
//	root->lc=NULL;
//	root->rc=NULL;
	root->data=po[por];
	int k;
	for(k=inl;k<=inr;k++){
		if(in[k]==root->data)
			break;
	}
	int m=k-inl+1;
	root->lc=creat(inl,k-1,pol,pol+m-1);
	root->rc=creat(k+1,inr,pol+m,por-1);
	return root;
}
static int p;
void print(int a){
	if (p>1){
		printf("%d ",a);
		p--;
	}
	else
	printf("%d",a);
}
void levelOrder(dot n){
	if(n==NULL) return;
	queue<dot> q;
	q.push(n);
	while(!q.empty()){
		dot now=q.front();
		q.pop();
		if(now->lc!=NULL)
			q.push(now->lc);
		if(now->rc!=NULL)
			q.push(now->rc);
		print(now->data);
			
	}
}


//queue<dot> q;
int main(){
	int N;
	scanf("%d",&N);
	p=N;
	node *tree;
	int n=N;
	for(int i=1;i<=N;i++){
		scanf("%d",po+i);
	}	

	for(int i=1;i<=N;i++){
		scanf("%d",in+i);
	}	

	tree=creat(1,N,1,N);
	levelOrder(tree);
	
	return 0;
}
 
