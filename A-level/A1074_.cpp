#include<cstdio>
struct node{
	int a;
	int na;
	int data;
	int next;
}list[1000000];
bool check(int a,int k){
	for(int i=0;i<k;i++){
		if(a==-1)
			return false;
		a=list[a].next;
	}
	return true;
}
int main(){
	
	int head,N,K;
	scanf("%d%d%d",&head,&N,&K);
	int da,ad,ne,former;
	former=1000000;
	for(int i=0;i<N;i++){
		scanf("%d %d%d",&ad,&da,&ne);
		list[ad].a=ad;
		list[ad].na=former;
		list[ad].data=da;
		list[ad].next=ne;
		former=ad;
	}
	int temp=head;
	int first=1000000;
	int tail;
	while(temp!=-1){
		if(!check(temp,K)) break;
		tail=temp;
		for(int i=0;i<K-1;i++)
			tail=list[tail].next;
		if(first==1000000) printf("%05d ",list[tail].a);
		else
			printf("%05d ",first);
		printf("%d %05d\n",list[tail].data,list[tail].na);
		first=list[temp].a;
		for(int i=list[tail].na;i!=-1;i=list[i].na){
			if(i!=temp)
				printf("%05d %d %05d\n",list[i].a,list[i].data,list[i].na);
			else{
				printf("%05d %d ",list[i].a,list[i].data);
				break;
			}
		}
		temp=list[tail].next;
	}
	if(temp!=-1){
		for(int i=temp;i!=-1;i=list[i].next){
			if(list[i].next!=-1){
				printf("%05d %d %05d\n",first,list[i].data,list[i].next);
			first=list[i].next;
			}
			else{
				printf("%05d %d %d\n",first,list[i].data,list[i].next);
				break;
			}
		}
	}
	
	return 0;
}

