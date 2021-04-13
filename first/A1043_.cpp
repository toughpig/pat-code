#include<cstdio>
#include<vector>
#include<cstdlib>
using namespace std;
struct node{
	int data;
	node* l;
	node* r;
};
vector<int> list[5];

node* create(int x){
	node* root=new node;
	root->l=NULL;
	root->r=NULL;
	root->data=x;
	return root;
}

void insert(node* &root,int x){
	if(root==NULL)
		root=create(x);
	else if(root->data>x)
		insert(root->l,x);
	else
		insert(root->r,x);
}

void pre(node* root){
	if(root==NULL) return;
	list[0].push_back(root->data);
	pre(root->l);
	pre(root->r);
}

void premir(node* root){
	if(root==NULL) return;
	list[1].push_back(root->data);
	premir(root->r);
	premir(root->l);
}

void postmir(node* root){
	if(root==NULL) return;
	postmir(root->r);
	postmir(root->l);
	list[3].push_back(root->data);
}

void post(node* root){
	if(root==NULL) return;
	post(root->l);
	post(root->r);
	list[2].push_back(root->data);
}

bool isequ(vector<int> a,vector<int> b){
	if(a.size()!=b.size()) return false;
	for(int i=0;i<a.size();i++)
		if(a[i]!=b[i]) return false;
	return true;
}

void print(vector<int> a){
	printf("YES\n");
	for(int i=0;i<a.size();i++)
	if(i==0)
		printf("%d",a[i]);
	else
		printf(" %d",a[i]);
}

int main(){
	int N,temp;
	scanf("%d",&N);
//	node* root=NULL;
	node* root=(node*)malloc(sizeof(node));
	root=NULL;
	for(int i=0;i<N;i++){
		scanf("%d",&temp);
		list[4].push_back(temp);
		insert(root,temp);
	}
	pre(root);
	premir(root);
	post(root);
	postmir(root);
	if(isequ(list[0],list[4])){
		print(list[2]);
	}
	else if(isequ(list[1],list[4])){
		print(list[3]);
	}
	else
		printf("NO");
	
	return 0;
}
