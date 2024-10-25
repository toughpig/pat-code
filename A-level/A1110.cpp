#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

struct node{
//	int pos;
	int id,l,r;
	node(int _id,int _l,int _r):id(_id),l(_l),r(_r){};
};

vector<node> ve;
bool notroot[25]={false};
int n,le,ri;
int tail;
bool flag=true;
queue<int> q;
int cnt=0;

//void getpos(int root,int po){
//	if(root==-1) return;
//	ve[root].pos=po;
//	if(po>n){
//		flag=false;
//		return;
//	}
//	if(po==n) tail=root;
//	getpos(ve[root].l,po*2);
//	getpos(ve[root].r,po*2+1);
//}
int main(){
	char ch1,ch2;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("\n%c %c",&ch1,&ch2);
		if(ch1=='-') le=-1;
		else{
			le=ch1-'0';
			notroot[le]=true;
		}
		if(ch2=='-') ri=-1;
		else{
			ri=ch2-'0';
			notroot[ri]=true;
		}
		ve.push_back(node(i,le,ri));
	}
	int head;
	for(int i=0;i<n;i++){
		if(notroot[i]==false)
			head=i;
	}
	q.push(head);
	int temp;
	while(!q.empty()){
		temp=q.front();
		q.pop();
		if(temp!=-1){
			cnt++;
			tail=temp;
		}
		else{
			if(cnt==n) printf("YES %d",tail);
			else printf("NO %d",head);
			break;
		}
		q.push(ve[temp].l);
		q.push(ve[temp].r);
		
	}
//	ve[head].pos=1;
//	getpos(head,1);
//	if(flag) printf("YES %d",tail);
//	else printf("NO %d",head);
	return 0;
}
