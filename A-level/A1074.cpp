#include<cstdio>
int maxn=1000100;
struct node{
	int data;
	int next;
}list[1000100];

bool check(int a,int k){
	for(int i=0;i<k;i++){
		if(a==-1)
		return false;
		a=list[a].next;
	}
	return true;
}
int main(){
	int head;
	int N;int K;
	scanf("%d%d%d",&head,&N,&K);
	int ad,da,ne;
	for(int i=0;i<N;i++){
		scanf("%d%d%d",&ad,&da,&ne);
		list[ad].data=da;
		list[ad].next=ne;
	}
	int temp,nex,mid,end,nowend;
	end=maxn;
	temp=head;
	while(temp!=-1){
		if(!check(temp,K))  break;
		nowend=temp;
		nex=list[temp].next;
		mid=list[nex].next;
		for(int i=0;i<K-1;i++){
			list[nex].next=temp;
			temp=nex;nex=mid;
			if(nex!=-1)
				mid=list[nex].next;
		}
		list[end].next=temp;
		end=nowend;
		temp=nex;
		
	}
	list[end].next=temp;
	int l=maxn;
	while(list[l].next!=-1){
		l=list[l].next;
		if(list[l].next!=-1)
		printf("%05d %d %05d\n",l,list[l].data,list[l].next);
		else
		printf("%05d %d %d",l,list[l].data,list[l].next);
	}
	return 0;
}

