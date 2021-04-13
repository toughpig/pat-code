#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;
struct node{
	int k;
	int f;
	int next;
}list[100000];
set<int> s;
bool find(int a){
	return s.find(a)!=s.end();
}
int main(){
	int a,N;
	int ad,da,ne;
	scanf("%d%d",&a,&N);
	for(int i=0;i<N;i++){
		scanf("%d%d%d",&ad,&da,&ne);
		list[ad].k=da;
		if(s.find(abs(da))!=s.end()){
			list[ad].f=1;
		}
		else{
			list[ad].f=0;
			s.insert(abs(da));
		}
		list[ad].next=ne;
	}
	int a1=-1;
	int a2=-1;
	for(int temp=a;temp!=-1;temp=list[temp].next){
		if(list[temp].f==0){
			if(a1==-1){
				printf("%05d %d ",temp,list[temp].k);
			}
			else{
				printf("%05d\n",temp);
				printf("%05d %d ",temp,list[temp].k);
			}
			a1=1;
		}
	}
	printf("%d\n",-1);
	int p;
	for(p=a;p!=-1;p=list[p].next){
		if(list[p].f==1)
		break;
	}
	if(p!=-1){
	
	for(int temp=p;temp!=-1;temp=list[temp].next){
		if(list[temp].f==1){
			if(a2==-1){
				printf("%05d %d ",temp,list[temp].k);
			}
			else{
				printf("%05d\n",temp);
				printf("%05d %d ",temp,list[temp].k);
			}
			a2=1;
		}
	}
	printf("%d\n",-1);
}
	return 0;
}

