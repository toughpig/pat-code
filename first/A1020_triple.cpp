#include<cstdio>
#include<queue>
#include<cstdlib>
using namespace std;
const int maxn=35;
struct node{
	int data;
	node* l;
	node* r;
};

int post[maxn];
int in[maxn];
int N;
queue<node> q;

node* creat(int postl,int postr,int inl,int inr){
	if(postl>postr) return NULL;
	node* root=new node;
	root->data=post[postr];
	int pos;
	for(pos=inl;pos<=inr;pos++)
		if(in[pos]==post[postr])
			break;
	int numl=pos-inl;
	root->l=creat(postl,postl+numl-1,inl,pos-1);
	root->r=creat(postl+numl,postr-1,pos+1,inr);
	return root;
} 

int main(){
	scanf("%d",&N);
	for(int i=1;i<=N;i++)
		scanf("%d",post+i);
	for(int i=1;i<=N;i++)
		scanf("%d",in+i);
	node* root=(node*)malloc(sizeof(node));
	root=creat(1,N,1,N);
	q.push(*root);
	while(!q.empty()){
		node temp=q.front();
		q.pop();
		if(temp.l)
			q.push(*(temp.l));
		if(temp.r)
			q.push(*(temp.r));
		printf("%d",temp.data);
		if(!q.empty())
			printf(" ");
	}
	return 0;
}
