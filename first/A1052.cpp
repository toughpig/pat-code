#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
struct node{
	int address;
	int data;
	int next;
	int flag;
}list[100010];

bool cmp(node a,node b){
	if(a.flag==0||b.flag==0)
		return a.flag>b.flag;
	else
		return a.data<b.data;
}
int main(){
	int N,head;
	scanf("%d %d",&N,&head);
	int add,key,addn;
	for(int i=0;i<N;i++){
		scanf("%d %d %d",&add,&key,&addn);
		list[add].address=add;
		list[add].data=key;
		list[add].next=addn;
		list[add].flag=-1;
	}
	int h=head;
	int len=0;
	while(list[h].flag==-1&&h!=-1){
		list[h].flag=1;
		h=list[h].next;
		len++;
	}
	sort(list,list+sizeof(list)/sizeof(node),cmp);
	if(len!=0){
	
	if(list[0].address!=-1){
	printf("%d %05d\n",len,list[0].address);
	for(int i=0;i<len-1;i++){
		printf("%05d %d %05d\n",list[i].address,list[i].data,list[i+1].address);
	}
	printf("%05d %d %d",list[len-1].address,list[len-1].data,-1);
}
else{
	printf("%05d %d %d",list[0].address,list[0].data,-1);
}
}
else{
	printf("%d %05d %d",0,head,-1);
}
	return 0;
}

