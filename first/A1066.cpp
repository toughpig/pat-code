#include<cstdio>
#include<cmath>
#include<iostream> 
#include<algorithm>
using namespace std;
const int maxn=30;

struct node{
	int data;
//	int h;
	struct node *l;
	struct node *r;
};

int geth(node *root){
	if(root==NULL)
		return 0;
	return max(geth(root->l),geth(root->r))+1;
} 

node *newnode(int v){
	node *Node=(node*)malloc(sizeof(node));  //必须初始化，动态分配内存空间，不然出错 
	Node->data=v;
//	Node->h=1;
	Node->l=NULL;
	Node->r=NULL;
	return Node;
}

int getbf(node *root){
	return geth(root->l)-geth(root->r);
}

//void updateh(node* &root){
//	root->h=max(geth(root->l),geth(root->r))+1;
//}

node *L(node *root){
	node *temp=root->r;
	root->r=temp->l;
	temp->l=root;
//	updateh(temp);
//	updateh(root);
//	root=temp;
	return temp;
}

node *R(node *root){
	node *temp=root->l;
	root->l=temp->r;
	temp->r=root;
//	updateh(temp);
//	updateh(root);
//	root=temp;
	return temp;
}


node *insert(node *root,int v){
	if(root==NULL){
		root=newnode(v);
//		root=new node();
//		root->data=v;
//		root->r=root->l=NULL;
	}
	else if(v<root->data){
		root->l=insert(root->l,v);
//		updateh(root);
		if(geth(root->l)-geth(root->r)==2){
			if(root->l->data>v){
				root=R(root);
//				updateh(root);
//				updateh(root->r);
			}
			else{
				root->l=L(root->l);
				root=R(root);
//				updateh(root);
//				updateh(root->r);
//				updateh(root->l);
			}
		}
	}
	else{
		root->r=insert(root->r,v);
//		updateh(root);
		if(geth(root->l)-geth(root->r)==-2){
			if(root->r->data<=v){
				root=L(root);
//				updateh(root);
//				updateh(root->l);
			}
			else{
				root->r=R(root->r);
				root=L(root);
//				updateh(root);
//				updateh(root->r);
//				updateh(root->l);
			}
		}
	}
	return root;
}

//node* creat(int a[],int n){
//	node* root=NULL;
//	for(int i=0;i<n;i++){
//		insert(root,a[i]);
//	}
//	return root;
//}

int main(){
	int N;
	int nn;
	node *root=NULL;
//	int a[maxn];
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d",&nn);
		root=insert(root,nn);
	}
//	node* p=creat(a,N);
	printf("%d",root->data);
	return 0;
	
}
