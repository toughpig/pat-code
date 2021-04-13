#include<cstdio>
#include<queue>
using namespace std;
const int maxn=11;
int num;
struct node{
	int left;
	int right;
}Node[maxn];
bool notroot[maxn]={false};
static int cntt=0;
void inver_inorder(int root){
	if(root==-1)
	return;
	inver_inorder(Node[root].right);
	printf("%d",root);
	if(++cntt!=num)
	printf(" ");
//	else
//	printf("\n");
	inver_inorder(Node[root].left);
}
int main(){
	char ch;
	int cnt=0;
	scanf("%d",&num);
	getchar();
	for(int i=0;i<num;i++){
		scanf("%c",&ch);
		getchar();
		if(ch=='-'){
			Node[i].left=-1;
		}
		else{
			Node[i].left=ch-'0';
			notroot[ch-'0']=true;
		}
		scanf("%c",&ch);
		getchar();
		if(ch=='-'){
			Node[i].right=-1;
		}
		else{
			Node[i].right=ch-'0';
			notroot[ch-'0']=true;
		}
	}
	int root;
	for(root=0;root<num;root++){
		if(notroot[root]==false)
			break;
	}
	queue<int> q;
	q.push(root);
	while(!q.empty()){
		int temp=q.front();
		q.pop();
		printf("%d",temp);
		cnt++;
		if(cnt<num){
			printf(" ");
		}
		else{
			printf("\n");
		}
		if(Node[temp].right!=-1){
			q.push(Node[temp].right);
		}
		if(Node[temp].left!=-1){
			q.push(Node[temp].left);
		}
	}
	inver_inorder(root);
	return 0;
}
